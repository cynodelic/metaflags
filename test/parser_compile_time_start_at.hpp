// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_START_AT_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_START_AT_HPP


CYNODELIC_TESTER_TEST_CASE(parser_compile_time_start_at);

CYNODELIC_TESTER_SECTION(parser_compile_time_start_at,from_second_argument_all_flags_a)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::start_at<2>
		>,
		FLAG_("t1","...",mfl::i32_arg<>),
		FLAG_("t2","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"ignored",
		"--t1","100",
		"--t2","50","22"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),6);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),6);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--t1")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--t2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t1",0)),100);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",0)),50);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",1)),22);
}

CYNODELIC_TESTER_SECTION(parser_compile_time_start_at,from_second_argument_all_flags_b)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::start_at<2>
		>,
		FLAG_("t1","...",mfl::i32_arg<>),
		FLAG_("t2","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"--t1","100",
		"--t2","50","22"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),5);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),5);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t1")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--t2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t1",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",0)),50);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",1)),22);
}

CYNODELIC_TESTER_SECTION(parser_compile_time_start_at,from_second_argument_all_flags_c)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::start_at<2>
		>,
		FLAG_("t1","...",mfl::i32_arg<>),
		FLAG_("t2","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"--t2","50","22",
		"--t1","100"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),5);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),5);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--t1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t1",0)),100);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",1)),0);
}

CYNODELIC_TESTER_SECTION(parser_compile_time_start_at,from_second_argument_no_flags_a)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::start_at<2>
		>,
		FLAG_("t1","...",mfl::i32_arg<>),
		FLAG_("t2","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),0);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t1",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",1)),0);
}

CYNODELIC_TESTER_SECTION(parser_compile_time_start_at,from_second_argument_no_flags_b)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::start_at<2>
		>,
		FLAG_("t1","...",mfl::i32_arg<>),
		FLAG_("t2","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"3.14159"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),1);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--t2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t1",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--t2",1)),0);
}


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_START_AT_HPP
