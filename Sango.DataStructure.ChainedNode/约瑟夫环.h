#pragma once

#include <stdio.h>
#include "Sango.LinkedNode.Extension.h"

void Լɪ��(int codes[], int count) {
	ReturnWhenNullPointer(codes);

	//������ת��Ϊ����
	LinkedNodePointer head = CreateLinkedNode(codes);
	LinkedNodePointer current = head;
	for (int i = 1; i < count; i++) {
		LinkedNodePointer p = CreateLinkedNode(codes + i);
		Connect2LinkedNodes(current, p);
		current = p;
	}
	Connect2LinkedNodes(current, head);

	//����ʼ
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

