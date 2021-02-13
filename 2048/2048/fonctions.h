#include <string>

using namespace std;

#ifndef FONCTIONS_H 
#define FONCTIONS_H
int CompterCasesVides(int* TableauDeJeu);
int* TrouverCasesVides(int* TableauDeJeu);
void AfficherTableau(int* TableauDeJeu, int& highscore);
void MoveZero(int* TableauDeJeu, string move);
void MoveAnyDirection(int* TableauDeJeu, string move);
void AjouterDeux(int* TableauDeJeu);
bool ComparerTableaux(int* TableauDeJeu, int* AncienTableauDeJeu);
void CopierTableau(int* TableauDeJeu, int* AncienTableauDeJeu);
bool MovePossible(int* TableauDeJeu);
#endif
