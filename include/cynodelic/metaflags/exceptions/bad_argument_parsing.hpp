// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file bad_argument_parsing.hpp
 *
 * @brief Defines the `bad_argument_parsing` exception type.
 */


#ifndef CYNODELIC_METAFLAGS_EXCEPTIONS_BAD_ARGUMENT_PARSING_HPP
#define CYNODELIC_METAFLAGS_EXCEPTIONS_BAD_ARGUMENT_PARSING_HPP

#include <cstdlib>
#include <string>
#include <stdexcept>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @brief Exception for bad argument parsing
 *
 * An exception that is thrown by @ref parser (`parse` member function).
 */
class bad_argument_parsing : public std::runtime_error
{
	public:
		bad_argument_parsing(const std::string& what_arg) :
			std::runtime_error(what_arg)
		{}


		bad_argument_parsing(const char* what_arg) :
			std::runtime_error(what_arg)
		{}
};


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_EXCEPTIONS_BAD_ARGUMENT_PARSING_HPP
