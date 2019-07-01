// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_ARGS_IN_BETWEEN_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_ARGS_IN_BETWEEN_HPP


CYNODELIC_TESTER_TEST_CASE(parser_default_parameters_extra_args_in_between);

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_args_in_between,all_long_flags_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"--first",
		"1",
		"extra_args",
		"431","33",
		"--second",
		"1","2",
		"__XYZ__",
		"--third",
		"1","2","3"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),13);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),13);

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--first",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",1)),2);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",1)),2);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",2)),3);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-f",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",1)),2);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",0)),1);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",1)),2);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",2)),3);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--first")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--second")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--third")));
}

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_args_in_between,single_long_flag_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"aaaaaaaaaa",
		"12345",
		"--first",
		"12"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),4);

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--first",0,0)),12);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",2,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-f",0,0)),12);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",2,0)),0);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--first")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--second")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--third")));
}

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_args_in_between,two_long_flags_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"--first",
		"963",
		"AAA",
		"--extra_arg",
		"--second",
		"34","56"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),7);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),7);

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--first",0,0)),963);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",0,0)),34);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--second",1,0)),56);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--third",2,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-f",0,0)),963);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",0,0)),34);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-s",1,0)),56);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",0,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",1,0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"-t",2,0)),0);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--first")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--second")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--third")));
}


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_ARGS_IN_BETWEEN_HPP
