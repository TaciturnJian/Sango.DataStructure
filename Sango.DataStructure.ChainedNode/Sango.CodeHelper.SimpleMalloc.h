/*
	Author: ����Sango
	Brief: �ṩ�����ڴ������ָ�봦��ĺ꺯��
*/

#ifndef SANGO_SIMPLE_MALLOC
#define SANGO_SIMPLE_MALLOC

#include <malloc.h>

#pragma region ��ʽת��

#define CastTo(type, x) (type)(x)
#define CastToPointer(type, x) (type*)(x)

typedef void *VoidPointer, *UniversalPointer;
typedef void ActionFunction(void), (*ActionFunctionPointer)(void);
#define CastToActionFunctionPointer(x) CastTo(ActionFunctionPointer, x)

#pragma endregion

#pragma region �ڴ�����

#define SangoAlloc(type) CastToPointer(type, alloca(sizeof(type)))
#define SangoAllocN(type, count) CastToPointer(type, alloca(sizeof(type)*(count)))
#define SangoMalloc(type) CastToPointer(type, malloc(sizeof(type)))
#define SangoMallocN(type, count) CastToPointer(type, malloc(sizeof(type)*(count)))

#pragma endregion

#pragma region ָ�봦��

#pragma region ��ָ����Ϊ

#define NullPointer(pointer) ((pointer) == 0)
#define ExecuteXWhenNullPointer(pointer, x)\
if NullPointer(pointer) {\
	x;\
}

#define ReturnWhenNullPointer(pointer) ExecuteXWhenNullPointer(pointer, return)
#define ReturnXWhenNullPointer(x, pointer) ExecuteXWhenNullPointer(pointer, return x)
#define FreeWhenNullPointer(pointer) ExecuteXWhenNullPointer(pointer, free(pointer))

#pragma endregion

#pragma region �ǿ�ָ����Ϊ

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
