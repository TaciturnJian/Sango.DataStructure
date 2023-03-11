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

typedef void *VoidPointer;
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
