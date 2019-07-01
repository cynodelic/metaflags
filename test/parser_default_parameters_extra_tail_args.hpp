// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_TAIL_ARGS_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_TAIL_ARGS_HPP


CYNODELIC_TESTER_TEST_CASE(parser_default_parameters_extra_tail_args);

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,all_long_flags_called)
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
		"--second",
		"1","2",
		"--third",
		"1","2","3",
		"asdf",
		"ECKS_DEE_123",
		"qwertyuiop"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),9);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),12);

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

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,single_long_flag_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"--first",
		"12",
		"-190",
		"_1_2_3_4_5",
		"hello",
		"asdf"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),6);

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

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,two_long_flags_called)
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
		"--second",
		"34","56",
		"--extra_arg",
		"123abc"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),5);
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

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,all_short_flags_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"-f",
		"1",
		"-s",
		"1","2",
		"-t",
		"1","2","3",
		"asdf",
		"ECKS_DEE_123",
		"qwertyuiop"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),9);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),12);

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

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,single_short_flag_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"-f",
		"12",
		"-190",
		"_1_2_3_4_5",
		"hello",
		"asdf"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),6);

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

CYNODELIC_TESTER_SECTION(parser_default_parameters_extra_tail_args,two_short_flags_called)
{
	using prs = mfl::parser<
		mfl::flag<STRING_("first,f"),STRING_("..."),mfl::i32_arg<>>,
		mfl::flag<STRING_("second,s"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>>,
		mfl::flag<STRING_("third,t"),STRING_("..."),mfl::i32_arg<>,mfl::i32_arg<>,mfl::i32_arg<>>
	>;

	argv_maker test_argv(
		"test",
		"-f",
		"963",
		"-s",
		"34","56",
		"--extra_arg",
		"123abc"
	);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),5);
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


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_DEFAULT_PARAMETERS_EXTRA_TAIL_ARGS_HPP
