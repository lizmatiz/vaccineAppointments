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
    node* removePtr;
    while(head != NULL){
        removePtr = head;
        head = head -> next();
        delete removePtr;
    }
}

void WaitList::load(std::istream& inF){ // load
    Appointment a;
    inF >> a;
    node* holder;
    if(head == NULL){
        head = new node;
        head -> set_data(a);
        head -> set_next(NULL);
    }
    node* cursor = head;
    while(!inF.eof()){
        inF >> a;
        while((cursor -> next()) != NULL){
            cursor = cursor -> next();
        }
        node* holder = new node;
        holder -> set_data(a);
        holder -> set_next(NULL);
        cursor -> set_next(holder);
    }
}

void WaitList::add(Appointment a){
    node* cursor = head;
    if(cursor -> data() >= a){
        node* tmp = new node;
        tmp -> set_data(a);
        tmp -> set_next(head);
        head = tmp;
        return;
    }

    while((cursor -> next()) != NULL && ((cursor -> next()) -> data()) < a ){
        cursor = cursor -> next();
    }

    if((cursor -> next()) == NULL){
        node* tmp = new node;
        tmp -> set_data(a);
        tmp -> set_next(NULL);
        cursor -> set_next(tmp);
    }
    else{
        node* tmp = new node;
        tmp -> set_data(a);
        tmp -> set_next(cursor -> next());
        cursor -> set_next(tmp);
    }
}

void WaitList::display(std::ostream& outs){
    node* iterator = head;
    while(iterator != NULL){
        outs << iterator -> data();
        iterator = iterator -> next();
        outs << endl;
    }
}

Appointment WaitList::find(std::string pName){
    node* iterator = head;
    while(iterator != NULL){
        if(iterator -> data().get_name() == pName){
            return (iterator -> data());
        }
        iterator = iterator -> next();
    }
    return Appointment();
}

void WaitList::remove(std::string patientname){
    if((head -> data()).get_name() == patientname){
        node* tmp = head;
        head = head -> next();
        delete tmp;
    }
    else{
        node* iterator = head -> next();
        node* previous = head;
        while(iterator != NULL){
            if(iterator -> data().get_name() == patientname){
                previous -> set_next(previous -> next() -> next());
                delete iterator;
                iterator = previous -> next();
            }
            else{
                iterator = iterator -> next();
                previous = previous -> next();
            }
        }
    }
}

int WaitList::waiting(){
    int i = 0;
    node* iterator = head;
    while(iterator != NULL){
        i++;
        iterator = iterator -> next();
    }
    return i;
}

unsigned int WaitList::longest_wait(){
    return head -> data().minutes_waiting();
}

unsigned int WaitList::average_wait(){
    node* iterator = head;
    unsigned int total = 0;
    unsigned int count = 0;
    while(iterator != NULL){
        total += iterator -> data().minutes_waiting();
        count ++;
        iterator = iterator -> next();
    }
    return total / count;
}

int WaitList::oldest(){
    Date oldest = (head -> data().get_bday());
    Date current;
    current.make_today();
    node* iterator = head;
    while(iterator != NULL){
        if((iterator -> data().get_bday()) < oldest){
            oldest = iterator -> data().get_bday();
        }
        iterator = iterator -> next();
    }
    return oldest.age(current);
}

int WaitList::youngest(){
    Date youngest = (head -> data().get_bday());
    Date current;
    current.make_today();
    node* iterator = head;
    while(iterator != NULL){
        if((iterator -> data().get_bday()) > youngest){
            youngest = iterator -> data().get_bday();
        }
        iterator = iterator -> next();
    }
    return youngest.age(current);
}

int WaitList::average_age(){
    node* iterator = head;
    int totalAge = 0;
    int totalPeople = 0;
    Date current;
    current.make_today();

    while(iterator != NULL){
        totalAge += iterator -> data().get_bday().age(current);
        totalPeople++;
        iterator = iterator -> next();
    }
    return totalAge / totalPeople;
}

void WaitList::save(std::ostream& outF){
    node* iterator = head;
    while(iterator != NULL){
        outF << iterator -> data();
        iterator = iterator -> next();
    }
}