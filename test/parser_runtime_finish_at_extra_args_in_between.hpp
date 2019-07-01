// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP


CYNODELIC_TESTER_TEST_CASE(parser_runtime_finish_at_extra_args_in_between);

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_second_argument_all_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(2);

	argv_maker test_argv(
		"test",
		"--x1",
		"arg",
		"--x2",
		"qqqqqqqqqq"
		"--x3",
		"--x4",
		"--x5"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),1);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_second_argument_single_switch)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(2);

	argv_maker test_argv(
		"test",
		"ddddd",
		"--x1",
		"aaaaa"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_second_argument_no_args)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(2);

	argv_maker test_argv(
		"test",
		"123456",
		"qwertyuiop"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),1);

	CYNODELIC_TESTER_MESSAGE << prs::last_parsed_argument_position();

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_fourth_argument_all_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(4);

	argv_maker test_argv(
		"test",
		"1",
		"--x3",
		"2",
		"--x5",
		"--x1",
		"9",
		"--x4",
		"--x2"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),4);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_fourth_argument_three_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(4);

	argv_maker test_argv(
		"test",
		"iiiii",
		"--x1",
		"a",
		"b",
		"--x3",
		"--x5",
		"x"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_fourth_argument_single_switch)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(4);

	argv_maker test_argv(
		"test",
		"--yy",
		"--x1",
		"--asdf"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}

CYNODELIC_TESTER_SECTION(parser_runtime_finish_at_extra_args_in_between,to_fourth_argument_no_args)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_finish_at
		>,
		SWITCH_("x1","..."),
		SWITCH_("x2","..."),
		SWITCH_("x3","..."),
		SWITCH_("x4","..."),
		SWITCH_("x5","...")
	>;

	prs::set_end(4);

	argv_maker test_argv(
		"test",
		"test",
		"input.jpg",
		"8"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),1);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--x5")));
}


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP
