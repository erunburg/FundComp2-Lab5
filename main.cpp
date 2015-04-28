// Elliott Runburg
// Fundamentals of Computing II
// Lab 5 Part 2

#include "puzzle.h"
#include <iostream>
using namespace std;
#include <cstdio>
#include <string>

int main() {

  string fileName; // String for name
  cout << "What is the name of the char puzzle file? "; // Prompts for input
  cin >> fileName;
  Puzzle<char> c(fileName);
  cout << "Here is the puzzle with chars:\n";
  c.print();

  cout << endl << endl << "What is the name of the int puzzle file? ";
  cin >> fileName;
  Puzzle<int> p(fileName); // Creates puzzle, reading in from file name
  p.play(); // Plays indefinitely
}
