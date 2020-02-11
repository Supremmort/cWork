/**
 * This is my record of learning the C language.
 * If the code is infringing, please contact suprammort@163.com and I will delete it.
 *
 * Sequential storage structure for linear list.
 **/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType * pElem;   //data address
    int length;           //length of list
    int capacity;       //capacity of list
} ArrList;


/**
 * A series of operations about linear list.
 **/

/**
 * Initialization
 **/
ArrList * InitArrList(ArrList * list);

/**
 *  Destroy list,
 *  and release the memory occupied by the sequence list.
 **/
void DestroyArrList(ArrList * list);

/**
 *  Clear list contents
 **/
void ClearArrList(ArrList * list);

/**
 *  Empty 
 *
 *  return:
 *  True: The list is empty
 *  False: The list is not empty
 **/
int ListEmpty(ArrList * list);

/**
 * Length
 * Returns the number of the valid elements of list.
 **/
int ListLength(ArrList * list);

/**
 * Length
 * Returns the number of the valid elements of list.
 **/
int ListCapacity(ArrList * list);

/**
 * Get a element
 * Get the i-th element in the list and store it in elem.
 **/
ElemType * GetElem(ArrList * list, int i, ElemType * elem);

/**
 * Find
 **/
int LocateElem(ArrList * list, ElemType elem);

/**
 * Pushback
 **/
void PushbackList(ArrList * list, ElemType value);

/**
 * Insert
 **/
void ListInsert(ArrList * list, int i, ElemType elem);

/**
 * Delete element
 **/
void ListDelete(ArrList * list, int i);

/**
 * Traverse
 **/
void ListTraverse(ArrList * list);

/**
 * Print 
 **/
void ListPrint(ArrList * list);


#endif
