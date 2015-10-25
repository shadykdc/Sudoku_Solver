#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  //cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  //cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  //assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

/* returns true if a 9x9 sudoku board called 'char board[9][9]' has been solved */
bool is_complete(char board[][9])
{
	/* return false if there are any blanks */
	for (int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(board[i][j] < '1' || board[i][j] > '9')
				return(false);
	return(true);
}

/* attempts to place a digit onto a Sudoku board at a given position */
bool make_move(char position[2], char digit, char board[][9])
{
	int spot_row = position[0]-65; // this makes I an 8 as in board[8][7] and A would be 0.
	int spot_col = position[1]-49; // this makes the number seven, seven (etc.).
	
	/* return false if digit is not between 1 and 9 */
	if(digit < 49 || digit > 57)
		return(false);

	/* return false if the position is not on the 9x9 board */
	if(spot_row > 8 || spot_col > 8 || spot_row < 0 || spot_col < 0)
		return(false);
	
	/* return false if that position is already occupied */
	if(board[spot_row][spot_col] != '.')
		return(false);
	
	/* return false if the digit is in the spot's row or column */
	for(int i = 0; i < 9; i++)
		if(board[i][spot_col] == digit || board[spot_row][i] == digit)
			return(false);
	
	/* return false if the digit already exists in that box */
	if (exists_in_box(digit, spot_row, spot_col, board))
		return(false);
	
	/* 'digit' fits into 'position' on 'board' so let's try it */
	board[spot_row][spot_col] = digit;
	return(true);
}

bool save_board(const char *filename, char board[][9])
{
	/* save board to file */
	ifstream in_stream;
	ofstream out_stream;
	out_stream.open(filename);
	for (int i = 0; i < 9; i++)
	{
		if(i > 0)
		{
			out_stream.put('\n');
		}
		for (int j = 0; j < 9; j++)
		{
			out_stream.put(board[i][j]);
		}
	}		
	out_stream.close();
	
	/* test that the file saved */
	in_stream.open(filename);
	if (in_stream.fail())
	{
		return(false);
	}
	else
	{
		in_stream.close();
		return(true);
	}
}

bool solve_board(char board[][9])
{
	/* recursively solve the board */
	char position[2];
	
	if(is_complete(board))
		return(true);
	
	/* try each digit in each box */
	for(char i = 'A'; i <= 'I'; i++)
	{
		for(char j = '1'; j <= '9'; j++)
		{
			/* skip over the boxes that are already filled in to speed up just a little */
			if(board[i-65][j-49] != '.')
				continue;

			for(char digit = '1'; digit <= '9'; digit++)
			{
				position[0] = i;
				position[1] = j;
				
				if(make_move(position, digit, board))	// try to insert that digit in that position
				{
					if(!solve_board(board))				// solve the new board
					{
						board[i-65][j-49] = '.';		// if the new board is false,
					}									// set last try back to blank
					else
					{
						return true;					// the board is complete!
					}
				}
				if(board[i-65][j-49] == '.' && digit == '9')
				{
					return(false);						// you're stuck --> return false
				}		
			}
		}
	}
	return(false);
}

bool exists_in_box(char digit, int spot_row, int spot_col, char board[][9])
{
	/* if that digit exists in that 3x3 box where spot is, return true */
	int min_row = (spot_row)/3*3;
		int max_row = (spot_row)/3*3+2;
		int min_col = (spot_col)/3*3;
		int max_col = (spot_col)/3*3+2;
		for (int i = min_row; i <= max_row; i++)
			for(int j = min_col; j <= max_col; j++)
				if(board[i][j] == digit)
					return(true);
	return(false);
}


/* for question 5 */
void attempt_solve(char board[][9], int count)
{
	/* solves the board as far as it can using basic logic
	(i.e. that found in make_move() and possible()) */
	
	char position[2];
		
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(char digit = '1'; digit <= '9'; digit++)
			{
				position[0] = (i+65);
				position[1] = (j+49);
				
				// if the digit doesn't fit anywhere else in that col/row/box
				if(!digit_fits_in_row(digit, i, j, board) ||
				!digit_fits_in_col(digit, i, j, board) ||
				!digit_fits_in_box(digit, i, j, board))
				{
					if(make_move(position, digit, board))
					{
						count++;
						cout << "I've filled in " << count << " boxes with basic logic." << endl;
						attempt_solve(board, count);
					}
				}	
			}
		}
	}
}

bool digit_fits_in_box(char digit, int spot_row, int spot_col, char board[][9])
{
	/* if you can put digit in any of the other 3x3 box values, return true */
	char position[2];
	for (int i = ((spot_row)/3*3); i <= ((spot_row)/3*3+2); i++)
		for(int j = ((spot_col)/3*3); j <= ((spot_col)/3*3+2); j++)
		{
			position[0] = (i+65);
			position[1] = (spot_col+49);
			if(possible(position, digit, board))
				return(true);
		}
	return(false);
}

bool digit_fits_in_row(char digit, int spot_row, int spot_col, char board[][9])
{
	/* if you can put digit in any of the other row values, return true */
	char position[2];
	for(int i = 0; i < 9; i++)
	{
		if (i == spot_row)
			continue;
		position[0] = i+65;
		position[1] = spot_col+49;
		if(possible(position, digit, board))
			return(true);
	}
	return(false);
}

bool digit_fits_in_col(char digit, int spot_row, int spot_col, char board[][9])
{
	/* if you can put digit in any of the other column values, return true */
	char position[2];
	for(int i = 0; i < 9; i++)
	{
		if (i == spot_col)
			continue;
		position[0] = spot_row+65;
		position[1] = i+49;
		if(possible(position, digit, board))
			return(true);
	}
	return(false);
}

bool possible(char position[2], char digit, char board[][9])
{
	/* this is basically the same as make_move() but it doesn't put the digit in */
	int spot_row = position[0]-65; // this makes I an 8 as in board[8][7] and A would be 0.
	int spot_col = position[1]-49; // this makes the number seven, seven (etc.).
	
	/* return false if digit is not between 1 and 9 */
	if(digit < 49 || digit > 57)
		return(false);
	
	/* return false if the position is not on the 9x9 board */
	if(spot_row > 8 || spot_col > 8 || spot_row < 0 || spot_col < 0)
		return(false);
	
	/* return false if that position is already occupied */
	if(board[spot_row][spot_col] != '.')
		return(false);
	
	/* return false if the digit is in the spot's row or column */
	for(int i = 0; i < 9; i++)
		if(board[i][spot_col] == digit || board[spot_row][i] == digit)
			return(false);
	
	/* return false if the digit already exists in that box */
	if (exists_in_box(digit, spot_row, spot_col, board))
		return(false);
	
	/* if none of the above are true */
	return(true);
}
