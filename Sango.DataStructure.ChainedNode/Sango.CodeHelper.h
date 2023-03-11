#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Sango.CodeHelper.ConnectArguments.h"
#include "Sango.CodeHelper.IterateArguments.h"
#include "Sango.CodeHelper.RepeatArguments.h"
#include "Sango.CodeHelper.Generic.h"

#define ClearScreen() system("cls")

#pragma region Function Argument Type

//表示此参数需要调用者提供一个指向某一对象的指针，函数会使用指针的数据，
#define ARG_IN

//表示此参数需要调用者提供一个指向某一对象的指针，函数会向指针里面填充数据
#define ARG_OUT

//表示此参数需要调用者提供一个指向某一对象的指针，函数会读或者填充数据
#define ARG_INOUT

#pragma endregion
