// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_IS_SWITCH_HPP
#define CYNODELIC_METAFLAGS_TEST_IS_SWITCH_HPP


CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(is_switch)
{
	CYNODELIC_TESTER_CHECK_TRUE((mfl::is_switch<mfl::flag<STRING_("tst1"),STRING_("..."),mfl::switch_tag>>::value));
	CYNODELIC_TESTER_CHECK_FALSE((mfl::is_switch<mfl::flag<STRING_("tst2"),STRING_("..."),mfl::dbl_arg<'a','r','g'>>>::value));
}


#endif // CYNODELIC_METAFLAGS_TEST_IS_SWITCH_HPP
