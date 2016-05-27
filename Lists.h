#ifndef LISTS_H_
#define LISTS_H_

#include"vehicle.h"





/*
 * Node Declaration
 */
struct node
{
    class Vehicle *info;
    struct node *next;
    struct node *skip = NULL;
};

/*
 * Class Declaration
 */
class single_llist
{
    public:

        //class Vehicle *value=NULL;
        node* start;
        node* create_node();
        void add(Vehicle *recieveValue);
        void print();
        void sort();
        void sortbyID();
        int size();
        single_llist* split();
        void API();
        void deleteSkipListNode(single_llist *mySkipList, int targetID, bool delObj, int range);
        single_llist();
        ~single_llist();
};

class skipList : public single_llist
{
    public:
        skipList(int sortCode, single_llist *parent);
        ~skipList();

};

class SLL : public single_llist
{
    public:
        ~SLL();
};



#endif /* LISTS_H_ */
