// Elliott Runburg
// Fundamentals of Computing II
// Lab 5 Part 2

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

template <typename T>
class Puzzle { // Class header

 public:
  Puzzle(string); // Constructor
  void print(); // Prints the board
  void play(); // Plays indefinitely

 private:
  vector< vector<T> > grid; // Grid made up of a 2D vector of type T	
  int checkLocation(int, int, int); // Checks to see if the location can be changed to said number
  int checkWin(); // Checks if the game is over
};

template <typename T>
Puzzle<T>::Puzzle(string name) {
  ifstream infile; 
  infile.open(name.c_str()); // Opens a file with the given name 
  T value; // Value of the file that is iterated
  
  vector<T> temp; // Temporary vector
  for (int i = 0; i < 9; i++) { // Iterates through the file
    for (int j = 0; j < 9; j++) {
      infile >> value;
      temp.push_back(value); // Pushes the current value into the temp
    }
    grid.push_back(temp); // Pushes the temp into the 2D vector
    temp.clear(); // Clears temp
  }
  
}

template <typename T>
void Puzzle<T>::print() {
  for ( int i = 0; i < 9; i++ ) { // Iterates through vector
    for ( int j = 0; j < 9; j++ ) {		
      cout << grid[i][j]; // Prints grid
    }
    cout << endl;
  }
} 

template <typename T>
void Puzzle<T>::play() {
  int row, col;
  int val;

  print();
  while ( !checkWin() ) { // Only run while the game isn't complete
    // Receive input
    cout << "What row would you like to place in? ";
    cin >> row;
    cout << "What column would you like to place in? ";
    cin >> col;
    cout << "What value would you like to place there? ";
    cin >> val;

    // Clear the screen
    system("clear");
   
    // If the location is valid, change it; otherwise, show error
    if ( checkLocation(row-1, col-1, val) ) 
      grid[row-1][col-1] = val;
    else
      cout << "Invalid entry." << endl;

    // Print the current board
    print();
  }

}

template <typename T>
int Puzzle<T>::checkLocation(int row, int col, int val) {
  // Check to see if input is valid ever
  if ( row < 0 || row > 8 || col < 0 || col > 8 || val < 1 || val > 9 )
    return 0;

  // Check if the row does not contain the input
  for ( int i = 0; i < 9; i++ ) {
    if ( grid[row][i]==val )
      return 0;
  }

  // Check the column
  for (int j = 0; j < 9; j++ ){
    if ( grid[j][col]==val )
      return 0;
  }
  
  // This will determine which block the spot is in
  int rowSq = row / 3;
  int colSq = col / 3;

  // Check the square around it
  for ( int i = rowSq*3; i < rowSq*3+3; i++ ) {
    for ( int j = colSq*3; j < colSq*3+3; j++ ) {
      if ( grid[i][j]==val )
	return 0;
    }
  }

  // If still running, it is good
  return 1;
}

template <typename T>
int Puzzle<T>::checkWin() {
  // Since only valid inputs are accepted, if everything is not 0, then the board is complete
  for ( int i = 0; i < 9; i++ ) {
    for ( int j = 0; j < 9; j++ ) {
      if ( grid[i][j] == 0 )
	return 0;
    }
  }
  cout << "You have completed the puzzle!" << endl;
  return 1;
}

#endif
