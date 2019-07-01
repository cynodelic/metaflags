// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>

#include <cynodelic/mulinum/concat.hpp>

#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/parser.hpp>
#include <cynodelic/metaflags/generate_list_of_flags.hpp>


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


using options_prsr = mfl::parser<
	mfl::parser_parameters<
		mfl::disable_help_in_parser
	>,
	FLAG_("display-mode,dm","Sets how the switches' statuses are displayed (default: grid).\nModes:\n    vertical/v\n    horizontal/h\n    grid/g\n    named/n",mfl::str_arg<>),
	SWITCH_("help,h","Displays this help and exits the program.")
>;

using switches_prsr = mfl::parser<
	mfl::parser_parameters<
		mfl::disable_help_in_parser,
		mfl::runtime_start_at
	>,
	SWITCH_("switch-00,s00","Switch 0,0"),
	SWITCH_("switch-01,s01","Switch 0,1"),
	SWITCH_("switch-02,s02","Switch 0,2"),
	SWITCH_("switch-10,s10","Switch 1,0"),
	SWITCH_("switch-11,s11","Switch 1,1"),
	SWITCH_("switch-12,s12","Switch 1,2"),
	SWITCH_("switch-20,s20","Switch 2,0"),
	SWITCH_("switch-21,s21","Switch 2,1"),
	SWITCH_("switch-22,s22","Switch 2,2")
>;


using opts_list = mfl::generate_list_of_flags<
	mfl::help_parameters<
		mfl::flags_list_header<STRING_("Options:")>,
		mfl::add_help_flags_to_list<false>
	>,
	options_prsr
>;

using sws_list = mfl::generate_list_of_flags<
	mfl::help_parameters<
		mfl::flags_list_header<STRING_("Switches:")>,
		mfl::add_help_flags_to_list<false>
	>,
	switches_prsr
>;

// The outputs are Mulinum strings, so they can be concatenated using `concat`
using compound_list = mln::concat<opts_list,sws_list>;


void print_help_and_exit(char *argv[])
{
	std::cout << "Usage: " << argv[0] << "[options...] [switches...]\n\n";

	std::cout << compound_list::c_str() << "\n";

	std::exit(EXIT_SUCCESS);
}


int main(int argc,char *argv[])
{
	options_prsr::parse(argc,argv);

	if (argc == 2 && WAS_CALLED(options_prsr,"--help"))
	{
		print_help_and_exit(argv);
	}

	switches_prsr::set_start(options_prsr::last_parsed_argument_position());
	switches_prsr::parse(argc,argv);

	std::string disp_mode = options_prsr::template get<STRING_("--display-mode"),0>("grid");

	if (disp_mode == std::string("vertical") || disp_mode == std::string("v"))
	{
		std::cout << "0,0: [" << (WAS_CALLED(switches_prsr,"-s00") ? '*' : ' ') << "]\n";
		std::cout << "0,1: [" << (WAS_CALLED(switches_prsr,"-s01") ? '*' : ' ') << "]\n";
		std::cout << "0,2: [" << (WAS_CALLED(switches_prsr,"-s02") ? '*' : ' ') << "]\n";

		std::cout << "1,0: [" << (WAS_CALLED(switches_prsr,"-s10") ? '*' : ' ') << "]\n";
		std::cout << "1,1: [" << (WAS_CALLED(switches_prsr,"-s11") ? '*' : ' ') << "]\n";
		std::cout << "1,2: [" << (WAS_CALLED(switches_prsr,"-s12") ? '*' : ' ') << "]\n";

		std::cout << "2,0: [" << (WAS_CALLED(switches_prsr,"-s20") ? '*' : ' ') << "]\n";
		std::cout << "2,1: [" << (WAS_CALLED(switches_prsr,"-s21") ? '*' : ' ') << "]\n";
		std::cout << "2,2: [" << (WAS_CALLED(switches_prsr,"-s22") ? '*' : ' ') << "]\n";
	}
	else if (disp_mode == std::string("horizontal") || disp_mode == std::string("h"))
	{
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s00") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s01") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s02") ? '*' : ' ') << "]";

		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s10") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s11") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s12") ? '*' : ' ') << "]";

		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s20") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s21") ? '*' : ' ') << "]";
		std::cout << "[" << (WAS_CALLED(switches_prsr,"-s22") ? '*' : ' ') << "]";

		std::cout << "\n";
	}
	else if (disp_mode == std::string("grid") || disp_mode == std::string("g"))
	{
		std::cout
			<< "["
			<< (WAS_CALLED(switches_prsr,"-s00") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s01") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s02") ? '*' : ' ') << "]\n";

		std::cout
			<< "["
			<< (WAS_CALLED(switches_prsr,"-s10") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s11") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s12") ? '*' : ' ') << "]\n";

		std::cout
			<< "["
			<< (WAS_CALLED(switches_prsr,"-s20") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s21") ? '*' : ' ') << "]["
			<< (WAS_CALLED(switches_prsr,"-s22") ? '*' : ' ') << "]\n";
	}
	else if (disp_mode == std::string("named") || disp_mode == std::string("n"))
	{
		if (WAS_CALLED(switches_prsr,"--switch-00"))
		{
			std::cout << "--switch-00 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-01"))
		{
			std::cout << "--switch-01 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-02"))
		{
			std::cout << "--switch-02 was called.\n";
		}
		
		if (WAS_CALLED(switches_prsr,"--switch-10"))
		{
			std::cout << "--switch-10 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-11"))
		{
			std::cout << "--switch-11 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-12"))
		{
			std::cout << "--switch-12 was called.\n";
		}
		
		if (WAS_CALLED(switches_prsr,"--switch-20"))
		{
			std::cout << "--switch-20 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-21"))
		{
			std::cout << "--switch-21 was called.\n";
		}

		if (WAS_CALLED(switches_prsr,"--switch-22"))
		{
			std::cout << "--switch-22 was called.\n";
		}
	}
}

