// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file argument_types_list.hpp
 *
 * @brief Defines the `argument_types_list` type operation
 */


#ifndef CYNODELIC_METAFLAGS_ARGUMENT_TYPES_LIST_HPP
#define CYNODELIC_METAFLAGS_ARGUMENT_TYPES_LIST_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector_c.hpp>
#include <cynodelic/mulinum/iota.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/fwd/parser_fwd.hpp>
#include <cynodelic/metaflags/number_of_flag_args.hpp>
#include <cynodelic/metaflags/argument_type.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <template <typename...> class,typename,typename,typename>
struct argument_types_list_impl_impl;


template <template <typename...> class TypeList,typename Parser,typename FlagString,std::size_t... Idcs>
struct argument_types_list_impl_impl<TypeList,Parser,FlagString,mulinum::vector_c<std::size_t,Idcs...>>
{
	using type = TypeList<argument_type<Parser,FlagString,Idcs>...>;
};


template <template <typename...> class TypeList,typename Parser,typename FlagString>
using argument_types_list_impl = argument_types_list_impl_impl<
	TypeList,
	Parser,
	FlagString,
	mulinum::iota<
		mulinum::vector_c_tag<std::size_t>,
		mulinum::size_c<0>,
		number_of_flag_args<Parser,FlagString>
	>
>;


#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits_
 * @brief Generates a list with the argument types of a flag
 *
 * Outputs a `TypeList` containing all the types corresponding to the desired
 * flag, which is indicated by `FlagString`.
 *
 * @tparam TypeList   The type list that will contain the argument types.
 * @tparam Parser     The @ref parser .
 * @tparam FlagString The @link cynodelic::mulinum::string string@endlink
 *                    corresponding to the desired flag.
 */
template <template <typename...> class TypeList,typename Parser,typename FlagString>
using argument_types_list = typename argument_types_list_impl<TypeList,Parser,FlagString>::type;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_ARGUMENT_TYPES_LIST_HPP
