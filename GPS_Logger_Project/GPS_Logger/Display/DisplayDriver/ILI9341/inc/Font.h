#pragma once

static const unsigned char font[][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// пробел
	{0x04,0x04,0x04,0x04,0x00,0x04,0x00,0x00},// !
	{0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x00},// "
	{0x0A,0x0A,0x1F,0x0A,0x1F,0x0A,0x0A,0x00},// #
	{0x04,0x0F,0x14,0x0E,0x05,0x1E,0x04,0x00},// $
	{0x18,0x19,0x02,0x04,0x08,0x13,0x03,0x00},// %
	{0x0C,0x12,0x14,0x08,0x14,0x12,0x0D,0x00},// &
	{0x0C,0x04,0x08,0x00,0x00,0x00,0x00,0x00},// '
	{0x02,0x04,0x08,0x08,0x08,0x04,0x02,0x00},// (
	{0x08,0x04,0x02,0x02,0x02,0x04,0x08,0x00},// )
	{0x00,0x04,0x15,0x0E,0x15,0x04,0x00,0x00},// *
	{0x00,0x04,0x04,0x1F,0x04,0x04,0x00,0x00},// +
	{0x00,0x00,0x00,0x00,0x0C,0x04,0x08,0x00},// ,
	{0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},// -
	{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00},// .
	{0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00},// /

	{0x0E,0x11,0x13,0x15,0x19,0x11,0x0E,0x00},// 0
	{0x04,0x0C,0x04,0x04,0x04,0x04,0x0E,0x00},// 1
	{0x0E,0x11,0x01,0x02,0x04,0x08,0x1F,0x00},// 2
	{0x1F,0x02,0x04,0x02,0x01,0x11,0x0E,0x00},// 3
	{0x02,0x06,0x0A,0x12,0x1F,0x02,0x02,0x00},// 4
	{0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E,0x00},// 5
	{0x06,0x08,0x10,0x1E,0x11,0x11,0x0E,0x00},// 6
	{0x1F,0x01,0x02,0x04,0x08,0x08,0x08,0x00},// 7
	{0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00},// 8
	{0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C,0x00},// 9
	{0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00},// :
	{0x00,0x0C,0x0C,0x00,0x0C,0x04,0x08,0x00},// ;
	{0x02,0x04,0x08,0x10,0x08,0x04,0x02,0x00},// <
	{0x00,0x00,0x1F,0x00,0x1F,0x00,0x00,0x00},// =
	{0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x00},// >
	{0x0E,0x11,0x01,0x02,0x04,0x00,0x04,0x00},// ?

	{0x0E,0x11,0x01,0x0D,0x15,0x15,0x0E,0x00},// @
	{0x0E,0x11,0x11,0x11,0x1F,0x11,0x11,0x00},// A
	{0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00},// B
	{0x0E,0x11,0x10,0x10,0x10,0x11,0x0E,0x00},// C
	{0x1C,0x12,0x11,0x11,0x11,0x12,0x1C,0x00},// D
	{0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F,0x00},// E
	{0x1F,0x10,0x10,0x1E,0x10,0x10,0x10,0x00},// F
	{0x0E,0x11,0x10,0x17,0x11,0x11,0x0E,0x00},// G
	{0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00},// H
	{0x0E,0x04,0x04,0x04,0x04,0x04,0x0E,0x00},// I
	{0x07,0x02,0x02,0x02,0x02,0x12,0x0C,0x00},// J
	{0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00},// K
	{0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00},// L
	{0x11,0x1B,0x15,0x15,0x11,0x11,0x11,0x00},// M
	{0x11,0x11,0x19,0x15,0x13,0x11,0x11,0x00},// N
	{0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},// O

	{0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00},// P
	{0x0E,0x11,0x11,0x11,0x15,0x12,0x0D,0x00},// Q
	{0x1E,0x11,0x11,0x1E,0x14,0x12,0x11,0x00},// R
	{0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E,0x00},// S
	{0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00},// T
	{0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},// U
	{0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00},// V
	{0x11,0x11,0x11,0x11,0x15,0x15,0x0E,0x00},// W
	{0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,0x00},// X
	{0x11,0x11,0x11,0x0A,0x04,0x04,0x04,0x00},// Y
	{0x1F,0x01,0x02,0x04,0x08,0x10,0x1F,0x00},// Z
	{0x0E,0x08,0x08,0x08,0x08,0x08,0x0E,0x00},// [
	{0x11,0x0A,0x1F,0x04,0x1F,0x04,0x04,0x00},//
	{0x0E,0x02,0x02,0x02,0x02,0x02,0x0E,0x00},// ]
	{0x04,0x0A,0x11,0x00,0x00,0x00,0x00,0x00},// ^
	{0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00},// _

	{0x08,0x04,0x00,0x00,0x00,0x00,0x00,0x00},// '
	{0x00,0x00,0x0E,0x01,0x0F,0x11,0x0F,0x00},// a
	{0x10,0x10,0x1E,0x11,0x11,0x11,0x1E,0x00},// b
	{0x00,0x00,0x0E,0x10,0x10,0x11,0x0E,0x00},// c
	{0x01,0x01,0x0D,0x13,0x11,0x11,0x0F,0x00},// d
	{0x00,0x00,0x0E,0x11,0x1F,0x10,0x0E,0x00},// e
	{0x06,0x09,0x08,0x1C,0x08,0x08,0x08,0x00},// f
	{0x00,0x0F,0x11,0x11,0x0F,0x01,0x0E,0x00},// g
	{0x10,0x10,0x16,0x19,0x11,0x11,0x11,0x00},// h
	{0x04,0x00,0x0C,0x04,0x04,0x04,0x0E,0x00},// i
	{0x02,0x00,0x06,0x02,0x02,0x12,0x0C,0x00},// j
	{0x10,0x10,0x12,0x14,0x18,0x14,0x12,0x00},// k
	{0x18,0x08,0x08,0x08,0x08,0x08,0x1C,0x00},// l
	{0x00,0x00,0x1A,0x15,0x15,0x11,0x11,0x00},// m
	{0x00,0x00,0x16,0x19,0x11,0x11,0x11,0x00},// n
	{0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00},// o

	{0x00,0x00,0x1E,0x11,0x1E,0x10,0x10,0x00},// p
	{0x00,0x00,0x0F,0x11,0x0F,0x01,0x01,0x00},// q
	{0x00,0x00,0x16,0x19,0x10,0x10,0x10,0x00},// r
	{0x00,0x00,0x0E,0x10,0x0E,0x01,0x1E,0x00},// s
	{0x08,0x08,0x1C,0x08,0x08,0x09,0x06,0x00},// t
	{0x00,0x00,0x11,0x11,0x11,0x13,0x0D,0x00},// u
	{0x00,0x00,0x11,0x11,0x11,0x0A,0x04,0x00},// v
	{0x00,0x00,0x11,0x11,0x11,0x15,0x0A,0x00},// w
	{0x00,0x00,0x11,0x0A,0x04,0x0A,0x11,0x00},// x
	{0x00,0x00,0x11,0x11,0x0F,0x01,0x0E,0x00},// y
	{0x00,0x00,0x1F,0x02,0x04,0x08,0x1F,0x00},// z
	{0x17,0x15,0x15,0x15,0x17,0x00,0x00,0x00},// 10
	{0x17,0x11,0x17,0x14,0x17,0x00,0x00,0x00},// 12
	{0x17,0x14,0x17,0x11,0x17,0x00,0x00,0x00},// 15
	{0x01,0x05,0x09,0x1F,0x08,0x04,0x00,0x00},// стрелка
	{0x00,0x07,0x0E,0x1C,0x11,0x1E,0x00,0x00}};// кракозяблик

