// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file flag.hpp
 *
 * @brief Defines the `flag` type
 */


#ifndef CYNODELIC_METAFLAGS_FLAG_HPP
#define CYNODELIC_METAFLAGS_FLAG_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/tags.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/at.hpp>
#include <cynodelic/mulinum/split.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/detail/is_flag_aliases_naming_valid.hpp>
#include <cynodelic/metaflags/detail/make_flag_aliases_list.hpp>
#include <cynodelic/metaflags/detail/arg_value_holder.hpp>
#include <cynodelic/metaflags/detail/call_status_holder.hpp>
#include <cynodelic/metaflags/detail/multiple_flag_arg_values_holder.hpp>
#include <cynodelic/metaflags/detail/is_in_string_vector.hpp>
#include <cynodelic/metaflags/detail/set_values_from_strings.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename,typename,typename...>
struct flag;

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup flags
 * @brief Type for flag with arguments
 *
 * Defines a _flag_, which is a command to pass parameters to a program and
 * has _arguments_, that contain such parameters.
 *
 * In this library, each flag is called in the command line like this:
 * `--my_flag 123 some_string false`.
 *
 * A short name can be set after the flag's _long_ name, followed by a comma
 * (example: `"my_flag,mf"`, which can be called as `--my_flag` or `-mf` in the
 * command line).
 *
 * @tparam FlagChars... The characters in the string corresponding to the flag
 *                      aliases.
 * @tparam HelpChars... The characters in the string corresponding to the
 *                      desctiption of the flag.
 * @tparam FlagArgs...  The arguments (parameters) of the flag.
 */
template <char... FlagChars,char... HelpChars,typename... FlagArgs>
struct flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>
{
	static_assert(
		detail::is_flag_aliases_naming_valid<mulinum::string<FlagChars...>>::value,
		"[cynodelic::metaflags::flag<...>] The flags must be named with alphanumeric characters, "
		"hyphens, and underscores, and cannot begin with hyphens or numbers."
	);

	/// @brief Reference to itself.
	using type = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>;

	/// @brief The string that contains the flag's alias(es).
	using flag_string = mulinum::string<FlagChars...>;

	/// @brief The string that containd the flag's description.
	using help_string = mulinum::string<HelpChars...>;

	/// @brief A `mulinum::vector` that contains the flag's aliases.
	using flags_list = detail::make_flag_aliases_list<mulinum::string<FlagChars...>>;

	/// @brief A `mulinum::vector`that contains all flag's arguments.
	using args_list = mulinum::vector<FlagArgs...>;

	/// @brief Number of arguments.
	static constexpr std::size_t num_args = args_list::size;


	/**
	 * @brief Returns the value of a flag's argument
	 *
	 * Returns the value on the `Idx`-th argument of the flag.
	 *
	 * @tparam Idx The position of the desired argument.
	 */
	template <std::size_t Idx>
	static auto flag_value() -> typename mulinum::at_c<args_list,Idx>::value_type
	{
		return detail::arg_value_holder<type,mulinum::at_c<args_list,Idx>,Idx>::value();
	}


	/**
	 * @brief Checks if a string equals to a flag's name
	 *
	 * Checks if `str` equals to one of the aliases of the corresponding flag.
	 *
	 * @param str The string to check.
	 */
	static inline bool equals(const std::string& str)
	{
		return detail::is_in_string_vector<flags_list>::eval(str);
	}
};

template <char... FlagChars,char... HelpChars,typename... FlagArgs>
constexpr std::size_t flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>::num_args;


/**
 * @ingroup flags
 * @brief Specialization for switch-type flags
 *
 * Defines a _switch_, i.e., a flag that takes no arguments and its value
 * depends on the calling of it in the command line (`true` if called, `false`
 * otherwise).
 *
 * In this library, each switch is caled like this: `--my_switch`.
 *
 * A short name can be set after the flag's _long_ name, followed by a comma
 * (example: `"my_switch,ms"`, which can be called as `--my_switch` or `-ms` in
 * the command line).
 *
 * @tparam FlagChars... The characters in the string corresponding to the flag
 *                      aliases.
 * @tparam HelpChars... The characters in the string corresponding to the
 *                      desctiption of the flag.
 */
template <char... FlagChars,char... HelpChars>
struct flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>
{
	static_assert(
		detail::is_flag_aliases_naming_valid<mulinum::string<FlagChars...>>::value,
		"[cynodelic::metaflags::flag<...>] The flags must be named with alphanumeric characters, "
		"hyphens, and underscores, and cannot begin with hyphens or numbers."
	);

	/// @brief Reference to itself.
	using type = flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>;

	/// @brief The string that contains the flag's name(s).
	using flag_string = mulinum::string<FlagChars...>;

	/// @brief The string that containd the flag's description.
	using help_string = mulinum::string<HelpChars...>;

	/// @brief A `mulinum::vector` that contains the flag's aliases.
	using flags_list = detail::make_flag_aliases_list<mulinum::string<FlagChars...>>;

	/// @brief Number of arguments.
	static constexpr std::size_t num_args = 0;


	/**
	 * @brief Checks if a string equals to a flag's name
	 *
	 * Checks if `str` equals to one of the aliases of the corresponding flag.
	 *
	 * @param str The string to check.
	 */
	static inline bool equals(const std::string& str)
	{
		return detail::is_in_string_vector<flags_list>::eval(str);
	}
};

template <char... FlagChars,char... HelpChars>
constexpr std::size_t flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>::num_args;


}} // end of "cynodelic::metaflags" namespace


#include <cynodelic/metaflags/preprocessor/pp_flag.hpp>


#endif // CYNODELIC_METAFLAGS_FLAG_HPP
