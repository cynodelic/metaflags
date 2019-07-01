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


using my_parser = mfl::parser<
	mfl::flag<STRING_("switch1,s1"),STRING_("Switch 1"),mfl::switch_tag>,
	SWITCH_("switch2,s2","Switch 2"),
	SWITCH_("switch3,s3","Switch 3"),
	SWITCH_("switch4,s4","Switch 4")
>;


int main(int argc, char *argv[])
{
	my_parser::parse(argc,argv);

	if (my_parser::template was_called<STRING_("--switch1")>())
	{
		std::cout << "Switch 1 set.\n";
	}

	if (WAS_CALLED(my_parser,"--switch2"))
	{
		std::cout << "Switch 2 set.\n";
	}

	if (WAS_CALLED(my_parser,"--switch3"))
	{
		std::cout << "Switch 3 set.\n";
	}

	if (WAS_CALLED(my_parser,"--switch4"))
	{
		std::cout << "Switch 4 set.\n";
	}
}

