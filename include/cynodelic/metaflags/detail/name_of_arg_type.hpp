// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_NAME_OF_ARG_TYPE_HPP
#define CYNODELIC_METAFLAGS_DETAIL_NAME_OF_ARG_TYPE_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/if.hpp>
#include <cynodelic/mulinum/string.hpp>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename>
	struct name_of_arg_type_impl;

	template <>
	struct name_of_arg_type_impl<std::int8_t> : mulinum::string<'i','n','t','8'>
	{};

	template <>
	struct name_of_arg_type_impl<std::int16_t> : mulinum::string<'i','n','t','1','6'>
	{};

	template <>
	struct name_of_arg_type_impl<std::int32_t> : mulinum::string<'i','n','t','3','2'>
	{};

	template <>
	struct name_of_arg_type_impl<std::int64_t> : mulinum::string<'i','n','t','6','4'>
	{};

	template <>
	struct name_of_arg_type_impl<std::uint8_t> : mulinum::string<'u','i','n','t','8'>
	{};

	template <>
	struct name_of_arg_type_impl<std::uint16_t> : mulinum::string<'u','i','n','t','1','6'>
	{};

	template <>
	struct name_of_arg_type_impl<std::uint32_t> : mulinum::string<'u','i','n','t','3','2'>
	{};

	template <>
	struct name_of_arg_type_impl<std::uint64_t> : mulinum::string<'u','i','n','t','6','4'>
	{};

	template <>
	struct name_of_arg_type_impl<bool> : mulinum::string<'b','o','o','l'>
	{};

	template <>
	struct name_of_arg_type_impl<float> : mulinum::string<'f','l','o','a','t'>
	{};

	template <>
	struct name_of_arg_type_impl<double> : mulinum::string<'d','o','u','b','l','e'>
	{};

	template <>
	struct name_of_arg_type_impl<std::string> : mulinum::string<'s','t','r','i','n','g'>
	{};

	template <typename T>
	using name_of_arg_type = typename name_of_arg_type_impl<T>::type;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_NAME_OF_ARG_TYPE_HPP
