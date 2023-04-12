#ifndef PIECES_H
#define PIECES_H

#include<stdlib.h>
#include<vector>

class Board 
{
  public:


  private:
  
};

class Piece
{
  public:
  Piece()
  {
    type = "U"; 
    col = -1;
    row = "z";
    checked = false;
  }

  Piece(char c, int i; char r) 
  {
    type = c;
    col = i;  
    row = r;
    checked = false;
  }

  bool check_pos(int i, char r) {
    // run through moves array, check if this square is a possible move
  }  

  void set_danger(bool b) {
    danger = b;
  }

  void set_pos(int i, char r) {
    col = i;
    row = r;
  }

  void add_move(int i, char r) {

  }

  void remove_move(int i, char r) {

  }

  vector<char*> * return_moves (void) {
    // should this be a reference, pointer, ???
  }
  
  virtual vector <char*> * ideal_moves(int i, char r) {
    // returns a list of squares where this class could 'theoretically' move from the passed position
  }

  private:
  char type;
  int col;
  char row;
  vector<char*> moves;
  bool danger;
  bool checked;
};






#endif

