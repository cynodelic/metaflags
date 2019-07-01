// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_SET_VALUES_FROM_STRINGS_HPP
#define CYNODELIC_METAFLAGS_DETAIL_SET_VALUES_FROM_STRINGS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/vector_c.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/detail/string_parsing_helper.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief Undefined
	 */
	template <typename,typename>
	struct set_values_from_strings;


	/**
	 * @brief Stores the parsed values into the flag's arguments
	 */
	template <typename ArgValHolder,std::size_t First,std::size_t... Others>
	struct set_values_from_strings<ArgValHolder,mulinum::vector_c<std::size_t,First,Others...>>
	{
		static inline void call(const std::vector<std::string>& str_vec)
		{
			using current_arg = decltype(ArgValHolder::current_arg_helper(mulinum::size_c<First>{}));

			ArgValHolder::value(mulinum::size_c<First>{}) = string_parsing_helper<current_arg>::call(str_vec[First]);

			set_values_from_strings<ArgValHolder,mulinum::vector_c<std::size_t,Others...>>::call(str_vec);
		}
	};


	/**
	 * @brief Stores the parsed values into the flag's arguments
	 */
	template <typename ArgValHolder,std::size_t Last>
	struct set_values_from_strings<ArgValHolder,mulinum::vector_c<std::size_t,Last>>
	{
		static inline void call(const std::vector<std::string>& str_vec)
		{
			using current_arg = decltype(ArgValHolder::current_arg_helper(mulinum::size_c<Last>{}));

			ArgValHolder::value(mulinum::size_c<Last>{}) = string_parsing_helper<current_arg>::call(str_vec[Last]);
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_SET_VALUES_FROM_STRINGS_HPP
