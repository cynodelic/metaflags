// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file parser_fwd.hpp
 *
 * @brief Forward declaration of the `parser` class
 */


#ifndef CYNODELIC_METAFLAGS_FWD_PARSER_FWD_HPP
#define CYNODELIC_METAFLAGS_FWD_PARSER_FWD_HPP


#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>
#include <stdexcept>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/parser_parameters.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup parsing
 * @brief Parser
 *
 * Type for parsing command-line arguments, given the flags to parse.
 *
 * @tparam Flags... The @link flags flags@endlink that will be parsed.
 */
template <typename... Flags>
struct parser;


/**
 * @ingroup parsing
 * @brief Parser with custom parameters
 *
 * Type for parsing command-line arguments, given an initial position and the
 * flags to parse.
 *
 * @tparam Params... The @link parsingparams parameters@endlink that will be used by the parser.
 * @tparam Flags...  The @link flags flags@endlink that will be parsed.
 */
template <typename... Params,typename... Flags>
struct parser<parser_parameters<Params...>,Flags...>;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_FWD_PARSER_FWD_HPP
