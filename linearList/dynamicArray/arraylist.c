/**
 * This is my record of learning the C language.
 * If the code is infringing, please contact suprammort@163.com and I will delete it.
 *
 * Sequential storage structure for linear list.
 **/

#include "arraylist.h"
#include "status.h"

/**
 * Initialization
 **/
ArrList * InitArrList(ArrList * list) {
    list->length = 0;
    list->capacity = 20;
    list->pElem = (ElemType *)malloc(sizeof(ElemType) * list->capacity);
    if ( list->pElem == NULL ) {
        printf("Initialization failed!!!\n");
    }

    return list;
}

/**
 *  Destroy list,
 *  and release the memory occupied by the sequence list.
 **/
void DestroyArrList(ArrList * list) {
    if ( list == NULL ) {
        return;
    }
    if ( list->pElem != NULL ) {
        free( list->pElem );
    }
    free(list);
}

/**
 *  Clear list contents
 **/
void ClearArrList(ArrList * list) {
    if ( list == NULL ) {
        return;
    }
    list->length = 0;
}

/**
 *  Empty 
 *
 *  return:
 *  True: The list is empty
 *  False: The list is not empty
 **/
int ListEmpty(ArrList * list) {
    if ( list == NULL ) {
        return 0;
    }
    return list->length == 0 ? 1 : 0;
}

/**
 * Length
 * Returns the number of the valid elements of list.
 **/
int ListLength(ArrList * list) {
    if ( list == NULL ) {
        return 0;
    }
    return list->length;
}

/**
 * Capacity
 **/
int ListCapacity(ArrList * list) {
    if ( list == NULL ) {
        return 0;
    }
    return list->capacity;
}

/**
 * Get a element
 * Get the i-th element in the list and store it in elem.
 **/
ElemType * GetElem(ArrList * list, int i, ElemType * elem) {
    if (list == NULL || i < 1 || i > list->length) {
        return 0;
    }
    *elem = list->pElem[i-1];
    return elem;
}

/**
 * Find
 **/
int LocateElem(ArrList * list, ElemType elem) {
    if ( list == NULL ) {
        return 0;
    }
    int i = 0;
    int pos;
    while ( i <= list->length ) {
        if ( list->pElem[i] == elem ) break;
        ++i;
    }
    if ( i <= list->length ) {
        return i;
    } else {
        return 0;
    }
}

/**
 * Pushback
 **/
void PushbackList(ArrList * list, ElemType value) {
    if ( list == NULL ) {
        return;
    }

    if ( list->length >= list->capacity ) {
        ElemType * newSpace = (ElemType *)realloc(list->pElem, sizeof(ElemType) * list->capacity * 2);
        if ( newSpace == NULL ) {
            exit(OVERFLOW);
        }
        list->pElem = newSpace;
        list->capacity = list->capacity * 2;
    }
    list->pElem[list->length] = value;
    list->length++;
}

/**
 * Insert
 **/
void ListInsert(ArrList * list, int i, ElemType elem) {
    ElemType * pointer1, * pointer2;
    if ( list == NULL || list->length == 0 ) {
        return;
    }
    if ( i < 1 || i > list->length + 1 ) {
        return;
    }

    if ( list->length >= list->capacity ) {
        ElemType * newSpace = (ElemType *)realloc(list->pElem, sizeof(ElemType) * list->capacity * 2);
        if ( newSpace == NULL ) {
            exit(OVERFLOW);
        }
        list->pElem = newSpace;
        list->capacity = list->capacity * 2;
    }
    pointer1 = &list->pElem[i-1];
    pointer2 = &list->pElem[list->length - 1];
    for ( ; pointer2 >= pointer1; --pointer2 ) {
        *(pointer2 + 1) = *pointer2;
    }
    *pointer1 = elem;
    list->length++;
}

/**
 * Delete element
 **/
void ListDelete(ArrList * list, int i) {
    ElemType * p;
    if ( list == NULL || list->length == 0 ) {
        return;
    }
    if ( i < 1 || i > list->length + 1 ) {
        return;
    }
    p = &(list->pElem[i - 1]);
    for ( int j = i-1; j < list->length - 1; j++ ) {
        list->pElem[j] = list->pElem[j+1];
    }
    list->length--;
}

/**
 * Traverse
 **/
void ListTraverse(ArrList * list);

/**
 * Print 
 **/
void ListPrint(ArrList * list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d\t", list->pElem[i]);
    }
    printf("\n");
}

