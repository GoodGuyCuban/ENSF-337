// list.cpp
// ENSF 337 Fall 2021 Lab 8 Exercises C

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA.year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
        
    }
    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}


bool FlowList::remove(const ListItem& itemA)
{
    Node *p = headM;
    Node *q = 0;
    while (p != 0 && p->item.year != itemA.year) {
        q = p;
        p = p->next;
    }
    if (p == 0)
        return false;
    if (q == 0)
        headM = p->next;
    else
        q->next = p->next;
    delete p;
    return true;
}

void FlowList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item.year << " " << headM->item.flow;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item.year << " " << p->item.flow;
    }
    cout << " ]\n";
}


void FlowList::reset()
{
    currentM = headM;
}




ListItem FlowList::next()
{
    if (currentM == 0)
        return ListItem();
    ListItem item = currentM->item;
    currentM = currentM->next;
    return item;
}


bool FlowList::hasNext()
{
    if (currentM == 0)
        return false;
    return true;
}


void FlowList::destroy()
{
    Node *p = headM;
    while (p != 0) {
        Node *q = p->next;
        delete p;
        p = q;
    }
}

void FlowList::copy(const FlowList& source)
{
    if (source.headM == 0)
        headM = 0;
    else {
        headM = new Node;
        headM->item = source.headM->item;
        Node *new_node = headM;
        for (Node *p = source.headM->next; p != 0; p = p->next) {
            new_node->next = new Node;
            new_node = new_node->next;
            new_node->item = p->item;
        }
        new_node->next = 0;
    }
}