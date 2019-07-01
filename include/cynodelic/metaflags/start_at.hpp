// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file start_at.hpp
 *
 * @brief Defines parameters for setting the first argument to parse
 */


#ifndef CYNODELIC_METAFLAGS_START_AT_HPP
#define CYNODELIC_METAFLAGS_START_AT_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup startatparams
 * @brief Tag for the position of the first parsed argument
 *
 * Determines at compile-time the position of the first argument that will be
 * parsed by an instance of @ref parser.
 *
 * @tparam Pos The position.
 */
template <std::size_t Pos>
struct start_at
{
	/// @brief Reference to itself
	using type = start_at;

	/// @brief Type of the stored value
	using value_type = std::size_t;
	
	/// @brief The value
	static constexpr value_type value = Pos;
};

template <std::size_t Pos>
constexpr typename start_at<Pos>::value_type start_at<Pos>::value;


/**
 * @ingroup startatparams
 * @brief Tag for the position of the first parsed argument
 *
 * Determines that the position of the first argument to parse by an instance
 * of @ref parser, can be set at runtime.
 */
struct runtime_start_at
{
	/// @brief Reference to itself
	using type = runtime_start_at;
};


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_START_AT_HPP
