// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file help_parameters.hpp
 *
 * @brief Defines parameters for help generation
 */


#ifndef CYNODELIC_METAFLAGS_HELP_PARAMETERS_HPP
#define CYNODELIC_METAFLAGS_HELP_PARAMETERS_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/metaflags/config.hpp>

#include <cynodelic/mulinum/if.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/null_type.hpp>
#include <cynodelic/mulinum/equals.hpp>


namespace cynodelic { namespace metaflags
{


/**
 * @ingroup helpparamsargs
 * @brief Tabulation size for flags
 *
 * Sets the number of spaces (i.e. _tabulation_ size) from the left to the
 * flags in the generated help.
 *
 * @tparam Value The number of spaces.
 */
template <std::size_t Value>
struct flag_tabulation
{
	using type = flag_tabulation<Value>;
	
	static constexpr std::size_t value = Value;
};

template <std::size_t Value>
constexpr std::size_t flag_tabulation<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Relative tabulation size for descriptions of flags
 *
 * Sets the relative tabulation from the first character of a flag, to the
 * said flag's description.
 *
 * @tparam Value The number of spaces.
 */
template <std::size_t Value>
struct flag_help_tabulation
{
	using type = flag_help_tabulation<Value>;
	
	static constexpr std::size_t value = Value;
};

template <std::size_t Value>
constexpr std::size_t flag_help_tabulation<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Determines if the program usage is displayed
 *
 * Determines if the program usage is displayed in the generated help.
 *
 * @tparam Value If `true`, the usage is displayed.
 */
template <bool Value>
struct show_usage
{
	using type = show_usage<Value>;
	
	static constexpr bool value = Value;
};

template <bool Value>
constexpr bool show_usage<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Determines if the header of the list of flags is displayed
 *
 * Determines if the header of the list of flags (that is, the _title_ of said
 * list) is added to the generated help.
 *
 * @tparam Value If `true`, the header is added to the help.
 */
template <bool Value>
struct show_list_header
{
	using type = show_list_header<Value>;
	
	static constexpr bool value = Value;
};

template <bool Value>
constexpr bool show_list_header<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Determines if the help flags are added to the parser's help
 *
 * Determines if the flags used to display the generated help are added to its
 * list of flags.
 *
 * @tparam Value If `true`, the flags are added to the help.
 */
template <bool Value>
struct add_help_flags_to_list
{
	using type = add_help_flags_to_list<Value>;
	
	static constexpr bool value = Value;
};

template <bool Value>
constexpr bool add_help_flags_to_list<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Sets the delimiter for the flag aliases
 *
 * Sets the character that delimits the different aliases of the flags in the
 * generated help.
 *
 * @tparam Value The delimiter.
 */
template <char Value>
struct flag_aliases_delimiter
{
	using type = flag_aliases_delimiter<Value>;
	
	static constexpr char value = Value;
};

template <char Value>
constexpr char flag_aliases_delimiter<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Determines if the help is printed in abscence of arguments
 *
 * Determines if the generated help will be printed when no arguments were set
 * when calling the program.
 *
 * @tparam Value If `true`, the help will be printed.
 */
template <bool Value>
struct print_help_if_no_arguments
{
	using type = print_help_if_no_arguments<Value>;
	
	static constexpr bool value = Value;
};

template <bool Value>
constexpr bool print_help_if_no_arguments<Value>::value;


/**
 * @ingroup helpparamsargs
 * @brief Tag type for the program name in the usage
 *
 * Tag type used as an argument in @ref usage_format to print the program's
 * name in the _program usage_.
 */
struct program_name
{
	using type = program_name;
};


/**
 * @ingroup helpparamsargs
 * @brief Defines the usage format
 *
 * Defines the help section related to how the program is called with its
 * arguments (i.e., the _program usage_).
 *
 + @tparam Args... The arguments used for the format generation (they can be
 *                 @link cynodelic::mulinum::string strings@endlink and/or
 *                 a @ref program_name).
 */
template <typename... Args>
struct usage_format
{
	using type = usage_format<Args...>;
};


/**
 * @ingroup helpparamsargs
 * @brief Defines the flag used for displaying the help
 *
 * Sets the flags used for displaying the generated help.
 *
 * @tparam HelpFlag The @link cynodelic::mulinum::string string@endlink with
 *                  the flag's name. A short name can be defined in such 
 *                  string, followed by a comma (default: a 
 *                  @link cynodelic::mulinum::string string@endlink, equivalent
 *                  to `"help,h"`).
 */
template <typename HelpFlag = mulinum::string<'h','e','l','p',',','h'>>
struct help_flag
{
	using type = help_flag;

