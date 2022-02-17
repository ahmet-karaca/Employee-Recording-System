//
// Created by lenovo on 2.12.2021.
//

#include "DoubleDynamicLinkedList.h"

Node::Node(const Employee &empData) : empData(empData) {
    next = NULL;
    previous = NULL;
}

DoubleDynamicLinkedList::DoubleDynamicLinkedList(Node *head) : head(head) {}

DoubleDynamicLinkedList::DoubleDynamicLinkedList() {
    head = NULL;
}

void DoubleDynamicLinkedList::append(Node *node) {
    if (isNumber(node->empData.getEmployeeNumber()) != NULL){
        cout << "Employee with this number already exists." << endl;
        return;
    }
    else{
        if (head == NULL){
            //"Head bos, basa ekleme yapilacak"
            head = node;
        }
        else{
            //"Head bos degil, degil dogru yere ekleme yapilacak"
            //"Date of appointment e gore sirali olacak"
            Node *temp = head;

            bool whileChecker = false;
            bool continueChecker = true;
            while (temp->empData.getEmployeeAppointmentDate() < node->empData.getEmployeeAppointmentDate()){
                whileChecker = true;
                // eger burasi NULL ise yeni eklenen eleman listedeki her elemandan büyüktür
                // break ile döngüyü kiriyorum ama aşagida devam etmesin diye continueChecker yaptım
                if (temp->next == NULL){
                    //"kontrol edilen eleman son eleman"
                    temp->next = node;
                    node->previous = temp;
                    continueChecker = false;
                    break;
                }
                temp = temp->next;
            }
            if (continueChecker){
                // eger whileChecker false ise hic while a girmemistir
                // bu da yeni eklenen eleman listedeki her elemandan kucuktur
                if (!whileChecker){
                    head = node;
                    node->next = temp;
                }
                    // eger whileChecker true ise yeni eklenen eleman listenin ortalarina eklenmistir
                else{
                    node->next = temp;
                    node->previous = temp->previous;
                    temp->previous = node;
                    node->previous->next = node;
                }
            }
        }
    }
}

Node* DoubleDynamicLinkedList::isNumber(int newNumber) {
    Node *temp = NULL;
    Node *node = head;

    while (node != NULL){
        if (newNumber == node->empData.getEmployeeNumber()){
            return node;
        }
        node = node->next;
    }
    return temp;
}

void DoubleDynamicLinkedList::deleteNode(int number){
    Node *node = isNumber(number);
    if (node == NULL){
        //"Bu numara listede yok"
        return;
    }
    else{
        if(node->previous == NULL){
            //"Eleman basta"
            if (node->next == NULL){
                //"Eleman basta ve yalniz"
                head = node->next;
            }
            else{
                head = node->next;
                node->next->previous = NULL;
            }
        }
        else if (node->next == NULL){
            //"Eleman sonda"
            node->previous->next = NULL;
        }
        else{
            //"Eleman ortada"
            node->next->previous = node->previous;
            node->previous->next = node->next;
        }
        //"Node gercekten siliniyor"
        delete(node);
    }
}
