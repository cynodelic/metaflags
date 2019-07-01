// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file parser.hpp
 *
 * @brief Defines the `parser` class
 */


#ifndef CYNODELIC_METAFLAGS_PARSER_HPP
#define CYNODELIC_METAFLAGS_PARSER_HPP


#include <cstdlib>
#include <cstddef>
#include <string>
#include <stdexcept>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/equals.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/parser_parameters.hpp>
#include <cynodelic/metaflags/detail/help_generation_helpers.hpp>
#include <cynodelic/metaflags/detail/parser_runtime_data_holder.hpp>
#include <cynodelic/metaflags/detail/parser_helper.hpp>
#include <cynodelic/metaflags/argument_type.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup parsing
 * @brief Parser
 *
 * Class for parsing command-line arguments, given the flags to parse.
 *
 * @tparam Flags... The @link flags flags@endlink that will be parsed.
 */
template <typename... Flags>
struct parser
{
	/// @brief Reference to itself
	using type = parser<Flags...>;

	/// @brief The parameters used by the parser
	using parameters = parser_parameters<start_at<1>,parse_to_last_arg,help_parameters<>>;

	/// @brief The contained flags
	using contained_flags = mulinum::vector<Flags...>;


	/**
	 * @brief Sets the position of the first argument to parse
	 *
	 * Determines at runtime, if allowed my the parser's parameters, where is the
	 * first argument to be parsed.
	 * It such parameter was defined at compile-time, this method will have no
	 * effect.
	 *
	 * @param pos The position of the first argument to parse (non-zero).
	 */
	static void set_start(const std::size_t& pos)
	{
		if (pos == 0)
		{
			throw std::invalid_argument("[cynodelic::metaflags::parser<...>] The position of the first argument to parse must not be zero.");
		}

		detail::parser_runtime_data_holder<type>::set_starts_parsing_at(pos);
	}


	/**
	 * @brief Sets the position of the last argument to parse
	 *
	 * Determines at runtime, if allowed my the parser's parameters, where is the
	 * last argument to be parsed.
	 * It such parameter was defined at compile-time or it was defined as the last
	 * parsed argument, this method will have no effect.
	 *
	 * @param pos The position of the last argument to parse (non-zero).
	 */
	static void set_end(const std::size_t& pos)
	{
		if (pos == 0)
		{
			throw std::invalid_argument("[cynodelic::metaflags::parser<...>] The position of the last argument to parse must not be zero.");
		}

		detail::parser_runtime_data_holder<type>::set_finishes_parsing_at(pos);
	}


	/**
	 * @brief Position of the first argument to parse
	 *
	 * Returns the position of the first argument that will be parsed.
	 */
	static std::size_t starts_at()
	{
		return detail::get_start_at_val<type,typename parameters::starts_at>::get();
	}


	/**
	 * @brief Prints the generated help
	 *
	 * Prints the generated help.
	 *
	 * @param argc The `argc` parameter (number of arguments) of the `main` function.
	 * @param argv The `argv` parameter (the arguments) of the `main` function.
	 */
	static void print_help(int argc,char** argv)
	{
		detail::help_printer<
			typename parameters::help_params,
			Flags...
		>::call(argc,argv);
	}


	/**
	 * @brief Parsing function
	 *
	 * Does the parsing of the command-line arguments.
	 *
	 * @param argc The `argc` parameter (number of arguments) of the `main` function.
	 * @param argv The `argv` parameter (the arguments) of the `main` function.
	 */
	static void parse(int argc,char** argv)
	{
		detail::parser_runtime_data_holder<type>::set_last_parsed_arg_pos(starts_at());

		detail::parse_and_print_help<
			typename parameters::help_params,
			detail::help_printer<
				typename parameters::help_params,
				Flags...
			>
		>::call(argc,argv);


		detail::set_last_argument_to_parse<
			detail::parser_runtime_data_holder<type>,
			typename parameters::finishes_at
		>::call(argc);


		detail::parser_helper<
			start_at<1>,
			detail::join_all_parser_flags<Flags...>,
			Flags...
		>::template parse<type>(argc,argv);
	}


