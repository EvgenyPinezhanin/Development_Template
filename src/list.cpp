#include<iostream>
#include"list.h"

using namespace std;

List::List()
{
    first = nullptr;
    size = 0;
}

void List::addNode(Node *nd) {   
    if (first == nullptr) {   
        first = nd;
    } else {
        Node *current = first;
        while (current->next != nullptr)
            current = current->next;
        current->next = nd;
    }
    size++;
}

Node* List::getPointer(int pos) {           
    if (pos == 0) {
        return first;
    }     
    Node *current = first;
    int count = 1;
    while(current->next != nullptr) {
        current = current->next;
        if (count == pos) {
            return current;
        }
        count++;
    }
    return current;   
}

bool List::CheckLoop1()
{
    Node * nd1 = nullptr;
    Node * nd2 = nullptr;
    if (first == nullptr) return false;
    nd1 = first;
    if (nd1->next == nullptr) return false;
    nd2 = nd1 ->next;
    while(true)
    {
        if (nd2->next != nullptr) nd2 = nd2->next;
            else return false;
        if (nd2->next != nullptr) nd2 = nd2->next;
            else return false;
        nd1 = nd1->next;
        if (nd1 == nd2) return true;
    }
}

bool List::CheckLoop2() {
    Node * nd = nullptr;
    Node * ndOld = nullptr;
    if (first == nullptr) return false;
    nd = first;
    ndOld = first;
    int count = 1;
    while(true) {
        for (int i = 0; i < count; i++) {
            if (nd -> next != nullptr) nd = nd ->next;
                else return false;
            if (nd == ndOld) return true;
        }
        ndOld = nd;
        count++;
    }
}

bool List::CheckLoop3() {
    Node * ndOld = nullptr;
    Node * ndCurr = nullptr;
    Node * ndNext = nullptr;
    bool isLoop = false;
    if (first == nullptr) return false;
    if (first->next == nullptr) return false;
    ndCurr = first;
    ndNext = first->next;
    while(true) {
        ndCurr->next = ndOld;
        if (ndNext == nullptr) {
            if (ndCurr == first) { 
                isLoop = true; 
            }
            Node *tmp = ndNext;
            ndNext = ndOld;
            ndOld = tmp;
            break;
        }
        ndOld = ndCurr;
        ndCurr = ndNext;
        ndNext = ndNext->next;
    }

    while(true) {
        ndCurr->next = ndOld;
        if (ndNext == nullptr) {
            break;
        }
        ndOld = ndCurr;
        ndCurr = ndNext;
        ndNext = ndNext->next;
    }

    return isLoop;
}

ostream& operator<<(ostream& ostr, const List& l) {
    Node *tmp = l.first;
    for (int i = 0; i < l.size; i++) {
        ostr << tmp->value << " ";
        tmp = tmp->next;
    }
    return ostr;
}