// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file pp_flag_arguments.hpp
 *
 * @brief Defines macros for flag arguments
 */


#ifndef CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_ARGUMENTS_HPP
#define CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_ARGUMENTS_HPP


#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/preprocessor/detail/flag_argument_helpers.hpp>
#include <cynodelic/metaflags/detail/remove_zeroes_from_string.hpp>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 8-bit signed integer arguments
 *
 * Initializes an @ref i8_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_I8_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::i8_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 16-bit signed integer arguments
 *
 * Initializes an @ref i16_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_I16_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::i16_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 32-bit signed integer arguments
 *
 * Initializes an @ref i32_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_I32_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::i32_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 64-bit signed integer arguments
 *
 * Initializes an @ref i64_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_I64_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::i64_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 8-bit unsigned integer arguments
 *
 * Initializes an @ref u8_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_U8_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::u8_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 16-bit unsigned integer arguments
 *
 * Initializes an @ref u16_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_U16_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::u16_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 32-bit unsigned integer arguments
 *
 * Initializes an @ref u32_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_U32_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::u32_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining 64-bit unsigned integer arguments
 *
 * Initializes an @ref u64_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_U64_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::u64_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>



/**
 * @ingroup flagargs
 * @brief Shorthand for defining single-precision floating arguments
 *
 * Initializes a @ref flt_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_FLT_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::flt_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>



/**
 * @ingroup flagargs
 * @brief Shorthand for defining double-precision floating arguments
 *
 * Initializes a @ref dbl_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_DBL_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::dbl_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining boolean arguments
 *
 * Initializes a @ref bln_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_BLN_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::bln_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


/**
 * @ingroup flagargs
 * @brief Shorthand for defining string arguments
 *
 * Initializes a @ref str_arg from a string literal for its description.
 *
 * @param str A description for the argument (a string literal).
 */
#define CYNODELIC_METAFLAGS_STR_ARG(str) ::cynodelic::metaflags::detail::remove_zeroes_from_string<::cynodelic::metaflags::str_arg<CYNODELIC_METAFLAGS_DETAIL_GET_STRING_CHARS(str,CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH)>>


#endif // CYNODELIC_METAFLAGS_PREPROCESSOR_PP_FLAG_ARGUMENTS_HPP
