#include <iostream>
#include "queue1.h"
#include <string>

using namespace std;

int main()
{
  queue line;
  
  // Add the three initial values.
  try
    {
      line.add("A");
      line.add("B");
      line.add("C");
    }
 
  catch (queue::Overflow)
    {
      cout << "Error!" << endl;
      cout << "There is no room in the queue for any more items." << endl;
    }

  // int i = 1; Only used for enumeration.
  // Infinite loop.  We cycle through the loop until we Overflow.
  // We could keep track of how many lines we've written, and then quit at 25 (req'd by spec),
  // but this works just as well for this assignment.
  while (true)
    {
      el_t elem;
      
      // Get elem from the front of the queue
      try
	{
	  line.remove(elem);
	}
      // Check for an underflow (won't happen in this program).
      catch (queue::Underflow)
	{
	  cout << "Queue underflow" << endl;
	}
      // Then output the element.
      cout << elem << endl;
      
      // Enumerates the output. Be sure to also uncomment lines with i above/below.
      //cout << i << ": " << elem << endl;
      
      // Finally, try to add the next triplet of elements
      try
	{
	  line.add(elem + 'A');
	  line.add(elem + 'B');
	  line.add(elem + 'C');
	}
      // This is where we'll end the loop when we have too many items in the queue.
      catch (queue::Overflow)
	{
	  /*  cout << "Error!" << endl;
	  cout << "There is no room in the queue for any more items." << endl;
	  cout << "Queue size: " << line.getSize() << endl;*/
	  // cout << "Queue contents: " << endl;
	  line.displayAll();
	  
	  
	  
	  return 0;
	}
      

    }
}
