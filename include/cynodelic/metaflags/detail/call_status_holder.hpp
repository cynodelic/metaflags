// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_CALL_STATUS_HOLDER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_CALL_STATUS_HOLDER_HPP


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
	template <typename ParentFlag>
	struct call_status_holder
	{
		using parent_flag = ParentFlag;
		
		static bool& value()
		{
			static bool instance;

			return instance;
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_CALL_STATUS_HOLDER_HPP
