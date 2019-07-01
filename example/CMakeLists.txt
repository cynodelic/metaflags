# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


set(example_names
	custom_help_parameters
	get_as_tuple
	runtime_start_at
	switches
	two_parsers
)

foreach(example_nm ${example_names})
	add_executable(${example_nm} ${example_nm}.cpp)
	target_include_directories(${example_nm} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include ${image_libs_libraries})
endforeach()