/*
static const unsigned char font[][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// пробел
	{0x04,0x04,0x04,0x04,0x00,0x04,0x00,0x00},// !
	{0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x00},// "
	{0x0A,0x0A,0x1F,0x0A,0x1F,0x0A,0x0A,0x00},// #
	{0x04,0x0F,0x14,0x0E,0x05,0x1E,0x04,0x00},// $
	{0x18,0x19,0x02,0x04,0x08,0x13,0x03,0x00},// %
	{0x0C,0x12,0x14,0x08,0x14,0x12,0x0D,0x00},// &
	{0x0C,0x04,0x08,0x00,0x00,0x00,0x00,0x00},// '
	{0x02,0x04,0x08,0x08,0x08,0x04,0x02,0x00},// (
	{0x08,0x04,0x02,0x02,0x02,0x04,0x08,0x00},// )
	{0x00,0x04,0x15,0x0E,0x15,0x04,0x00,0x00},// *
	{0x00,0x04,0x04,0x1F,0x04,0x04,0x00,0x00},// +
	{0x00,0x00,0x00,0x00,0x0C,0x04,0x08,0x00},// ,
	{0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},// -
	{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00},// .
	{0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00},// /

	{0x0E,0x11,0x13,0x15,0x19,0x11,0x0E,0x00},// 0
	{0x04,0x0C,0x04,0x04,0x04,0x04,0x0E,0x00},// 1
	{0x0E,0x11,0x01,0x02,0x04,0x08,0x1F,0x00},// 2
	{0x1F,0x02,0x04,0x02,0x01,0x11,0x0E,0x00},// 3
	{0x02,0x06,0x0A,0x12,0x1F,0x02,0x02,0x00},// 4
	{0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E,0x00},// 5
	{0x06,0x08,0x10,0x1E,0x11,0x11,0x0E,0x00},// 6
	{0x1F,0x01,0x02,0x04,0x08,0x08,0x08,0x00},// 7
	{0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00},// 8
	{0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C,0x00},// 9
	{0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00},// :
	{0x00,0x0C,0x0C,0x00,0x0C,0x04,0x08,0x00},// ;
	{0x02,0x04,0x08,0x10,0x08,0x04,0x02,0x00},// <
	{0x00,0x00,0x1F,0x00,0x1F,0x00,0x00,0x00},// =
	{0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x00},// >
	{0x0E,0x11,0x01,0x02,0x04,0x00,0x04,0x00},// ?

	{0x0E,0x11,0x01,0x0D,0x15,0x15,0x0E,0x00},// @
	{0x0E,0x11,0x11,0x11,0x1F,0x11,0x11,0x00},// A
	{0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00},// B
	{0x0E,0x11,0x10,0x10,0x10,0x11,0x0E,0x00},// C
	{0x1C,0x12,0x11,0x11,0x11,0x12,0x1C,0x00},// D
	{0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F,0x00},// E
	{0x1F,0x10,0x10,0x1E,0x10,0x10,0x10,0x00},// F
	{0x0E,0x11,0x10,0x17,0x11,0x11,0x0E,0x00},// G
	{0b11110000,0b10001000,0b10001000,0b11110000,0b10100000,0b10010000,0b10001000,0x00},// H
	{0x0E,0x04,0x04,0x04,0x04,0x04,0x0E,0x00},// I
	{0x07,0x02,0x02,0x02,0x02,0x12,0x0C,0x00},// J
	{0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00},// K
	{0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00},// L
	{0x11,0x1B,0x15,0x15,0x11,0x11,0x11,0x00},// M
	{0x11,0x11,0x19,0x15,0x13,0x11,0x11,0x00},// N
	{0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},// O

	{0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00},// P
	{0x0E,0x11,0x11,0x11,0x15,0x12,0x0D,0x00},// Q
	{0x1E,0x11,0x11,0x1E,0x14,0x12,0x11,0x00},// R
	{0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E,0x00},// S
	{0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00},// T
	{0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00},// U
	{0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00},// V
	{0x11,0x11,0x11,0x11,0x15,0x15,0x0E,0x00},// W
	{0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,0x00},// X
	{0x11,0x11,0x11,0x0A,0x04,0x04,0x04,0x00},// Y
	{0x1F,0x01,0x02,0x04,0x08,0x10,0x1F,0x00},// Z
	{0x0E,0x08,0x08,0x08,0x08,0x08,0x0E,0x00},// [
	{0x11,0x0A,0x1F,0x04,0x1F,0x04,0x04,0x00},//
	{0x0E,0x02,0x02,0x02,0x02,0x02,0x0E,0x00},// ]
	{0x04,0x0A,0x11,0x00,0x00,0x00,0x00,0x00},// ^
	{0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00},// _

	{0x08,0x04,0x00,0x00,0x00,0x00,0x00,0x00},// '
	{0x00,0x00,0x0E,0x01,0x0F,0x11,0x0F,0x00},// a
	{0x10,0x10,0x1E,0x11,0x11,0x11,0x1E,0x00},// b
	{0x00,0x00,0x0E,0x10,0x10,0x11,0x0E,0x00},// c
	{0x01,0x01,0x0D,0x13,0x11,0x11,0x0F,0x00},// d
	{0x00,0x00,0x0E,0x11,0x1F,0x10,0x0E,0x00},// e
	{0x06,0x09,0x08,0x1C,0x08,0x08,0x08,0x00},// f
	{0x00,0x0F,0x11,0x11,0x0F,0x01,0x0E,0x00},// g
	{0x10,0x10,0x16,0x19,0x11,0x11,0x11,0x00},// h
	{0x04,0x00,0x0C,0x04,0x04,0x04,0x0E,0x00},// i
	{0x02,0x00,0x06,0x02,0x02,0x12,0x0C,0x00},// j
	{0x10,0x10,0x12,0x14,0x18,0x14,0x12,0x00},// k
	{0x18,0x08,0x08,0x08,0x08,0x08,0x1C,0x00},// l
	{0x00,0x00,0x1A,0x15,0x15,0x11,0x11,0x00},// m
	{0x00,0x00,0x16,0x19,0x11,0x11,0x11,0x00},// n
	{0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00},// o

	{0x00,0x00,0x1E,0x11,0x1E,0x10,0x10,0x00},// p
	{0x00,0x00,0x0F,0x11,0x0F,0x01,0x01,0x00},// q
	{0x00,0x00,0x16,0x19,0x10,0x10,0x10,0x00},// r
	{0x00,0x00,0x0E,0x10,0x0E,0x01,0x1E,0x00},// s
	{0x08,0x08,0x1C,0x08,0x08,0x09,0x06,0x00},// t
	{0x00,0x00,0x11,0x11,0x11,0x13,0x0D,0x00},// u
	{0x00,0x00,0x11,0x11,0x11,0x0A,0x04,0x00},// v
	{0x00,0x00,0x11,0x11,0x11,0x15,0x0A,0x00},// w
	{0x00,0x00,0x11,0x0A,0x04,0x0A,0x11,0x00},// x
	{0x00,0x00,0x11,0x11,0x0F,0x01,0x0E,0x00},// y
	{0x00,0x00,0x1F,0x02,0x04,0x08,0x1F,0x00},// z
	{0x17,0x15,0x15,0x15,0x17,0x00,0x00,0x00},// 10
	{0x17,0x11,0x17,0x14,0x17,0x00,0x00,0x00},// 12
	{0x17,0x14,0x17,0x11,0x17,0x00,0x00,0x00},// 15
	{0x01,0x05,0x09,0x1F,0x08,0x04,0x00,0x00},// стрелка
	{0x00,0x07,0x0E,0x1C,0x11,0x1E,0x00,0x00}};// кракозяблик
*/
