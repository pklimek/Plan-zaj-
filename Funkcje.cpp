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

Plan::Plan ()
{
	tydzien = new Godzina **[5];							//5 dni tygodnia
	for (int i; i < 5; i++)
	{
		tydzien [i] = new Godzina *[8];						//maksymalnie 8 godzin dziennie
		for (int k = 0; k < 8; k++)
			tydzien [i][k] = NULL;
	}					
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

void Plan::wpisz (int dzien, int godzina, int ileKlas)
{
	tydzien[dzien - 1][godzina - 1] = new Godzina(ileKlas);
}

bool Plan::sprawdzNull (int dzien, int godzina)
{
	if (tydzien [dzien - 1][godzina - 1] == NULL)
		return true;
	else
		return false;
}

void dodajZajecia (Plan & lekcje, int ileKlas)
{
	string nazwa;
	int dzien;
	int godzina;
	cout << "Podaj dzieñ(pon, wt, sr, czw, pt):" << endl;
	cin >> nazwa;
	cout << "Podaj godzinê(1 - 8):" << endl;
	cin >> godzina;
	if (nazwa == "pon")
	{
		if (lekcje.sprawdzNull(1, godzina))
			lekcje.wpisz(1, godzina, ileKlas);
	}
	if (nazwa == "wt")
	{
		if (lekcje.sprawdzNull(2, godzina))
			lekcje.wpisz(2, godzina, ileKlas);
	}
	if (nazwa == "sr")
	{
		if (lekcje.sprawdzNull(3, godzina))
			lekcje.wpisz(3, godzina, ileKlas);
	}
	if (nazwa == "czw")
	{
		if (lekcje.sprawdzNull(4, godzina))
			lekcje.wpisz(4, godzina, ileKlas);
	}
	if (nazwa == "pt")
	{
		if (lekcje.sprawdzNull(5, godzina))
			lekcje.wpisz(5, godzina, ileKlas);
	}
}



