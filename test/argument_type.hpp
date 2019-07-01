// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPE_HPP
#define CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPE_HPP


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(argument_type)
{
	using prs_1 = mfl::parser<
		FLAG_("ints,i","...",I8_ARG("arg1"),I16_ARG("arg2"),I32_ARG("arg3"),I64_ARG("arg4")),
		FLAG_("uints,u","...",U8_ARG("uint8"),U16_ARG("uint16"),U32_ARG("uint32"),U64_ARG("uint64")),
		FLAG_("str,s","...",STR_ARG("the string"),BLN_ARG("true/false")),
		FLAG_("flts,f","...",FLT_ARG("float"),DBL_ARG("double"))
	>;

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--ints"),0>,std::int8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--ints"),1>,std::int16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--ints"),2>,std::int32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--ints"),3>,std::int64_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-i"),0>,std::int8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-i"),1>,std::int16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-i"),2>,std::int32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-i"),3>,std::int64_t>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--uints"),0>,std::uint8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--uints"),1>,std::uint16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--uints"),2>,std::uint32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--uints"),3>,std::uint64_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-u"),0>,std::uint8_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-u"),1>,std::uint16_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-u"),2>,std::uint32_t>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-u"),3>,std::uint64_t>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--str"),0>,std::string>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--str"),1>,bool>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-s"),0>,std::string>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-s"),1>,bool>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--flts"),0>,float>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("--flts"),1>,double>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-f"),0>,float>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_type<prs_1,STRING_("-f"),1>,double>::value));
}


#endif // CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPE_HPP
