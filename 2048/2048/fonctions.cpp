#include <iostream>
#include "fonctions.h"

using namespace std;

int GetFreeSquares(int* gameBoard) {
	int nbFreeSquares = 0;
	for (int i = 0; i < 16; i++) {
		if (gameBoard[i] == 0) {
			nbFreeSquares++;
		}
	}
	return nbFreeSquares;
}
int* FindFreeSquares(int* gameBoard) {
	int counter = 0;
	int freeSquares[16] = {};
	for (int i = 0; i < 16; i++) {
		if (gameBoard[i] == 0) {
			freeSquares[counter] = i;
			counter++;
		}
	}
	return freeSquares;
}
void DisplayGameBoard(int* gameBoard, int& highscore) {
	for (int i = 0; i < 16; i++) {
		if (gameBoard[i] > highscore)
			highscore = gameBoard[i];
	}
	for (int i = 0; i < 16; i++) {
		cout << gameBoard[i];
		int j = to_string(gameBoard[i]).length();
		// Adjust the size of the square depending on the number size
		while (j <= to_string(highscore).length()) {
			cout << " ";
			j++;
		}
		if ((i + 1) % 4 == 0) {
			cout << endl;
		}
	}
}
void MoveZero(int* gameBoard, string move) {

	if (move == "left") {
		for (int i = 1; i < 16; i++) {
			if (i % 4 == 0) {
				i++;
			}
			if (gameBoard[i] != 0) {
				if (gameBoard[i - 1] == 0) {
					gameBoard[i - 1] = gameBoard[i];
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "right") {
		for (int i = 14; i >= 0; i--) {
			if (i % 4 == 3) {
				i -= 1;
			}
			if (gameBoard[i] != 0) {
				if (gameBoard[i + 1] == 0) {
					gameBoard[i + 1] = gameBoard[i];
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "up") {
		for (int i = 4; i < 16; i++) {
			if (gameBoard[i] != 0) {
				if (gameBoard[i - 4] == 0) {
					gameBoard[i - 4] = gameBoard[i];
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "down") {
		for (int i = 11; i >= 0; i--) {
			if (gameBoard[i] != 0) {
				if (gameBoard[i + 4] == 0) {
					gameBoard[i + 4] = gameBoard[i];
					gameBoard[i] = 0;
				}
			}
		}
	}

}
void MoveAddition(int* gameBoard, string move) {
	if (move == "left") {
		for (int i = 1; i < 16; i++) {
			if (i % 4 == 0) {
				i++;
			}
			if (gameBoard[i] != 0) {
				if (gameBoard[i - 1] == gameBoard[i]) {
					gameBoard[i - 1] *= 2;
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "right") {
		for (int i = 14; i >= 0; i--) {
			if (i % 4 == 3) {
				i -= 1;
			}
			if (gameBoard[i] != 0) {
				if (gameBoard[i + 1] == gameBoard[i]) {
					gameBoard[i + 1] *= 2;
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "up") {
		for (int i = 4; i < 16; i++) {
			if (gameBoard[i] != 0) {
				if (gameBoard[i - 4] == gameBoard[i]) {
					gameBoard[i - 4] *= 2;
					gameBoard[i] = 0;
				}
			}
		}
	}
	else if (move == "down") {
		for (int i = 11; i >= 0; i--) {
			if (gameBoard[i] != 0) {
				if (gameBoard[i + 4] == gameBoard[i]) {
					gameBoard[i + 4] *= 2;
					gameBoard[i] = 0;
				}
			}
		}
	}
}
void MoveAnyDirection(int* gameBoard, string move) {
	for (int k = 0; k < 4; k++) {
		MoveZero(gameBoard, move);
	}
	MoveAddition(gameBoard, move);
	MoveZero(gameBoard, move);
}
void AddTwo(int* gameBoard) {
	int position = rand() % GetFreeSquares(gameBoard);
	int* freeSquares = FindFreeSquares(gameBoard);
	int gamePosition = freeSquares[position];
	gameBoard[gamePosition] = 2;
}
bool CompareGameBoards(int* gameBoard, int* oldGameBoard) {
	for (int i = 0; i < 16; i++) {
		if (oldGameBoard[i] != gameBoard[i]) {
			return true;
		}
	}
	return false;
}
void CopyGameBoard(int* gameBoard, int* oldGameBoard) {
	for (int i = 0; i < 16; i++) {
		oldGameBoard[i] = gameBoard[i];
	}
}
bool MovePossible(int* gameBoard) {
	bool haventLost = false;
	if (GetFreeSquares(gameBoard) != 0) {
		haventLost = true;
	}
	else {
		for (int i = 0; i < 16; i++) {
			if (i % 4 != 0) {
				if (gameBoard[i] == gameBoard[i - 1]) {
					haventLost = true;
				}
			}
			if (i > 3) {
				if (gameBoard[i] == gameBoard[i - 4]) {
					haventLost = true;
				}
			}
		}
	}
	return haventLost;
}