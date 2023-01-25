// OLList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
        
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
        // print the list at point two
        //cout << "List after insert at point two: ";
        //print();
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // point three
        if (maybe_doomed != 0 && itemA == maybe_doomed->item) {
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
    if (doomed_node != 0) {
        delete doomed_node;
    }
    // the remaining part of this function is missing. As part of exercise A
    // students are supposed to complete the rest of the definition of this function.
}

void OLList::destroy()
{
    
    // this function is not properly designed. As part of the exercise A
    // students are supposed to remove the folloiwng lines and
    // complete the definition of this helper function.
    // destroy function
    Node *p = headM;
    while (p != 0) {
        Node *doomed = p;
        p = p->next;
        delete doomed;
    }
    headM = 0;
}

void OLList::copy(const OLList& source)
{
    // this function is not properly designed. As part of the exercise A
    // students are supposed to remove the folloiwng lines and
    // complete the definition of this helper function.
    
    // The only effect of the next line is to tell the compiler
    // not to generate an "unused argument" warning.  Don't leave it
    // it in your solution.
    
    // copy function
    headM = 0;
    if (source.headM == 0)
        return;

    headM = new Node;
    headM->item = source.headM->item;
    Node *p = headM;
    
    for (Node *q = source.headM->next; q != 0; q = q->next) {
        p->next = new Node;
        p = p->next;
        p->item = q->item;
    }
    p->next = 0;
}


