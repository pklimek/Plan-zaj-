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
	Objekt (string l, int sala, string prowadzacy, string k);			//konstruktor wstawiaj¹cy dane do objektu "objekt"
	void wyswietl (void);												//Funkcja sk³adowa wypisuj¹ca zawartoœæ objektu "Objekt"
	
};

class Godzina
{
	Objekt * tablica;
public:
	//Godzina (int i);
};


class Plan
{
	Godzina ** tydzien;
public:
};



#endif
