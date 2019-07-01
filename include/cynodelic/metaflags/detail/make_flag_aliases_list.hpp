// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_MAKE_FLAG_ALIASES_LIST_HPP
#define CYNODELIC_METAFLAGS_DETAIL_MAKE_FLAG_ALIASES_LIST_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/split.hpp>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename>
	struct format_flag_aliases_impl;

	template <char... LongNameChars>
	struct format_flag_aliases_impl<mulinum::vector<mulinum::string<LongNameChars...>>>
	{
		using type = mulinum::vector<mulinum::string<'-','-',LongNameChars...>>;
	};

	template <char... LongNameChars,char... ShortNameChars>
	struct format_flag_aliases_impl<mulinum::vector<mulinum::string<LongNameChars...>,mulinum::string<ShortNameChars...>>>
	{
		using type = mulinum::vector<mulinum::string<'-','-',LongNameChars...>,mulinum::string<'-',ShortNameChars...>>;
	};

	template <typename FlagAliasesVec>
	using format_flag_aliases = typename format_flag_aliases_impl<FlagAliasesVec>::type;


	template <typename>
	struct make_flag_aliases_list_impl;

	template <char... Chars>
	struct make_flag_aliases_list_impl<mulinum::string<Chars...>>
	{
		using type = format_flag_aliases<mulinum::split<mulinum::string<Chars...>,mulinum::char_c<','>,mulinum::vector_tag>>;
	};

	template <typename FlagAliasesString>
	using make_flag_aliases_list = typename make_flag_aliases_list_impl<FlagAliasesString>::type;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_MAKE_FLAG_ALIASES_LIST_HPP
