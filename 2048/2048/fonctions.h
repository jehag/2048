#include <string>

using namespace std;

#ifndef FONCTIONS_H 
#define FONCTIONS_H
int GetFreeSquares(int* TableauDeJeu);
int* FindFreeSquares(int* TableauDeJeu);
void DisplayGameBoard(int* TableauDeJeu, int& highscore);
void MoveZero(int* TableauDeJeu, string move);
void MoveAnyDirection(int* TableauDeJeu, string move);
void AddTwo(int* TableauDeJeu);
bool CompareGameBoards(int* TableauDeJeu, int* AncienTableauDeJeu);
void CopyGameBoard(int* TableauDeJeu, int* AncienTableauDeJeu);
bool MovePossible(int* TableauDeJeu);
#endif
