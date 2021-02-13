#include <iostream>
#include "fonctions.h"

using namespace std;

int CompterCasesVides(int* TableauDeJeu) {
	//la fonction compte le nombre de cases vides
	//param 	[in]	int*	TableauDeJeu 
	//return	int NbCasesVides

	int NbCasesVides = 0;
	for (int i = 0; i < 16; i++) {
		if (TableauDeJeu[i] == 0) {
			NbCasesVides++;
		}
	}
	return NbCasesVides;
}
int* TrouverCasesVides(int* TableauDeJeu) {
	int compteur = 0;
	int CasesVides[16] = {};
	for (int i = 0; i < 16; i++) {
		if (TableauDeJeu[i] == 0) {
			CasesVides[compteur] = i;
			compteur++;
		}
	}
	return CasesVides;
}
void AfficherTableau(int* TableauDeJeu, int& highscore) {
	for (int i = 0; i < 16; i++) {
		if (TableauDeJeu[i] > highscore)
			highscore = TableauDeJeu[i];
	}
	for (int i = 0; i < 16; i++) {
		cout << TableauDeJeu[i];
		int j = to_string(TableauDeJeu[i]).length();
		while (j <= to_string(highscore).length()) {
			cout << " ";
			j++;
		}
		if ((i + 1) % 4 == 0) {
			cout << endl;
		}
	}
}
void MoveZero(int* TableauDeJeu, string move) {

	if (move == "left") {
		for (int i = 1; i < 16; i++) {
			if (i % 4 == 0) {
				i++;
			}
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i - 1] == 0) {
					TableauDeJeu[i - 1] = TableauDeJeu[i];
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "right") {
		for (int i = 14; i >= 0; i--) {
			if (i % 4 == 3) {
				i -= 1;
			}
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i + 1] == 0) {
					TableauDeJeu[i + 1] = TableauDeJeu[i];
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "up") {
		for (int i = 4; i < 16; i++) {
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i - 4] == 0) {
					TableauDeJeu[i - 4] = TableauDeJeu[i];
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "down") {
		for (int i = 11; i >= 0; i--) {
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i + 4] == 0) {
					TableauDeJeu[i + 4] = TableauDeJeu[i];
					TableauDeJeu[i] = 0;
				}
			}
		}
	}

}
void MoveAddition(int* TableauDeJeu, string move) {
	if (move == "left") {
		for (int i = 1; i < 16; i++) {
			if (i % 4 == 0) {
				i++;
			}
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i - 1] == TableauDeJeu[i]) {
					TableauDeJeu[i - 1] *= 2;
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "right") {
		for (int i = 14; i >= 0; i--) {
			if (i % 4 == 3) {
				i -= 1;
			}
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i + 1] == TableauDeJeu[i]) {
					TableauDeJeu[i + 1] *= 2;
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "up") {
		for (int i = 4; i < 16; i++) {
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i - 4] == TableauDeJeu[i]) {
					TableauDeJeu[i - 4] *= 2;
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
	else if (move == "down") {
		for (int i = 11; i >= 0; i--) {
			if (TableauDeJeu[i] != 0) {
				if (TableauDeJeu[i + 4] == TableauDeJeu[i]) {
					TableauDeJeu[i + 4] *= 2;
					TableauDeJeu[i] = 0;
				}
			}
		}
	}
}
void MoveAnyDirection(int* TableauDeJeu, string move) {
	for (int k = 0; k < 4; k++) {
		MoveZero(TableauDeJeu, move);
	}
	MoveAddition(TableauDeJeu, move);
	MoveZero(TableauDeJeu, move);
}
void AjouterDeux(int* TableauDeJeu) {
	int chiffre = rand() % CompterCasesVides(TableauDeJeu);
	int* CasesVides = TrouverCasesVides(TableauDeJeu);
	int chiffre2 = CasesVides[chiffre];
	TableauDeJeu[chiffre2] = 2;
}
bool ComparerTableaux(int* TableauDeJeu, int* AncienTableauDeJeu) {
	bool memeTableau = false;
	for (int i = 0; i < 16; i++) {
		if (AncienTableauDeJeu[i] != TableauDeJeu[i]) {
			memeTableau = true;
			break;
		}
	}
	return memeTableau;
}
void CopierTableau(int* TableauDeJeu, int* AncienTableauDeJeu) {
	for (int i = 0; i < 16; i++) {
		AncienTableauDeJeu[i] = TableauDeJeu[i];
	}
}
bool MovePossible(int* TableauDeJeu) {
	bool pasPerdu = false;
	if (CompterCasesVides(TableauDeJeu) != 0) {
		pasPerdu = true;
	}
	else {
		for (int i = 0; i < 16; i++) {
			if (i % 4 != 0) {
				if (TableauDeJeu[i] == TableauDeJeu[i - 1]) {
					pasPerdu = true;
				}
			}
			if (i > 3) {
				if (TableauDeJeu[i] == TableauDeJeu[i - 4]) {
					pasPerdu = true;
				}
			}
		}
	}
	return pasPerdu;
}