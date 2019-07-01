// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file parser_parameters.hpp
 *
 * @brief Defines the `parser_parameters` type
 */


#ifndef CYNODELIC_METAFLAGS_PARSER_PARAMETERS_HPP
#define CYNODELIC_METAFLAGS_PARSER_PARAMETERS_HPP


#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>
#include <stdexcept>

#include <cynodelic/mulinum/if.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/null_type.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/start_at.hpp>
#include <cynodelic/metaflags/finish_at.hpp>
#include <cynodelic/metaflags/help_parameters.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS
	namespace detail
	{
		template <typename...>
		struct has_start_at_arg;

		template <typename First,typename... Others>
		struct has_start_at_arg<First,Others...> : has_start_at_arg<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct has_start_at_arg<start_at<Value>,Others...> : mulinum::true_
		{};

		template <typename... Others>
		struct has_start_at_arg<runtime_start_at,Others...> : mulinum::true_
		{};

		template <>
		struct has_start_at_arg<> : mulinum::false_
		{};

		template <typename...>
		struct get_start_at_arg_impl;

		template <typename First,typename... Others>
		struct get_start_at_arg_impl<First,Others...> : get_start_at_arg_impl<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct get_start_at_arg_impl<start_at<Value>,Others...> : start_at<Value>
		{};

		template <typename... Others>
		struct get_start_at_arg_impl<runtime_start_at,Others...> : runtime_start_at
		{};

		template <>
		struct get_start_at_arg_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_start_at_arg = typename get_start_at_arg_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_help_params_arg;

		template <typename First,typename... Others>
		struct has_help_params_arg<First,Others...> : has_help_params_arg<Others...>
		{};

		template <typename... Params,typename... Others>
		struct has_help_params_arg<help_parameters<Params...>,Others...> : mulinum::true_
		{};

		template <typename... Others>
		struct has_help_params_arg<disable_help_in_parser,Others...> : mulinum::true_
		{};

		template <>
		struct has_help_params_arg<> : mulinum::false_
		{};

		template <typename...>
		struct get_help_params_arg_impl;

		template <typename First,typename... Others>
		struct get_help_params_arg_impl<First,Others...> : get_help_params_arg_impl<Others...>
		{};

		template <typename... Params,typename... Others>
		struct get_help_params_arg_impl<help_parameters<Params...>,Others...> : help_parameters<Params...>
		{};

		template <typename... Others>
		struct get_help_params_arg_impl<disable_help_in_parser,Others...> : disable_help_in_parser
		{};

		template <>
		struct get_help_params_arg_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_help_params_arg = typename get_help_params_arg_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_finish_at_arg;

		template <typename First,typename... Others>
		struct has_finish_at_arg<First,Others...> : has_finish_at_arg<Others...>
		{};

		template <std::size_t Pos,typename... Others>
		struct has_finish_at_arg<finish_at<Pos>,Others...> : mulinum::true_
		{};

		template <typename... Others>
		struct has_finish_at_arg<runtime_finish_at,Others...> : mulinum::true_
		{};

		template <typename... Others>
		struct has_finish_at_arg<parse_to_last_arg,Others...> : mulinum::true_
		{};

		template <>
		struct has_finish_at_arg<> : mulinum::false_
		{};

		template <typename...>
		struct get_finish_at_arg_impl;

		template <typename First,typename... Others>
		struct get_finish_at_arg_impl<First,Others...> : get_finish_at_arg_impl<Others...>
		{};

		template <std::size_t Pos,typename... Others>
		struct get_finish_at_arg_impl<finish_at<Pos>,Others...> : finish_at<Pos>
		{};

		template <typename... Others>
		struct get_finish_at_arg_impl<runtime_finish_at,Others...> : runtime_finish_at
		{};

		template <typename... Others>
		struct get_finish_at_arg_impl<parse_to_last_arg,Others...> : parse_to_last_arg
		{};

		template <>
		struct get_finish_at_arg_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_finish_at_arg = typename get_finish_at_arg_impl<Args...>::type;
	}
#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup parsing
 * @brief Contains parameters for a parser
 *
 * Contains the parameters used by an instance of @ref parser, set in a _named
 * parameters_ fashion: the first and last arguments to parse, as well as the
 * parameters related to the help generation.
 *
 * @tparam Args... The @link parsingparams parameters@endlink.
 */
template <typename... Args>
struct parser_parameters
{
	/// @brief The parameter related to the first argument to parse
	using starts_at = mulinum::if_<detail::has_start_at_arg<Args...>::value,detail::get_start_at_arg<Args...>,start_at<1>>;

	/// @brief The parameter related to the last argument to parse
	using finishes_at = mulinum::if_<detail::has_finish_at_arg<Args...>::value,detail::get_finish_at_arg<Args...>,parse_to_last_arg>;

	/// @brief The set of parameters related to the help generation
	using help_params = mulinum::if_<detail::has_help_params_arg<Args...>::value,detail::get_help_params_arg<Args...>,help_parameters<>>;
};


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_PARSER_PARAMETERS_HPP
