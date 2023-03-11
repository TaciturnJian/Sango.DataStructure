/*
	Author: 三苟Sango
	Brief: 提供一些用(typedef char)重定义的类型，以及这些类型相关的宏函数、宏定义
*/

#ifndef SANGO_BOOL
#define SANGO_BOOL

//表示在合法情况下只有0和1两个状态的类型
typedef unsigned char SangoBool, condition;
#define TRUE 1
#define FALSE 0

//表示在合法情况下只有三种状态的类型（比较结果: 大于=>More; 小于=>LESS; 等于=>EQUAL）
typedef char CompareResult;
#define MORE 1
#define EQUAL 0
#define LESS -1
#define CheckMoreOrEqual(compareResult) ((compareResult) >= 0)
#define CheckLessOrEqual(compareResult) ((compareResult) <= 0)

//表示在合法情况下只有两种状态的类型（-1表示出错,0表示正常）
typedef char status;
#define STATUS_ERROR -1
#define STATUS_NORMAL 0

//表示在合法情况下只有三种状态的类型（选择: 同意=>ACCEPTED; 否定=>DENIED; 未知=>UNKNOWN）
typedef char choice;
#define ACCEPTED 1
#define DENIED -1
#define UNKNWON 0

#endif
