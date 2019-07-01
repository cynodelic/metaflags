// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_REMOVE_ZEROES_FROM_STRING_HPP
#define CYNODELIC_METAFLAGS_DETAIL_REMOVE_ZEROES_FROM_STRING_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/if.hpp>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename,typename>
	struct flag_arg_push_back_impl;


	template <template <char...> class FlagArg,char... CharsL,char... CharsR>
	struct flag_arg_push_back_impl<FlagArg<CharsL...>,FlagArg<CharsR...>>
	{
		using type = FlagArg<CharsL...,CharsR...>;
	};


	template <typename Lhs,typename Rhs>
	using flag_arg_push_back = typename flag_arg_push_back_impl<Lhs,Rhs>::type;


	template <typename>
	struct remove_zeroes_from_string_impl;


	template <template <char...> class FlagArg,char First,char... Others>
	struct remove_zeroes_from_string_impl<FlagArg<First,Others...>>
	{
		using type = mulinum::if_<
			First == '\0',
			FlagArg<>,
			flag_arg_push_back<
				FlagArg<First>,
				typename remove_zeroes_from_string_impl<
					FlagArg<Others...>
				>::type
			>
		>;
	};


	template <template <char...> class FlagArg>
	struct remove_zeroes_from_string_impl<FlagArg<>>
	{
		using type = FlagArg<>;
	};


	template <typename FlagArg>
	using remove_zeroes_from_string = typename remove_zeroes_from_string_impl<FlagArg>::type;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_REMOVE_ZEROES_FROM_STRING_HPP
