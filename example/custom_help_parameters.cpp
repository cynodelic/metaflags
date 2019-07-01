// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>

#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/parser.hpp>


namespace mln = cynodelic::mulinum;
namespace mfl = cynodelic::metaflags;


#ifndef STRING_
#define STRING_ CYNODELIC_METAFLAGS_STRING
#endif

#ifndef FLAG_
#define FLAG_ CYNODELIC_METAFLAGS_FLAG
#endif

#ifndef SWITCH_
#define SWITCH_ CYNODELIC_METAFLAGS_SWITCH
#endif

#ifndef WAS_CALLED
#define WAS_CALLED CYNODELIC_METAFLAGS_WAS_CALLED
#endif

#ifndef I32_ARG
#define I32_ARG CYNODELIC_METAFLAGS_I32_ARG
#endif

#ifndef STR_ARG
#define STR_ARG CYNODELIC_METAFLAGS_STR_ARG
#endif


using my_parser = mfl::parser<
	mfl::parser_parameters<
		mfl::help_parameters<
			mfl::flag_tabulation<8>,                                                                    /* <-- Spaces from the left to the flag aliases */
			mfl::flag_help_tabulation<2>,                                                               /* <-- Spaces from the flag aliases to their descriptions */
			mfl::usage_format<STRING_("How to call: "),mfl::program_name,STRING_(" [the options...]")>, /* <-- it will be "Usage: the_program [the options...]" */
			mfl::flag_aliases_delimiter<';'>,                                                           /* <-- "--flag;-f" instead of "--flag/-f" */
			mfl::flags_list_header<STRING_("The options:")>,
			mfl::help_flag<STRING_("usage,u")>,                                                         /* <-- to call the help with "--usage/-u" */
			mfl::print_help_if_no_arguments<true>                                                       /* <-- Displays the help if no arguments were set */
		>
	>,
	FLAG_("test_a,ta","A test flag.",I32_ARG("first"),I32_ARG("second"),I32_ARG("third")),
	FLAG_("test_b,tb","Another test flag.",I32_ARG("argument 1"),I32_ARG("argument 2")),
	SWITCH_("thing,t","A test switch.")
>;


int main(int argc,char *argv[])
{
	// Use "--usage/-u" instead of "--help/-h"
	my_parser::parse(argc,argv);
}

