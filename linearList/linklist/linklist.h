/**
 * Thu, Feb 20 2020
 **/


/**
 * Thinking:
 * 1.Create the struct of node for the linklist.
 * 2.Create the struct of the linklist.
 * 3.Declare the operation of the linklist.
 **/
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

// the code of linklist
typedef struct LINKNODE {
    void * data;
    struct LINKNODE * next;
}LinkNode;

// the struct of linklist
typedef struct LINKLIST {
    LinkNode * head;
    int size;
}LinkList;

// Print the pointer of function
typedef void(*PRINTLINKLIST) (void*);

// Initation
LinkList * InitLinkList();

// Insert by position
void InsertLinkList(LinkList * list, int pos, void * data);

// Remove the element by position
void RemoveByPosLinkList(LinkList * list, int pos);

// Get the length of the linklist
int SizeLinkList(LinkList * list);

// Get the first node of linklist
void * FirstNodeLinkList(LinkList * list);

// Find element and return the poistion of the element
int FindLinkList(LinkList * list, void * data);

// Print the node of the linklist
void PrintLinkList(LinkList * list, PRINTLINKLIST print);

// Free the memory space of the linklist
void FreeLinkList(LinkList * list);

#endif


#ifndef NULL
#define NULL ((void*)0)
#endif
