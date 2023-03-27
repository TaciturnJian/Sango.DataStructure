/*
	Author: 三苟Sango
	Brief: 提供关于泛型的类型、宏定义、宏函数
*/

#ifndef SANGO_GENERIC
#define SANGO_GENERIC

#include <string.h>
#include "Sango.Bool.h"
#include "Sango.CodeHelper.SimpleMalloc.h"

#ifndef SANGO_ELEMENT_TYPE
#define SANGO_ELEMENT_TYPE int
#endif

typedef SANGO_ELEMENT_TYPE ElementType, *ElementPointer;
#define MallocElement() SangoMalloc(ElementType)
#define MallocElementN(count) SangoMallocN(ElementType, count)
#define SANGO_ELEMENT_SIZE sizeof(ElementType)
#define CopyElement(destination, elementPointer) memcpy(destination, elementPointer, SANGO_ELEMENT_SIZE)

typedef void ElementActionFunction(ElementPointer), (*ElementActionFunctionPointer)(ElementPointer);
#define CastToElementActionFunction(x) CastToPointer(ElementActionFunction, x)

typedef CompareResult CompareFunction(ElementPointer, ElementPointer), (*CompareFunctionPointer)(ElementPointer, ElementPointer);
#define CastToCompareFunction(x) CastToPointer(CompareFunction, x)

typedef ElementPointer ElementSelectionFunction(UniversalPointer), (*ElementSelectionFunctionPointer)(UniversalPointer);
#define CastToElementSelectionFunction(x) CastToPointer(ElementSelectionFunction, x)

#endif
