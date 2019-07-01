// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAGS_GETTERS_MAKER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAGS_GETTERS_MAKER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/string.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/at.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>
#include <cynodelic/metaflags/detail/call_status_holder.hpp>
#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/is_switch.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	template <typename,std::size_t,typename>
	struct multiple_aliases_flag_getters_maker_impl;


	template <typename Flag,std::size_t Count>
	struct multiple_aliases_flag_getters_maker_impl<Flag,Count,mulinum::false_> : multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::false_>
	{
		static inline constexpr std::size_t num_args(mulinum::at_c<typename Flag::flags_list,Count>)
		{
			return Flag::num_args;
		}

		template <std::size_t Idx>
		static inline auto get(mulinum::at_c<typename Flag::flags_list,Count>,mulinum::size_c<Idx>) -> typename mulinum::at_c<typename Flag::args_list,Idx>::value_type
		{
			return Flag::template flag_value<Idx>();
		}

		static inline bool was_called(mulinum::at_c<typename Flag::flags_list,Count>)
		{
			return call_status_holder<Flag>::value();
		}

		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::false_>::num_args;
		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::false_>::get;
		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::false_>::was_called;
	};


	template <typename Flag>
	struct multiple_aliases_flag_getters_maker_impl<Flag,0,mulinum::false_>
	{
		static inline constexpr std::size_t num_args(mulinum::at_c<typename Flag::flags_list,0>)
		{
			return Flag::num_args;
		}

		template <std::size_t Idx>
		static inline auto get(mulinum::at_c<typename Flag::flags_list,0>,mulinum::size_c<Idx>) -> typename mulinum::at_c<typename Flag::args_list,Idx>::value_type
		{
			return Flag::template flag_value<Idx>();
		}

		static inline bool was_called(mulinum::at_c<typename Flag::flags_list,0>)
		{
			return call_status_holder<Flag>::value();
		}
	};


	template <typename Flag,std::size_t Count>
	struct multiple_aliases_flag_getters_maker_impl<Flag,Count,mulinum::true_> : multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::true_>
	{
		static inline constexpr std::size_t num_args(mulinum::at_c<typename Flag::flags_list,Count>)
		{
			return Flag::num_args;
		}

		template <std::size_t Idx>
		static inline bool get(mulinum::at_c<typename Flag::flags_list,Count>,mulinum::size_c<Idx>)
		{
			return call_status_holder<Flag>::value();
		}

		static inline bool was_called(mulinum::at_c<typename Flag::flags_list,Count>)
		{
			return call_status_holder<Flag>::value();
		}

		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::true_>::num_args;
		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::true_>::get;
		using multiple_aliases_flag_getters_maker_impl<Flag,(Count - 1),mulinum::true_>::was_called;
	};

	
	template <typename Flag>
	struct multiple_aliases_flag_getters_maker_impl<Flag,0,mulinum::true_>
	{
		static inline constexpr std::size_t num_args(mulinum::at_c<typename Flag::flags_list,0>)
		{
			return Flag::num_args;
		}

		template <std::size_t Idx>
		static inline bool get(mulinum::at_c<typename Flag::flags_list,0>,mulinum::size_c<Idx>)
		{
			return call_status_holder<Flag>::value();
		}

		static inline bool was_called(mulinum::at_c<typename Flag::flags_list,0>)
		{
			return call_status_holder<Flag>::value();
		}
	};


	template <typename Flag>
	using multiple_aliases_flag_getters_maker = multiple_aliases_flag_getters_maker_impl<Flag,(Flag::flags_list::size - 1),is_switch<Flag>>;


	template <typename First,typename... Others>
	struct multiple_flags_data_helper :
		multiple_flags_data_helper<First>,
		multiple_flags_data_helper<Others...>
	{
		using multiple_flags_data_helper<First>::num_args;
		using multiple_flags_data_helper<First>::get;
		using multiple_flags_data_helper<First>::was_called;

		using multiple_flags_data_helper<Others...>::num_args;
		using multiple_flags_data_helper<Others...>::get;
		using multiple_flags_data_helper<Others...>::was_called;
	};


	template <typename Last>
	struct multiple_flags_data_helper<Last> :
		multiple_aliases_flag_getters_maker<Last>
	{
		using multiple_aliases_flag_getters_maker<Last>::num_args;
		using multiple_aliases_flag_getters_maker<Last>::get;
		using multiple_aliases_flag_getters_maker<Last>::was_called;
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAGS_GETTERS_MAKER_HPP