	/**
	 * @brief Obtains a value from a flag argument
	 *
	 * Obtains the value of the `Idx`-th argument of a given flag. If it is a
	 * _switch_ (a flag with no arguments), it will return a `bool` indicating if it
	 * was called (`true` if called).
	 * If the flag was not called in the command line, it will return a default
	 * value, with the same type as the desired argument.
	 *
	 * @tparam FlagString  A @link cynodelic::mulinum::string string@endlink
	 *                     containing alias of the flag that contains the desired
	 *                     argument.
	 * @tparam Idx         The position of the desired argument (it will have no
	 *                     effect for _switches_).
	 * @param  default_val The default value that will be returned, if the flag was
	 *                     not called in the command line.
	 */
	template <typename FlagString,std::size_t Idx>
	static auto get(argument_type<type,FlagString,Idx> default_val = {}) -> argument_type<type,FlagString,Idx>
	{
		if (detail::multiple_flags_data_helper<Flags...>::was_called(FlagString{}))
		{
			return detail::multiple_flags_data_helper<Flags...>::get(FlagString{},mulinum::size_c<Idx>{});
		}
		else
		{
			return default_val;
		}
	}


	/**
	 * @brief Checks if a flag was called
	 *
	 * Checks if a flag was called (set) in the command-line, returning `true` if
	 * this was accomplished.
	 *
	 * @tparam FlagString A @link cynodelic::mulinum::string string@endlink with the
	 *                    flag to check.
	 */
	template <typename FlagString>
	static bool was_called()
	{
		return detail::multiple_flags_data_helper<Flags...>::was_called(FlagString{});
	}


	/**
	 * @brief Position of the last parsed argument
	 *
	 * Returns the position of the last parsed argument.
	 */
	static std::size_t last_parsed_argument_position()
	{
		return detail::parser_runtime_data_holder<type>::last_parsed_arg_pos();
	}


	/**
	 * @brief Indicates the last element that was parsed
	 *
	 * Indicates the position of the last command-line argument that was analyzed by
	 * the parser, including the invalid ones.
	 */
	static std::size_t finished_at()
	{
		return detail::parser_runtime_data_holder<type>::finishes_parsing_at();
	}
};


/**
 * @ingroup parsing
 * @brief Parser with custom parameters
 *
 * Class for parsing command-line arguments, given the initial and final
 * positions and the parameters for the help generation (contained in a
 * @ref parsing_parameters), and the flags to parse.
 *
 * @tparam Params... The @link parsingparams parameters@endlink that will be used by the parser.
 * @tparam Flags...  The @link flags flags@endlink that will be parsed.
 */
template <typename... Params,typename... Flags>
struct parser<parser_parameters<Params...>,Flags...>
{
	/// @brief Reference to itself
	using type = parser<parser_parameters<Params...>,Flags...>;

	/// @brief The parameters used by the parser
	using parameters = parser_parameters<Params...>;

	/// @brief The contained flags
	using contained_flags = mulinum::vector<Flags...>;


	/**
	 * @brief Sets the position of the first argument to parse
	 *
	 * Determines at runtime, if allowed my the parser's parameters, where is the
	 * first argument to be parsed.
	 * It such parameter was defined at compile-time, this method will have no
	 * effect.
	 *
	 * @param pos The position of the first argument to parse (non-zero).
	 */
	static void set_start(const std::size_t& pos)
	{
		if (pos == 0)
		{
			throw std::invalid_argument("[cynodelic::metaflags::parser<...>] The position of the first argument to parse must not be zero.");
		}

		detail::parser_runtime_data_holder<type>::set_starts_parsing_at(pos);
	}


	/**
	 * @brief Sets the position of the last argument to parse
	 *
	 * Determines at runtime, if allowed my the parser's parameters, where is the
	 * last argument to be parsed.
	 * It such parameter was defined at compile-time or it was defined as the last
	 * parsed argument, this method will have no effect.
	 *
	 * @param pos The position of the last argument to parse (non-zero).
	 */
	static void set_end(const std::size_t& pos)
	{
		if (pos == 0)
		{
			throw std::invalid_argument("[cynodelic::metaflags::parser<...>] The position of the last argument to parse must not be zero.");
		}

		detail::parser_runtime_data_holder<type>::set_finishes_parsing_at(pos);
	}


