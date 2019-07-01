// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cstring>
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

#ifndef GET_ARGUMENT
#define GET_ARGUMENT CYNODELIC_METAFLAGS_GET_ARGUMENT
#endif


using my_parser = mfl::parser<
	mfl::parser_parameters<
		mfl::help_parameters<
			mfl::usage_format<STRING_("Usage: "),mfl::program_name,STRING_(" [skip_one [options...]]/[skip_two argument [options...]]")>
		>,
		mfl::runtime_start_at
	>,
	FLAG_("flag1,f1","Flag 1",mfl::i64_arg<>,mfl::i64_arg<>,mfl::i64_arg<>),
	FLAG_("flag2,f2","Flag 2",mfl::i64_arg<>,mfl::i64_arg<>,mfl::i64_arg<>),
	FLAG_("flag3,f3","Flag 3",mfl::i64_arg<>,mfl::i64_arg<>,mfl::i64_arg<>)
>;


int main(int argc,char *argv[])
{
	std::size_t start_at_pos     = 1;
	bool        skip_two_was_set = false;
	std::string skip_two_arg;

	if (argc > 1)
	{
		if (!std::strcmp(argv[1],"skip_one"))
		{
			start_at_pos = 2;
		}
		else if (!std::strcmp(argv[1],"skip_two"))
		{
			start_at_pos     = 3;
			skip_two_was_set = true;
			skip_two_arg     = argv[2];
		}
	}

	my_parser::set_start(start_at_pos);

	my_parser::parse(argc,argv);

	std::cout << "Parsing started at position " << my_parser::starts_at() << "\n\n";

	if (skip_two_was_set)
	{
		std::cout << "Argument after \"skip_two\": " << skip_two_arg << "\n";
	}

	std::cout
		<< "Content of --flag1/-f1: " << "{"
		<< my_parser::template get<STRING_("--flag1"),0>(0) << ","
		<< my_parser::template get<STRING_("--flag1"),1>(0) << ","
		<< my_parser::template get<STRING_("--flag1"),2>(0)
		<< "}\n";

	std::cout
		<< "Content of --flag2/-f2: " << "{"
		<< GET_ARGUMENT(my_parser,"--flag2",0,0) << ","
		<< GET_ARGUMENT(my_parser,"--flag2",1,0) << ","
		<< GET_ARGUMENT(my_parser,"--flag2",2,0)
		<< "}\n";
}
