// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file generate_list_of_flags.hpp
 *
 * @brief Defines the `generate_list_of_flags` type
 */


#ifndef CYNODELIC_METAFLAGS_GENERATE_LIST_OF_FLAGS_HPP
#define CYNODELIC_METAFLAGS_GENERATE_LIST_OF_FLAGS_HPP


#include <cstdlib>
#include <cstddef>
#include <stdexcept>

#include <cynodelic/mulinum/integer_c.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/help_parameters.hpp>
#include <cynodelic/metaflags/detail/help_generation_helpers.hpp>
#include <cynodelic/metaflags/parser_parameters.hpp>
#include <cynodelic/metaflags/parser.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename,typename>
struct generate_list_of_flags_impl;


template <typename... Params,typename... Flags>
struct generate_list_of_flags_impl<help_parameters<Params...>,parser<Flags...>> : detail::generate_list_of_flags_with_header<help_parameters<Params...>,Flags...>
{};


template <typename... Params,typename... PrsParams,typename... Flags>
struct generate_list_of_flags_impl<help_parameters<Params...>,parser<parser_parameters<PrsParams...>,Flags...>> : detail::generate_list_of_flags_with_header<help_parameters<Params...>,Flags...>
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup helpgeneration
 * @brief Generates a list with the flags of a parser
 *
 * Generates a @link cynodelic::mulinum::string string@endlink with a list of
 * the flags, as well as their arguments (if any) and descriptions, from a
 * @ref parser.
 *
 * @tparam ParamT A @ref help_parameters used for the generation of the list.
 * @tparam Parser The @ref parser.
 */
template <typename ParamT,typename Parser>
using generate_list_of_flags = typename generate_list_of_flags_impl<ParamT,Parser>::type;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_GENERATE_LIST_OF_FLAGS_HPP
