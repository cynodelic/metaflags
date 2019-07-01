// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_PARSING_HPP
#define CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_PARSING_HPP


CYNODELIC_TESTER_TEST_CASE(flag_arguments_parsing);

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,i8_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--int8","-128"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int8",0)),static_cast<std::int8_t>(-128));

	argv_maker test_argv_2(
		"test",
		"--int8","0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int8",0)),static_cast<std::int8_t>(0));

	argv_maker test_argv_3(
		"test",
		"--int8","127"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int8",0)),static_cast<std::int8_t>(127));


	argv_maker test_argv_4(
		"test",
		"--int8","128"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int8 128\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}


	argv_maker test_argv_5(
		"test",
		"--int8","-129"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int8 -129\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,i16_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--int16","-32768"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int16",0)),-32768);

	argv_maker test_argv_2(
		"test",
		"--int16","0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int16",0)),0);

	argv_maker test_argv_3(
		"test",
		"--int16","32767"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int16",0)),32767);


	argv_maker test_argv_4(
		"test",
		"--int16","32768"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int16 32768\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}


	argv_maker test_argv_5(
		"test",
		"--int16","-32769"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int16 -32769\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,i32_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--int32","-2147483648"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int32",0)),-2147483648);

	argv_maker test_argv_2(
		"test",
		"--int32","0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int32",0)),0);

	argv_maker test_argv_3(
		"test",
		"--int32","2147483647"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int32",0)),2147483647);


	argv_maker test_argv_4(
		"test",
		"--int32","2147483648"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int32 2147483648\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}


	argv_maker test_argv_5(
		"test",
		"--int32","-2147483649"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--int32 -2147483649\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,i64_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--int64","-9223372036854775808"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int64",0)),std::numeric_limits<std::int64_t>::min());

	argv_maker test_argv_2(
		"test",
		"--int64","0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int64",0)),0);

	argv_maker test_argv_3(
		"test",
		"--int64","9223372036854775807"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--int64",0)),std::numeric_limits<std::int64_t>::max());
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,u8_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--uint8","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint8",0)),static_cast<std::uint8_t>(0));

	argv_maker test_argv_2(
		"test",
		"--uint8","255"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint8",0)),static_cast<std::uint8_t>(255));


	argv_maker test_argv_3(
		"test",
		"--uint8","256"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--uint8 256\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,u16_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--uint16","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint16",0)),0);

	argv_maker test_argv_2(
		"test",
		"--uint16","65535"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint16",0)),65535);


	argv_maker test_argv_3(
		"test",
		"--uint16","65536"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--uint16 65536\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,u32_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--uint32","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint32",0)),0);

	argv_maker test_argv_2(
		"test",
		"--uint32","4294967295"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint32",0)),4294967295);


	argv_maker test_argv_3(
		"test",
		"--uint32","4294967296"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--uint32 4294967296\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,u64_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--uint64","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint64",0)),0);

	argv_maker test_argv_2(
		"test",
		"--uint64","18446744073709551615"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--uint64",0)),std::numeric_limits<std::uint64_t>::max());
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,bln_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--boolean","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--boolean",0)),false);

	argv_maker test_argv_2(
		"test",
		"--boolean","false"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--boolean",0)),false);

	argv_maker test_argv_3(
		"test",
		"--boolean","1"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--boolean",0)),true);

	argv_maker test_argv_4(
		"test",
		"--boolean","true"
	);

	prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--boolean",0)),true);


	argv_maker test_argv_5(
		"test",
		"--boolean","invalid"
	);

	try
	{
		prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());
	}
	catch (...)
	{
		CYNODELIC_TESTER_MESSAGE << "The expected exception for \"--boolean invalid\" was thrown.";
		CYNODELIC_TESTER_CHECK_TRUE(true);
	}
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,flt_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--float","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),0.0f);

	argv_maker test_argv_2(
		"test",
		"--float","-0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),-0.0f);

	argv_maker test_argv_3(
		"test",
		"--float","-INF"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),-std::numeric_limits<float>::infinity());

	argv_maker test_argv_4(
		"test",
		"--float","INF"
	);

	prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),std::numeric_limits<float>::infinity());

	argv_maker test_argv_5(
		"test",
		"--float","2.71"
	);

	prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),2.71f);

	argv_maker test_argv_6(
		"test",
		"--float","-1.608"
	);

	prsr::parse(static_cast<int>(test_argv_6.size()),test_argv_6.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--float",0)),-1.608f);
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,dbl_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--double","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),0.0);

	argv_maker test_argv_2(
		"test",
		"--double","-0"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),-0.0);

	argv_maker test_argv_3(
		"test",
		"--double","-INF"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),-std::numeric_limits<double>::infinity());

	argv_maker test_argv_4(
		"test",
		"--double","INF"
	);

	prsr::parse(static_cast<int>(test_argv_4.size()),test_argv_4.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),std::numeric_limits<double>::infinity());

	argv_maker test_argv_5(
		"test",
		"--double","2.71"
	);

	prsr::parse(static_cast<int>(test_argv_5.size()),test_argv_5.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),2.71);

	argv_maker test_argv_6(
		"test",
		"--double","-1.608"
	);

	prsr::parse(static_cast<int>(test_argv_6.size()),test_argv_6.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--double",0)),-1.608);
}

CYNODELIC_TESTER_SECTION(flag_arguments_parsing,str_argument)
{
	using prsr = mfl::parser<
		FLAG_("int8,i8","8-bit signed integer",mfl::i8_arg<>),
		FLAG_("int16,i16","16-bit signed integer",mfl::i16_arg<>),
		FLAG_("int32,i32","32-bit signed integer",mfl::i32_arg<>),
		FLAG_("int64,i64","64-bit signed integer",mfl::i64_arg<>),
		FLAG_("uint8,u8","8-bit unsigned integer",mfl::u8_arg<>),
		FLAG_("uint16,u16","16-bit unsigned integer",mfl::u16_arg<>),
		FLAG_("uint32,u32","32-bit unsigned integer",mfl::u32_arg<>),
		FLAG_("uint64,u64","64-bit unsigned integer",mfl::u64_arg<>),
		FLAG_("boolean,b","Boolean",mfl::bln_arg<>),
		FLAG_("float,f","Single-precision floating point",mfl::flt_arg<>),
		FLAG_("double,d","Double-precision floating point",mfl::dbl_arg<>),
		FLAG_("string,s","String",mfl::str_arg<>)
	>;

	argv_maker test_argv_1(
		"test",
		"--string","0"
	);

	prsr::parse(static_cast<int>(test_argv_1.size()),test_argv_1.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--string",0)),std::string("0"));

	// Remember that strings with spaces, as a single argument,
	// should be written between quotation marks in the command line.
	argv_maker test_argv_2(
		"test",
		"--string","String with multiple s p a c e s"
	);

	prsr::parse(static_cast<int>(test_argv_2.size()),test_argv_2.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--string",0)),std::string("String with multiple s p a c e s"));

	argv_maker test_argv_3(
		"test",
		"--string","!#$%&/()[];:-._,{@}"
	);

	prsr::parse(static_cast<int>(test_argv_3.size()),test_argv_3.data());

	CYNODELIC_TESTER_CHECK_EQUALS((GET_ARG(prsr,"--string",0)),std::string("!#$%&/()[];:-._,{@}"));
}


#endif // CYNODELIC_METAFLAGS_TEST_FLAG_ARGUMENTS_PARSING_HPP
