// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file finish_at.hpp
 *
 * @brief Defines parameters for setting the last argument to parse
 */


#ifndef CYNODELIC_METAFLAGS_FINISH_AT_HPP
#define CYNODELIC_METAFLAGS_FINISH_AT_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup finishatparams
 * @brief Tag for the position of the last parsed argument
 *
 * Determines at compile-time the position of the last argument that will be
 * parsed by an instance of @ref parser.
 *
 * @tparam Pos The position.
 */
template <std::size_t Pos>
struct finish_at
{
	/// @brief Reference to itself
	using type = finish_at;

	/// @brief Type of the stored value
	using value_type = std::size_t;
	
	/// @brief The value
	static constexpr value_type value = Pos;
};

template <std::size_t Pos>
constexpr typename finish_at<Pos>::value_type finish_at<Pos>::value;


/**
 * @ingroup finishatparams
 * @brief Tag for the position of the last parsed argument
 *
 * Determines that the position of the last argument to parse by an instance
 * of @ref parser, can be set at runtime.
 */
struct runtime_finish_at
{
	/// @brief Reference to itself
	using type = runtime_finish_at;
};


/**
 * @ingroup finishatparams
 * @brief Tag for the position of the last parsed argument
 *
 * Determines that the @ref parser must parse until the last argument of the
 * command line.
 */
struct parse_to_last_arg
{
	/// @brief Reference to itself
	using type = parse_to_last_arg;
};


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_FINISH_AT_HPP
