// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <string>
#include <limits>

#include <cynodelic/tester.hpp>

#include <cynodelic/mulinum/equals.hpp>

#include <cynodelic/metaflags/flag.hpp>
#include <cynodelic/metaflags/is_switch.hpp>
#include <cynodelic/metaflags/parser.hpp>
#include <cynodelic/metaflags/argument_type.hpp>
#include <cynodelic/metaflags/argument_types_list.hpp>
#include <cynodelic/metaflags/get_as_tuple.hpp>


namespace tst = cynodelic::tester;
namespace mln = cynodelic::mulinum;
namespace mfl = cynodelic::metaflags;


#ifndef STRING_
#define STRING_ CYNODELIC_METAFLAGS_STRING
#endif

#ifndef FLAG_
#define FLAG_ CYNODELIC_METAFLAGS_FLAG
#endif

#ifndef SWITCH_
#define SWITCH_ CYNODELIC_METAFLAGS_SWITCH
#endif

#ifndef GET_ARG
#define GET_ARG CYNODELIC_METAFLAGS_GET_ARGUMENT
#endif

#ifndef WAS_CALLED
#define WAS_CALLED CYNODELIC_METAFLAGS_WAS_CALLED
#endif

#ifndef I8_ARG
#define I8_ARG CYNODELIC_METAFLAGS_I8_ARG
#endif

#ifndef I16_ARG
#define I16_ARG CYNODELIC_METAFLAGS_I16_ARG
#endif

#ifndef I32_ARG
#define I32_ARG CYNODELIC_METAFLAGS_I32_ARG
#endif

#ifndef I64_ARG
#define I64_ARG CYNODELIC_METAFLAGS_I64_ARG
#endif

#ifndef U8_ARG
#define U8_ARG CYNODELIC_METAFLAGS_U8_ARG
#endif

#ifndef U16_ARG
#define U16_ARG CYNODELIC_METAFLAGS_U16_ARG
#endif

#ifndef U32_ARG
#define U32_ARG CYNODELIC_METAFLAGS_U32_ARG
#endif

#ifndef U64_ARG
#define U64_ARG CYNODELIC_METAFLAGS_U64_ARG
#endif

#ifndef FLT_ARG
#define FLT_ARG CYNODELIC_METAFLAGS_FLT_ARG
#endif

#ifndef DBL_ARG
#define DBL_ARG CYNODELIC_METAFLAGS_DBL_ARG
#endif

#ifndef BLN_ARG
#define BLN_ARG CYNODELIC_METAFLAGS_BLN_ARG
#endif

#ifndef STR_ARG
#define STR_ARG CYNODELIC_METAFLAGS_STR_ARG
#endif


#include "argv_maker.hpp"

#include "flag_arguments.hpp"

#include "is_switch.hpp"

#include "flag_arguments_parsing.hpp"
#include "different_stored_argument_values.hpp"

#include "parser_default_parameters.hpp"
#include "parser_default_parameters_extra_tail_args.hpp"
#include "parser_default_parameters_extra_args_in_between.hpp"

#include "parser_runtime_start_at.hpp"
#include "parser_compile_time_start_at.hpp"

#include "parser_runtime_finish_at.hpp"
#include "parser_runtime_finish_at_extra_args_in_between.hpp"
#include "parser_compile_time_finish_at.hpp"
#include "parser_compile_time_finish_at_extra_args_in_between.hpp"

#include "argument_type.hpp"
#include "argument_types_list.hpp"

#include "get_as_tuple.hpp"
