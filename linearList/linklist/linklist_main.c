/**
 * Thu, Feb 20 2020
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
#include "linklist.c"

typedef struct Student {
    char name[10];
    int age;
    int score;
}student;


void MyPrint(void * data) {
    student * p = (student *)data;
    printf("%s\t%d\t%d\n", p->name, p->age, p->score);
}


int main() {

    LinkList * list = InitLinkList();

    student stu1 = { "AAA", 18, 100 };
    student stu2 = { "BBB", 20, 99  };
    student stu3 = { "CCC", 19, 87  };
    student stu4 = { "SSS", 19, 100 };
    student stu5 = { "XXX", 18, 99  };

    InsertLinkList(list, 0, &stu1);
    InsertLinkList(list, 0, &stu2);
    InsertLinkList(list, 0, &stu3);
    InsertLinkList(list, 0, &stu4);
    InsertLinkList(list, 0, &stu5);

    printf("name\tage\tscore\n");
    PrintLinkList(list, MyPrint);

    // Remove student3
    printf("***********************\n");
    RemoveByPosLinkList(list, 3);
    PrintLinkList(list, MyPrint);

    printf("***********************\n");
    student * stud = (student *)FirstNodeLinkList(list);
    printf("%s\t%d\t%d\n", stud->name, stud->age, stud->score);

    FreeLinkList(list);

    return 0;
}
