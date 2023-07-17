//
//  Node.h
//  A simple typeless data structure for a node.
//
//  Created by Jacob Hogrefe on 7/11/23.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

Node * createNode(void *);
void destroyNode(Node *);
void setNodeData(Node *, void *);
void * getNodeData(Node *);

#endif /* Node_h */
