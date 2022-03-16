
#include "funcs.h"

void writeToFile(Pet cat)
{
	ofstream dataFile;
	dataFile.open("gameData.txt");
	dataFile << cat.getT() << "\n";
	dataFile << cat.getHP() << "\n";
	dataFile << cat.getHG() << "\n";
	dataFile << cat.getHS() << "\n";
	dataFile << cat.getA() << "\n";
	dataFile << cat.getE() << "\n";
	dataFile << cat.getN() << "\n";
	dataFile << cat.getO() << "\n";
	dataFile << cat.getTDrain() << "\n";
	dataFile << cat.getHPDrain() << "\n";
	dataFile << cat.getHGDrain() << "\n";
	dataFile << cat.getHSDrain() << "\n";
	dataFile << cat.getEDrain() << "\n";
	dataFile.close();
}

short correctOption0(short chosenOption)
{
	if(chosenOption < 0)
	{
		return 2;
	}
	if(chosenOption > 2)
	{
		return 0;
	}
}

short correctOption1(short chosenOption)
{
	if(chosenOption < 0)
	{
		return 3;
	}
	if(chosenOption > 3)
	{
		return 0;
	}
}

string getOption0(short chosenOption)
{
	switch(chosenOption)
	{
		case 0: return "NEW GAME"; break;
		case 1: return "LOAD GAME"; break;
		case 2: return "EXIT"; break;
	}
}

string getOption1(short chosenOption)
{
	switch(chosenOption)
	{
		case 0: return "BACK TO MENU"; break;
		case 1: return "FEED"; break;
		case 2: return "PET"; break;
		case 3: return "EXERCISE"; break;
	}
}

void startMenu(short chosenOption)
{
	cout << endl << " _      _____ _      _    " << endl;
	cout << "/ \\__/|/  __// \\  /|/ \\ /\\" << endl;
	cout << "| |\\/|||  \\  | |\\ ||| | ||" << endl;
	cout << "| |  |||  /_ | | \\||| \\_/|" << endl;
	cout << "\\_/  \\|\\____\\\\_/  \\|\\____/" << endl;
	cout << "                          " << endl << endl;
	cout << "NEW GAME\nLOAD GAME\nEXIT\n\n";
	cout << getOption0(chosenOption);
	int c = 0;
	bool running = true;
	while(running)
	{
		c = getch();
		if(c == ENTER)
		{
			switch(chosenOption)
			{
				case 0: Beep(659,100); system ("CLS"); newGame(); break;
				case 1: Beep(659,100); loadGame();	break;
				case 2: Beep(659,100); exit(0);	
				default: system ("CLS"); cout << "wtf"; break;
			}		
		}
		switch((c=getch())) 
		{
        	case KEY_UP:
        		Beep(698,100);
            	system ("CLS");
            	chosenOption = correctOption0(chosenOption-1);
            	startMenu(chosenOption);
            	break;
        	case KEY_DOWN:
        		Beep(698,100);
        		system ("CLS");
        		chosenOption = correctOption0(chosenOption+1);
           		startMenu(chosenOption);
            	break;
		}	
	}
}

void newGame()
{
	cout << " ____  ____  _____    ____  ____  _____ ____  _____  _  ____  _     " << endl;
	cout << "/   _\\/  _ \\/__ __\\  /   _\\/  __\\/  __//  _ \\/__ __\\/ \\/  _ \\/ \\  /|" << endl;
	cout << "|  /  | / \\|  / \\    |  /  |  \\/||  \\  | / \\|  / \\  | || / \\|| |\\ ||" << endl;
	cout << "|  \\__| |-||  | |    |  \\__|    /|  /_ | |-||  | |  | || \\_/|| | \\||" << endl;
	cout << "\\____/\\_/ \\|  \\_/    \\____/\\_/\\_\\\\____\\\\_/ \\|  \\_/  \\_/\\____/\\_/  \\|" << endl;
	cout << "                                                                    " << endl << endl;
	string owner, name;
	cout << "YOUR NAME : ";
	cin >> owner;
	cout << "CAT NAME: ";
	cin >> name;
	Pet * cat = new Pet(name, owner);
	writeToFile(*cat);
	system ("CLS");
	gameOn(*cat, 0, clock());
}

