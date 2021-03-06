#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

	char board[9][9];

	/* This section illustrates the use of the pre-supplied helper functions. */
/*	cout << "============== Pre-supplied functions ==================" << endl << endl;

	cout << "Calling load_board():" << endl;
	load_board("easy.dat", board);

	cout << endl << "Displaying Sudoku board with display_board():" << endl;
	display_board(board);
	cout << "Done!" << endl << endl;

	cout << "====================== Question 1 ======================" << endl << endl;

	load_board("easy.dat", board);
	cout << "The easy.dat board is ";
	if (!is_complete(board))
		cout << "NOT ";
	cout << "complete." << endl << endl;

	load_board("easy-solution.dat", board);
	cout << "The easy-solution.dat board is ";
	if (!is_complete(board))
		cout << "NOT ";
	cout << "complete." << endl << endl;

	cout << "====================== Question 2 ======================" << endl << endl;

	load_board("easy.dat", board);

	// Should be OK
	cout << "Putting '1' into I8 is ";
	if (!make_move("I8", '1', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);

	// write more tests
	cout << "Putting '5' into A1 is ";
	if (!make_move("A1", '5', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// should not be OK
	// 1 is already in that row
	cout << "Putting '1' into A3 is ";
	if (!make_move("A3", '1', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// digit is not valid
	cout << "Putting '0' into C1 is ";
	if (!make_move("C1", '0', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// position is not valid
	cout << "Putting '1' into J1 is ";
	if (!make_move("J1", '1', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// 5 is already in that box
	cout << "Putting '5' into G9 is ";
	if (!make_move("G9", '5', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// 2 is already in that column
	cout << "Putting '2' into G3 is ";
	if (!make_move("G3", '2', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);
	
	// that space is already occupied
	cout << "Putting '5' into B1 is ";
	if (!make_move("B1", '5', board))
		cout << "NOT ";
	cout << "a valid move. The board is:" << endl;
	display_board(board);

	cout << "====================== Question 3 ======================" << endl << endl;

	load_board("easy.dat", board);
	
	if (save_board("easy-copy.dat", board))
		cout << "Save board to 'easy-copy.dat' successful." << endl;
	else
		cout << "Save board failed." << endl;
	cout << endl;

	cout << "====================== Question 4 ======================" << endl << endl;

	load_board("easy.dat", board);
	
	if (solve_board(board))
	{
		cout << "The 'easy' board has a solution:" << endl;
		display_board(board);
	} 
	else
	{
		cout << "A solution cannot be found." << endl;
	}
	cout << endl;

	load_board("medium.dat", board);
	
	if (solve_board(board))
	{
		cout << "The 'medium' board has a solution:" << endl;
		display_board(board);
	}
	else
	{
		cout << "A solution cannot be found." << endl;
	}
	cout << endl;

	// write more tests
	
	load_board("mystery1.dat", board);
	
	if (solve_board(board))
	{
		cout << "The 'mystery1' board has a solution:" << endl;
		display_board(board);
	}
	else
	{
		cout << "A solution cannot be found." << endl;
	}
	cout << endl;
	
	load_board("mystery2.dat", board);
	
	if (solve_board(board))
	{
		cout << "The 'mystery2' board has a solution:" << endl;
		display_board(board);
	}
	else
	{
		cout << "A solution cannot be found for mystery2 board." << endl;
	}
	cout << endl;
*/	
	load_board("mystery3.dat", board);
	
	if (solve_board(board))
	{
		cout << "The 'mystery3' board has a solution:" << endl;
		display_board(board);
	}
	else
	{
		cout << "A solution cannot be found." << endl;
	}
	cout << endl;
/*
	cout << "====================== Question 5 ======================" << endl << endl;

	// write more tests
	load_board("easy.dat", board);
	attempt_solve(board, 0);
	display_board(board);
 	 
	load_board("medium.dat", board);
	attempt_solve(board, 0);
	display_board(board);
 	 
	load_board("mystery1.dat", board);
	attempt_solve(board, 0);
	display_board(board);
 	 
	load_board("mystery2.dat", board);
	attempt_solve(board, 0);
	display_board(board);
 	 
	load_board("mystery3.dat", board);
	attempt_solve(board, 0);
	display_board(board);
*/ 	 
	return 0;
}