	using flag_string = HelpFlag;

	using flags_list = detail::make_flag_aliases_list<HelpFlag>;
};


/**
 * @ingroup helpparamsargs
 * @brief Sets the header for the list of flags
 *
 * Sets the header (the _title_) of the generated list of flags in the help.
 *
 * @tparam ListHeader A @link cynodelic::mulinum::string string@endlink
 *                    containing the header.
 */
template <typename ListHeader = CYNODELIC_METAFLAGS_STRING_KL("Options:",8)>
struct flags_list_header
{
	using type = flags_list_header;

	using str_val = ListHeader;
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
	namespace detail
	{
		template <typename...>
		struct has_flag_tabulation;

		template <typename First,typename... Others>
		struct has_flag_tabulation<First,Others...> : has_flag_tabulation<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct has_flag_tabulation<flag_tabulation<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_flag_tabulation<> : mulinum::false_
		{};

		template <typename...>
		struct get_flag_tabulation_impl;

		template <typename First,typename... Others>
		struct get_flag_tabulation_impl<First,Others...> : get_flag_tabulation_impl<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct get_flag_tabulation_impl<flag_tabulation<Value>,Others...> : flag_tabulation<Value>
		{};

		template <>
		struct get_flag_tabulation_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_flag_tabulation = typename get_flag_tabulation_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_flag_help_tabulation;

		template <typename First,typename... Others>
		struct has_flag_help_tabulation<First,Others...> : has_flag_help_tabulation<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct has_flag_help_tabulation<flag_help_tabulation<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_flag_help_tabulation<> : mulinum::false_
		{};

		template <typename...>
		struct get_flag_help_tabulation_impl;

		template <typename First,typename... Others>
		struct get_flag_help_tabulation_impl<First,Others...> : get_flag_help_tabulation_impl<Others...>
		{};

		template <std::size_t Value,typename... Others>
		struct get_flag_help_tabulation_impl<flag_help_tabulation<Value>,Others...> : flag_help_tabulation<Value>
		{};

		template <>
		struct get_flag_help_tabulation_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_flag_help_tabulation = typename get_flag_help_tabulation_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_help_flag;

		template <typename First,typename... Others>
		struct has_help_flag<First,Others...> : has_help_flag<Others...>
		{};

		template <typename HelpFlag,typename... Others>
		struct has_help_flag<help_flag<HelpFlag>,Others...> : mulinum::true_
		{};

		template <>
		struct has_help_flag<> : mulinum::false_
		{};

		template <typename...>
		struct get_help_flag_impl;

		template <typename First,typename... Others>
		struct get_help_flag_impl<First,Others...> : get_help_flag_impl<Others...>
		{};

		template <typename HelpFlag,typename... Others>
		struct get_help_flag_impl<help_flag<HelpFlag>,Others...> : help_flag<HelpFlag>
		{};

		template <>
		struct get_help_flag_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_help_flag = typename get_help_flag_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_show_usage;

		template <typename First,typename... Others>
		struct has_show_usage<First,Others...> : has_show_usage<Others...>
		{};

		template <bool Value,typename... Others>
		struct has_show_usage<show_usage<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_show_usage<> : mulinum::false_
		{};

		template <typename...>
		struct get_show_usage_impl;

		template <typename First,typename... Others>
		struct get_show_usage_impl<First,Others...> : get_show_usage_impl<Others...>
		{};

		template <bool Value,typename... Others>
		struct get_show_usage_impl<show_usage<Value>,Others...> : show_usage<Value>
		{};

		template <>
		struct get_show_usage_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_show_usage = typename get_show_usage_impl<Args...>::type;
	}
	namespace detail /* *************************************************************************************************************** */
	{
		template <typename...>
		struct has_print_help_if_no_arguments;

		template <typename First,typename... Others>
		struct has_print_help_if_no_arguments<First,Others...> : has_print_help_if_no_arguments<Others...>
		{};

		template <bool Value,typename... Others>
		struct has_print_help_if_no_arguments<print_help_if_no_arguments<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_print_help_if_no_arguments<> : mulinum::false_
		{};

		template <typename...>
		struct get_print_help_if_no_arguments_impl;

		template <typename First,typename... Others>
		struct get_print_help_if_no_arguments_impl<First,Others...> : get_print_help_if_no_arguments_impl<Others...>
		{};

		template <bool Value,typename... Others>
		struct get_print_help_if_no_arguments_impl<print_help_if_no_arguments<Value>,Others...> : print_help_if_no_arguments<Value>
		{};

