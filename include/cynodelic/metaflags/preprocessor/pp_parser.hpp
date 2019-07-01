// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file pp_parser.hpp
 *
 * @brief Defines macros for the member functions in `parser`
 */


#ifndef CYNODELIC_METAFLAGS_PREPROCESSOR_PP_PARSER_HPP
#define CYNODELIC_METAFLAGS_PREPROCESSOR_PP_PARSER_HPP


#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/preprocessor/detail/pp_concat.hpp>
#include <cynodelic/metaflags/preprocessor/detail/get_argument_helpers.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define CYNODELIC_METAFLAGS_GET_ARGUMENT(prs,flag,...) CYNODELIC_METAFLAGS_PP_CONCAT(CYNODELIC_METAFLAGS_DETAIL_GET_ARGUMENT_IMPL_,CYNODELIC_METAFLAGS_DETAIL_HAS_EXTRA_ARG(__VA_ARGS__))(prs,flag,__VA_ARGS__)

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup parsing
 * @brief Shorthand for `get` and `get_with_default`
 *
 * If three arguments were used (`prs`,`flag` and the position of the desired
 * argument, `idx`, in the `...` field), it will act as
 * `prs::template get<flag,idx>()`.
 *
 * If, in addition to the previous three arguments, is used a fourth one (the
 * _default_ value, i.e., the value returned if the corresponding flag was not
 * called), it will act as `prs::template get<flag,idx>(deft)`, where `deft` is
 * said _default_ value.
 *
 * @param prs  An instance of @ref parser .
 * @param flag The alias of the desired flag (a string literal).
 */
#define CYNODELIC_METAFLAGS_GET_ARGUMENT(prs,flag,...) /* unspecified */

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup parsing
 * @brief Shorthand for `was_called`
 *
 * Same as calling `prs::template was_called<flag>()`.
 *
 * @param prs  An instance of @ref parser .
 * @param flag The alias of the desired flag (a string literal).
 */
#define CYNODELIC_METAFLAGS_WAS_CALLED(prs,flag) prs::template was_called<CYNODELIC_METAFLAGS_STRING_KL(flag,CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH)>()


#endif // CYNODELIC_METAFLAGS_PREPROCESSOR_PP_PARSER_HPP
