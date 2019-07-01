// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <tuple>

#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/parser.hpp>
#include <cynodelic/metaflags/argument_types_list.hpp>
#include <cynodelic/metaflags/get_as_tuple.hpp>


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
	FLAG_("flag1,f1","Flag 1",mfl::str_arg<>,mfl::i64_arg<>),
	FLAG_("flag2,f2","Flag 2",mfl::flt_arg<>,mfl::bln_arg<>,mfl::u8_arg<>)
>;

using flag1_args_t = mfl::argument_types_list<std::tuple,my_parser,STRING_("--flag1")>;
using flag2_args_t = mfl::argument_types_list<std::tuple,my_parser,STRING_("--flag2")>;


int main(int argc,char *argv[])
{
	my_parser::parse(argc,argv);

	flag1_args_t flag1_content = mfl::get_as_tuple<my_parser,STRING_("--flag1")>({"nothing",0});
	flag2_args_t flag2_content = mfl::get_as_tuple<my_parser,STRING_("--flag2")>();

	std::cout
		<< "Content from --flag1: "
		<< std::get<0>(flag1_content) << ", "
		<< std::get<1>(flag1_content) << "\n";

	std::cout
		<< "Content from --flag2: "
		<< std::get<0>(flag2_content) << ", "
		<< std::get<1>(flag2_content) << ", "
		<< static_cast<unsigned>(std::get<2>(flag2_content)) << "\n";
}
