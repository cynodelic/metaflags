// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_HELP_GENERATION_HELPERS_HPP
#define CYNODELIC_METAFLAGS_DETAIL_HELP_GENERATION_HELPERS_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/mulinum/if.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/concat.hpp>
#include <cynodelic/mulinum/fill.hpp>
#include <cynodelic/mulinum/to_string.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/help_parameters.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename First,typename... Others>
	struct make_list_of_flag_args_helper
	{
		using type = mulinum::concat<
			mulinum::string<'['>,
			typename First::help_str,
			mulinum::string<']',' '>,
			typename make_list_of_flag_args_helper<Others...>::type
		>;
	};


	template <typename Last>
	struct make_list_of_flag_args_helper<Last>
	{
		using type = mulinum::concat<
			mulinum::string<'['>,
			typename Last::help_str,
			mulinum::string<']'>
		>;
	};


	template <typename>
	struct make_list_of_flag_args_impl;


	template <char... FlagChars,char... HelpChars,typename... FlagArgs>
	struct make_list_of_flag_args_impl<flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>> : make_list_of_flag_args_helper<FlagArgs...>::type
	{};


	template <typename Flag>
	using make_list_of_flag_args = typename make_list_of_flag_args_impl<Flag>::type;


	template <std::size_t,typename>
	struct tabulate_in_new_line_impl;


	template <std::size_t TabSize,char First,char... Others>
	struct tabulate_in_new_line_impl<TabSize,mulinum::string<First,Others...>>
	{
		using type = mulinum::concat<
			mulinum::string<First>,
			typename tabulate_in_new_line_impl<TabSize,mulinum::string<Others...>>::type
		>;
	};


	template <std::size_t TabSize,char... Others>
	struct tabulate_in_new_line_impl<TabSize,mulinum::string<'\n',Others...>>
	{
		using type = mulinum::concat<
			mulinum::string<'\n'>,
			mulinum::string_fill<' ',TabSize>,
			typename tabulate_in_new_line_impl<TabSize,mulinum::string<Others...>>::type
		>;
	};


	template <std::size_t TabSize>
	struct tabulate_in_new_line_impl<TabSize,mulinum::string<>>
	{
		using type = mulinum::string<>;
	};


	template <std::size_t TabSize,typename StringT>
	using tabulate_in_new_line = typename tabulate_in_new_line_impl<TabSize,StringT>::type;


	template <typename,char>
	struct join_flags_impl;


	template <char... Chars,typename... Others,char Delim>
	struct join_flags_impl<mulinum::vector<mulinum::string<Chars...>,Others...>,Delim> :
		mulinum::concat<
			mulinum::string<Chars...,Delim>,
			typename join_flags_impl<mulinum::vector<Others...>,Delim>::type
		>
	{};


	template <char... Chars,char Delim>
	struct join_flags_impl<mulinum::vector<mulinum::string<Chars...>>,Delim> :
		mulinum::string<Chars...>
	{};


	template <typename StrVec,char Delim>
	using join_flags = typename join_flags_impl<StrVec,Delim>::type;


	template <bool,typename,typename...>
	struct generate_itemized_list_of_flags_impl;


	template <bool AddHelpFlag,typename... Params,char... FlagChars,char... HelpChars,typename... FlagArgs,typename... Others>
	struct generate_itemized_list_of_flags_impl<AddHelpFlag,help_parameters<Params...>,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>,Others...>
	{
		using type = mulinum::concat<
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation>,
			join_flags<typename flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>::flags_list,help_parameters<Params...>::flag_aliases_delimiter>,
			mulinum::string<' '>,
			make_list_of_flag_args<
				flag<
					mulinum::string<FlagChars...>,
					mulinum::string<HelpChars...>,
					FlagArgs...
				>
			>,
			mulinum::string<':','\n'>,
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation>,
			tabulate_in_new_line<
				help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation,
				mulinum::string<HelpChars...>
			>,
			mulinum::string<'\n'>,
			typename generate_itemized_list_of_flags_impl<
				AddHelpFlag,
				help_parameters<Params...>,
				Others...
			>::type
		>;
	};


	template <bool AddHelpFlag,typename... Params,char... FlagChars,char... HelpChars,typename... Others>
	struct generate_itemized_list_of_flags_impl<AddHelpFlag,help_parameters<Params...>,flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>,Others...>
	{
		using type = mulinum::concat<
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation>,
			join_flags<typename flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>::flags_list,help_parameters<Params...>::flag_aliases_delimiter>,
			mulinum::string<':','\n'>,
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation>,
			tabulate_in_new_line<
				help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation,
				mulinum::string<HelpChars...>
			>,
			mulinum::string<'\n'>,
			typename generate_itemized_list_of_flags_impl<
				AddHelpFlag,
				help_parameters<Params...>,
				Others...
			>::type
		>;
	};


	template <typename... Params>
	struct generate_itemized_list_of_flags_impl<true,help_parameters<Params...>>
	{
		using type = mulinum::concat<
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation>,
			join_flags<typename help_parameters<Params...>::flags_list,help_parameters<Params...>::flag_aliases_delimiter>,
			mulinum::string<':','\n'>,
			mulinum::string_fill<' ',help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation>,
			tabulate_in_new_line<
				help_parameters<Params...>::flag_tabulation + help_parameters<Params...>::flag_help_tabulation,
				CYNODELIC_METAFLAGS_STRING_KL("Displays this help and quits the program.",42)
			>,
			mulinum::string<'\n'>
		>;
	};


	template <typename... Params>
	struct generate_itemized_list_of_flags_impl<false,help_parameters<Params...>>
	{
		using type = mulinum::string<>;
	};


	template <bool AddHelpFlags,typename ParamT,typename... Flags>
	using generate_itemized_list_of_flags = typename generate_itemized_list_of_flags_impl<AddHelpFlags,ParamT,Flags...>::type;


	template <typename,typename...>
	struct generate_list_of_flags_with_header_impl;


	template <typename... Params,typename... Flags>
	struct generate_list_of_flags_with_header_impl<help_parameters<Params...>,Flags...>
	{
		using type = mulinum::concat<
			mulinum::if_<
				help_parameters<Params...>::show_list_header,
				mulinum::concat<typename help_parameters<Params...>::flags_list_header,mulinum::string<'\n'>>,
				mulinum::string<>
			>,
			generate_itemized_list_of_flags<help_parameters<Params...>::add_help_flags_to_list,help_parameters<Params...>,Flags...>
		>;
	};


	template <typename HelpParams,typename... Flags>
	using generate_list_of_flags_with_header = typename generate_list_of_flags_with_header_impl<HelpParams,Flags...>::type;


	template <bool,typename>
	struct usage_printer_impl;

	template <typename... Args>
	struct usage_printer_impl<false,usage_format<Args...>>
	{
		static inline void print(int,char**)
		{}
	};


	template <char... Chars,typename... Others>
	struct usage_printer_impl<true,usage_format<mulinum::string<Chars...>,Others...>>
	{
		static inline void print(int argc,char** argv)
		{
			std::cout << mulinum::string<Chars...>::c_str();

			usage_printer_impl<true,usage_format<Others...>>::print(argc,argv);
		}
	};


	template <typename... Others>
	struct usage_printer_impl<true,usage_format<program_name,Others...>>
	{
		static inline void print(int argc,char** argv)
		{
			std::cout << argv[0];

			usage_printer_impl<true,usage_format<Others...>>::print(argc,argv);
		}
	};


	template <>
	struct usage_printer_impl<true,usage_format<>>
	{
		static inline void print(int,char**)
		{
			std::cout << '\n';
		}
	};


	template <typename>
	struct usage_printer;


	template <typename... Args>
	struct usage_printer<help_parameters<Args...>> : usage_printer_impl<help_parameters<Args...>::show_usage,typename help_parameters<Args...>::usage_format>
	{
		using usage_printer_impl<help_parameters<Args...>::show_usage,typename help_parameters<Args...>::usage_format>::print;
	};


	template <typename HelpParams,typename... Flags>
	struct help_printer
	{
		static void print(int argc,char** argv)
		{
			usage_printer<HelpParams>::print(argc,argv);
			std::cout << generate_list_of_flags_with_header<HelpParams,Flags...>::c_str();
		}
	};


	template <typename... Flags>
	struct help_printer<disable_help_in_parser,Flags...>
	{
		static void print(int /* argc */,char** /* argv */)
		{
			return;
		}
	};


	template <typename,typename>
	struct parse_and_print_help;


	template <typename... Args,typename... Flags>
	struct parse_and_print_help<help_parameters<Args...>,help_printer<help_parameters<Args...>,Flags...>>
	{
		static void call(int argc,char** argv)
		{
			if (
				(argc == 2 && detail::is_in_string_vector<typename help_parameters<Args...>::flags_list>::eval(argv[1])) ||
				(argc == 1 && help_parameters<Args...>::print_help_if_no_arguments)
			)
			{
				help_printer<help_parameters<Args...>,Flags...>::print(argc,argv);

				std::exit(EXIT_SUCCESS);
			}
		}
	};


	template <typename... Flags>
	struct parse_and_print_help<disable_help_in_parser,help_printer<disable_help_in_parser,Flags...>>
	{
		static void call(int /* argc */,char** /* argv */)
		{
			return;
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_HELP_GENERATION_HELPERS_HPP
