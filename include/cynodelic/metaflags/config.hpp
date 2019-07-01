// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file config.hpp
 *
 * @brief Header for configurations
 */


#ifndef CYNODELIC_METAFLAGS_CONFIG_HPP
#define CYNODELIC_METAFLAGS_CONFIG_HPP


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define CYNODELIC_METAFLAGS_STRINGIZE_IMPL(x) #x
#define CYNODELIC_METAFLAGS_STRINGIZE(x) CYNODELIC_METAFLAGS_STRINGIZE_IMPL(x)

#endif // DOXYGEN_SHOULD_SKIP_THIS


#define CYNODELIC_METAFLAGS_VERSION_MAJOR 1 /**< @brief Major version of this library. */
#define CYNODELIC_METAFLAGS_VERSION_MINOR 0 /**< @brief Minor version of this library. */
#define CYNODELIC_METAFLAGS_VERSION_PATCH 0 /**< @brief Patch version of this library. */


/// @brief The version of this library
#define CYNODELIC_METAFLAGS_VERSION CYNODELIC_METAFLAGS_STRINGIZE(CYNODELIC_METAFLAGS_VERSION_MAJOR) "." CYNODELIC_METAFLAGS_STRINGIZE(CYNODELIC_METAFLAGS_VERSION_MINOR) "." CYNODELIC_METAFLAGS_STRINGIZE(CYNODELIC_METAFLAGS_VERSION_PATCH)


/**
 * @ingroup types
 * @brief Synonym for `CYNODELIC_MULINUM_STRING`
 */
#define CYNODELIC_METAFLAGS_STRING(str) CYNODELIC_MULINUM_STRING(str)


/**
 * @ingroup types
 * @brief Synonym for `CYNODELIC_MULINUM_STRING_KL`
 */
#define CYNODELIC_METAFLAGS_STRING_KL(str,known_length) CYNODELIC_MULINUM_STRING_KL(str,known_length)


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifndef CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH
#	define CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH 30
#endif
#ifndef CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH
#	define CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH 40
#endif
#ifndef CYNODELIC_METAFLAGS_MAX_HELP_STRING_LENGTH
#	define CYNODELIC_METAFLAGS_MAX_HELP_STRING_LENGTH 300
#endif

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup configuration_
 * @brief Maximum string length for descriptions of flag arguments
 *
 * If it is defined before the first library's header, it will set the maximum
 * string length for the descriptions of flag arguments, otherwise, it will
 * have a default value, defined by this library.
 */
#define CYNODELIC_METAFLAGS_MAX_ARG_STRING_LENGTH /* implementation-defined */


/**
 * @ingroup configuration_
 * @brief Maximum string length for flag aliases
 *
 * If it is defined before the first library's header, it will set the maximum
 * string length for the aliases of a flag, otherwise, it will have a default
 * value, defined by this library.
 */
#define CYNODELIC_METAFLAGS_MAX_FLAG_STRING_LENGTH /* implementation-defined */


/**
 * @ingroup configuration_
 * @brief Maximum string length for descriptions of flags
 *
 * If it is defined before the first library's header, it will set the maximum
 * string length for the description of a flag, otherwise, it will have a
 * default value, defined by this library.
 */
#define CYNODELIC_METAFLAGS_MAX_HELP_STRING_LENGTH /* implementation-defined */


/**
 * @ingroup configuration_
 * @brief Disables the constraints for flags naming
 *
 * If it is defined before the first library's header, it will disable the
 * constraints for the naming of the @link flags flags@endlink.
 */
#define CYNODELIC_METAFLAGS_DISABLE_FLAG_NAMING_CONSTRAINTS

#endif // DOXYGEN_SHOULD_SKIP_THIS


#endif // CYNODELIC_METAFLAGS_CONFIG_HPP
