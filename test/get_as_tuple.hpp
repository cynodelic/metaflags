// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_GET_AS_TUPLE_HPP
#define CYNODELIC_METAFLAGS_TEST_GET_AS_TUPLE_HPP


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(get_as_tuple)
{
	using prs = mfl::parser<
		FLAG_("test-flag-1,t1","First",mfl::i8_arg<>,mfl::i16_arg<>,mfl::i32_arg<>,mfl::i64_arg<>),
		FLAG_("test-flag-2,t2","Second",mfl::u8_arg<>,mfl::u16_arg<>,mfl::u32_arg<>,mfl::u64_arg<>),
		FLAG_("test-flag-3,t3","Third",mfl::str_arg<>,mfl::str_arg<>,mfl::str_arg<>),
		FLAG_("test-flag-4,t4","Fourth",mfl::bln_arg<>,mfl::flt_arg<>,mfl::dbl_arg<>),
		FLAG_("test-flag-5,t5","Fifth",mfl::i64_arg<>,mfl::str_arg<>,mfl::bln_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"--test-flag-1",
		"100","-1000","50505123","-51664194501",
		"--test-flag-2",
		"255","60043","17789101","405997145235",
		"--test-flag-3",
		"hello","awful","world",
		"--test-flag-4",
		"true","3.14159265","-0.994746987312397",
		"--test-flag-5",
		"845071348902","some_argument","false"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	std::tuple<std::int8_t,std::int16_t,std::int32_t,std::int64_t>     first_expected{100,-1000,50505123,-51664194501};
	std::tuple<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t> second_expected{255,60043,17789101,405997145235};
	std::tuple<std::string,std::string,std::string>                    third_expected{"hello","awful","world"};
	std::tuple<bool,float,double>                                      fourth_expected{true,3.14159265,-0.994746987312397};
	std::tuple<std::int64_t,std::string,bool>                          fifth_expected{845071348902,"some_argument",false};

	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("--test-flag-1")>()),first_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("--test-flag-2")>()),second_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("--test-flag-3")>()),third_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("--test-flag-4")>()),fourth_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("--test-flag-5")>()),fifth_expected);

	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("-t1")>()),first_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("-t2")>()),second_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("-t3")>()),third_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("-t4")>()),fourth_expected);
	CYNODELIC_TESTER_CHECK_EQUALS((mfl::get_as_tuple<prs,STRING_("-t5")>()),fifth_expected);
}


#endif // CYNODELIC_METAFLAGS_TEST_GET_AS_TUPLE_HPP
