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

Godzina::Godzina(int i) 											//definicja konstruktora
{
	tablica = new Objekt[i] ;
	ile = i;
}

Objekt::Objekt(void)												//definicja konstruktora domyœlnego
{
	nazwaKlasy = ""; 
	numerSali = 0;
	nauczyciel = "";
	przedmiot = "";
} 

void Godzina::wyswietl (void)
{
	for (int k = 0; k < ile; k++)
	{
		cout << "Godzina: " << k + 1 << endl;						//Ta funkcja jeszcze nie do koñca dzia³a
		tablica[k].wyswietl ();
	}
}
