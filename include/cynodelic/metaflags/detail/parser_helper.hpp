// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_PARSER_HELPER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_PARSER_HELPER_HPP


#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>
#include <stdexcept>

#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/vector_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/iota.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/start_at.hpp>
#include <cynodelic/metaflags/detail/call_status_holder.hpp>
#include <cynodelic/metaflags/detail/multiple_flag_getters_maker.hpp>
#include <cynodelic/metaflags/detail/join_all_parser_flags.hpp>
#include <cynodelic/metaflags/detail/parser_runtime_data_holder.hpp>
#include <cynodelic/metaflags/exceptions/bad_argument_parsing.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename,typename>
	struct set_last_argument_to_parse;
	

	template <typename ParserRtDataHolder,std::size_t Pos>
	struct set_last_argument_to_parse<ParserRtDataHolder,finish_at<Pos>>
	{
		static inline void call(const int&)
		{
			ParserRtDataHolder::finishes_parsing_at() = Pos;
		}
	};


	template <typename ParserRtDataHolder>
	struct set_last_argument_to_parse<ParserRtDataHolder,runtime_finish_at>
	{
		static inline void call(const int&)
		{
			return;
		}
	};


	template <typename ParserRtDataHolder>
	struct set_last_argument_to_parse<ParserRtDataHolder,parse_to_last_arg>
	{
		static inline void call(const int& argc)
		{
			ParserRtDataHolder::finishes_parsing_at() = static_cast<std::size_t>(argc - 1);
		}
	};


	template <typename,typename>
	struct get_start_at_val;


	template <typename Parser,std::size_t Pos>
	struct get_start_at_val<Parser,start_at<Pos>>
	{
		static inline std::size_t get()
		{
			return Pos;
		}
	};


	template <typename Parser>
	struct get_start_at_val<Parser,runtime_start_at>
	{
		static inline std::size_t get()
		{
			return parser_runtime_data_holder<Parser>::starts_parsing_at();
		}
	};


	/**
	 * @brief Undefined
	 */
	template <typename,typename,typename,typename...>
	struct parser_helper;


	/**
	 * @brief Helper for `parser`
	 */
	template <std::size_t Pos,typename AllParserFlags,char... FlagChars,char... HelpChars,typename... FlagArgs,typename... Others>
	struct parser_helper<start_at<Pos>,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>,Others...>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>;
			using next_parser  = parser_helper<start_at<Pos>,AllParserFlags,Others...>;

			call_status_holder<current_flag>::value() = false;

			std::vector<std::string> captured_args(current_flag::num_args);

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = Pos; i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					for (std::size_t j = 0; j < current_flag::num_args; j++)
					{
						if (is_in_string_vector<AllParserFlags>::eval(argv[i + 1 + j]))
						{
							std::string throw_msg = std::string("[cynodelic::metaflags::detail::parser_helper<...>::parse()] A flag (")
								+ std::string(argv[i + 1 + j])
								+ std::string(") cannot be passed as an argument for another flag.");

							throw bad_argument_parsing(throw_msg);
						}

						captured_args[j] = argv[i + 1 + j];
					}

					//current_flag::set_from_string_vector(captured_args);
					set_values_from_strings<
						multiple_flag_arg_values_holder<current_flag>,
						mulinum::iota_c<mulinum::vector_c_tag<std::size_t>,0,current_flag::num_args>
					>::call(captured_args);

					call_status_holder<current_flag>::value() = true;

					finished_at = i + current_flag::num_args;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}

			next_parser::template parse<ParentParser>(argc,argv);
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <std::size_t Pos,typename AllParserFlags,char... FlagChars,char... HelpChars,typename... FlagArgs>
	struct parser_helper<start_at<Pos>,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>;

			call_status_holder<current_flag>::value() = false;

			std::vector<std::string> captured_args(current_flag::num_args);

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = Pos; i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					for (std::size_t j = 0; j < current_flag::num_args; j++)
					{
						if (is_in_string_vector<AllParserFlags>::eval(argv[i + 1 + j]))
						{
							std::string throw_msg = std::string("[cynodelic::metaflags::detail::parser_helper<...>::parse()] A flag (")
								+ std::string(argv[i + 1 + j])
								+ std::string(") cannot be passed as an argument for another flag.");

							throw bad_argument_parsing(throw_msg);
						}
						
						captured_args[j] = argv[i + 1 + j];
					}

					//current_flag::set_from_string_vector(captured_args);
					set_values_from_strings<
						multiple_flag_arg_values_holder<current_flag>,
						mulinum::iota_c<mulinum::vector_c_tag<std::size_t>,0,current_flag::num_args>
					>::call(captured_args);

					call_status_holder<current_flag>::value() = true;

					finished_at = i + current_flag::num_args;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <std::size_t Pos,typename AllParserFlags,char... FlagChars,char... HelpChars,typename... Others>
	struct parser_helper<start_at<Pos>,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>,Others...>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>;
			using next_parser  = parser_helper<start_at<Pos>,AllParserFlags,Others...>;

			call_status_holder<current_flag>::value() = false;

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = Pos; i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					call_status_holder<current_flag>::value() = true;

					finished_at = i;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}

			next_parser::template parse<ParentParser>(argc,argv);
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <std::size_t Pos,typename AllParserFlags,char... FlagChars,char... HelpChars>
	struct parser_helper<start_at<Pos>,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>;

			call_status_holder<current_flag>::value() = false;

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = Pos; i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					call_status_holder<current_flag>::value() = true;

					finished_at = i;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <typename AllParserFlags,char... FlagChars,char... HelpChars,typename... FlagArgs,typename... Others>
	struct parser_helper<runtime_start_at,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>,Others...>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>;
			using next_parser  = parser_helper<runtime_start_at,AllParserFlags,Others...>;

			call_status_holder<current_flag>::value() = false;

			std::vector<std::string> captured_args(current_flag::num_args);

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = parser_runtime_data_holder<ParentParser>::starts_parsing_at(); i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					for (std::size_t j = 0; j < current_flag::num_args; j++)
					{
						if (is_in_string_vector<AllParserFlags>::eval(argv[i + 1 + j]))
						{
							std::string throw_msg = std::string("[cynodelic::metaflags::detail::parser_helper<...>::parse()] A flag (")
								+ std::string(argv[i + 1 + j])
								+ std::string(") cannot be passed as an argument for another flag.");

							throw bad_argument_parsing(throw_msg);
						}

						captured_args[j] = argv[i + 1 + j];
					}

					//current_flag::set_from_string_vector(captured_args);
					set_values_from_strings<
						multiple_flag_arg_values_holder<current_flag>,
						mulinum::iota_c<mulinum::vector_c_tag<std::size_t>,0,current_flag::num_args>
					>::call(captured_args);

					call_status_holder<current_flag>::value() = true;

					finished_at = i + current_flag::num_args;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}

			next_parser::template parse<ParentParser>(argc,argv);
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <typename AllParserFlags,char... FlagChars,char... HelpChars,typename... FlagArgs>
	struct parser_helper<runtime_start_at,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>;

			call_status_holder<current_flag>::value() = false;

			std::vector<std::string> captured_args(current_flag::num_args);

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = parser_runtime_data_holder<ParentParser>::starts_parsing_at(); i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					for (std::size_t j = 0; j < current_flag::num_args; j++)
					{
						if (is_in_string_vector<AllParserFlags>::eval(argv[i + 1 + j]))
						{
							std::string throw_msg = std::string("[cynodelic::metaflags::detail::parser_helper<...>::parse()] A flag (")
								+ std::string(argv[i + 1 + j])
								+ std::string(") cannot be passed as an argument for another flag.");

							throw bad_argument_parsing(throw_msg);
						}
						
						captured_args[j] = argv[i + 1 + j];
					}

					//current_flag::set_from_string_vector(captured_args);
					set_values_from_strings<
						multiple_flag_arg_values_holder<current_flag>,
						mulinum::iota_c<mulinum::vector_c_tag<std::size_t>,0,current_flag::num_args>
					>::call(captured_args);

					call_status_holder<current_flag>::value() = true;

					finished_at = i + current_flag::num_args;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <typename AllParserFlags,char... FlagChars,char... HelpChars,typename... Others>
	struct parser_helper<runtime_start_at,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>,Others...>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>;
			using next_parser  = parser_helper<runtime_start_at,AllParserFlags,Others...>;

			call_status_holder<current_flag>::value() = false;

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = parser_runtime_data_holder<ParentParser>::starts_parsing_at(); i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					call_status_holder<current_flag>::value() = true;

					finished_at = i;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}

			next_parser::template parse<ParentParser>(argc,argv);
		}
	};


	/**
	 * @brief Helper for `parser`
	 */
	template <typename AllParserFlags,char... FlagChars,char... HelpChars>
	struct parser_helper<runtime_start_at,AllParserFlags,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>>
	{
		template <typename ParentParser>
		static inline void parse(int argc,char** argv,parser_runtime_data_holder<ParentParser> = {})
		{
			using current_flag = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>;

			call_status_holder<current_flag>::value() = false;

			std::size_t finished_at = parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos();

			std::size_t end_of_parsing = (static_cast<std::size_t>(argc - 1) > parser_runtime_data_holder<ParentParser>::finishes_parsing_at()) ?
				parser_runtime_data_holder<ParentParser>::finishes_parsing_at() :
				static_cast<std::size_t>(argc - 1);

			for (std::size_t i = parser_runtime_data_holder<ParentParser>::starts_parsing_at(); i < (end_of_parsing + 1); i++)
			{
				if (current_flag::equals(argv[i]))
				{
					call_status_holder<current_flag>::value() = true;

					finished_at = i;

					break;
				}
			}

			if (finished_at > parser_runtime_data_holder<ParentParser>::last_parsed_arg_pos())
			{
				parser_runtime_data_holder<ParentParser>::set_last_parsed_arg_pos(finished_at);
			}
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_PARSER_HELPER_HPP
