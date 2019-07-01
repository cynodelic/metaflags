// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_ARG_VALUE_HOLDER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_ARG_VALUE_HOLDER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief Holds the value of a flag's argument.
	 */
	template <typename ParentFlag,typename ArgT,std::size_t Idx>
	struct arg_value_holder : ArgT
	{
		using parent_flag = ParentFlag;
		
		static typename ArgT::value_type& value()
		{
			static typename ArgT::value_type instance;

			return instance;
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_ARG_VALUE_HOLDER_HPP
