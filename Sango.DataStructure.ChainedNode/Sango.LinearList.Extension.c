#include "Sango.LinearList.Extension.h"

#pragma region 创建和销毁线性表

LinearListPointer CreateLinearList(int maxCapacity) {
	if (maxCapacity < 0) {
		return 0;
	}

	if (maxCapacity == 0) {
		LinearListPointer list = MallocList();
		ReturnWhenNullPointer(list);

		list->count = 0;
		list->element_list = 0;
		list->max_capacity = 0;
		return list;
	}

	LinearListPointer list = MallocList();
	ReturnWhenNullPointer(list);

	list->count = 0;
	list->max_capacity = maxCapacity;
	list->element_list = MallocElementN(maxCapacity);

	if NullPointer(list->element_list) {
		free(list);
		return 0;
	}

	return list;
}

void DestroyLinearList(LinearListPointer list) {
	ReturnWhenNullPointer(list);
	FreeWhenNotNullPointer(list->element_list);
	free(list);
}

#pragma endregion

#pragma region 线性表的基本操作

ElementPointer GetElementPointerFromLinearList(LinearListPointer list, int index) {
	ReturnWhenNullPointer(list);
	if CheckValidIndexInLinearListPointer(index, list) {
		return 0;
	}

	return list->element_list + index;
}

status AppendCopiedElementIntoLinearList(LinearListPointer list, ElementPointer e) {
	ReturnWhenNullPointer(list);
	ReturnWhenNullPointer(e);

	if (list->count >= list->max_capacity) {
		return STATUS_ERROR;
	}

	memcpy(list->element_list + list->count, e, SANGO_ELEMENT_SIZE);
	list->count++;

	return STATUS_NORMAL;
}

void RemoveIndexOfLinearList(LinearListPointer list, int index) {
	if (index >= list->count || index < 0) {
		return;
	}

	for (int i = index; i < list->count; i++) {
		list->element_list[i] = list->element_list[i + 1];
	}

	list->count--;
}

ElementPointer FindFirstTargetInLinearList(LinearListPointer list, ElementPointer target, CompareFunctionPointer compare) {
	for (int i = 0; i < list->count; i++) {
		if (compare(list->element_list + i, target) == EQUAL) {
			return list->element_list + i;
		}
	}

	return 0;
}

void QuickSortForLinearList(LinearListPointer list, CompareFunctionPointer compare, int left, int right) {
	ReturnWhenNullPointer(list);
	ReturnWhenNullPointer(compare);

	if (left < right) {
		int i = left, j = right;
		ElementType element_temp;
		CopyElement(&element_temp, list->element_list + left);

		while (i < j) {
			//从右向左寻找第一个小于x的元素
			while (i < j && (CheckMoreOrEqual(compare(list->element_list + j, &element_temp)))) {
				j--;
			}

			if (i < j) {
				CopyElement(list->element_list + i, list->element_list + j);
				i++;
			}

			//从左向右寻找第一个大于x的元素
			while (i < j && (CheckLessOrEqual(compare(list->element_list + i, &element_temp)))) {
				i++;
			}

			if (i < j) {
				CopyElement(list->element_list + j, list->element_list + i);
				j--;
			}
		}
		CopyElement(list->element_list + i, &element_temp);
		QuickSortForLinearList(list, compare, left, i - 1);
		QuickSortForLinearList(list, compare, i + 1, right);
	}
}

void SortLinearList(LinearListPointer list, CompareFunctionPointer compareFunction) {
	return QuickSortForLinearList(list, compareFunction, 0, list->count - 1);
}

//TODO
LinearListPointer CreateUnionFromTwoUnsortedLists(LinearListPointer listA, LinearListPointer listB) {

}

//TODO
LinearListPointer CreateUnionFromTwoSortedLists(LinearListPointer list1, LinearListPointer list2) {
	ReturnXWhenNullPointer(0, list1);
	ReturnXWhenNullPointer(0, list2);

	LinearListPointer result = CreateLinearList(list1->count + list2->count);
	ReturnXWhenNullPointer(0, result);


}

void ForEachElementInLinearList(LinearListPointer list, ElementActionFunctionPointer actionFunctionPointer) {
	ReturnWhenNullPointer(list);
	ReturnWhenNullPointer(actionFunctionPointer);

	for (int i = 0; i < list->count; i++) {
		actionFunctionPointer(list->element_list + i);
	}
}

#pragma endregion