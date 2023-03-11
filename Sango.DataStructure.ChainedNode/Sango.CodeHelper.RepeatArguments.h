/*
	Author: 三苟Sango
	Brief: 提供关于(x)重复为 (x, x, x, ...)的宏函数
*/

#ifndef SANGO_REPEAT_ARGUMENTS
#define SANGO_REPEAT_ARGUMENTS

#define RepeatArguments1(x) x
#define ArgumentRepeater(n, x) x, RepeatArguments##n(x)
#define RepeatArguments2(x) ArgumentRepeater(1, x)
#define RepeatArguments3(x) ArgumentRepeater(2, x)
#define RepeatArguments4(x) ArgumentRepeater(3, x)
#define RepeatArguments5(x) ArgumentRepeater(4, x)
#define RepeatArguments6(x) ArgumentRepeater(5, x)
#define RepeatArguments7(x) ArgumentRepeater(6, x)
#define RepeatArguments8(x) ArgumentRepeater(7, x)
#define RepeatArguments9(x) ArgumentRepeater(8, x)
#define RepeatArguments(n) RepeatArguments##n 

#endif
