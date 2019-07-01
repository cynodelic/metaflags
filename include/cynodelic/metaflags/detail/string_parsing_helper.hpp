// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_DETAIL_STRING_PARSING_HELPER_HPP
#define CYNODELIC_METAFLAGS_DETAIL_STRING_PARSING_HELPER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <limits>

#include <cynodelic/mulinum/if.hpp>
#include <cynodelic/mulinum/integer_c.hpp>
#include <cynodelic/mulinum/equals.hpp>
#include <cynodelic/mulinum/logical_or.hpp>

#include <cynodelic/metaflags/config.hpp>
#include <cynodelic/metaflags/flag_arguments.hpp>


namespace cynodelic { namespace metaflags
{

namespace detail
{
	/**
	 * @brief Tag selector for `string_parsing_helper`
	 */
	template <typename FlagArg>
	using select_sp_tag = mulinum::if_<
		mulinum::equals<typename FlagArg::value_type,std::int64_t>::value,
		mulinum::int_c<1>,
		mulinum::if_<
			mulinum::logical_or<
				mulinum::equals<typename FlagArg::value_type,std::int8_t>,
				mulinum::equals<typename FlagArg::value_type,std::int16_t>,
				mulinum::equals<typename FlagArg::value_type,std::int32_t>
			>::value,
			mulinum::int_c<2>,
			mulinum::if_<
				mulinum::equals<typename FlagArg::value_type,std::uint64_t>::value,
				mulinum::int_c<3>,
				mulinum::if_<
					mulinum::logical_or<
						mulinum::equals<typename FlagArg::value_type,std::uint8_t>,
						mulinum::equals<typename FlagArg::value_type,std::uint16_t>,
						mulinum::equals<typename FlagArg::value_type,std::uint32_t>
					>::value,
					mulinum::int_c<4>,
					mulinum::int_c<0>
				>
			>
		>
	>;


	/**
	 * @brief Undefined
	 */
	template <typename,typename>
	struct string_parsing_helper_impl;


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <template <char...> class FlagArg,char... Chars>
	struct string_parsing_helper_impl<FlagArg<Chars...>,mulinum::int_c<1>>
	{
		static inline typename FlagArg<Chars...>::value_type call(const std::string& x)
		{
			return static_cast<typename FlagArg<Chars...>::value_type>(std::stoll(x));
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <template <char...> class FlagArg,char... Chars>
	struct string_parsing_helper_impl<FlagArg<Chars...>,mulinum::int_c<2>>
	{
		static inline typename FlagArg<Chars...>::value_type call(const std::string& x)
		{
			using val_type_ = typename FlagArg<Chars...>::value_type;

			long res = std::stol(x);

			if (res < static_cast<long>(std::numeric_limits<val_type_>::min()) || res > static_cast<long>(std::numeric_limits<val_type_>::max()))
			{
				throw std::out_of_range("[cynodelic::metaflags::detail::string_parsing_helper_impl<...,cynodelic::mulinum::int_c<2>>::call()] The parsed value is outside the range for the specified argument type.");
			}
			else
			{
				return static_cast<val_type_>(res);
			}
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <template <char...> class FlagArg,char... Chars>
	struct string_parsing_helper_impl<FlagArg<Chars...>,mulinum::int_c<3>>
	{
		static inline typename FlagArg<Chars...>::value_type call(const std::string& x)
		{
			return static_cast<typename FlagArg<Chars...>::value_type>(std::stoull(x));
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <template <char...> class FlagArg,char... Chars>
	struct string_parsing_helper_impl<FlagArg<Chars...>,mulinum::int_c<4>>
	{
		static inline typename FlagArg<Chars...>::value_type call(const std::string& x)
		{
			using val_type_ = typename FlagArg<Chars...>::value_type;

			unsigned long res = std::stoul(x);

			if (res < static_cast<unsigned long>(std::numeric_limits<val_type_>::min()) || res > static_cast<unsigned long>(std::numeric_limits<val_type_>::max()))
			{
				throw std::out_of_range("[cynodelic::metaflags::detail::string_parsing_helper_impl<...,cynodelic::mulinum::int_c<4>>::call()] The parsed value is outside the range for the specified argument type.");
			}
			else
			{
				return static_cast<typename FlagArg<Chars...>::value_type>(res);
			}
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <char... Chars>
	struct string_parsing_helper_impl<flt_arg<Chars...>,mulinum::int_c<0>>
	{
		static inline typename flt_arg<Chars...>::value_type call(const std::string& x)
		{
			return std::stof(x);
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <char... Chars>
	struct string_parsing_helper_impl<dbl_arg<Chars...>,mulinum::int_c<0>>
	{
		static inline typename dbl_arg<Chars...>::value_type call(const std::string& x)
		{
			return std::stod(x);
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <char... Chars>
	struct string_parsing_helper_impl<bln_arg<Chars...>,mulinum::int_c<0>>
	{
		static inline typename bln_arg<Chars...>::value_type call(const std::string& x)
		{
			if (x == "1" || x == "true")
				return true;
			else if (x == "0" || x == "false")
				return false;
			else
				throw std::invalid_argument("Not a valid boolean argument");
		}
	};


	/**
	 * @brief Helper for `string_parsing_helper`
	 */
	template <char... Chars>
	struct string_parsing_helper_impl<str_arg<Chars...>,mulinum::int_c<0>>
	{
		static inline typename str_arg<Chars...>::value_type call(const std::string& x)
		{
			return x;
		}
	};


	/**
	 * @brief Helper type for string parsing
	 */
	template <typename FlagArg>
	using string_parsing_helper = string_parsing_helper_impl<FlagArg,select_sp_tag<FlagArg>>;
} // end of "detail" namespace

}} // end of "cynodelic::metaflags" namespace


#endif // CYNODELIC_METAFLAGS_DETAIL_STRING_PARSING_HELPER_HPP
