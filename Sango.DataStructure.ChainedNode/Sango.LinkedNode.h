#ifndef SANGO_LINKED_NODE
#define SANGO_LINKED_NODE

#include "Sango.CodeHelper.Generic.h"

//µ•œÚ¡¥±Ì
typedef struct _LinkedNode {
	ElementPointer element;
	struct _LinkedNode *next;
} LinkedNode, *LinkedNodePointer;

#define SANGO_LINKED_NODE_SIZE sizeof(LinkedNode)
#define MallocLinkedNode() SangoMalloc(LinkedNode)
#define MallocLinkedNodeN(count) SangoMallocN(LinkedNode, count)

#endif
