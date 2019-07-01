// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_PREPROCESSOR_DETAIL_PP_CONCAT_HPP
#define CYNODELIC_METAFLAGS_PREPROCESSOR_DETAIL_PP_CONCAT_HPP


#include <cynodelic/metaflags/config.hpp>


#define CYNODELIC_METAFLAGS_PP_CONCAT_IMPL(x,y) x##y
#define CYNODELIC_METAFLAGS_PP_CONCAT(x,y) CYNODELIC_METAFLAGS_PP_CONCAT_IMPL(x,y)


#endif // CYNODELIC_METAFLAGS_PREPROCESSOR_DETAIL_PP_CONCAT_HPP
