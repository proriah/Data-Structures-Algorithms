// CS311 Yoshii FALL21 - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** NEVER delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Zach Mekaelian
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  //  add the job j at the rear (and update count)
  //    if impossible else display error message. **
  if (count == MAX)
  {
	  cout << "Cannot add" << endl;
	  return;
  }
  else {
	  Q[count] = j;
	  count++;
  }
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
for (int i = 0; i < count; i++) {
	cout << Q[i] << " ";
} 
cout << endl; } 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  //  simply swap the values in these locations in Q **
	int q = Q[loc1];
		Q[loc1] = Q[loc2];
		Q[loc2] = q;
}

// Purpose: to make the very last job trickle up to the right location.
// Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  //  While x is > 0   
  //    compare Q[x] with the parent value (*)
  //    and if the parent value is bigger call swap & update x 
  //    to be the parent location. Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  //**
  int p;
  while (x > 0) {
	  p = getParent(x);
	  if (Q[x] >= Q[p]) 
		  return;
		  this -> swap(x, p);
		  x = p;
	  }
  }


// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{   //**  return the parent location based on the child loc
	int p;
	if (even(childloc)) {
		p = ((childloc - 2) / 2);
		cout << "even" << endl;
	} else {
		p = ((childloc - 1) / 2);
	}
	return p;
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  //  Start X at 0 (the root)**
  X = 0;
  //  While X is within the array (the used portion):
  //       Find the location of the smaller child by calling getSmallerchild.
  //       (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent value,
  //          call swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop. **
  while (X < count)
  {
	  int s = getSmallerchild(X);
	  if (s < count && Q[X] > Q[s]) {
		  swap(X, s);
		  X = s;
	  } else {
		  break ;
	  }
  }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{ int LC, RC; // locations of children
int cL = (2 * i) + 1;// ** set LC and RC first.
int cR = (2 * i) + 2;
//    return the location of the smaller child 
//    Be careful because one or both of them may be
//    beyond count-1 or just the RC is beyond count-1.
//    Check boundaries before you 
//    compare Q contents!!!!
//    If both are beyond count-1, you want to return a special value.
 //**
int smallest;
if (Q[cL] > Q[cR]) {
	smallest = cR;
} else {
	smallest = cL;
}
return smallest;
}
// NEVER GO TO UNUSED PART OF THE ARRAY 