	/**
	 * @brief Position of the first argument to parse
	 *
	 * Returns the position of the first argument that will be parsed.
	 */
	static std::size_t starts_at()
	{
		return detail::get_start_at_val<type,typename parameters::starts_at>::get();
	}


	/**
	 * @brief Prints the generated help
	 *
	 * Prints the generated help.
	 *
	 * @param argc The `argc` parameter (number of arguments) of the `main` function.
	 * @param argv The `argv` parameter (the arguments) of the `main` function.
	 */
	static void print_help(int argc,char** argv)
	{
		detail::help_printer<
			typename parameters::help_params,
			Flags...
		>::call(argc,argv);
	}


	/**
	 * @brief Parsing function
	 *
	 * Does the parsing of the command-line arguments.
	 *
	 * @param argc The `argc` parameter (number of arguments) of the `main` function.
	 * @param argv The `argv` parameter (the arguments) of the `main` function.
	 */
	static void parse(int argc,char** argv)
	{
		detail::parser_runtime_data_holder<type>::set_last_parsed_arg_pos(starts_at());

		detail::parse_and_print_help<
			typename parameters::help_params,
			detail::help_printer<
				typename parameters::help_params,
				Flags...
			>
		>::call(argc,argv);


		detail::set_last_argument_to_parse<
			detail::parser_runtime_data_holder<type>,
			typename parameters::finishes_at
		>::call(argc);


		detail::parser_helper<
			typename parameters::starts_at,
			detail::join_all_parser_flags<Flags...>,
			Flags...
		>::template parse<type>(argc,argv);
	}


	/**
	 * @brief Obtains a value from a flag argument
	 *
	 * Obtains the value of the `Idx`-th argument of a given flag. If it is a
	 * _switch_ (a flag with no arguments), it will return a `bool` indicating if it
	 * was called (`true` if called).
	 * If the flag was not called in the command line, it will return a default
	 * value, with the same type as the desired argument.
	 *
	 * @tparam FlagString  A @link cynodelic::mulinum::string string@endlink
	 *                     containing alias of the flag that contains the desired
	 *                     argument.
	 * @tparam Idx         The position of the desired argument (it will have no
	 *                     effect for _switches_).
	 * @param  default_val The default value that will be returned, if the flag was
	 *                     not called in the command line.
	 */
	template <typename FlagString,std::size_t Idx>
	static auto get(argument_type<type,FlagString,Idx> default_val = {}) -> argument_type<type,FlagString,Idx>
	{
		if (detail::multiple_flags_data_helper<Flags...>::was_called(FlagString{}))
		{
			return detail::multiple_flags_data_helper<Flags...>::get(FlagString{},mulinum::size_c<Idx>{});
		}
		else
		{
			return default_val;
		}
	}


	/**
	 * @brief Checks if a flag was called
	 *
	 * Checks if a flag was called (set) in the command-line, returning `true` if
	 * this was accomplished.
	 *
	 * @tparam FlagString A @link cynodelic::mulinum::string string@endlink with the
	 *                    flag to check.
	 */
	template <typename FlagString>
	static bool was_called()
	{
		return detail::multiple_flags_data_helper<Flags...>::was_called(FlagString{});
	}


	/**
	 * @brief Position of the last parsed argument
	 *
	 * Returns the position of the last parsed argument.
	 */
	static std::size_t last_parsed_argument_position()
	{
		return detail::parser_runtime_data_holder<type>::last_parsed_arg_pos();
	}


	/**
	 * @brief Indicates the last element that was parsed
	 *
	 * Indicates the position of the last command-line argument that was analyzed by
	 * the parser, including the invalid ones.
	 */
	static std::size_t finished_at()
	{
		return detail::parser_runtime_data_holder<type>::finishes_parsing_at();
	}
};


}} // end of "cynodelic::metaflags" namespace


#include <cynodelic/metaflags/preprocessor/pp_parser.hpp>


#endif // CYNODELIC_METAFLAGS_PARSER_HPP
