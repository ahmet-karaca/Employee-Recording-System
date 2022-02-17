//
// Created by lenovo on 2.12.2021.
//

#include "CircularArrayLinkedList.h"

#include <iostream>
using namespace std;


void CircularArrayLinkedList::append(Employee *x){
    if (isNumber(x->getEmployeeNumber()) != NULL){
        cout << "Employee with this number already exists. " << endl;
        return;
    }
    else{
        //cout << "Sirali ekleme" << endl;
        if ((rear + 1) % MAX_NODES == head){
            //"Liste full"
            return;
        }
        if (head < 0) //
        {
            //"Liste bos, ilk ekleme"
            head++;
            rear++;
            nodes[rear].data = x;
            nodes[rear].next = (rear + 1) % MAX_NODES;
        }
        else{
            //"Bos degil, siralama yapilacak"
            bool isSmall;
            //"yeni eleman kucukse en basa degilse donguye girecek"
            isSmall = x < nodes[head].data;
            while(nodes[head].data < x){
                //"yeni eleman ilk elemandan kucuk degil - while a girdi"
                int temp;
                temp = head;
                int temp2;
                temp2 = temp;
                bool isLast = false;
                while (nodes[temp].data < x){
                    temp2 = temp;
                    temp = nodes[temp].next;
                    if (nodes[temp].data == NULL){
                        //"butun liste bitti temp su an bos bir slot"
                        isLast = true;
                        break;
                    }
                }
                if (isLast){
                    rear = (rear + 1) % MAX_NODES;
                    nodes[temp].data = x;
                    nodes[temp].next = (rear + 1) % MAX_NODES;
                    return;
                }
                else{
                    rear = (rear + 1) % MAX_NODES;
                    nodes[temp2].next = rear;
                    nodes[rear].data = x;
                    nodes[rear].next = temp;
                    int temp3;
                    temp3 = rear;
                    while (nodes[temp3].next != rear){
                        temp3 = nodes[temp3].next;
                    }
                    nodes[temp3].next = (rear + 1) % MAX_NODES;
                    return;
                }

            }
            //"yeni eleman kucuk, en basa"
            int temp = nodes[head].next;
            while(nodes[temp].data != NULL){
                temp = nodes[temp].next;
            }
            nodes[temp].data = x;
            nodes[temp].next = head;
            head = temp;
            int temp2 = temp;
            while(nodes[temp2].next != temp){
                temp2 = nodes[temp2].next;
            }
            rear = (rear + 1) % MAX_NODES;
            nodes[temp2].next = (rear + 1) % MAX_NODES;

        }
    }
}

void CircularArrayLinkedList::arrayFiller(){
    for (int i = 0; i < 20; ++i) {
        nodes[i].data = NULL;
    }
}


void CircularArrayLinkedList::deleteEmp(int number) {
    Nodee *node = isNumber(number);
    if (node == NULL){
        //"Bu numara listede yok"
        return;
    }
    else{
        if (head == 0){
            if (rear == 0){
                node->data = NULL;
                head = 0;
                rear = 0;
                return;
            }
        }
    }
}

Nodee *CircularArrayLinkedList::isNumber(int number) {
    int temp = head;
    if (temp == -1){
        //"liste bos"
        return NULL;
    }
    if (nodes[temp].data->getEmployeeNumber() == number){
        return &nodes[temp];
    }
    else{
        while (nodes[temp].data->getEmployeeNumber() != number){
            if (nodes[temp].data->getEmployeeNumber() == number){
                return &nodes[temp];
            }
            if (nodes[temp].next < 0){
                //cout << "0 dan kucuk" << endl;
                return NULL;
            }
            temp = nodes[temp].next;
            if (nodes[temp].data == NULL){
                //cout << "yeni data null" << endl;
                return NULL;
            }
        }
        if (nodes[temp].data->getEmployeeNumber() == number){
            //"eslesme var"
            return &nodes[temp];
        }
        return NULL;
    }
}