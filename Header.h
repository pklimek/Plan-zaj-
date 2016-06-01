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
	void wyswietl (void);

                                                                        //Funkcja sk³adowa wypisuj¹ca zawartoœæ objektu "Objekt"

};

class Godzina
{
	int ileKlas;
	Objekt **tablica;												//Tablica wskaŸników na "Objekt"
public:

	Godzina (int a);
	void wyswietl (void);
	void przypisz (Objekt & a);
	~Godzina (void);
	void wpiszObjekt (int ileKlas);
};


class Plan
{
	Godzina *** tydzien;										//Dwuwymiarowa tablica wskaŸników na "Godzina"
public:
	Plan (void);
	~Plan (void);
	void wpiszGodzine (int dzien, int godzina, int ileKlas);
	void wpiszObjekt (int dzien, int godzina, int ileKlas);
	void wyswietl (int dzien, int godzina);
	bool sprawdzNull (int dzien, int godzina);
};

void dodajZajecia (Plan & lekcje, int ileKlas);
void wyswietlPlan (Plan & lekcje);

#endif
