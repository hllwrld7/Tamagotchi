#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include "Windows.h"
#include "Pet.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27
#define SPACE 32

using namespace std;

void writeToFile(int hp, int hg, int hs, string n, string o); // writes data to the file

// MENUS
short correctOption0(short chosenOption); // makes sure 0 >= option >= 2 for start menu
short correctOption1(short chosenOption); // makes sure 0 >= option >= 4 for in game menu
string getOption0(short chosenOption); // equates numbers with menu options for start menu
string getOption1(short chosenOption); // equates numbers with menu options for in game menu
void startMenu(short chosenOption); // start menu screen

void newGame(); // creates a new cat and asks user their name and cat's name
void loadGame(); // gets data from the file and writes to the cat object

// GAME SCREEN
void gameOn(Pet cat, short chosenOption, clock_t start); // in game screen
void gameOver();
void printAge(double a); // equates numbers with age and outputs a string
void HPbar(int hp); // outputs HP bar
void HGbar(int hg); // outputs hunger bar
void HSbar(int hs); // outputs happiness bar
void Ebar(int e); // outputs energy bar
// int runtimeMins(clock_t start, double runtime); // returns time in mins
void screen0(); // image of a cat

// CAT INTERACTIONS
Pet exerciseCat(Pet cat, bool up , clock_t start); // REWORK IT!!!!!!!!!!!!!!!!!!!!!!
void catUp(Pet cat);
void catDown(Pet cat);
void babyCat();
void childCat();
void teenageCat();
void adultCat();

string printCatState(Pet cat);
#endif