void loadGame()
{
	Pet * cat = new Pet();
	ifstream dataFile;
	dataFile.open("gameData.txt");
	string t;
	int num;
	stringstream ss;
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setT(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	if(t.empty())
	{
		system("CLS");
		cout << "No saved games, start a new game.";
		startMenu(0);
	}
	ss >> num;
	cat->setHP(num);
	if(cat->getHP() == 0)
	{
		system("CLS");
		cout << "No saved games, start a new game.";
		startMenu(0);
	}
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setHG(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setHS(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setA(num);
	ss.clear();	
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setE(num);
	ss.clear();
	
	dataFile >> t;
	cat->setN(t);
	
	dataFile >> t;
	cat->setO(t);
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setTDrain(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setHPDrain(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setHGDrain(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setHSDrain(num);
	ss.clear();
	
	dataFile >> t;
	ss << t;
	ss >> num;
	cat->setEDrain(num);
	ss.clear();

	dataFile.close();
	system ("CLS");
	gameOn(*cat, 0, clock());
}

void gameOn(Pet cat, short chosenOption, clock_t start) 
{ 
	int c = 0;
	while(true)
	{
		double runtime = (clock() - start ) / (double) CLOCKS_PER_SEC * 60;
		if(runtime > 100)
		{
			cat.setHGDrain(cat.getHGDrain()+10);
			cat.setHSDrain(cat.getHSDrain()+10);
			cat.setEDrain(cat.getEDrain()+10);
			cat.setTDrain(cat.getTDrain()+30); // resource for exercise
			cat.setA(cat.getA()+0.5);
			gameOn(cat, chosenOption, clock());
			system("CLS");
		}
		if(cat.getHG() == 100) { cat.setHPDrain(cat.getHPDrain()+20); }
		writeToFile(cat);
		if(cat.getHP() == 0)
		{
			system ("CLS");
			gameOver();
		}
		cout << "-BACK TO MENU-----------------FEED-----------------PET-----------------EXERCISE-" << endl << endl<< endl;
		cout << cat.getN() << "----------------------------------------------------------" << cat.getO() << "'s cat" << endl << endl<< endl;		
		HPbar(cat.getHP());
		HGbar(cat.getHG());
		HSbar(cat.getHS());
		Ebar(cat.getE());
		printAge(cat.getA());
		cout << printCatState(cat);
		cout << getOption1(chosenOption) << endl;

//		if(kbhit()) // checks if the key was pressed
//		{
			c = getch();
			if(c == ENTER)
				{
				switch(chosenOption)
					{
					case 0: Beep(659,100); writeToFile(cat); system ("CLS"); startMenu(0); break;
					case 1: // feed cat
						Beep(659,100);
						cat.setHGDrain(0);
						cat.setHP(cat.getHP() + 20);
						cat.setHG(cat.getHG() - 20);
						break;						
					case 2: // pet cat
						Beep(659,100);
						cat.setHSDrain(0);
						cat.setHS(cat.getHS() + 20);
						break;
					case 3: // exercise cat
						Beep(659,100);
						system ("CLS");
						cat = exerciseCat(cat, false, start);
						break; 
					}		
				}	
			else
			{
				switch((c=getch())) 
				{
        		case KEY_LEFT:
        			Beep(698,100);
            		system ("CLS");
            		chosenOption = correctOption1(chosenOption-1);
            		gameOn(cat, chosenOption, start);
            		break;
        		case KEY_RIGHT:
        			Beep(698,100);
        			system ("CLS");
        			chosenOption = correctOption1(chosenOption+1);
           			gameOn(cat, chosenOption, start);
            		break;
				}		
			}
//		}	


		system ("CLS");
	}
}

void gameOver()
{
	int c;
	Beep(698,200);
	Beep(587,200);
	Beep(493,200);
	cout << " _____   ___  ___  ___ _____   _____  _   _ ___________ " << endl;
	cout << "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\" << endl;
	cout << "| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /" << endl;
	cout << "| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    / " << endl;
	cout << "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ " << endl;
	cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|" << endl << endl << endl;
	cout << "           ___" << endl;
	cout << "          (___)" << endl;
	cout << "   ____" << endl;
	cout << " _\\___ \\  |\\_/|" << endl;
	cout << "\\     \\ \\/ , , \\ ___" << endl;
	cout << " \\__   \\ \\ =\"= //|||\\" << endl;
	cout << "  |===  \\/____)_)||||" << endl;
	cout << "  \\______|    | |||||" << endl;
	cout << "      _/_|  | | =====" << endl;
	cout << "     (_/  \\_)_)    " << endl;
	cout << "  _________________" << endl;
	cout << " (                _)" << endl;
	cout << "  (__   '          )" << endl;
	cout << "    (___    _____)" << endl;
	cout << "        '--'" << endl << endl<< endl;
	cout << "            PRESS ANY KEY TO RETURN TO MAIN MENU             " << endl;
	c = getch();
	system ("CLS");
	startMenu(0);
}

void printAge(double a)
{
		if(a < 1)
		{
			cout << "BABY" << endl << endl;;
			babyCat();
		}
		else if(a < 2)
		{
			cout << "CHILD" << endl << endl;;
			childCat();
		}
		else if(a < 3)
		{
			cout << "TEENAGER" << endl << endl;;
			teenageCat();
		}
		else
		{
			cout << "ADULT" << endl << endl;;
			adultCat(); 
		}
}

void HPbar(int hp)
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Health    ";
	if(hp > 50) { SetConsoleTextAttribute(hConsole, 10); } // green if hp > 50
	else if(hp > 20) { SetConsoleTextAttribute(hConsole, 14); } // yellow if hp > 20
	else { SetConsoleTextAttribute(hConsole, 12); } // red if hp <= 20
	for(int i = 0; i < hp; i++)
	{
		cout << "|";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15); // prevents colouring of all the text
}

void HGbar(int hg)
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Hunger    ";
	if(hg < 20) { SetConsoleTextAttribute(hConsole, 10); } // green if hg < 20
	else if(hg < 50) { SetConsoleTextAttribute(hConsole, 14); } // yellow if hg < 50
	else { SetConsoleTextAttribute(hConsole, 12); } // red if hg >= 50
	for(int i = 0; i < hg; i++)
	{
		cout << "|";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void HSbar(int hs)
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Happiness ";
	if(hs > 50) { SetConsoleTextAttribute(hConsole, 10); } // green if hs > 50
	else if(hs > 20) { SetConsoleTextAttribute(hConsole, 14); } // yellow if hs > 20
	else { SetConsoleTextAttribute(hConsole, 12); } // red if hs <= 20
	for(int i = 0; i < hs; i++)
	{
		cout << "|";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Ebar(int e)
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Exercise  ";
	if(e > 50) { SetConsoleTextAttribute(hConsole, 10); } // green if e > 50
	else if(e > 20) { SetConsoleTextAttribute(hConsole, 14); } // yellow if e > 20
	else { SetConsoleTextAttribute(hConsole, 12); } // red if hs <= 20
	for(int i = 0; i < e; i++)
	{
		cout << "|";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

Pet exerciseCat(Pet cat, bool up, clock_t start)
{
	bool running = true;
	int c;
	if(cat.getT() >= 100)
	{
		running = false;
		catDown(cat);
		cout << cat.getN() << " is tired and doesn't want to exercise anymore\n";
		c = getch();
		if(c == ESC) { system("CLS"); gameOn(cat, 0, start); }
		else { system("CLS"); exerciseCat(cat, false, start); }
	}
	while(running)
	{	
		catDown(cat);
		if(up)
		{
			system("CLS");
			catUp(cat);
			Sleep(500);
			system("CLS");
			cat = exerciseCat(cat, !up, start);
		}
		switch(c = getch())
		{
			case ESC: system("CLS"); gameOn(cat, 0, start); break;
			case SPACE:
				{
					cat.setT(cat.getT() + 20);
					cat.setE(cat.getE() + 20);
					cat.setEDrain(0);
					if(cat.getT() >= 100)
					{
						system("CLS");
						cat = exerciseCat(cat, false, start);	
					}
					else
					{
						system("CLS");
						cat = exerciseCat(cat, !up, start);
					}
				}
		}
	}
	return cat;
}

void catUp(Pet cat)
{
	cout << "press SPACE to jump\npress ESC to stop exercising" << endl << endl;
	cout << "     _._     _,-'""`-._" << endl;
	cout << "     (,-.`._,'(       |\\`-/|" << endl;
	cout << "         `-.-' \\ )-`( , o o)" << endl;
	cout << "               `-    \\`_`\\\"'-" << endl << endl << endl << endl;
	Ebar(cat.getE());
	cout << endl;
}

void catDown(Pet cat)
{
	cout << "press SPACE to jump\npress ESC to stop exercising" << endl << endl;
	cout << endl << endl << endl;
	cout << "     _._     _,-'""`-._" << endl;
	cout << "     (,-.`._,'(       |\\`-/|" << endl;
	cout << "         `-.-' \\ )-`( , o o)" << endl;
	cout << "               `-    \\`_`\\\"'-" << endl;
	Ebar(cat.getE());
	cout << endl;
}

void babyCat()
{
	cout << "     _" << endl;
	cout << "  |\\'/-..--." << endl;
	cout << " / _ _   ,  ;" << endl;
	cout << "`~=`Y'~_<._./" << endl;
	cout << " <`-....__.'  " << endl;		

}

void childCat()
{
	cout << "   |\\__/,|   (`\\" << endl;
	cout << "   |o o  |__ _)" << endl;
	cout << " _.( T   )  `  /" << endl;
	cout << "((_ `^--' /_<  \\\\" << endl;
	cout << "`` `-'(((/  (((/" << endl;
}

void teenageCat()
{
	cout << "     _._     _,-'""`-._" << endl;
	cout << "     (,-.`._,'(       |\\`-/|" << endl;
	cout << "         `-.-' \\ )-`( , o o)" << endl;
	cout << "               `-    \\`_`\\\"'-" << endl;
}

void adultCat()
{
	cout << "         ,-""""""-." << endl;
	cout << "      /\\j__/\\  (  \\`--." << endl;
	cout << "      \\`@_@'/  _)  >--.`." << endl;
	cout << "     _{.:Y:_}_{{_,'    ) )" << endl;
	cout << "    {_}`-^{_} ```     (_/" << endl;	
}

string printCatState(Pet cat)
{
	ifstream dataFile;
	if(cat.getHS() < 20)
	{
		dataFile.open("sadCat.txt");
	}
	else if(cat.getHS() < 50)
	{
		dataFile.open("okCat.txt");
	}
	else
	{
		dataFile.open("happyCat.txt");
	}
	
	string line = cat.getN();
	string randLine;
	int randNum;
	randNum = rand() % 5; // returns a number from 0 to 4
	for(int i = 0; i < randNum; i++)
	{
		getline(dataFile, randLine);
	}
	getline(dataFile, randLine);
	line += randLine + "\n";
	return line;
}
