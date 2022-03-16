#ifndef PET_H
#define PET_H
#include<string>
#include <time.h> 

class Pet
{
	public:
		// constructors
		Pet();
		Pet(std::string n, std::string o);
		// getters
		int getT();
		int getHP();
		int getHG();
		int getHS();
		double getA();
		int getE();
		
		int getTDrain();
		int getHPDrain();
		int getHGDrain();
		int getHSDrain();
		int getEDrain();
		
		std::string getN();
		std::string getO();
		// setters
		void setT(int t);
		void setHP(int hp);
		void setHG(int hg);
		void setHS(int hs);
		void setA(double a);
		void setE(int e);
		
		void setTDrain(int td);
		void setHPDrain(int hpd);
		void setHGDrain(int hgd);
		void setHSDrain(int hsd);
		void setEDrain(int ed);
		
		void setN(std::string n);
		void setO(std::string o);
		
		// i wanted to have add functions (like addHP(int hp) { return health + hp; } but the implementation
		// was too similar to the set functions and i already made everything using them
		// so i decided to stick to the setHP(getHP()+x); formula
 		
	protected:
		double age;
		int tiredness, health, hunger, happiness, exercise;
		int tDrain, hpDrain, hgDrain, hsDrain, eDrain;
		std::string name;
		std::string owner;
};

#endif
