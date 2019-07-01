// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_ARGV_MAKER_HPP
#define CYNODELIC_METAFLAGS_TEST_ARGV_MAKER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>


/**
 * @brief Command line arguments simulator
 *
 * Simulates the arguments set in the command line (and the `argc` and `argv`
 * arguments of the `main` function) for testing the parsers.
 */
class argv_maker
{
	public:
		template <typename... ArgTypes>
		argv_maker(ArgTypes... args) :
			num_(sizeof...(args))
		{
			std::vector<std::string> strs{args...};

			data_ = new char*[num_];

			for (std::size_t i = 0; i < num_; i++)
			{
				data_[i] = new char[strs[i].length() + 1];
				
				std::strcpy(data_[i],strs[i].c_str());
			}
		}
		

		~argv_maker()
		{
			for (std::size_t i = 0; i < num_; i++)
			{
				delete [] data_[i];
			}

			delete [] data_;
		}
		

		/**
		 * @brief Returns the underlying data array
		 */
		char** data() const
		{
			return data_;
		}
		

		/**
		 * @brief Returns the number of contained strings
		 */
		std::size_t size() const
		{
			return num_;
		}
	private:
		std::size_t num_;
		char**      data_;
};


#endif // CYNODELIC_METAFLAGS_TEST_ARGV_MAKER_HPP
