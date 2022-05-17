# Metaflags

A header-only, C++14 library for parsing command-line arguments, which is based on template metaprogramming and magic statics.

## Requirements

- A C++14-compatible compiler
- [Mulinum](https://github.com/cynodelic/mulinum)

## Building and installation

This library is header-only, so no building is necessary for installing it. However, the examples, unit tests and documentation need to be built, using [CMake](http://cmake.org/).

Run `mkdir build && cd build && cmake [options] .. && make` (or your equivalent) for building.

### Building the examples

Use the `-DCYNODELIC_METAFLAGS_BUILD_EXAMPLES=1` option for building the examples.

### Building and running the tests

Use the `-DCYNODELIC_METAFLAGS_BUILD_TEST=1` option for building the unit tests.

Run the tests using `make test`.

### Building the documentation

The documentation is generated with [Doxygen](http://www.doxygen.nl/), if avaliable.

Use the `-DCYNODELIC_METAFLAGS_BUILD_DOC=1` for allowing its generation.

#### Linking with Mulinum's documentation

To link with Mulinum's documentation, set the path to it using the `-DCYNODELIC_METAFLAGS_MULINUM_DOC_DIR=/path/to/your/mulinum/doc` option.

### Installing the library

The installation path is set using the `-DCMAKE_INSTALL_PREFIX=path/to/your/libraries` option.

Run `make install` to install the library, as well as its documentation.

The documentation will be installed in `path/to/your/libraries/doc/cynodelic/metaflags`.

## To-do

- Generate a binary search tree (preferably a red-black tree) for the argument lookup
- Facilities for defining mutually exclusive groups of arguments

## License

This library is licensed under the Boost Software License.
