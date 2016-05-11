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
	Objekt (void);														//konstruktor domyœlny
	Objekt (string l, int sala, string prowadzacy, string k);			//konstruktor wstawiaj¹cy dane do objektu "objekt"
	void wyswietl (void);											//Funkcja sk³adowa wypisuj¹ca zawartoœæ objektu "Objekt"
	
};

class Godzina
{	
	int ileKlas;
	Objekt **tablica;												//Tablica wskaŸników na "Objekt"			
public:

	Godzina (void);
	void wyswietl (void);
	~Godzina (void);
};


class Plan
{
	Godzina *** tydzien;										//Dwuwymiarowa tablica wskaŸników na "Godzina"
public:
	Plan (void);
	~Plan (void);
};



#endif
