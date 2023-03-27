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

typedef void *VoidPointer, *UniversalPointer;
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

#pragma region 空指针行为

#define NullPointer(pointer) ((pointer) == 0)
#define ExecuteXWhenNullPointer(pointer, x)\
if NullPointer(pointer) {\
	x;\
}

#define ReturnWhenNullPointer(pointer) ExecuteXWhenNullPointer(pointer, return)
#define ReturnXWhenNullPointer(x, pointer) ExecuteXWhenNullPointer(pointer, return x)
#define FreeWhenNullPointer(pointer) ExecuteXWhenNullPointer(pointer, free(pointer))

#pragma endregion

#pragma region 非空指针行为

#define NotNullPointer(pointer) ((pointer) != 0)
#define ExecuteXWhenNotNullPointer(x, pointer)\
if NotNullPointer(pointer) {\
	x;\
}

#define ReturnWhenNotNullPointer(pointer) ExecuteXWhenNotNullPointer(return, pointer)
#define ReturnXWhenNotNullPointer(x, pointer) ExecuteXWhenNotNullPointer(return x, pointer)
#define FreeWhenNotNullPointer(pointer) ExecuteXWhenNotNullPointer(free(pointer), pointer)

#pragma endregion

#pragma endregion

#endif
