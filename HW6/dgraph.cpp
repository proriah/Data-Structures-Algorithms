//CS311 Yoshii FALL21 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Zach Mekaelian
// File Type: cpp
//========================================================

#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

using namespace std;

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{

    for (int i = 0; i < SIZE; i++)
    {
        Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;

    }
    countUsed = 0;

}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
    char x;
    int index = 0;

  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  while (fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
  {
      fin >> Gtable[countUsed].outDegree;
      //Then for the OutDegree times(for - loop) :
      for (int i = 0; i < Gtable[countUsed].outDegree; i++) {
          fin >> x;
          (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
          
      }
      countUsed++;
  }
}
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top 
    for (int i = 0; i < countUsed; i++)
    {
        cout << "Vertex is: " << Gtable[i].vertexName << endl;
        cout << "Out Degree: " << Gtable[i].outDegree << endl;
        cout << "Adjacent Values: " << endl;
        (Gtable[i].adjacentOnes).displayAll();
        cout << "Visit Number is: " << Gtable[i].visit << endl;
        cout << endl;
    }
}

int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
    // does not use a loop - go directly to a slot using V
    
    for (int i = 0; i < SIZE; i++)
    {
        if (V == Gtable[i].vertexName)
        {
            return Gtable[i].outDegree; // Implicitly calls copy constructor of slist
        }
        
    }
    throw BadVertex();
    
}

slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
    for (int i = 0; i < SIZE; i++)
    {
        if (V == Gtable[i].vertexName)
        {
            return Gtable[i].adjacentOnes; // Implicitly calls copy constructor of slist
        }
        
    }
    throw BadVertex();
}

