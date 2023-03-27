#pragma once

#include <stdio.h>
#include "Sango.LinkedNode.Extension.h"

void 约瑟夫环(int codes[], int count) {
	ReturnWhenNullPointer(codes);

	//将数组转化为链表
	LinkedNodePointer head = CreateLinkedNode(codes);
	LinkedNodePointer current = head;
	for (int i = 1; i < count; i++) {
		LinkedNodePointer p = CreateLinkedNode(codes + i);
		Connect2LinkedNodes(current, p);
		current = p;
	}
	Connect2LinkedNodes(current, head);

	//链表开始
	int code = *current->element;
	LinkedNodePointer last = current;
	current = head;
	while (current != 0) {
		for (int i = 0; i < code; i++) {
			last = current;
			current = current->next;
		}
		LinkedNodePointer target = current;
		current = current->next;
		last->next = current;
		printf("%d ", code);
		free(target);
	}
}

