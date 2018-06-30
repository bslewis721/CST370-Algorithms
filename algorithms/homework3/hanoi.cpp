/*-------------------------------------------------------------------------
   Program to solve the Towers of Hanoi puzzle recursively.

   Input:  numDisks, the number of disks to be moved
   Output: A sequence of moves that solve the puzzle
 -------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

void move(int n, char source, char spare, char destination);

int main()
{
   const char TOWER1 = 'A',  // three towers
              TOWER2 = 'B',
              TOWER3 = 'C';

   cout << "This program solves the Hanoi Towers puzzle.\n\n";
   cout << "Enter the number of disks: ";

   int numDisks;     // the number of disks to be moved
   cin >> numDisks;
   cout << endl;

   move(numDisks, TOWER1, TOWER2, TOWER3); // the solution
}


void move(int n, char source, char spare, char destination)
/*-------------------------------------------------------------------------
  Recursive function to solve the Towers of Hanoi puzzle with n disks.

  Precondition:  None.
  Postcondition: A message describing the move is output to cout.
 ------------------------------------------------------------------------*/
{
  if (n == 1)   // initial condition
  {
    cout << "  Move the top disk from " << source << " to " << destination << endl;
  }
  else  // recursive case
  {
      move(n-1, source, destination, spare);
      move(1, source, spare, destination);
      move(n-1, spare, source, destination);
  }
}