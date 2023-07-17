//
//  LinkedList.c
//  Implementation of LinkedList.h with some internal functions.
//
//  Created by Jacob Hogrefe on 7/11/23.
//

#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "Node.h"

//creates the list
LinkedList * createList(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    
    //initializes all of the variables within the list
    if (list != NULL) {
        list -> head = NULL;
        list -> tail = NULL;
        list -> size = 0;
    }
    
    return list;
}

//destroys the list
void destroyList(LinkedList *list) {
    if (list == NULL) return;
    
    //traverses through the list, destroying each element along the way
    if (list -> head != NULL) {
        Node *startNode = list -> head;
        Node *nextNode = list -> head -> next;

        while (nextNode != NULL) {
            destroyNode(startNode);

            startNode = nextNode;
            nextNode = nextNode -> next;
        }

        destroyNode(startNode);
        destroyNode(nextNode);
        list -> head = NULL;
    }
    
    free(list);
}

//internal function to get a node at a specified index
Node * getNodeAtIndex(LinkedList *list, unsigned int index) {
    //returns the head or tail
    if (index == 0) return  list -> head;
    if (index == list -> size - 1) return list -> tail;
    
    //traverses list to retrieve the node at that index
    Node *currentNode = list -> head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode -> next;
    }
    
    return currentNode;
}

//function to add a node to the beginning of the list
void addFirst(LinkedList *list, void *data) {
    if (list == NULL) return;
    //sets the head and tail of the list to the provided node if both are null
    Node *node = createNode(data);
    if (list -> head == NULL && list -> tail == NULL) {
        list -> head = node;
        list -> tail = node;
    } else if (list -> head == NULL) {
        list -> head = node;
    } else {
        node -> next = list -> head;
        list -> head = node;
    }
}

//function to add an element to the end of the list
void addLast(LinkedList *list, void *data) {
    if (list == NULL) return;
    //sets the head and tail of the list to the provided node if both are null
    Node *node = createNode(data);
    if (list -> head == NULL && list -> tail == NULL) {
        list -> head = node;
        list -> tail = node;
    } else if (list -> tail == NULL) {
        list -> tail = node;
    } else {
        list -> tail -> next = node;
        list -> tail = node;
    }
}

//adds a node in a specified index
void addAtIndex(LinkedList *list, unsigned int index, void *data) {
    if (list == NULL) return;
    
    //exit if index is out of bounds
    if (index >= list -> size) {
        printf("Cannot add at index %i for length %i!\n", index, list -> size);
        exit(EXIT_FAILURE);
    }
    
    if (index == 0) {
        addFirst(list, data);
    } else if (index == list -> size - 1) {
        addLast(list, data);
    } else {
        Node *node = createNode(data);
        getNodeAtIndex(list, index - 1) -> next = node;
        node -> next = getNodeAtIndex(list, index + 1);
    }
    list -> size++;
}

//internal function to remove the first element of the list
void removeFirst(LinkedList *list) {
    Node *headNode = list -> head;
    list -> head = headNode -> next;
    destroyNode(headNode);
}

//internal function to remove the last element of a list
void removeLast(LinkedList *list) {
    Node *tailNode = list -> tail;
    list -> tail = getNodeAtIndex(list, list -> size - 1);
    list -> tail -> next = NULL;
    destroyNode(tailNode);
}

//removes an element at a given index
void removeAtIndex(LinkedList *list, unsigned int index) {
    if (list == NULL) return;
    
    //exit if index is out of bounds
    if (index >= list -> size) {
        printf("Cannot remove at index %i for length %i!\n", index, list -> size);
        exit(EXIT_FAILURE);
    }
    
    if (index == 0) {
        removeFirst(list);
    } else if (index == list -> size - 1) {
        removeLast(list);
    } else {
        Node *desiredNode = getNodeAtIndex(list, index);
        getNodeAtIndex(list, index - 1) -> next = getNodeAtIndex(list, index + 1);
        destroyNode(desiredNode);
    }
    list -> size--;
}

//gets the element at a specified index
void * getAtIndex(LinkedList *list, unsigned int index) {
    if (list == NULL) return NULL;
    
    //exit if index is out of bounds
    if (index >= list -> size) {
        printf("Cannot get at index %i for length %i!\n", index, list -> size);
        exit(EXIT_FAILURE);
    }
    
    return getNodeData(getNodeAtIndex(list, index));
}

//sets the data at a given index to the data provided
void setAtIndex(LinkedList *list, unsigned int index, void *data) {
    if (list == NULL) return;
    
    //exit if index is out of bounds
    if (index >= list -> size) {
        printf("Cannot set at index %i for length %i!\n", index, list -> size);
        exit(EXIT_FAILURE);
    }
    
    setNodeData(getNodeAtIndex(list, index), data);
}

//returns an int based on if the list contains the given data or not
int contains(LinkedList *list, void *data) {
    if (list == NULL) return -1;
    
    Node *currentNode = list -> head;
    for (int i = 0; i < list -> size; i++) {
        if (currentNode -> data == data) return 1;
        currentNode = currentNode -> next;
    }
    
    return 0;
}

//converts the list to an array
void ** toArray(LinkedList *list) {
    if (list == NULL) return NULL;
    
    void** array = malloc(list->size * sizeof(void *));
    
    Node *currentNode = list -> head;
    for (int i = 0; i < list -> size; i++) {
        array[i] = getNodeData(currentNode);
        currentNode = currentNode -> next;
    }
    
    return array;
}

//prints the list to console
void printList(LinkedList *list, void *printElement(void *)) {
    Node *currentNode = list -> head;
    
    printf("[");
    for (int i =0; i < list -> size; i++) {
        if (list -> tail != currentNode) {
            printElement(currentNode -> data);
            printf(", ");
        } else {
            printElement(currentNode -> data);
            printf("]\n");
        }
    }
}
