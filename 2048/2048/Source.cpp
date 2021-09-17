#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "fonctions.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main() {
	bool lost = 0;
	int highscore = 0;
	srand(time(NULL));
	int gameBoard[16] = {}, oldGameBoard[16] = {};
	AddTwo(gameBoard);
	AddTwo(gameBoard);
	DisplayGameBoard(gameBoard, highscore);
	while (true) {
		string move;
		int c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			move = "up";
			break;
		case KEY_DOWN:
			move = "down";
			break;
		case KEY_LEFT:
			move = "left";
			break;
		case KEY_RIGHT:
			move = "right";
			break;
		}
		CopyGameBoard(gameBoard, oldGameBoard);
		MoveAnyDirection(gameBoard, move);
		if (CompareGameBoards(gameBoard, oldGameBoard)) {
			AddTwo(gameBoard);
			system("cls");
			DisplayGameBoard(gameBoard, highscore);
		}
		
		lost = MovePossible(gameBoard);
		if (!lost) {
			while (!lost) {
				cout << highscore << endl << "Sorry you lost! :(";
				cin >> move;
			}
			break;
		}
		cout << endl;
	}
}