		template <>
		struct get_print_help_if_no_arguments_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_print_help_if_no_arguments = typename get_print_help_if_no_arguments_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_show_list_header;

		template <typename First,typename... Others>
		struct has_show_list_header<First,Others...> : has_show_list_header<Others...>
		{};

		template <bool Value,typename... Others>
		struct has_show_list_header<show_list_header<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_show_list_header<> : mulinum::false_
		{};

		template <typename...>
		struct get_show_list_header_impl;

		template <typename First,typename... Others>
		struct get_show_list_header_impl<First,Others...> : get_show_list_header_impl<Others...>
		{};

		template <bool Value,typename... Others>
		struct get_show_list_header_impl<show_list_header<Value>,Others...> : show_list_header<Value>
		{};

		template <>
		struct get_show_list_header_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_show_list_header = typename get_show_list_header_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_flags_list_header;

		template <typename First,typename... Others>
		struct has_flags_list_header<First,Others...> : has_flags_list_header<Others...>
		{};

		template <typename HeaderStr,typename... Others>
		struct has_flags_list_header<flags_list_header<HeaderStr>,Others...> : mulinum::true_
		{};

		template <>
		struct has_flags_list_header<> : mulinum::false_
		{};

		template <typename...>
		struct get_flags_list_header_impl;

		template <typename First,typename... Others>
		struct get_flags_list_header_impl<First,Others...> : get_flags_list_header_impl<Others...>
		{};

		template <typename HeaderStr,typename... Others>
		struct get_flags_list_header_impl<flags_list_header<HeaderStr>,Others...> : flags_list_header<HeaderStr>
		{};

		template <>
		struct get_flags_list_header_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_flags_list_header = typename get_flags_list_header_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_usage_format;

		template <typename First,typename... Others>
		struct has_usage_format<First,Others...> : has_usage_format<Others...>
		{};

		template <typename... Args,typename... Others>
		struct has_usage_format<usage_format<Args...>,Others...> : mulinum::true_
		{};

		template <>
		struct has_usage_format<> : mulinum::false_
		{};

		template <typename...>
		struct get_usage_format_impl;

		template <typename First,typename... Others>
		struct get_usage_format_impl<First,Others...> : get_usage_format_impl<Others...>
		{};

		template <typename... Args,typename... Others>
		struct get_usage_format_impl<usage_format<Args...>,Others...> : usage_format<Args...>
		{};

		template <>
		struct get_usage_format_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_usage_format = typename get_usage_format_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_add_help_flags_to_list;

		template <typename First,typename... Others>
		struct has_add_help_flags_to_list<First,Others...> : has_add_help_flags_to_list<Others...>
		{};

		template <bool Value,typename... Others>
		struct has_add_help_flags_to_list<add_help_flags_to_list<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_add_help_flags_to_list<> : mulinum::false_
		{};

		template <typename...>
		struct get_add_help_flags_to_list_impl;

		template <typename First,typename... Others>
		struct get_add_help_flags_to_list_impl<First,Others...> : get_add_help_flags_to_list_impl<Others...>
		{};

		template <bool Value,typename... Others>
		struct get_add_help_flags_to_list_impl<add_help_flags_to_list<Value>,Others...> : add_help_flags_to_list<Value>
		{};

		template <>
		struct get_add_help_flags_to_list_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_add_help_flags_to_list = typename get_add_help_flags_to_list_impl<Args...>::type;
	}
	namespace detail
	{
		template <typename...>
		struct has_flag_aliases_delimiter;

		template <typename First,typename... Others>
		struct has_flag_aliases_delimiter<First,Others...> : has_flag_aliases_delimiter<Others...>
		{};

		template <char Value,typename... Others>
		struct has_flag_aliases_delimiter<flag_aliases_delimiter<Value>,Others...> : mulinum::true_
		{};

		template <>
		struct has_flag_aliases_delimiter<> : mulinum::false_
		{};

		template <typename...>
		struct get_flag_aliases_delimiter_impl;

		template <typename First,typename... Others>
		struct get_flag_aliases_delimiter_impl<First,Others...> : get_flag_aliases_delimiter_impl<Others...>
		{};

		template <char Value,typename... Others>
		struct get_flag_aliases_delimiter_impl<flag_aliases_delimiter<Value>,Others...> : flag_aliases_delimiter<Value>
		{};

		template <>
		struct get_flag_aliases_delimiter_impl<> : mulinum::null_type
		{};

