#include "Pet.h"

Pet::Pet()
{
	tiredness = 0;
	health = 100;
	hunger = 0;
	happiness = 50;
	exercise = 0;
	age = 0;
	tDrain = 0;
	hpDrain = 0;
	hgDrain = 0;
	hsDrain = 0;
	eDrain = 0;
	name = "???";
	owner = "???";
}

Pet::Pet(std::string n, std::string o)
{
	tiredness = 0;
	health = 100;
	hunger = 0;
	happiness = 50;
	age = 0;
	exercise = 0;
	tDrain = 0;
	hpDrain = 0;
	hgDrain = 0;
	hsDrain = 0;
	eDrain = 0;
	name = n;
	owner = o;
}

int Pet::getT() 
	{
		if(tiredness > 100) { return 100; }
		else if (tiredness < 0) { return 0; }
		else { return tiredness; }
	} 
int Pet::getHP()
	{
		if(health > 100) { return 100; }
		else if (health < 0) { return 0; }
		else { return health; }
	} 
int Pet::getHG()
	{
		if(hunger > 100) { return 100; }
		else if (hunger < 0) { return 0; }
		else { return hunger; }
	} 
int Pet::getHS()
	{
		if(happiness > 100) { return 100; }
		else if (happiness < 0) { return 0; }
		else { return happiness; }
	} 
int Pet::getE() 
	{
		if(exercise > 100) { return 100; }
		else if (exercise < 0) { return 0; }
		else { return exercise; }
	} 
double Pet::getA()
	{
		if(age > 3) { return 3; }
		else if (age < 0) { return 0; }
		else { return age; }
	} 
int Pet::getTDrain()
	{
		if(tDrain > 100) { return 100; }
		else if (tDrain < 0) { return 0; }
		else { return tDrain; }
	} 
int Pet::getHPDrain()
	{
		if(hpDrain > 100) { return 100; }
		else if (hpDrain < 0) { return 0; }
		else { return hpDrain; }
	} 
int Pet::getHGDrain()
	{
		if(hgDrain > 100) { return 100; }
		else if (hgDrain < 0) { return 0; }
		else { return hgDrain; }
	} 
int Pet::getHSDrain()
	{
		if(hsDrain > 100) { return 100; }
		else if (hsDrain < 0) { return 0; }
		else { return hsDrain; }
	} 
int Pet::getEDrain()
	{
		if(eDrain > 100) { return 100; }
		else if (eDrain < 0) { return 0; }
		else { return eDrain; }
	} 
std::string Pet::getN() { return name; }
std::string Pet::getO() { return owner; }

void Pet::setT(int t) 
	{
		if(t > 100) { tiredness = 100; }
		else if (t < 0) { tiredness = 0; }
		else { tiredness = t; }
	} 
void Pet::setHP(int hp)
	{
		if(hp > 100) { health = 100; }
		else if (hp < 0) { health = 0; }
		else { health = hp; }
	} 
void Pet::setHG(int hg)
	{
		if(hg > 100) { hunger = 100; }
		else if (hg < 0) { hunger = 0; }
		else { hunger = hg; }
	} 
void Pet::setHS(int hs)
	{
		if(hs > 100) { happiness = 100; }
		else if (hs < 0) { happiness = 0; }
		else { happiness = hs; }
	} 
void Pet::setA(double a)
	{
		if(a > 3) { age = 3; }
		else if (a < 0) { age = 0; }
		else { age = a; }
	} 
void Pet::setE(int e) 
	{
		if(e > 100) { exercise = 100; }
		else if (e < 0) { exercise = 0; }
		else { exercise = e; }
	}
void Pet::setTDrain(int td) 
	{
		if(td > 100) { tDrain = 0; tiredness -= 20; }
		else if (td < 0) { tDrain = 0; }
		else { tDrain = td; }
	}
void Pet::setHPDrain(int hpd) 
	{
		if(hpd > 100) { hpDrain = 100; health -= 20; }
		else if (hpd < 0) { hpDrain = 0; }
		else { hpDrain = hpd; }
	}
void Pet::setHGDrain(int hgd) 
	{
		if(hgd > 100) { hgDrain = 100; hunger += 20; }
		else if (hgd < 0) { hgDrain = 0; }
		else { hgDrain = hgd; }
	}
void Pet::setHSDrain(int hsd) 
	{
		if(hsd > 100) { hsDrain = 100; happiness -= 20; }
		else if (hsd < 0) { hsDrain = 0; }
		else { hsDrain = hsd; }
	}
void Pet::setEDrain(int ed) 
	{
		if(ed > 100) { eDrain = 100; exercise -= 20; }
		else if (ed < 0) { eDrain = 0; }
		else { eDrain = ed; }
	}
void Pet::setN(std::string n) { name = n; }
void Pet::setO(std::string o) { owner = o;}

