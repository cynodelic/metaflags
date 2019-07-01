// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_DIFFERENT_STORED_ARGUMENT_VALUES
#define CYNODELIC_METAFLAGS_TEST_DIFFERENT_STORED_ARGUMENT_VALUES


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(different_stored_argument_values)
{
	using prsr_1 = mfl::parser<
		FLAG_("flag11,f11","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third")),
		FLAG_("flag12,f12","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third")),
		FLAG_("flag13,f13","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third"))
	>;

	using prsr_2 = mfl::parser<
		FLAG_("flag21,f21","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third")),
		FLAG_("flag22,f22","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third")),
		FLAG_("flag23,f23","A flag",I32_ARG("first"),I32_ARG("second"),I32_ARG("third"))
	>;

	argv_maker test_argv_1(
		"the_test",
		"--flag22",
		"56","-31664","65536"
	);

	prsr_2::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),0>()),(prsr_1::template get<STRING_("--flag11"),0>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),0>()),(prsr_1::template get<STRING_("--flag12"),0>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),0>()),(prsr_1::template get<STRING_("--flag13"),0>()));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag11"),1>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag12"),1>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag13"),1>()));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),2>()),(prsr_1::template get<STRING_("--flag11"),2>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),2>()),(prsr_1::template get<STRING_("--flag12"),2>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),2>()),(prsr_1::template get<STRING_("--flag13"),2>()));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),0>()),(prsr_1::template get<STRING_("--flag11"),0>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),0>()),(prsr_1::template get<STRING_("--flag13"),0>()));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag11"),1>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag13"),1>()));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag11"),1>()));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((prsr_2::template get<STRING_("--flag22"),1>()),(prsr_1::template get<STRING_("--flag13"),1>()));


	using prsr_3 = mfl::parser<
		FLAG_("flag31","...",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag32","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	using prsr_4 = mfl::parser<
		FLAG_("flag41","...",mfl::i32_arg<>,mfl::i32_arg<>),
		FLAG_("flag42","...",mfl::i32_arg<>,mfl::i32_arg<>)
	>;

	argv_maker test_argv_2(
		"_test_",
		"--flag31",
		"123","-963"
	);

	prsr_3::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_3,"--flag31",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_3,"--flag32",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_3,"--flag32",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_4,"--flag41",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_4,"--flag41",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_4,"--flag42",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",0)),(GET_ARG(prsr_4,"--flag42",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_3,"--flag32",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_3,"--flag32",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_4,"--flag41",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_4,"--flag41",1)));

	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_4,"--flag42",0)));
	CYNODELIC_TESTER_CHECK_NOT_EQUALS((GET_ARG(prsr_3,"--flag31",1)),(GET_ARG(prsr_4,"--flag42",1)));
}


#endif // CYNODELIC_METAFLAGS_TEST_DIFFERENT_STORED_ARGUMENT_VALUES
