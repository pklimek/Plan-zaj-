#ifndef HEADER
#define HEADER

#include <iostream>
#include <string.h>

using namespace std;

int ileKlas;										//trzeba wpisa� warto�� na samym pocz�tku programu

class Objekt
{
	string nazwaKlasy;
	int numerSali;
	string nauczyciel;
	string przedmiot;
public:
	Objekt (void);														//konstruktor domy�lny
	Objekt (string l, int sala, string prowadzacy, string k);			//konstruktor wstawiaj�cy dane do objektu "objekt"
	void wyswietl (void);											//Funkcja sk�adowa wypisuj�ca zawarto�� objektu "Objekt"
	
};

class Godzina
{	
	Objekt *tablica;													
public:

	Godzina (void);
	void wyswietl (void);
	~Godzina (void);
};


class Plan
{
	Godzina ** tydzien;
public:
	Plan (void);
	~Plan (void);
};



#endif
