// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP


CYNODELIC_TESTER_TEST_CASE(parser_compile_time_finish_at_extra_args_in_between);

CYNODELIC_TESTER_SECTION(parser_compile_time_finish_at_extra_args_in_between,to_fourth_argument_all_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::finish_at<4>
		>,
		SWITCH_("sw1","..."),
		SWITCH_("sw2","..."),
		SWITCH_("sw3","..."),
		SWITCH_("sw4","..."),
		SWITCH_("sw5","..."),
		SWITCH_("sw6","...")
	>;

	argv_maker test_argv(
		"test",
		"--sw1",
		"arg1",
		"__a_r_g_2__",
		"--sw2",
		"--sw3",
		"--sw4",
		"AAAAAAAAAA",
		"--sw5",
		"--sw6"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--sw1")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--sw2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw5")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw6")));
}

CYNODELIC_TESTER_SECTION(parser_compile_time_finish_at_extra_args_in_between,to_fourth_argument_single_switch)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::finish_at<4>
		>,
		SWITCH_("sw1","..."),
		SWITCH_("sw2","..."),
		SWITCH_("sw3","..."),
		SWITCH_("sw4","..."),
		SWITCH_("sw5","..."),
		SWITCH_("sw6","...")
	>;

	argv_maker test_argv(
		"test",
		"ttttt",
		"--sw1",
		"t_e_s_t"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--sw1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw5")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw6")));
}

CYNODELIC_TESTER_SECTION(parser_compile_time_finish_at_extra_args_in_between,to_fourth_argument_four_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::finish_at<4>
		>,
		SWITCH_("sw1","..."),
		SWITCH_("sw2","..."),
		SWITCH_("sw3","..."),
		SWITCH_("sw4","..."),
		SWITCH_("sw5","..."),
		SWITCH_("sw6","...")
	>;

	argv_maker test_argv(
		"test",
		"--sw4",
		"hello",
		"--sw3",
		"xDDDDD",
		"--sw2",
		"--sw1"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),3);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw2")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--sw3")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--sw4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw5")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw6")));
}

CYNODELIC_TESTER_SECTION(parser_compile_time_finish_at_extra_args_in_between,to_fourth_argument_no_switches)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::finish_at<4>
		>,
		SWITCH_("sw1","..."),
		SWITCH_("sw2","..."),
		SWITCH_("sw3","..."),
		SWITCH_("sw4","..."),
		SWITCH_("sw5","..."),
		SWITCH_("sw6","...")
	>;

	argv_maker test_argv(
		"test",
		"uwu",
		"extra_arg"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw2")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw3")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw4")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw5")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--sw6")));
}


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_COMPILE_TIME_FINISH_AT_EXTRA_ARGS_IN_BETWEEN_HPP
