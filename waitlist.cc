#include "node.h"
#include "waitlist.h"
#include <iostream>

using namespace std;

WaitList::WaitList(){ // 
    head = NULL;
}

WaitList::WaitList(const WaitList& w){ // copy constructor

}


WaitList::~WaitList(){ // destructor

}

void WaitList::load(std::istream& inF){ // load
        Appointment a;
   
        inF >> a;
        node* holder;
        if(head == NULL){
            head = new node;
            head -> set_data(a);
            head -> set_next(NULL);
            cout << "got here" << endl;
        }
        node* cursor = head;
        while(!inF.eof()){
            inF >> a;
            //cout << a;
            while((cursor -> next()) != NULL){
                cursor = cursor -> next();
            }
            node* holder = new node;
            holder -> set_data(a);
            holder -> set_next(NULL);
            cursor -> set_next(holder);
        }
}

void WaitList::save(std::ostream& outF){
    node* iterator = head;
    while((iterator -> next()) != NULL){
        outF << iterator -> data();
        iterator = iterator -> next();
    }
}



/*
            inF >> a;
            node* iterator = head;
            node* iteratorNext;
            //Appointment b;
            while(a.get_callin() > iterator -> data().get_callin()){
                iterator = iterator -> next();
            }
            iteratorNext = iterator -> next();
            iterator -> set_next(new node);
            iterator -> next() -> set_data(a);
            iterator -> next() -> set_next(iteratorNext);
            cout << "another node" << endl;

            // create a new node and set data in it whi
            // set the new nodes next equal to iterators next
*/