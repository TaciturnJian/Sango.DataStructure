/*
	Author: 三苟Sango
	Brief: 提供关于内存申请和指针处理的宏函数
*/

#ifndef SANGO_SIMPLE_MALLOC
#define SANGO_SIMPLE_MALLOC

#include <malloc.h>

#pragma region 显式转换

#define CastTo(type, x) (type)(x)
#define CastToPointer(type, x) (type*)(x)

typedef void *VoidPointer;
typedef void ActionFunction(void), (*ActionFunctionPointer)(void);
#define CastToActionFunctionPointer(x) CastTo(ActionFunctionPointer, x)

#pragma endregion

#pragma region 内存申请

#define SangoAlloc(type) CastToPointer(type, alloca(sizeof(type)))
#define SangoAllocN(type, count) CastToPointer(type, alloca(sizeof(type)*(count)))
#define SangoMalloc(type) CastToPointer(type, malloc(sizeof(type)))
#define SangoMallocN(type, count) CastToPointer(type, malloc(sizeof(type)*(count)))

#pragma endregion

#pragma region 指针处理

#define NullPointer(pointer) ((pointer) == 0)
#define ExecuteXWhenNullPointer(pointer, x)\
if NullPointer(pointer) {\
	x;\
}

#define ReturnWhenNullPointer(pointer) ExecuteXWhenNullPointer(pointer, return)
#define ReturnXWhenNullPointer(x, pointer) ExecuteXWhenNullPointer(pointer, return x)
#define FreeWhenNotNullPointer(pointer) ExecuteXWhenNullPointer(pointer, free(pointer))

#define NotNullPointer(pointer) ((pointer) != 0)
#define ExecuteXWhenNotNullPointer(pointer, x)\
if NotNullPointer(pointer) {\
	x;\
}

#define ReturnWhenNotNullPointer(pointer) ExecuteXWhenNotNullPointer(pointer, return)
#define ReturnXWhenNotNullPointer(x, pointer) ExecuteXWhenNotNullPointer(pointer, return x)
#define FreeWhenNotNotNullPointer(pointer) ExecuteXWhenNotNullPointer(pointer, free(pointer))

#pragma endregion

#endif
