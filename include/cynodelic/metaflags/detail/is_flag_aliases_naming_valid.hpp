// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_IS_FLAG_ALIASES_NAMING_VALID_HPP
#define CYNODELIC_METAFLAGS_DETAIL_IS_FLAG_ALIASES_NAMING_VALID_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/at.hpp>
#include <cynodelic/mulinum/logical_and.hpp>
#include <cynodelic/mulinum/split.hpp>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
#ifdef CYNODELIC_METAFLAGS_DISABLE_FLAG_NAMING_CONSTRAINTS

	template <char>
	using is_valid_flag_character = mulinum::true_;
#else // CYNODELIC_METAFLAGS_DISABLE_FLAG_NAMING_CONSTRAINTS

	template <char Chr>
	using is_valid_flag_character = mulinum::bool_c<
		(Chr >= 'A' && Chr <= 'Z') ||
		(Chr >= 'a' && Chr <= 'z') ||
		(Chr >= '0' && Chr <= '9') ||
		(Chr == '_') || (Chr == '-')
	>;
#endif // CYNODELIC_METAFLAGS_DISABLE_FLAG_NAMING_CONSTRAINTS


	template <typename>
	struct string_has_valid_chars_impl;


	template <char... Chars>
	struct string_has_valid_chars_impl<mulinum::string<Chars...>> :
		mulinum::logical_and<is_valid_flag_character<Chars>...>
	{};


	template <>
	struct string_has_valid_chars_impl<mulinum::string<>> :
		mulinum::false_
	{};


	template <typename StringT>
	using string_has_valid_chars = typename string_has_valid_chars_impl<StringT>::type;


	template <typename>
	struct is_valid_flag_alias_impl;


	template <char First,char... Others>
	struct is_valid_flag_alias_impl<mulinum::string<First,Others...>> :
		mulinum::logical_and<
			mulinum::bool_c<First != '-'>,
			string_has_valid_chars<mulinum::string<Others...>>
		>
	{};


	template <char Chr>
	struct is_valid_flag_alias_impl<mulinum::string<Chr>> :
		mulinum::bool_c<
			(Chr >= 'A' && Chr <= 'Z') ||
			(Chr >= 'a' && Chr <= 'z') ||
			(Chr >= '0' && Chr <= '9') ||
			(Chr == '_')
		>
	{};


	template <typename StringT>
	using is_valid_flag_alias = typename is_valid_flag_alias_impl<StringT>::type;


	template <typename>
	struct check_strings_in_vector;


	template <typename... Strings>
	struct check_strings_in_vector<mulinum::vector<Strings...>> :
		 mulinum::logical_and<is_valid_flag_alias<Strings>...>
	{};


	template <>
	struct check_strings_in_vector<mulinum::vector<>> :
		 mulinum::false_
	{};


	template <typename FlagAliasesString>
	using is_flag_aliases_naming_valid = typename check_strings_in_vector<
		mulinum::split<
			FlagAliasesString,
			mulinum::char_c<','>,
			mulinum::vector_tag
		>
	>::type;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_IS_FLAG_ALIASES_NAMING_VALID_HPP
