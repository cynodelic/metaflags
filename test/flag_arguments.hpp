// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_HPP
#define CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_HPP


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(flag_arguments)
{
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i8_arg<>::value_type,std::int8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i8_arg<>::help_str,mln::string<'i','n','t','8'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i8_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u8_arg<>::value_type,std::uint8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u8_arg<>::help_str,mln::string<'u','i','n','t','8'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u8_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i16_arg<>::value_type,std::int16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i16_arg<>::help_str,mln::string<'i','n','t','1','6'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i16_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u16_arg<>::value_type,std::uint16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u16_arg<>::help_str,mln::string<'u','i','n','t','1','6'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u16_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i32_arg<>::value_type,std::int32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i32_arg<>::help_str,mln::string<'i','n','t','3','2'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i32_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u32_arg<>::value_type,std::uint32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u32_arg<>::help_str,mln::string<'u','i','n','t','3','2'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u32_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i64_arg<>::value_type,std::int64_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i64_arg<>::help_str,mln::string<'i','n','t','6','4'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::i64_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u64_arg<>::value_type,std::uint64_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u64_arg<>::help_str,mln::string<'u','i','n','t','6','4'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::u64_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::bln_arg<>::value_type,bool>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::bln_arg<>::help_str,mln::string<'b','o','o','l'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::bln_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::flt_arg<>::value_type,float>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::flt_arg<>::help_str,mln::string<'f','l','o','a','t'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::flt_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::dbl_arg<>::value_type,double>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::dbl_arg<>::help_str,mln::string<'d','o','u','b','l','e'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::dbl_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
	
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::str_arg<>::value_type,std::string>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::str_arg<>::help_str,mln::string<'s','t','r','i','n','g'>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<typename mfl::str_arg<'t','e','s','t'>::help_str,mln::string<'t','e','s','t'>>::value));
}


#endif // CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_HPP
