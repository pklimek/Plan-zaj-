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
	Objekt (void);														//konstruktor domyślny
	Objekt (string l, int sala, string prowadzacy, string k);			//konstruktor wstawiający dane do objektu "objekt"
	void wyswietl (void);											//Funkcja składowa wypisująca zawartość objektu "Objekt"
	
};

class Godzina
{
	int ile;
public:
	Objekt *tablica;
	Godzina (int i);
	void wyswietl (void);
};


class Plan
{
	Godzina ** tydzien;
public:
};



#endif
