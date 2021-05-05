#include <iostream>
#include <string>
using namespace std;

bool checkSpace(string board[], int playerMove);
bool checkWinner(string board[]);
void printBoard(string board[]);

int main() {
	string board[9] = {" ", " ", " ",
			   " ", " ", " ",
			   " ", " ", " "};
       	string player1 = "X";
	string player2 = "O";
	string whoseTurn = player1;
	int playerMove;
	bool gameOver = false;

	cout << "Welcome to Tic Tac Toe." << endl;
	printBoard(board);

	while (!gameOver) {
		cout << "Turn: " << whoseTurn << endl;
		cout << "Choose Space: ";
		cin >> playerMove;

		while (!checkSpace(board, playerMove)) {
			cout << "Please select an open space!" << endl;
			cin >> playerMove;
		}

		board[playerMove] = whoseTurn;
		printBoard(board);

		gameOver = checkWinner(board);
		if (whoseTurn == player1) {
			whoseTurn = player2;
		}
		else {
			whoseTurn = player1;
		}
	}

	cout << "Game Over!" << endl;
}


bool checkSpace(string board[], int playerMove) {
	return board[playerMove] == " ";
}

bool checkWinner(string board[]) {
	const int WINNING_NUM = 8;
	const int NUM_SQUARES = 3;
	int winningCombos[WINNING_NUM][NUM_SQUARES] = {{0, 1, 2},
				 		       {3, 4, 5},
				 		       {6, 7, 8},
				 		       {0, 3, 6},
				 		       {1, 4, 7},
				 		       {2, 5, 8},
				 		       {0, 4, 8},
				 		       {2, 4, 6}};
	
	for (int i = 0; i < WINNING_NUM; i++) {
	       	if (board[winningCombos[i][0]] != " " &&
				board[winningCombos[i][0]] == board[winningCombos[i][1]]
				&& board[winningCombos[i][1]] == board[winningCombos[i][2]]) {
			return true;
		}
	}
	return false;
}

void printBoard(string board[]) {
	cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
	cout << "-----" << endl;
	cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
	cout << "-----" << endl;;
	cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
	cout << "-----" << endl;;
}
