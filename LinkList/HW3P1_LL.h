/* ====================================================

HW3P1 llist
Your name: William Ward
Complier:  g++
File type: .h

======================================================*/

#ifndef HW3P1_LL_H
#define HW3P1_LL_H
#include<vector>
typedef int el_t ;

struct Node
{
  el_t Elem;
  Node* Next;
  // Node* Prev;
};



class llist
{

 protected:

  Node *Front;       // front  pointer
  Node *Rear;        // rear   pointer
  int  count;        // counter for the number of elements
  void makeNew(el_t NewNum);
 public:

  class Underflow {};
  class OutOfRange {};

  llist ();                       // constructor
  ~llist();                       // destructor

  bool isEmpty();

  void displayAll();

  void addRear(el_t NewNum);

  void deleteFront(el_t& OldNum);

  void addFront(el_t NewNum);

  void deleteRear(el_t& OldNum);

  void deleteIth(int I, el_t& OldNum);

  void addbeforeIth(int I, el_t newNum);

};

#endif
