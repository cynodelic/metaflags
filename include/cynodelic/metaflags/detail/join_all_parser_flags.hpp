// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_JOIN_ALL_PARSER_FLAGS_HPP
#define CYNODELIC_METAFLAGS_DETAIL_JOIN_ALL_PARSER_FLAGS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>

#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/concat.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename...>
	struct join_all_parser_flags_impl;


	template <char... FlagChars,char... HelpChars,typename... FlagArgs,typename... Others>
	struct join_all_parser_flags_impl<flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>,Others...>
	{
		using type = mulinum::concat<
			typename flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>::flags_list,
			typename join_all_parser_flags_impl<Others...>::type
		>;
	};


	template <char... FlagChars,char... HelpChars,typename... Others>
	struct join_all_parser_flags_impl<flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>,Others...>
	{
		using type = mulinum::concat<
			typename flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>::flags_list,
			typename join_all_parser_flags_impl<Others...>::type
		>;
	};


	template <>
	struct join_all_parser_flags_impl<>
	{
		using type = mulinum::vector<>;
	};


	template <typename... Flags>
	using join_all_parser_flags = typename join_all_parser_flags_impl<Flags...>::type;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_JOIN_ALL_PARSER_FLAGS_HPP
