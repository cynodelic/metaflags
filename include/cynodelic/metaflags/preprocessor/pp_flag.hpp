// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file pp_flag.hpp
 *
 * @brief Defines macros for flags
 */


#ifndef CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_HPP
#define CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_HPP


#include <cynodelic/metaflags/config.hpp>


/**
 * @ingroup flags
 * @brief Macro for defining a flag
 *
 * Equivalent to `flag<CYNODELIC_METAFLAGS_STRING(flag_str),CYNODELIC_METAFLAGS_STRING(help_str),...>`,
 * with the flag arguments defined in the `...` field.
 *
 * @param flag_str The alias(es) of the flag (a string literal).
 * @param help_str The description for the flag (a string literal).
 */
#define CYNODELIC_METAFLAGS_FLAG(flag_str,help_str,...) ::cynodelic::metaflags::flag<CYNODELIC_METAFLAGS_STRING_KL(flag_str,CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH),CYNODELIC_METAFLAGS_STRING_KL(help_str,CYNODELIC_METAFLAGS_MAX_HELP_STRING_LENGTH),__VA_ARGS__>


/**
 * @ingroup flags
 * @brief Macro for defining a switch
 *
 * Equivalent to `flag<CYNODELIC_METAFLAGS_STRING(flag_str),CYNODELIC_METAFLAGS_STRING(help_str),switch_tag>`
 * (defines a _switch_).
 *
 * @param flag_str The alias(es) of the flag (a string literal).
 * @param help_str The description for the flag (a string literal).
 */
#define CYNODELIC_METAFLAGS_SWITCH(flag_str,help_str) ::cynodelic::metaflags::flag<CYNODELIC_METAFLAGS_STRING_KL(flag_str,CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH),CYNODELIC_METAFLAGS_STRING_KL(help_str,CYNODELIC_METAFLAGS_MAX_HELP_STRING_LENGTH),::cynodelic::metaflags::switch_tag>


#endif // CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_HPP
