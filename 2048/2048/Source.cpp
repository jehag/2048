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
	bool ok = 0;
	int highscore = 0;
	srand(time(NULL));
	int TableauDeJeu[16] = {}, AncienTableauDeJeu[16] = {};
	AjouterDeux(TableauDeJeu);
	AjouterDeux(TableauDeJeu);
	AfficherTableau(TableauDeJeu, highscore);
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
		CopierTableau(TableauDeJeu, AncienTableauDeJeu);
		MoveAnyDirection(TableauDeJeu, move);
		if (ComparerTableaux(TableauDeJeu, AncienTableauDeJeu)) {
			AjouterDeux(TableauDeJeu);
			system("cls");
			AfficherTableau(TableauDeJeu, highscore);
		}
		
		ok = MovePossible(TableauDeJeu);
		if (!ok) {

			while (!ok) {
				cout << highscore << endl << "Sorry you lost! :(";
				cin >> move;
			}
			break;
		}
		cout << endl;
	}
}