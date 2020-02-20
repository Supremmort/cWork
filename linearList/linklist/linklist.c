/**
 * Thu, Feb 20 2020
 **/

#include "linklist.h"


// Initation
LinkList * InitLinkList() {

    LinkList * list = (LinkList *)malloc(sizeof(LinkList));
    list->size = 0;

    list->head = (LinkNode *)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
    
    return list;
}

// Insert by position
void InsertLinkList(LinkList * list, int pos, void * data) {

    if (list == NULL || data == NULL) {
        return;
    }
    if (pos < 0 || pos > list->size) {
        return;
    }

    // Create new node
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = NULL;

    // Use pointer to find the inserted position
    LinkNode * pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    // Link the new node
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    list->size++;

}

// Remove the element by position
void RemoveByPosLinkList(LinkList * list, int pos) {

    if (list == NULL) {
        return;
    }
    if (pos < 0 || pos > list->size) {
        return;
    }

    // Use pointer to find the position that need to remove
    LinkNode * pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    // Delet the node
    LinkNode * pDelet = pCurrent->next;
    pCurrent->next = pDelet->next;
    // Free the space of the temporary pointer
    free(pDelet);

    list->size--;

}

// Get the length of the linklist
int SizeLinkList(LinkList * list) {
    if (list == NULL) {
        return 0;
    }

    return list->size;
}

// Get the first node of linklist
void * FirstNodeLinkList(LinkList * list) {

    return list->head->next->data;
}

// Find element and return the poistion of the element
int FindLinkList(LinkList * list, void * data) {

    if (list == NULL || data == NULL) {
        return 0;
    }

    // Use pointer to find the element
    LinkNode * pCurrent = list->head->next;
    int i = 0;
    for (; pCurrent != NULL; i++) {
        if (pCurrent->data == data) {
            break;
        }
        pCurrent = pCurrent->next;
    }

    return i;
}

// Print the node of the linklist
void PrintLinkList(LinkList * list, PRINTLINKLIST print) {

    if (list == NULL) {
        return;
    }

    // Use pointer to visit the element
    LinkNode * pCurrent = list->head->next;
    while (pCurrent != NULL) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }

}

// Free the memory space of the linklist
void FreeLinkList(LinkList * list) {

    if (list == NULL) {
        return;
    }

    LinkNode * pCurrent = list->head;
    while (pCurrent != NULL) {
        LinkNode * pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    // Free list
    list->size = 0;
    free(list);

}


