// list.h
// ENSF 337 Fall 2021 Lab 8 Exercises C


#ifndef List_H
#define List_H

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList {
public:
    FlowList();
    FlowList(const FlowList& source);
    FlowList& operator =(const FlowList& rhs);
    ~FlowList();
    void insert(const ListItem& itemA);
    bool remove(const ListItem& itemA);
    void print() const;
    
    void reset();
    
    ListItem next();
    bool hasNext();
    
private:
    Node *headM;
    Node *currentM;
    void destroy();
    void copy(const FlowList& source);
};

#endif /* List_H */