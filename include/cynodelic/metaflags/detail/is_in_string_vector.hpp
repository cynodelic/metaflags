// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_IS_IN_STRING_VECTOR_HPP
#define CYNODELIC_METAFLAGS_DETAIL_IS_IN_STRING_VECTOR_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief Undefined
	 */
	template <typename>
	struct is_in_string_vector;


	/**
	 * @brief Checks if a string is in a _vector of strings_.
	 */
	template <char... Chars,typename... Others>
	struct is_in_string_vector<mulinum::vector<mulinum::string<Chars...>,Others...>>
	{
		static inline bool eval(const std::string& str)
		{
			return (str == mulinum::string<Chars...>::c_str()) ? true : is_in_string_vector<mulinum::vector<Others...>>::eval(str);
		}
	};


	/**
	 * @brief Checks if a string is in a _vector of strings_.
	 */
	template <char... Chars>
	struct is_in_string_vector<mulinum::vector<mulinum::string<Chars...>>>
	{
		static inline bool eval(const std::string& str)
		{
			return (str == mulinum::string<Chars...>::c_str());
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_IS_IN_STRING_VECTOR_HPP