		template <typename... Args>
		using get_flag_aliases_delimiter = typename get_flag_aliases_delimiter_impl<Args...>::type;
	}
#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup helpparams
 * @brief Contains the parameters for the parser's help generation
 *
 * Contains @link helpparamsargs the parameters@endlink, which are set in a
 * _named parameters_ fashion, to use in the help generation of an instance of
 * @ref parser, when passed as an argument in its @ref parser_parameters.
 *
 * @tparam Args... The @link helpparamsargs parameters@endlink.
 */
template <typename... Args>
struct help_parameters
{
	/// @brief Reference to itself
	using type = help_parameters<Args...>;
	
	/// @brief Tabulation of the flags (default: 4)
	static constexpr std::size_t flag_tabulation = mulinum::if_<detail::has_flag_tabulation<Args...>::value,detail::get_flag_tabulation<Args...>,flag_tabulation<4>>::value;

	/// @brief Tabulation of descriptions from its respective flags (default: 4)
	static constexpr std::size_t flag_help_tabulation = mulinum::if_<detail::has_flag_help_tabulation<Args...>::value,detail::get_flag_help_tabulation<Args...>,flag_help_tabulation<4>>::value;

	/// @brief Allows displaying the usage (default: `true`)
	static constexpr bool show_usage = mulinum::if_<detail::has_show_usage<Args...>::value,detail::get_show_usage<Args...>,show_usage<true>>::value;

	/// @brief Allows displaying the header of the list of flags (default: `true`)
	static constexpr bool show_list_header = mulinum::if_<detail::has_show_list_header<Args...>::value,detail::get_show_list_header<Args...>,show_list_header<true>>::value;

	/// @brief Allows adding the help flags to the list (default: `true`)
	static constexpr bool add_help_flags_to_list = mulinum::if_<detail::has_add_help_flags_to_list<Args...>::value,detail::get_add_help_flags_to_list<Args...>,add_help_flags_to_list<true>>::value;

	/// @brief Allows printing the help of no arguments were set (default: `false`)
	static constexpr bool print_help_if_no_arguments = mulinum::if_<detail::has_print_help_if_no_arguments<Args...>::value,detail::get_print_help_if_no_arguments<Args...>,print_help_if_no_arguments<false>>::value;

	/// @brief Delimiter for the aliases of a flag (default: `/`)
	static constexpr char flag_aliases_delimiter = mulinum::if_<detail::has_flag_aliases_delimiter<Args...>::value,detail::get_flag_aliases_delimiter<Args...>,flag_aliases_delimiter<'/'>>::value;

	/// @brief The flag corresponding to the displaying of the help
	using detected_help_flag = mulinum::if_<detail::has_help_flag<Args...>::value,detail::get_help_flag<Args...>,help_flag<>>;

	/// @brief The aliases of the _help_ flag
	using flags_list = typename detected_help_flag::flags_list;

	/// @brief The string with the aliases of the _help_ flag
	using flag_string = typename detected_help_flag::flag_string;

	/// @brief The header of the list of flags
	using flags_list_header = typename mulinum::if_<detail::has_flags_list_header<Args...>::value,detail::get_flags_list_header<Args...>,flags_list_header<>>::str_val;

	/// @brief The usage format
	using usage_format = typename mulinum::if_<detail::has_usage_format<Args...>::value,detail::get_usage_format<Args...>,usage_format<CYNODELIC_METAFLAGS_STRING_KL("Usage: ",7),program_name,CYNODELIC_METAFLAGS_STRING_KL(" [options...]",13)>>::type;
};

template <typename... Args>
constexpr std::size_t help_parameters<Args...>::flag_tabulation;

template <typename... Args>
constexpr std::size_t help_parameters<Args...>::flag_help_tabulation;

template <typename... Args>
constexpr bool help_parameters<Args...>::show_usage;

template <typename... Args>
constexpr bool help_parameters<Args...>::show_list_header;

template <typename... Args>
constexpr bool help_parameters<Args...>::add_help_flags_to_list;

template <typename... Args>
constexpr char help_parameters<Args...>::flag_aliases_delimiter;

template <typename... Args>
constexpr bool help_parameters<Args...>::print_help_if_no_arguments;


/**
 * @ingroup helpparams
 * @brief Disables the help generation in the parser
 *
 * A parameter that disables the generation and displaying of the help in it,
 * when passed as an argument in the @ref parser_parameters of a @ref parser.
 */
struct disable_help_in_parser
{
	/// @brief Reference to itself
	using type = disable_help_in_parser;
};


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_HELP_PARAMETERS_HPP
