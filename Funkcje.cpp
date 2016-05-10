#include <iostream>
#include <string.h>
#include "Header.h"

extern int ileKlas;

Objekt::Objekt (string l, int sala, string prowadzacy, string k)		//definicja konstruktora
{
	nazwaKlasy = l;
	numerSali = sala;
	nauczyciel = prowadzacy;
	przedmiot = k;
}

void Objekt::wyswietl(void)												//definicja funckji
{
	cout << "Klasa: " << nazwaKlasy << endl;
	cout << "Sala: " << numerSali << endl;
	cout << "Prowadz¹cy: " << nauczyciel << endl;
	cout << "Przedmiot: " << przedmiot << endl;
}

Godzina::Godzina (void)					
{
	tablica = new Objekt[ileKlas] ;
} 

Objekt::Objekt(void)
{
	nazwaKlasy = ""; 
	numerSali = 0;
	nauczyciel = "";
	przedmiot = "";
} 

void Godzina::wyswietl (void)
{
	for (int k = 0; k < ileKlas; k++)
	{
		cout << "Godzina: " << k + 1 << endl;
		tablica[k].wyswietl ();
	}
}

Godzina::~Godzina(void)
{
	delete [] tablica;
}

Plan::Plan (void)
{
	tydzien = new Godzina *[5];							//5 dni tygodnia
	for (int i; i < 8; i++)
		tydzien [i] = new Godzina[8];					//maksymalnie 8 godzin w tygodniu
}

Plan::~Plan(void)
{
	for (int i; i<8; i++)
		delete [] tydzien [i];
	delete [] tydzien;
}


