// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file get_as_tuple.hpp
 *
 * @brief Defines the `get_as_tuple` function
 */


#ifndef CYNODELIC_METAFLAGS_GET_AS_TUPLE_HPP
#define CYNODELIC_METAFLAGS_GET_AS_TUPLE_HPP


#include <cstdlib>
#include <cstddef>
#include <tuple>

#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector_c.hpp>
#include <cynodelic/mulinum/iota.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/argument_types_list.hpp>
#include <cynodelic/metaflags/number_of_flag_args.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace detail
{
	template <typename Parser,typename FlagString,std::size_t... Idcs>
	inline argument_types_list<std::tuple,Parser,FlagString> get_as_tuple_impl(mulinum::vector_c<std::size_t,Idcs...>)
	{
		return argument_types_list<std::tuple,Parser,FlagString>{(Parser::template get<FlagString,Idcs>())...};
	}	
} // end of "detail" namespace

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup parsing
 * @brief Gets the parsed arguments of a flag as a tuple
 *
 * If the flag corresponding to `FlagString` was called, returns a `std::tuple`
 * containing all the parsed parameters of a flag, otherwise, returns a
 * _default_ value, given by `default_val`.
 *
 * @tparam Parser      The @ref parser that contains the desired flag.
 * @tparam FlagString  The @link cynodelic::mulinum::string string@endlink
 *                     that corresponds to the desired flag.
 * @param  default_val A `std::tuple` with all the default values (optional).
 */
template <typename Parser,typename FlagString>
argument_types_list<std::tuple,Parser,FlagString> get_as_tuple(argument_types_list<std::tuple,Parser,FlagString> default_val = {})
{
	if (Parser::template was_called<FlagString>())
	{
		return detail::get_as_tuple_impl<Parser,FlagString>(
			mulinum::iota<
				mulinum::vector_c_tag<std::size_t>,
				mulinum::size_c<0>,
				number_of_flag_args<Parser,FlagString>
			>{}
		);
	}
	else
	{
		return default_val;
	}
}


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_GET_AS_TUPLE_HPP
