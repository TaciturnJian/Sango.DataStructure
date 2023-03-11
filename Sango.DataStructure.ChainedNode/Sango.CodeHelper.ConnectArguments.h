/*
	Author: 三苟Sango
	Brief: 提供关于连接几个参数的宏函数
*/

#ifndef SANGO_CONNECT_ARGUMENTS
#define SANGO_CONNECT_ARGUMENTS

#define Connect1Arguments(x1) x1
#define Connect2Arguments(x1, x2) Connect1Arguments(x1)##x2
#define Connect3Arguments(x1, x2, x3) Connect2Arguments(x1,x2)##x3
#define Connect4Arguments(x1, x2, x3, x4) Connect3Arguments(x1,x2,x3)##x4
#define Connect5Arguments(x1, x2, x3, x4, x5) Connect4Arguments(x1,x2,x3,x4)##x5
#define Connect6Arguments(x1, x2, x3, x4, x5, x6) Connect5Arguments(x1,x2,x3,x4,x5)##x6
#define Connect7Arguments(x1, x2, x3, x4, x5, x6, x7) Connect6Arguments(x1,x2,x3,x4,x5,x6)##x7
#define Connect8Arguments(x1, x2, x3, x4, x5, x6, x7, x8) Connect7Arguments(x1,x2,x3,x4,x5,x6,x7)##x8
#define Connect9Arguments(x1, x2, x3, x4, x5, x6, x7, x8, x9) Connect8Arguments(x1,x2,x3,x4,x5,x6,x7,x8)##x9
#define ConnectArguments(n) Connect##n##Arguments
#endif
