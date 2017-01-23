#include<iostream>
#include "HW3P1_LL.h"
using namespace std;


/* ====================================================

HW3P1 llist
Your name: William Ward
Complier:  g++
File type: .cpp

======================================================*/


/*- initialize Front and Rear to be NULL and Count = 0.
  - This does not create any node.  The new list is empty.*/
llist::llist()
{
  Front=NULL;
  Rear=NULL;
  count=0;
}


/*Destructor
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."
*/

llist::~llist()
{
  while (!isEmpty())
    {
      el_t item;
      deleteFront(item);
    }
}


/*- return true if Front and Rear are both pointing to NULL.
  - (note: do not use Count for this!!!)*/
bool llist:: isEmpty()
{
  if(Front==NULL&&Rear==NULL){return true;}

  else {return false;}

}
void llist:: makeNew(el_t NewNum)
{
  Node *P = new Node;
  P->Next = NULL;
  P->Elem = NewNum;
  Front = P;
  Rear = P;
}



/*- displays each element of the list starting from Front in [ ].
  - (special case: if the list is empty, display [ empty ] ).*/
void llist:: displayAll()
{
  if (isEmpty())
    {
      cout << " empty " << endl;
    }
  else
    {
      Node *P = Front; // A temporary pointer used to cycle through the list.

      int i = 0;
      // Print a node, then set the temp pointer to point to that node's Next,
      // repeat until we've gone through all the nodes.
      while (i != count)
        {
          cout << "[ " << P->Elem << " ] ";
          P = P->Next;
          i++;
        }
      cout << endl;
    }
}


/*- 2 cases
- adds a new node at the rear and puts NewNum in the Elem field
  of this new node. Count is updated.
- (special case: if this is going to be the very first node, you must
create a new node and make Front and Rear point to it.)*/


void llist:: addRear(el_t NewNum)
{
  if (isEmpty())
    {
      makeNew(NewNum);
    }
  else
    {
      Rear->Next = new Node;// This will become the new rear.
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
    }
  count++;
}


/*- 3 cases
-  error case: if the List is empty, throw an exception.
-  else give back the front node element through OldNum (pass by reference)
   and also remove the front node. Count is updated.
-  (special case: if this is going to make the list empty,
make sure both Front and Rear become NULL).*/
void llist:: deleteFront(el_t& OldNum)
{
  if (isEmpty())
    {
      throw Underflow(); // The list is empty, you can delete anything from it.
    }
  else
    {
      OldNum = Front->Elem; // This passes the data by-reference back to main.

      if (Front->Next == NULL) // Handles the case where count == 1
        {
          Front = NULL;
          Rear = NULL;
        }
      else // The regular case (eg list has more than one node.)
        {
          Node *P = Front->Next; // temp points to the second node in the list
          delete Front;
          Front = P;// Set the second node to be the new front of the list.
        }
      count--;
    }
}

/*- 2 cases
- will add a new node to the front of the list. Count is updated.
- (special case: if this is going to be the very first node, you must
create a new node and make Front and Rear point to it.)*/
void llist:: addFront(el_t NewNum)
{
  // Node* P;
  // P=new Node;
  if(isEmpty())
    {

      makeNew(NewNum);
    }
  else
    {
      Node* P= new Node;
      P->Next=Front;
      Front=P;
      Front->Elem=NewNum;
    }
  count++;
}


/*- 3 cases
- error case: if empty, throw an exception.
- else give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
- (special case: if this is going to make the list empty,
make sure both Front and Rear become NULL).*/
void llist:: deleteRear(el_t& OldNum)
{
  if (isEmpty())
    {
      throw Underflow(); // The list is empty, you can delete anything from it.
    }
  else
    {
      OldNum = Rear->Elem; // This passes the data by-reference back to main.

      // This is the case in which Count == 1
      if (Front->Next == NULL)
        {
          Front = NULL;
          Rear = NULL;
        }
      else
        {
          Node *P= Front;// Temp will eventually point to the second to last node

          while (P->Next != Rear)
            {
              P=P->Next;
            }

          delete Rear;
          Rear = P;// Set rear to be the second to last node.
          Rear->Next = NULL;
        }

      count--;
    }
}

/*- 4 cases
- will delete the Ith node (I starts out at 1).  Count is updated.
- Error cases:
  If I is an illegal value (i.e. > Count or < 1) throw an exception.
  - (note: this may simply call deleteFront or deleteRear for some cases)*/
void llist:: deleteIth(int I, el_t& OldNum)
{
  if ((I < 1) || (I > count))
    {
      throw OutOfRange(); // The given index is to low or high for our list.
    }
  else if (isEmpty())
    {
      throw Underflow(); // The list is empty, you can delete anything from it.
    }
  else if (I == 1) // This is the case where we are deleting the first node.
    {
      deleteFront(OldNum);
    }
  else if (I == count) // This is the case where we are deleting the last node.
    {
      deleteRear(OldNum);
    }
  else
    {
      Node *P, *P_delete;
      P = Front;

      for (int i = 0; i < I-2; i++)
        {
          P = P->Next;
        }

      P_delete = P->Next;
      OldNum = P_delete->Elem;
      P->Next = P_delete->Next;

      delete P_delete;
      count--;
    }

}
/*- 4 cases
-  will add right before the Ith node.  Count is updated.
-  Error cases:
   If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
   -  (note: this may simply call addFront or addRear for some cases)*/
void llist:: addbeforeIth(int I, el_t NewNum)
{
  if ((I < 1) || (I > count+1))
    {
      throw OutOfRange();
    }
  else if (isEmpty())
    {
      throw Underflow();
    }
  else if (I == 1)
    {
      addFront(NewNum);
    }
  else if (I == count + 1)
    {
      addRear(NewNum);
    }
  else
    {
      Node *P, *P_insert;
      P = Front;

      for (int i = 0; i < I-2; i++)
        {
          P = P->Next;
        }

      P_insert = new Node;
      P_insert->Next = P->Next;
      P->Next = P_insert;
      P_insert->Elem = NewNum;

      count++;
    }
}
