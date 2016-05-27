/*
 * This program utilizes some code found online at http://www.sanfoundry.com/cpp-program-implement-single-linked-list/
 */

#include "Lists.h"

using namespace std;

//Constructor
single_llist::single_llist()
{

    start = NULL;
}

//Base Class Destructor  - Gets automatically called when deleting an inherited class
single_llist::~single_llist()
{
}
// SLL Destructor
SLL::~SLL()
{
    int i=0;
    int j=0;
    if (start != NULL)
    {
		struct node *p;
		p = start;
		while (p->next != NULL)
		{
			p = start->next;
			//delete start->info;
			//delete start->skip;
			delete start->info;
			delete start;

			//cout << "SLL Node Deleted." << endl <<"SLL Object Deleted" <<endl;
			start = p;
			i++;j++;
		}
		delete start->info;
		delete start;
        //cout << "SLL Node Deleted." << endl <<"SLL Object Deleted" <<endl;
        i++;j++;
		//cout<< i << " Nodes deleted this SLL. " << j << " Objects deleted this SLL" <<endl;
    }
}

//SkipList Destructor
skipList::~skipList()
{
    int i=0;
    if (start != NULL)
    {
		struct node *p;
		p = start;
		while (p->next != NULL)
		{
			p = start->next;
			delete start;
			//cout << "Skip List Node Deleted." << endl;
			start = p;
			i++;
		}
    }
		delete start;
		i++;
		//cout << i << " Nodes deleted for this skipList " << endl;

}

/*
 * Inserts element at the end of the linked list
 */
void single_llist::add(Vehicle* receiveValue)
{
    struct node *temp, *p;
    struct node *t;
    if (start == NULL)
    {
        start = new(struct node);
        start->info = receiveValue;
        start->next = NULL;
        start->info->index++;
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            p = p->next;
        }
        t=new(struct node);
        p->next=t;
        t->info=receiveValue;
        t->next = NULL;
        t->info->index++;
    }

}
/*
 * Return size of linked list
 */
int single_llist::size()
{
    struct node *temp;
    int i=1;
    if (start == NULL)
        return 0;
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
}

/*
 * Display Elements of a link list
 */
void single_llist::print()
{
    struct node *temp;
    if (size() == 0)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    else{
        temp = start;
        cout<<endl << "Elements of list are: "<<endl;
        int i =1;
        while (temp != NULL)
        {
            cout << endl << "VEHICLE " << i << ":" << endl;
            temp->info->print();
            temp = temp->next;
            i++;
        }
        //cout<<"NULL"<<endl;

    }
}

/*
 * Split linked list into two halves and returns a pointer to new list
 */

