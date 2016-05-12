#ifndef HEADER
#define HEADER

#include <iostream>
#include <string.h>

using namespace std;


class Objekt
{
	string nazwaKlasy;
	int numerSali;
	string nauczyciel;
	string przedmiot;
public:
	Objekt (string l, int sala, string prowadzacy, string k);			//konstruktor wstawiający dane do objektu "objekt"
	void wyswietl (void);											//Funkcja składowa wypisująca zawartość objektu "Objekt"
	
};

class Godzina
{	
	int ileKlas;
	Objekt **tablica;												//Tablica wskaźników na "Objekt"			
public:

	Godzina (void);
	void wyswietl (void);
	void przypisz (Objekt & a);
	~Godzina (void);
	void ustaw (int a) { ileKlas = a;}
};


class Plan
{
	Godzina *** tydzien;										//Dwuwymiarowa tablica wskaźników na "Godzina"
public:
	Plan (void);
	~Plan (void);
};




#endif
