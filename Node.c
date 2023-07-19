//
//  Node.c
//  Implementation of Node.h.
//
//  Created by Jacob Hogrefe on 7/11/23.
//

#include <stdlib.h>
#include <stdio.h>

#include "Node.h"

//allocates space for a node
Node * createNode(void *value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> data = value;
        newNode -> next = NULL;
    }
    return newNode;
}

//deallocates node and data within it
void destroyNode(Node *node) {
    if (node == NULL) return;
    if (node -> data != NULL) free(node -> data);
    node -> next = NULL;
    free(node);
}

//sets the data for a node
void setNodeData(Node *node, void *value) {
    if (node == NULL) return;
    node -> data = value;
}

//gets the data of the node
void * getNodeData(Node *node) {
    return node -> data;
}
