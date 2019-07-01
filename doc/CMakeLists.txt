# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


find_package(Doxygen REQUIRED)

if(NOT DOXYGEN_FOUND)
	message(WARNING "Doxygen was not found; the documentation files will not be built.")
	return()
endif()


set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR})
set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/doc/cynodelic/metaflags)


configure_file(${PROJECT_SOURCE_DIR}/doc/Doxyfile.in ${PROJECT_SOURCE_DIR}/doc/Doxyfile @ONLY)
add_custom_target(doc ALL
	COMMAND ${CMAKE_COMMAND} -E echo_append "Building documentation..."
	COMMAND ${CMAKE_COMMAND} -E make_directory ${DOXYGEN_OUTPUT_DIR}
	COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/doc/Doxyfile
	COMMAND ${CMAKE_COMMAND} -E echo "Done."
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

install(DIRECTORY ${DOXYGEN_OUTPUT_DIR}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/doc/cynodelic
	COMPONENT doc
)

install(FILES ${PROJECT_SOURCE_DIR}/doc/cynodelic_metaflags_tagfile.tag
	DESTINATION ${CMAKE_INSTALL_PREFIX}/doc/cynodelic/metaflags
)
