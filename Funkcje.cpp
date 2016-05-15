#include <iostream>
#include <string.h>
#include "Header.h"



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

Godzina::Godzina (int a)					
{
	ileKlas = a;
	tablica = new Objekt *[ileKlas] ;
	for (int k = 0; k < ileKlas; k++)
		tablica [k] = NULL;
} 




void Godzina::wyswietl (void)
{
	for (int k = 0; k < ileKlas; k++)
	{
		if (tablica[k] != NULL)
		{
			cout << "Godzina: " << k + 1 << endl;
			tablica[k] -> wyswietl ();
		}
	}
}

Godzina::~Godzina(void)
{
	delete [] tablica;
}

Plan::Plan (void)
{
	tydzien = new Godzina **[5];							//5 dni tygodnia
	for (int i; i < 5; i++)
		tydzien [i] = new Godzina *[8];					//maksymalnie 8 godzin dziennie
}

Plan::~Plan(void)
{
	for (int i; i<5; i++)
		delete [] tydzien [i];
	delete [] tydzien;
}

void Godzina::przypisz (Objekt & a)
{
	for (int k = 0; k < ileKlas; k++)
	{
		if (tablica[k] == NULL)
		{
			tablica[k] = &a;
			break;
		}
	}
}
		

void Plan::wyswietl (int dzien, int godzina)
{
	tydzien[dzien - 1][ godzina - 1] -> wyswietl();
}

