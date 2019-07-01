// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAG_ARG_VALUES_HOLDER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAG_ARG_VALUES_HOLDER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/vector.hpp>
#include <cynodelic/mulinum/at.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/detail/arg_value_holder.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief Helper for `multiple_flag_arg_values_holder`
	 */
	template <typename ParentFlag,std::size_t Idx>
	struct multiple_flag_arg_values_holder_impl :
		multiple_flag_arg_values_holder_impl<ParentFlag,(Idx - 1)>
	{
		static inline typename mulinum::at<typename ParentFlag::args_list,mulinum::size_c<Idx>>::value_type& value(mulinum::size_c<Idx>)
		{
			return arg_value_holder<ParentFlag,mulinum::at<typename ParentFlag::args_list,mulinum::size_c<Idx>>,Idx>::value();
		}

		static typename mulinum::at<typename ParentFlag::args_list,mulinum::size_c<Idx>>::value_type value_type_helper(mulinum::size_c<Idx>);

		static mulinum::at<typename ParentFlag::args_list,mulinum::size_c<Idx>> current_arg_helper(mulinum::size_c<Idx>);

		using multiple_flag_arg_values_holder_impl<ParentFlag,(Idx - 1)>::value;
		using multiple_flag_arg_values_holder_impl<ParentFlag,(Idx - 1)>::value_type_helper;
		using multiple_flag_arg_values_holder_impl<ParentFlag,(Idx - 1)>::current_arg_helper;
	};
	

	/**
	 * @brief Helper for `multiple_flag_arg_values_holder`
	 */
	template <typename ParentFlag>
	struct multiple_flag_arg_values_holder_impl<ParentFlag,0>
	{
		static inline typename mulinum::at<typename ParentFlag::args_list,mulinum::size_c<0>>::value_type& value(mulinum::size_c<0>)
		{
			return arg_value_holder<ParentFlag,mulinum::at<typename ParentFlag::args_list,mulinum::size_c<0>>,0>::value();
		}

		static typename mulinum::at<typename ParentFlag::args_list,mulinum::size_c<0>>::value_type value_type_helper(mulinum::size_c<0>);

		static mulinum::at<typename ParentFlag::args_list,mulinum::size_c<0>> current_arg_helper(mulinum::size_c<0>);
	};


	/**
	 * @brief Allows holding the values of all the flag's arguments.
	 */
	template <typename ParentFlag>
	using multiple_flag_arg_values_holder = multiple_flag_arg_values_holder_impl<ParentFlag,(ParentFlag::args_list::size - 1)>;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_MULTIPLE_FLAG_ARG_VALUES_HOLDER_HPP