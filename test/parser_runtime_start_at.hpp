// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_START_AT_HPP
#define CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_START_AT_HPP


CYNODELIC_TESTER_TEST_CASE(parser_runtime_start_at);

CYNODELIC_TESTER_SECTION(parser_runtime_start_at,from_first_argument_all_flags)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_start_at
		>,
		FLAG_("flag1","Flag 1",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag2","Flag 2",mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"--flag1","-301","56",
		"--flag2","123"
	);

	prs::set_start(1);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),5);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),5);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--flag1")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--flag2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",0)),-301);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",1)),56);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag2",0)),123);
}

CYNODELIC_TESTER_SECTION(parser_runtime_start_at,from_first_argument_no_flags)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_start_at
		>,
		FLAG_("flag1","Flag 1",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag2","Flag 2",mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test"
	);

	prs::set_start(1);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::starts_at() = " << prs::starts_at() << tst::newline
		<< "prs::last_parsed_argument_position() = " << prs::last_parsed_argument_position() << tst::newline
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),1);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),0);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--flag1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--flag2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",1)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag2",0)),0);
}

CYNODELIC_TESTER_SECTION(parser_runtime_start_at,from_second_argument_all_flags)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_start_at
		>,
		FLAG_("flag1","Flag 1",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag2","Flag 2",mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test",
		"__ignored__",
		"--flag1","-301","56",
		"--flag2","123"
	);

	prs::set_start(2);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),6);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),6);

	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--flag1")));
	CYNODELIC_TESTER_CHECK_TRUE((WAS_CALLED(prs,"--flag2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",0)),-301);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",1)),56);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag2",0)),123);
}

CYNODELIC_TESTER_SECTION(parser_runtime_start_at,from_second_argument_no_flags)
{
	using prs = mfl::parser<
		mfl::parser_parameters<
			mfl::runtime_start_at
		>,
		FLAG_("flag1","Flag 1",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag2","Flag 2",mfl::i32_arg<>)
	>;

	argv_maker test_argv(
		"test"
	);

	prs::set_start(2);

	prs::parse(static_cast<int>(test_argv.size()),test_argv.data());

	CYNODELIC_TESTER_MESSAGE
		<< "prs::starts_at() = " << prs::starts_at() << tst::newline
		<< "prs::last_parsed_argument_position() = " << prs::last_parsed_argument_position() << tst::newline
		<< "prs::finished_at() = " << prs::finished_at();

	CYNODELIC_TESTER_CHECK_EQUALS(prs::starts_at(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::last_parsed_argument_position(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(prs::finished_at(),0);

	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--flag1")));
	CYNODELIC_TESTER_CHECK_FALSE((WAS_CALLED(prs,"--flag2")));

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",0)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag1",1)),0);
	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prs,"--flag2",0)),0);
}


#endif // CYNODELIC_METAFLAGS_TEST_PARSER_RUNTIME_START_AT_HPP
