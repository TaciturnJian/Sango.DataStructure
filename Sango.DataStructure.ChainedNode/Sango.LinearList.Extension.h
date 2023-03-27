/*
	Author: 三苟Sango

*/


#ifndef SANGO_LINEAR_LIST_EXTENSION
#define SANGO_LINEAR_LIST_EXTENSION

#include "Sango.LinearList.h"

#pragma region 创建和销毁线性表

LinearListPointer CreateLinearList(int maxCapacity);

void DestroyLinearList(LinearListPointer list);

#pragma endregion

#pragma region 线性表的基本操作

ElementPointer GetElementPointerFromLinearList(LinearListPointer list, int index);

status AppendCopiedElementIntoLinearList(LinearListPointer list, ElementPointer e);

void RemoveIndexOfLinearList(LinearListPointer list, int index);

ElementPointer FindFirstTargetInLinearList(LinearListPointer list, ElementPointer target, CompareFunctionPointer compare);

/// <summary>
/// 线性表快速排序
/// T(n) = O(nlogn)
/// S(n) = O(1)
/// </summary>
void QuickSortForLinearList(LinearListPointer list, CompareFunctionPointer compare, int left, int right);

void SortLinearList(LinearListPointer list, CompareFunctionPointer compareFunction);

//TODO
LinearListPointer CreateUnionFromTwoUnsortedLists(LinearListPointer listA, LinearListPointer listB);

//TODO
LinearListPointer CreateUnionFromTwoSortedLists(LinearListPointer list1, LinearListPointer list2);

void ForEachElementInLinearList(LinearListPointer list, ElementActionFunctionPointer actionFunctionPointer);

#pragma endregion

#endif
