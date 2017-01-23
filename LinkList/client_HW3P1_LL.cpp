/* ====================================================

HW3P1 llist
Your name: William Ward
Complier:  g++
File type: .cpp

======================================================*/



#include <iostream>
#include "HW3P1_LL.h"
using namespace std;

void case1()
{
  llist ll;

  if (ll.isEmpty())
    {
      cout << "List is empty" << endl;
    }
  else
    {
      cout << "List is not empty" << endl;
    }

  ll.displayAll();

  ll.addRear(1);
  ll.addRear(2);
  ll.addRear(3);

  ll.displayAll();

  el_t elem;
  ll.deleteFront(elem);
  cout << elem << endl;
  ll.deleteFront(elem);
  cout << elem << endl;

  ll.displayAll();

  if (ll.isEmpty())
    {
      cout << "List is empty" << endl;
    }
  else
    {
      cout << "List is not empty" << endl;
    }

  ll.deleteFront(elem);
  cout << elem << endl;

  if (ll.isEmpty())
    {
      cout << "List is empty" << endl;
    }
  else
    {
      cout << "List is not empty" << endl;
    }
}
void case2()
{
  llist ll = llist();

  ll.addFront(5);
  ll.addFront(4);

  el_t elem;
  ll.deleteFront(elem);

  ll.addRear(6);
  ll.addRear(8);
  ll.addRear(9);

  ll.displayAll();

  ll.addbeforeIth(1, 4);
  ll.addbeforeIth(4, 7);
  ll.addbeforeIth(7, 10);

  try
    {
      ll.addbeforeIth(9, 12);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  try
    {
      ll.addbeforeIth(0, 0);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  ll.displayAll();

  ll.deleteIth(1, elem);
  cout << elem << endl;
  ll.deleteIth(6, elem);
  cout << elem << endl;
  ll.deleteIth(3, elem);
  cout << elem << endl;

  try
    {
      ll.deleteIth(5, elem);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  try
    {
      ll.deleteIth(0, elem);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  ll.displayAll();
  while (!ll.isEmpty())
    {
      ll.deleteRear(elem);
      cout << elem << endl;
    }

  ll.displayAll();
}
void case3()
{
  llist ll = llist();

  try
    {
      ll.addbeforeIth(0, 0);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  el_t elem;
  try
    {
      ll.deleteFront(elem);
    }
  catch (llist::Underflow)
    {
      cout << "The list is currently empty." << endl;
    }
}
void case4()
{
  llist ll = llist();

  el_t elem;
  try
    {
      ll.deleteIth(2, elem);
    }
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  try
    {
      ll.deleteRear(elem);
    }
  catch (llist::Underflow)
    {
      cout << "The list is currently empty." << endl;
    }
}
int main()
{
  cout << "**** case 1 ****" << endl;
  case1();
  cout << "**** End of case 1 ****" << endl;

  cout << "****  case 2 ****" << endl;
  case2();
  cout << "**** End of case 2 ****" << endl;

  cout << "**** case 3 ****" << endl;
  case3();
  cout << "**** End of case 3 ****" << endl;

  cout << "****  case 4 ****" << endl;
  case4();
  cout << "**** End of case *****" << endl;

  return(0);
}
