// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file argument_type.hpp
 *
 * @brief Defines the `argument_type` type operation
 */


#ifndef CYNODELIC_METAFLAGS_ARGUMENT_TYPE_HPP
#define CYNODELIC_METAFLAGS_ARGUMENT_TYPE_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/detail/multiple_flag_getters_maker.hpp>
#include <cynodelic/metaflags/fwd/parser_fwd.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename,typename,std::size_t>
struct argument_type_impl;


template <typename... Flags,char... FlagChars,std::size_t ArgIdx>
struct argument_type_impl<parser<Flags...>,mulinum::string<FlagChars...>,ArgIdx>
{
	using type = decltype(detail::multiple_flags_data_helper<Flags...>::get(mulinum::string<FlagChars...>{},mulinum::size_c<ArgIdx>{}));
};


template <typename... Params,typename... Flags,char... FlagChars,std::size_t ArgIdx>
struct argument_type_impl<parser<parser_parameters<Params...>,Flags...>,mulinum::string<FlagChars...>,ArgIdx>
{
	using type = decltype(detail::multiple_flags_data_helper<Flags...>::get(mulinum::string<FlagChars...>{},mulinum::size_c<ArgIdx>{}));
};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits_
 * @brief Obtains the type of the argument of a flag
 *
 * Obtains the type of the `ArgIdx`-th argument of a given flag.
 *
 * @tparam Parser     An instance of @ref parser.
 * @tparam FlagString A @link cynodelic::mulinum::string string@endlink
 *                    containing the alias of the desired flag.
 * @tparam ArgIdx     The position of the desired argument.
 */
template <typename Parser,typename FlagString,std::size_t ArgIdx>
using argument_type = typename argument_type_impl<Parser,FlagString,ArgIdx>::type;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_ARGUMENT_TYPE_HPP
