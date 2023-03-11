/*
	Author: 三苟Sango
	Brief: 提供关于(x)迭代为 (x1, x2, x3, ...)的宏函数
*/

#ifndef SANGO_ITERATE_ARGUMENTS
#define SANGO_ITERATE_ARGUMENTS

#define IterateArguments1(x) x##1
#define IterateArguments2(x) IterateArguments1(x), x##2
#define IterateArguments3(x) IterateArguments2(x), x##3
#define IterateArguments4(x) IterateArguments3(x), x##4
#define IterateArguments5(x) IterateArguments4(x), x##5
#define IterateArguments6(x) IterateArguments5(x), x##6
#define IterateArguments7(x) IterateArguments6(x), x##7
#define IterateArguments8(x) IterateArguments7(x), x##8
#define IterateArguments9(x) IterateArguments8(x), x##9
#define IterateArguments(n) IterateArguments##n

#endif
