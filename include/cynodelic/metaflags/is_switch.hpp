// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file is_switch.hpp
 *
 * @brief Defines the `is_switch` type trait
 */


#ifndef CYNODELIC_METAFLAGS_IS_SWITCH_HPP
#define CYNODELIC_METAFLAGS_IS_SWITCH_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/flag.hpp>


namespace cynodelic { namespace metaflags
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename>
struct is_switch_impl;


template <char... FlagChars,char... HelpChars>
struct is_switch_impl<flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,switch_tag>> : mulinum::true_
{};


template <char... FlagChars,char... HelpChars,typename... FlagArgs>
struct is_switch_impl<flag<mulinum::string<FlagChars...>,mulinum::string<HelpChars...>,FlagArgs...>> : mulinum::false_
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits_
 * @brief Checks if a flag is a _switch_
 *
 * Checks if `Flag` defines a switch (a flag that takes no arguments), returning
 * a @link cynodelic::mulinum::true_ `true_`@endlink if this is accomplished,
 * otherwise, it will return a @link cynodelic::mulinum::false_ `false_`@endlink.
 *
 * @tparam Flag The type to check.
 */
template <typename Flag>
using is_switch = typename is_switch_impl<Flag>::type;


}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_IS_SWITCH_HPP
