//
//  LinkedList.h
//  A typeless LinkedList data structure.
//
//  Created by Jacob Hogrefe on 7/11/23.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include "Node.h"

typedef struct LinkedList {
    Node *head;
    Node *tail;
    unsigned int size;
} LinkedList;

LinkedList * createList(void);
void destroyList(LinkedList *);

void addFirst(LinkedList *, void *);
void addLast(LinkedList *, void *);
void addAtIndex(LinkedList *, unsigned int, void *);
void removeAtIndex(LinkedList *, unsigned int);
void * getAtIndex(LinkedList *, unsigned int);
void setAtIndex(LinkedList *, unsigned int,  void *);
int contains(LinkedList *, void *);

void ** toArray(LinkedList *);
void printList(LinkedList *, void *(void *));

#endif /* LinkedList_h */