single_llist* single_llist::split()
{
    single_llist* half;
    int i=1;

    if (start==NULL){
        cout << endl << "Unable to split. List is empty. Returning pointer to new empty list." << endl;
        half = new single_llist();
        return half;
        }
    else{
        struct node *p, *temp;
        p=start;
        while (i<size()/2)
        {
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = NULL;
        half = new single_llist();
        half->start = temp;
        return half;
    }
}
//Sorts LL by carrying capacity
void single_llist::sort() {
    struct node *ptr, *s;
    Vehicle *value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info->GetcarryingCapacity() > s->info->GetcarryingCapacity())
            {
                value = ptr->info;
                ptr->info=s->info;
                s->info=value;
            }
        }
        ptr = ptr->next;
    }
}
//sorts LL by ID
void single_llist::sortbyID() {
    struct node *ptr, *s;
    Vehicle *value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info->GetID() > s->info->GetID())
            {
                value = ptr->info;
                ptr->info=s->info;
                s->info=value;
            }
        }
        ptr = ptr->next;
    }
}
//skiplist constructor
skipList::skipList(int sortCode, single_llist *parent)
{
    node *p, *t;
    node *popper = parent->start->skip;
    std::string *temp, *test;
    char tempC, testC;
    int tempInt, testInt;
    p = parent->start;
    if (sortCode == 1) //determine what you're sorting by.
        temp = p->info->Getmake();
    else if (sortCode==2)
        tempC = p->info->GetengineType();
    else if (sortCode==3)
        tempInt = p->info->GetcarryingCapacity();

    if(sortCode==1 || sortCode ==2){    //if sorting by make or engine, just add the first object of the list. 1=make 2=enginetype 3=CC
        add(p->info);
        p = p->next;
    }
    int checker =0;
    while (p != NULL)
    {
        if (sortCode == 1)
        {
            test = p->info->Getmake();
            if (temp->compare(*test) == 0)
                add(p->info);
            else
            {
                checker++;
                if (checker == 1)
                    parent->start->skip = p;
            }
        }
        else if (sortCode == 2)
        {
            testC = p->info->GetengineType();
            if (tempC == testC)
                add(p->info);
            else
            {
                checker++;
                if (checker == 1)
                    parent->start->skip = p;
            }
        }
        else if (sortCode == 3)
        {
            node *p = parent->start;
            while(p!=NULL)
            {
                add(p->info);
                p=p->next;
            }

            break;
        }

        if(sortCode != 3)
            p = p->next;
    }

    p=parent->start->skip;


    if (sortCode == 1)
        temp = p->info->Getmake();

    else if(sortCode == 2)
        tempC = p->info->GetengineType();
    else if(sortCode == 3)
        tempInt = p->info->GetcarryingCapacity();

        while (p != NULL)
        {
            if(sortCode==3)
                break;
            add(p->info);
            parent->start->skip = NULL;
            checker =sortCode -1;
            t=p->next;
            temp = p->info->Getmake();
            tempC = p->info->GetengineType();
            while (t != NULL)
            {
                if (sortCode == 1)
                {
                     test = t->info->Getmake();
                    if (temp->compare(*test) == 0)
                    {
                        if (t->info->index == sortCode)
                            add(t->info);
                        t = t->next;
                    }
                    else
                    {
                        int n = t->info->index;
                        if(n == 1)
                        {
                            checker++;
                            if (checker == 1)
                                {
                                    parent->start->skip = t;
                                }
                        }
                        t=t->next;
                    }
                }
                else if (sortCode == 2)
                {
                     testC = t->info->GetengineType();
                    if (tempC == testC)
                        {
                            if(t->info->index == sortCode)
                                add(t->info);
                            t = t->next;
                        }
                    else
                    {
                        int n = t->info->index;
                        if(n == sortCode)
                        {
                            checker++;
                            if (checker == sortCode)
                            {
                                parent->start->skip = t;
                            }
                        }
                        t=t->next;
                    }
                }
                else if (sortCode == 3)
                {
                     testInt = t->info->GetcarryingCapacity();
                    if (tempInt == testInt)
                        {
                            if(t->info->index == sortCode)
                                add(t->info);
                            t = t->next;
                        }
                    else
                    {
                        int n = t->info->index;
                        if(n == sortCode)
                        {
                            checker++;
                            if (checker == sortCode)
                            {
                                parent->start->skip = t;
                            }
                        }
                        t=t->next;
                    }
                }

            }
                p=parent->start->skip;
                if (size() == parent->size())
                    {
                        parent->start->skip = popper;
                        break;
                    }
            parent->start->skip = popper;
        }
        p = start;
        t = start;
        temp = p->info->Getmake();
        tempC = p->info->GetengineType();
        tempInt = p->info->GetcarryingCapacity();
        if(sortCode == 3)
            this->sort();
        while(p!= NULL)
        {
            if(sortCode == 1)
            {
                if(t == NULL)
                    break;
                test = t->info->Getmake();
                if (temp->compare(*test) == 0)
                    t = t->next;
                else
                {
                    p->skip = t;
                    p=t;
                    t=t->next;
                    if (p != NULL)
                        temp = p->info->Getmake();
                }
            }
            else if(sortCode == 2)
            {
                if(t == NULL)
                    break;
                testC = t->info->GetengineType();
                if (tempC == testC)
                    t = t->next;
                else
                {
                    p->skip = t;
                    p=t;
                    t=t->next;
                    if (p != NULL)
                        tempC = p->info->GetengineType();
                }
            }
            else if(sortCode == 3)
            {
                if(t == NULL)
                    break;
                testInt = t->info->GetcarryingCapacity();
                if (t->info->GetcarryingCapacity()  == p->info->GetcarryingCapacity()){
                    t = t->next;
                    testInt = t->info->GetcarryingCapacity();
                }
                else
                {
                    p->skip = t;
                    p=t;
                    tempInt = p->info->GetcarryingCapacity();
                    t=t->next;
                    if (p != NULL)
                        tempInt = p->info->GetcarryingCapacity();
                }
            }
        }

}
//delete skip list node function
void single_llist::deleteSkipListNode(single_llist *mySkipList, int targetID, bool delObj, int range)
{
    node *p, *curr, *prev;
    prev = NULL;
    bool del = true;
    bool delAtStart = false;
    p=mySkipList->start;
    int info = p->info->GetID();
    if (info == targetID)
    {
        delAtStart = true;
        curr = p;
        //if (curr->skip !=NULL)
           // if(curr->next->info->GetID() == curr->info->GetID())
           //     curr->next->skip = curr->skip;
    }
    else
    {
        while(info != targetID)
        {
            prev = p;
            p = p->next;
            if(p==NULL)
            {
                cout << "No Results found in this range." <<endl;
                del = false;
                break;
            }
            info = p->info->GetID();
        }
        curr = p;
    }
    if(del)
    {
        if(prev != NULL)
            prev->next = curr->next;
        if (curr->skip !=NULL){
            if(curr->next->info->GetID() == curr->info->GetID())
                curr->next->skip = curr->skip;
            else
            {
                p = mySkipList->start;
                node *pss = p->skip->skip;
                node *css = curr->skip;
                if(!delAtStart){
                    p=p->skip;
                    while(p != curr->skip)
                        p=p->skip;
                }
                else if (delAtStart && curr->next->skip == NULL){
                    curr->next->skip=curr->skip;
                    //mySkipList->start = curr->next;
                }

                p->skip=curr->skip;
            }
        }
        if(curr->next == NULL)
            prev->next = NULL;

        if(delAtStart)
            mySkipList->start = curr->next;
        if (delObj == true){
            delete curr->info;
            cout << "Vehicle " <<targetID << " deleted." <<endl;
        }
        delete curr;
        if(range){
            //configure skip nodes

            p=mySkipList->start;

            while(p != NULL){
                p->skip=NULL;
                p=p->next;
            }

            p=mySkipList->start;
            prev = p;
            p=p->next;
            while(p != NULL){
                if(prev->info->GetcarryingCapacity() != p->info->GetcarryingCapacity()){
                    prev->skip = p;
                    p=p->next;
                    prev=prev->next;
                }
                else{
                    node *temp = p->next;
                    while(temp->info->GetcarryingCapacity() == prev->info->GetcarryingCapacity() || temp == NULL)
                        temp = temp->next;
                    prev->skip = temp;
                    p=prev->skip->next;
                    prev=prev->skip;
                }

            }
            //p->skip=p->next;
        }
    }
}
//Creates list from file and implements User Interface
void single_llist::API()
{
    SLL *allVehicles;
    skipList *byMake, *byEngineType, *byCarryingCapacity;
    Vehicle *newCar;
    string input, command, IDvalue, makeValue, modelValue, typeValue, CCValue, CRValue;
    char foo;
    allVehicles = newCar->readFile();
    byMake = new skipList(1, allVehicles);
    //byMake->print();
    byEngineType = new skipList(2, byMake);
    //byEngineType->print();
    byCarryingCapacity = new skipList(3, byEngineType);
    byCarryingCapacity->sort();
    allVehicles->sortbyID();
    //byCarryingCapacity->print();

    while(1)
    {
        cout << "Welcome. Please enter a command. Type \"h\" for help." << endl;
        getline(cin, input);
        std::size_t found = input.find("add");
        size_t temp;
        if(found == 0)//if "add" is found at beginning
        {
            bool dup = false;
            found = input.find(char(32), 4);
            IDvalue = input.substr(4, (found - 4));
            temp = found+1;
            //cout << "ID= " << IDvalue <<endl;

            found = input.find(char(32), found+1);
            makeValue = input.substr(temp, (found - temp));
            temp = found+1;
            //cout << "Make= " << makeValue<<endl;

            found = input.find(char(32), found+1);
            modelValue = input.substr(temp, (found - temp));
            temp = found+1;
            //cout << "Model= " << modelValue<<endl;

            found = input.find(char(32), found+1);
            typeValue = input.substr(temp, (found - temp));
            temp = found+1;
            //cout << "Type= " << typeValue<<endl;

            found = input.find(char(32), found+1);
            CCValue = input.substr(temp, (found - temp));
            temp = found+1;
            //cout << "CC= " << CCValue<<endl;

            found = input.find(char(32), found+1);
            CRValue = input.substr(temp, (found - temp));
            temp = found+1;
            //cout << "CR= " << CRValue<<endl;

            char typeChar = typeValue[0];
            int IDInt = newCar->stringToInt(IDvalue);
            int CCInt = newCar->stringToInt(CCValue);
            int CRInt = newCar->stringToInt(CRValue);
            //cout << IDInt << endl << CCInt << endl << CRInt<<endl;

            newCar = new Vehicle(IDInt, makeValue, modelValue, typeChar, CCInt, CRInt);
            node *p,*q;
            p=allVehicles->start;
            while(p->info->GetID() <= IDInt){
                if (p->info->GetID() == IDInt){
                    dup = true;
                    break;}
                p=p->next;
            }
            if (dup)
                cout << "Could not add duplicate ID. Please try again." << endl;
            else{
                allVehicles->add(newCar);

                //Adding vehicle to Skip Lists

                string *newMake, *oldMake;
                newMake = newCar->Getmake();
                p=byMake->start;
                while (p!=NULL)  //to byMake
                {
                    oldMake = p->info->Getmake();
                    if(newMake->compare(*oldMake)==0)
                    {
                        q=p->next;
                        p->next = new (struct node);
                        p->next->info = newCar;
                        p->next->next = q;
                        break;
                    }
                    else
                    {
                        if(p->skip == NULL){
                            byMake->add(newCar);
                            q=p;
                            while(q->next != NULL)
                            {
                                q=q->next;
                            }
                            p->skip = q;
                            break;
                        }
                        else
                            p=p->skip;
                    }
                }
                p=byEngineType->start;
                while(p!=NULL)  //to byEngineType
                {
                    if(newCar->GetengineType() == p->info->GetengineType())
                    {
                        q=p->next;
                        p->next = new (struct node);
                        p->next->info = newCar;
                        p->next->next = q;
                        break;
                    }
                    else
                    {
                        if(p->skip == NULL){
                            byEngineType->add(newCar);
                            q=p;
                            while(q->next != NULL)
                            {
                                q=q->next;
                            }
                            p->skip = q;
                            break;
                        }
                        else
                            p=p->skip;
                    }
                }
                p=byCarryingCapacity->start;
                while(p!=NULL)  //to byCarryingCapacity
                {
                    if((newCar->GetcarryingCapacity() - p->info->GetcarryingCapacity())*(newCar->GetcarryingCapacity() - p->info->GetcarryingCapacity()) <= 10000)
                    {
                        q=p->next;
                        p->next = new (struct node);
                        p->next->info = newCar;
                        p->next->next = q;
                        break;
                    }
                    else
                    {
                        if(p->skip == NULL){
                            byCarryingCapacity->add(newCar);
                            q=p;
                            while(q->next != NULL)
                            {
                                q=q->next;
                            }
                            p->skip = q;
                            break;
                        }
                        else
                            p=p->skip;
                    }
                }
                byCarryingCapacity->sort();
                cout << makeValue << " " << modelValue << " added to list." << endl;
                //allVehicles->print();
            }
        }
        else if(!input.find("delete"))
        {
            found = input.find("delete");   //if 'delete' command
            string searchTerm;
            if (found == 0)
            {
                found = input.find(char(32), 7);
                command = input.substr(7, found);
                int targetID = newCar->stringToInt(command);
                deleteSkipListNode(byMake, targetID, 0, 0);
                deleteSkipListNode(byCarryingCapacity, targetID, 0, 1);
                deleteSkipListNode(byEngineType, targetID, 0, 0);
                deleteSkipListNode(allVehicles, targetID, true, 0);
            }
        }
        else if(!input.find("allVehicles")){ //print all vehicles
            allVehicles->sortbyID();
            allVehicles->print();
        }
        else if(input == "h"){ //help menu lists all commands
            cout << "API Commands: " <<endl<<"1) allVehicles | view all vehicles by ID." << endl << "2) byMake Make | view all vehicles with make \"Make\" " <<endl
            << "3) byEngineType G | view all vehicles with engine type G" << endl << "4) byCarryingCapacity 600 | view all vehicles with +/- 100 pounds carrying capacity of 600." << endl <<
            "5) add 11 Toyota Camry G 650 5 | add vehicle with properties: ID, Make, Model, Engine Type, Carrying Capacity: 650, Customer Rating" << endl <<
            "6) delete 11 | delete vehicle w/ ID 11" << endl << "7) t | Terminate program" << endl << "Commands are case sensitive." << endl;
        }
        else if(!input.find("t") || !input.find("by"))
        {
            found = input.find("t"); //terminate if t
            if (found == 0)
                break;
            else
            {
                found = input.find("by");   //if 'by' command
                string searchTerm;
                if (found == 0)
                {
                    found = input.find(char(32), 0);
                    command = input.substr(0, found);
                    temp = found+1;
                    if (command == "byMake")    //byMake
                    {
                        found = input.find(char(32), temp);
                        searchTerm = input.substr(temp, found-temp);
                        node *p, *q;
                        p = byMake->start;
                        string *info = p->info->Getmake();
                        if (*info == searchTerm)
                            {
                                while(*info == searchTerm)
                                      {
                                            p->info->print();
                                            p=p->next;
                                            info = p->info->Getmake();
                                      }
                            }
                            else
                            {
                                while(*info != searchTerm)
                                {
                                    p = p->skip;

                                    if (p==NULL){
                                        cout << "Error. No Vehicles found." << endl;
                                        break;
                                    }
                                    info = p->info->Getmake();
                                }
                                while(*info == searchTerm)
                                {
                                    p->info->print();
                                    p=p->next;
                                    if(p==NULL)
                                        break;
                                    info = p->info->Getmake();
                                }
                            }
                    }
                    else if (command == "byEngineType")    //byEngineType
                    {
                        found = input.find(char(32), temp);
                        searchTerm = input.substr(temp, found-temp);
                        char searchC = searchTerm[0];
                        node *p, *q;
                        p = byEngineType->start;
                        char info = p->info->GetengineType();
                        if (info == searchC)
                        {
                            while(info == searchC)
                                  {
                                        p->info->print();
                                        p=p->next;
                                        info = p->info->GetengineType();
                                  }
                        }
                        else
                        {
                            int i =0;
                            while(info != searchC)
                            {
                                p = p->skip;
                                if(p==NULL){
                                    cout << "No results found." << endl;
                                    break;
                                }
                                info = p->info->GetengineType();
                                i++;

                            }
                            while(info == searchC)
                            {
                                p->info->print();
                                p=p->next;
                                if (p == NULL)
                                    break;
                                info = p->info->GetengineType();
                            }
                        }
                    }
                    else if (command == "byCarryingCapacity") //byCarryingCapacity
                    {
                        found = input.find(char(32), temp);
                        searchTerm = input.substr(temp, found-temp);
                        int searchInt = newCar->stringToInt(searchTerm);
                        node *p, *q;
                        p=byCarryingCapacity->start;
                        int info = p->info->GetcarryingCapacity();
                        if ((info - searchInt)*(info - searchInt) <= 10001)
                            {
                                while((info - searchInt)*(info - searchInt) <= 10001)
                                      {
                                            p->info->print();
                                            p=p->next;
                                            info = p->info->GetcarryingCapacity();
                                      }
                            }
                        else
                        {
                            int i=0;
                            while((info - searchInt)*(info - searchInt) >= 10001)
                            {
                                p = p->skip;
                                if(p==NULL)
                                {
                                    cout << "No Results found in this range." <<endl;
                                    break;
                                }
                                info = p->info->GetcarryingCapacity();
                                i++;
                                if(i>byCarryingCapacity->size())
                                {
                                    cout << "No Results found in this range." <<endl;
                                    break;
                                }
                            }
                            while((info - searchInt)*(info - searchInt) <= 10001)
                            {
                                p->info->print();
                                p=p->next;
                                if (p == NULL)
                                    break;
                                info = p->info->GetcarryingCapacity();
                            }
                        }
                    }
                }

            }
        }
        else
        {
            cout << "Invalid command. Enter a valid command or enter h for help." << endl;
        }
    }
    delete byMake;
    delete byEngineType;
    delete byCarryingCapacity;
    delete allVehicles;
}



