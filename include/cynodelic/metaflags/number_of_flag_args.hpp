// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file number_of_flag_args.hpp
 *
 * @brief Defines the `number_of_flag_args` type trait
 */


#ifndef CYNODELIC_METAFLAGS_NUMBER_OF_FLAG_ARGS_HPP
#define CYNODELIC_METAFLAGS_NUMBER_OF_FLAG_ARGS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/parser_parameters.hpp>
#include <cynodelic/metaflags/detail/multiple_flag_getters_maker.hpp>
#include <cynodelic/metaflags/fwd/parser_fwd.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename,typename>
struct number_of_flag_args_impl;


template <typename... Flags,char... FlagChars>
struct number_of_flag_args_impl<parser<Flags...>,mulinum::string<FlagChars...>> :
	mulinum::size_c<
		detail::multiple_flags_data_helper<Flags...>::num_args(mulinum::string<FlagChars...>{})
	>
{};


template <typename... Params,typename... Flags,char... FlagChars>
struct number_of_flag_args_impl<parser<parser_parameters<Params...>,Flags...>,mulinum::string<FlagChars...>> :
	mulinum::size_c<
		detail::multiple_flags_data_helper<Flags...>::num_args(mulinum::string<FlagChars...>{})
	>
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits_
 * @brief Number of flag arguments
 *
 * Outputs a @link cynodelic::mulinum::size_c size_c@endlink with the number
 * of arguments of a flag, indicated by `FlagString`.
 *
 * @tparam Parser     The @ref parser .
 * @tparam FlagString The @link cynodelic::mulinum::string string@endlink
 *                    corresponding to the desired flag.
 */
template <typename Parser,typename FlagString>
using number_of_flag_args = typename number_of_flag_args_impl<Parser,FlagString>::type;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_NUMBER_OF_FLAG_ARGS_HPP
