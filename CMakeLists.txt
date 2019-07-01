# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


cmake_minimum_required(VERSION 3.11)


set(detail_header_files
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/arg_value_holder.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/call_status_holder.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/help_generation_helpers.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/is_flag_aliases_naming_valid.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/is_in_string_vector.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/join_all_parser_flags.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/make_flag_aliases_list.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/multiple_flag_arg_values_holder.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/multiple_flag_getters_maker.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/name_of_arg_type.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/parser_helper.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/parser_runtime_data_holder.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/remove_zeroes_from_string.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/set_values_from_strings.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/detail/string_parsing_helper.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/detail/flag_argument_helpers.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/detail/get_argument_helpers.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/detail/pp_concat.hpp
)


set(header_files
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/config.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/pp_flag.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/pp_flag_arguments.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/preprocessor/pp_parser.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/argument_type.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/argument_types_list.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/finish_at.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/flag.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/flag_arguments.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/generate_list_of_flags.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/get_as_tuple.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/help_parameters.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/is_switch.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/number_of_flag_args.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/parser.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/parser_parameters.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/start_at.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/exceptions/bad_argument_parsing.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/metaflags/fwd/parser_fwd.hpp
)


# Gets the version
file(READ include/cynodelic/metaflags/config.hpp _ver_impl)

string(REGEX MATCH "#define CYNODELIC_METAFLAGS_VERSION_MAJOR ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_metaflags_ver_major ${CMAKE_MATCH_1})

string(REGEX MATCH "#define CYNODELIC_METAFLAGS_VERSION_MINOR ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_metaflags_ver_minor ${CMAKE_MATCH_1})

string(REGEX MATCH "#define CYNODELIC_METAFLAGS_VERSION_PATCH ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_metaflags_ver_patch ${CMAKE_MATCH_1})

set(cynodelic_metaflags_ver_string "${cynodelic_metaflags_ver_major}.${cynodelic_metaflags_ver_minor}.${cynodelic_metaflags_ver_patch}")

message("Cynodelic::Metaflags, version ${cynodelic_metaflags_ver_string}")


# Project name and version
project(cynodelic_metaflags VERSION ${cynodelic_metaflags_ver_string} LANGUAGES CXX)


# Options
option(CYNODELIC_METAFLAGS_BUILD_EXAMPLES "Builds the examples" OFF)
option(CYNODELIC_METAFLAGS_BUILD_DOC "Builds the corresponding documentation" OFF)
option(CYNODELIC_METAFLAGS_BUILD_TEST "Builds the unit tests" ON)
set(CMAKE_CXX_STANDARD 14)

# Path to Mulinum doc directory
set(CYNODELIC_METAFLAGS_MULINUM_DOC_DIR "" CACHE PATH "Path of Mulinum\'s \"doc\" directory")


if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()


# Library operations
add_library(metaflags INTERFACE)
target_sources(metaflags INTERFACE $<BUILD_INTERFACE:${detail_header_files} ${header_files}>)
target_include_directories(metaflags INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/cynodelic" DESTINATION include)


# Builds unit tests
if (CYNODELIC_METAFLAGS_BUILD_TEST)
	enable_testing()
	add_subdirectory(test)
endif()


# Builds examples
if (CYNODELIC_METAFLAGS_BUILD_EXAMPLES)
	add_subdirectory(example)
endif()


# Builds documentation
if (CYNODELIC_METAFLAGS_BUILD_DOC)
	add_subdirectory(doc)
endif()
