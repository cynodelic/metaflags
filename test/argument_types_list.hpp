// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPES_LIST_HPP
#define CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPES_LIST_HPP


template <typename...>
struct my_type_list
{
	using type = my_type_list;
};


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(argument_types_list)
{
	using prs = mfl::parser<
		FLAG_("test-flag-1,t1","First",mfl::i8_arg<>,mfl::i16_arg<>,mfl::i32_arg<>,mfl::i64_arg<>),
		FLAG_("test-flag-2,t2","Second",mfl::u8_arg<>,mfl::u16_arg<>,mfl::u32_arg<>,mfl::u64_arg<>),
		FLAG_("test-flag-3,t3","Third",mfl::str_arg<>,mfl::str_arg<>,mfl::str_arg<>),
		FLAG_("test-flag-4,t4","Fourth",mfl::bln_arg<>,mfl::flt_arg<>,mfl::dbl_arg<>),
		FLAG_("test-flag-5,t5","Fifth",mfl::i64_arg<>,mfl::str_arg<>,mfl::bln_arg<>)
	>;

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("--test-flag-1")>,std::tuple<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("--test-flag-2")>,std::tuple<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("--test-flag-3")>,std::tuple<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("--test-flag-4")>,std::tuple<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("--test-flag-5")>,std::tuple<std::int64_t,std::string,bool>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("-t1")>,std::tuple<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("-t2")>,std::tuple<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("-t3")>,std::tuple<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("-t4")>,std::tuple<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<std::tuple,prs,STRING_("-t5")>,std::tuple<std::int64_t,std::string,bool>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("--test-flag-1")>,mln::vector<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("--test-flag-2")>,mln::vector<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("--test-flag-3")>,mln::vector<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("--test-flag-4")>,mln::vector<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("--test-flag-5")>,mln::vector<std::int64_t,std::string,bool>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("-t1")>,mln::vector<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("-t2")>,mln::vector<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("-t3")>,mln::vector<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("-t4")>,mln::vector<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<mln::vector,prs,STRING_("-t5")>,mln::vector<std::int64_t,std::string,bool>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("--test-flag-1")>,my_type_list<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("--test-flag-2")>,my_type_list<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("--test-flag-3")>,my_type_list<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("--test-flag-4")>,my_type_list<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("--test-flag-5")>,my_type_list<std::int64_t,std::string,bool>>::value));

	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("-t1")>,my_type_list<std::int8_t,std::int16_t,std::int32_t,std::int64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("-t2")>,my_type_list<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("-t3")>,my_type_list<std::string,std::string,std::string>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("-t4")>,my_type_list<bool,float,double>>::value));
	CYNODELIC_TESTER_CHECK_TRUE((mln::equals<mfl::argument_types_list<my_type_list,prs,STRING_("-t5")>,my_type_list<std::int64_t,std::string,bool>>::value));
}


#endif // CYNODELIC_METAFLAGS_TEST_ARGUMENT_TYPES_LIST_HPP
