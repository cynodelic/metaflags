// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_PARSER_RUNTIME_DATA_HOLDER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_PARSER_RUNTIME_DATA_HOLDER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/metaflags/config.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief ...
	 */
	template <typename Parser>
	struct parser_runtime_data_holder
	{
		using parent_parser = Parser;
		
		
		static std::size_t& last_parsed_arg_pos()
		{
			static std::size_t instance = 0;

			return instance;
		}


		static std::size_t& starts_parsing_at()
		{
			static std::size_t instance = 1;

			return instance;
		}


		static std::size_t& finishes_parsing_at()
		{
			static std::size_t instance = 1;

			return instance;
		}


		static void set_last_parsed_arg_pos(const std::size_t& val)
		{
			last_parsed_arg_pos() = val;
		}


		static void set_starts_parsing_at(const std::size_t& val)
		{
			starts_parsing_at() = val;
		}


		static void set_finishes_parsing_at(const std::size_t& val)
		{
			finishes_parsing_at() = val;
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_PARSER_RUNTIME_DATA_HOLDER_HPP
