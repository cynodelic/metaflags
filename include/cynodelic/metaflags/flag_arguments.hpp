// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file flag_arguments.hpp
 *
 * @brief Defines flag arguments
 */


#ifndef CYNODELIC_METAFLAGS_FLAG_ARGUMENTS_HPP
#define CYNODELIC_METAFLAGS_FLAG_ARGUMENTS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>

#include <cynodelic/mulinum/string.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/detail/name_of_arg_type.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup flagargs
 * @brief Defines an 8-bit signed integer agrument
 * 
 * A type for defining an integer argument for a @ref flag, which type is
 * `std::int8_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct i8_arg
{
	/// @brief Reference to itself
	using type = i8_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::int8_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"int8"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines an 8-bit unsigned integer agrument
 * 
 * A type for defining an unsigned integer argument for a @ref flag, which type
 *  is `std::uint8_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct u8_arg
{
	/// @brief Reference to itself
	using type = u8_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::uint8_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"uint8"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 16-bit signed integer agrument
 * 
 * A type for defining an integer argument for a @ref flag, which type is
 * `std::int16_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct i16_arg
{
	/// @brief Reference to itself
	using type = i16_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::int16_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"int16"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 16-bit unsigned integer agrument
 * 
 * A type for defining an unsigned integer argument for a @ref flag, which type
 *  is `std::uint16_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct u16_arg
{
	/// @brief Reference to itself
	using type = u16_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::uint16_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"uint16"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 32-bit signed integer agrument
 * 
 * A type for defining an integer argument for a @ref flag, which type is
 * `std::int32_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct i32_arg
{
	/// @brief Reference to itself
	using type = i32_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::int32_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"int32"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 32-bit unsigned integer agrument
 * 
 * A type for defining an unsigned integer argument for a @ref flag, which type
 *  is `std::uint32_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct u32_arg
{
	/// @brief Reference to itself
	using type = u32_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::uint32_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"uint32"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 64-bit signed integer agrument
 * 
 * A type for defining an integer argument for a @ref flag, which type is
 * `std::int64_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct i64_arg
{
	/// @brief Reference to itself
	using type = i64_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::int64_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"int64"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a 64-bit unsigned integer agrument
 * 
 * A type for defining an unsigned integer argument for a @ref flag, which type
 *  is `std::uint64_t`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct u64_arg
{
	/// @brief Reference to itself
	using type = u64_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::uint64_t;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"uint64"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a boolean agrument
 * 
 * A type for defining an boolean argument for a @ref flag, which type is
 * `bool`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct bln_arg
{
	/// @brief Reference to itself
	using type = bln_arg;

	/// @brief The type corresponding to the argument
	using value_type = bool;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"bool"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a single-precision floating point agrument
 * 
 * A type for defining an single-precision floating point argument for a
 * @ref flag, which type is `float`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct flt_arg
{
	/// @brief Reference to itself
	using type = flt_arg;

	/// @brief The type corresponding to the argument
	using value_type = float;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"float"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a double-precision floating point agrument
 * 
 * A type for defining an double-precision floating point argument for a
 * @ref flag, which type is `double`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct dbl_arg
{
	/// @brief Reference to itself
	using type = dbl_arg;

	/// @brief The type corresponding to the argument
	using value_type = double;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"double"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Defines a string agrument
 * 
 * A type for defining an string argument for a @ref flag, which type is
 * `std::string`.
 *
 * @tparam Chars... The characters corresponding to the description of the
 *                  argument.
 */
template <char... Chars>
struct str_arg
{
	/// @brief Reference to itself
	using type = str_arg;

	/// @brief The type corresponding to the argument
	using value_type = std::string;

	/**
	 * @brief Description of the argument
	 *
	 * Contains the description of the argument. If there are no characters in
	 * `Chars...`, it will be equivalent to `"string"`.
	 */
	using help_str = mulinum::if_<(sizeof...(Chars) > 0),mulinum::string<Chars...>,detail::name_of_arg_type<value_type>>;
};


/**
 * @ingroup flagargs
 * @brief Tag type for defining switches
 *
 * When used in a @link flags flag@endlink, it defines said _flag_ as a
 * _switch_ (a flag with no arguments).
 */
struct switch_tag
{
	/// @brief Reference to itself
	using type = switch_tag;
};


}} // end of "cynodelic::metaflags" namespace


#include <cynodelic/metaflags/preprocessor/pp_flag_arguments.hpp>


#endif // CYNODELIC_METAFLAGS_FLAG_ARGUMENTS_HPP
