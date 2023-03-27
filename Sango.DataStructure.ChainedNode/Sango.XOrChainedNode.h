#pragma once

#include "Sango.CodeHelper.Generic.h"

typedef struct _XOrChainedNode {
	ElementPointer element;
	struct _XOrChainedNode *ptr;
} XOrChainedNode, *XOrChainedNodePointer;

void visit(XOrChainedNodePointer head) {
	return visit2(0, head);
}

XOrChainedNodePointer transform(XOrChainedNodePointer current, XOrChainedNodePointer target) {
	return (XOrChainedNodePointer)(
		CastTo(unsigned long long, current->ptr) ^ CastTo(unsigned long long, target)
	);
}

void visit2(XOrChainedNodePointer last, XOrChainedNodePointer current) {
	ReturnWhenNullPointer(current);

	//TODO ´òÓ¡ÔªËØ

	while NotNullPointer(current) {
		XOrChainedNodePointer next = transform(current, last);
		last = current;
		current = next;
	}
}