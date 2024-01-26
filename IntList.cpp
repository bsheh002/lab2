#include "IntList.h"

#include <iostream>
#include <exception>

using namespace std;

// This is just for the throws during the
// development phase... it is a turd once
// you remove all the HERE's
#define STRINGIZE(x) #x
#define STR(x) STRINGIZE(x)
#define HERE ("Broken at\n" __FILE__ ":" STR(__LINE__) ": broken")

//#include <iostream>
ostream & operator<<(ostream &out, const IntList &rhs) { //overloads the << operator in order to be used in the context of nodes
    IntNode* curr = rhs.dummyHead.next;
    while(curr != rhs.dummyTail){ //checks to see if at the end of the node list
        out<<curr->data;
        if(curr->next!=rhs.dummyTail){ //checks to see if the next node value is at the end of the list
            out << " ";
        }
        curr= curr->next;
    }
  return out;
}

IntList::~IntList() { //destructor
  while(!empty()){ //continues to pop front a node until list is empty
      pop_front();
  }
}

void IntList::push_front(int value) { // pushes a node to the front of the list
    IntNode* newNode = new IntNode(value);
    newNode->prev =&dummyHead;
    newNode->next =dummyHead.next;
    dummyHead.next->prev = newNode;
    dummyHead.next = newNode;
  throw runtime_error(HERE);
}

void IntList::pop_front() { //removes a node from the front of the list
    if(!empty()){ //makes sure list is not empty before removing nodes
        IntNode* front = dummyHead.next;
        dummyHead.next = front->next;
        front->next->prev = &dummyHead;
        delete front;
    }
  throw runtime_error(HERE);
}

void IntList::push_back(int value) { //pushes a node to the back of the list
    IntNode* newNode = new IntNode(value);
    newNode->next = &dummyTail;
    newNode->prev = dummyTail.prev;
    dummyTail.prev->next = newNode;
    dummyTail.prev = newNode;
  throw runtime_error(HERE);
}

void IntList::pop_back() { //removes a node from the back of the list
    if(!empty()){ //makes sure list is not empty before removing nodes
        IntNode* back = dummyTail.prev;
        dummyTail.prev = back->prev;
        back->prev->next = &dummyTail;
        delete back;
    }
  throw runtime_error(HERE);
}

bool IntList::empty() const { //checks to see if there is a next node in the node list in order to see if it is empty
    if(dummyHead.next == &dummyTail){
        return true;
    }
    else
        return false;
  throw runtime_error(HERE);
}

void IntList::printReverse() const { //prints node elements in reverse
    IntNode* curr = dummyTail.prev;
    while(curr!=&dummyHead){ //makes sure the current node is not equal to dummyHead's address
        cout << curr->data;
        if(curr->prev!=&dummyHead){ //makes sure the previous node is not equal to dummyHead's address
            cout << " ";
        }
        curr = curr-> prev;
    }
  throw runtime_error(HERE);
}

