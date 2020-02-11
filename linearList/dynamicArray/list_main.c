#include <stdio.h>
#include "arraylist.h"
#include "arraylist.c"
#include "status.h"


void test01() {
    ArrList * list = (ArrList *)malloc(sizeof(ArrList));
    list = InitArrList(list);
    printf("The capacity of list is: %d\n", ListCapacity(list));
    printf("The length of list is: %d\n", ListLength(list));
    // insert element
    for ( int i = 0; i < 30; i++ ) {
        PushbackList(list, i);
    }
    printf("The capacity of list is: %d\n", ListCapacity(list));
    printf("The length of list is: %d\n", ListLength(list));
    ListDelete(list, 4);
    ListPrint(list);

    int pos = LocateElem(list, 13);
    printf("The position of 13 is: %d\n", pos);
    ListPrint(list);
    DestroyArrList(list);
} 

int main(int argc, char** argv) {
    
    test01();

    return 0;
}
