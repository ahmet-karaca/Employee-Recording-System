//
// Created by lenovo on 2.12.2021.
//

#ifndef ASSIGNMENT2_DOUBLEDYNAMICLINKEDLIST_H
#define ASSIGNMENT2_DOUBLEDYNAMICLINKEDLIST_H


#include<iostream>
#include "Employee.h"

using namespace std;

struct Node {
    Employee empData;
    Node * next;
    Node * previous;

    Node(const Employee &empData);
};

class DoubleDynamicLinkedList {

public:

    Node * head;

    DoubleDynamicLinkedList(Node *head);

    DoubleDynamicLinkedList();

    void append(Node *node);

    Node* isNumber(int newNumber);

    void deleteNode(int number);
};


#endif //ASSIGNMENT2_DOUBLEDYNAMICLINKEDLIST_H
