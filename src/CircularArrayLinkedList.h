//
// Created by lenovo on 2.12.2021.
//

#ifndef ASSIGNMENT2_CIRCULARARRAYLINKEDLIST_H
#define ASSIGNMENT2_CIRCULARARRAYLINKEDLIST_H


#include "Employee.h"

struct Nodee{
    Employee *data;
    int next;
};

class CircularArrayLinkedList {
public:
    static const int MAX_NODES = 20;
    Nodee nodes[MAX_NODES];
    int head;
    int rear;

    CircularArrayLinkedList() : rear(-1), head(-1){}

    void append(Employee *x);

    void arrayFiller();

    Nodee *isNumber(int number);

    void deleteEmp(int number);
};


#endif //ASSIGNMENT2_CIRCULARARRAYLINKEDLIST_H
