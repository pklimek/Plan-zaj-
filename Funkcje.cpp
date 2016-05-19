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
	cout << "Prowadz�cy: " << nauczyciel << endl;
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
			return;
		}
	}
}
		

void Plan::wyswietl (int dzien, int godzina)
{
	tydzien[dzien - 1][ godzina - 1] -> wyswietl();
}

void Plan::wpiszGodzine (int dzien, int godzina, int ileKlas)
{
	if (tydzien [dzien - 1][godzina - 1] == NULL)
		tydzien[dzien - 1][godzina - 1] = new Godzina(ileKlas);
}

void Plan::wpiszObjekt (int dzien, int godzina, int ileKlas)
{
	if (tydzien [dzien - 1][godzina - 1] != NULL)
		(*tydzien[dzien - 1][godzina - 1]).wpiszObjekt(ileKlas);
	
} 


void Godzina::wpiszObjekt (int ileKlas)
{
	int sala;
	string prowadzacy, klasa, przedmiot;
	int i = 0;
	if (tablica[i] == NULL && i < ileKlas)
	{
		cout << "Podaj klas� dla kt�rej chcesz wpisa� zaj�cia:";
		cin >> klasa;
		cout << "Podaj przedmiot:";
		cin >> przedmiot;
		cout << "Podaj sal� w kt�rej odb�d� si� zaj�cia:";
		cin >> sala;
		cout << "Podaj prowadz�cego:";
		cin >> prowadzacy;
		tablica [i] = new Objekt(klasa, sala, prowadzacy, przedmiot);
		return ;
	}
	i++;
	if (i >= ileKlas)
	{
		cout << "Wszystkie Klasy maj� w tym czasie zaj�cia" << endl;
		return ;
	}
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
	cout << "Podaj dzie�(pon, wt, sr, czw, pt):" << endl;
	cin >> nazwa;
	cout << "Podaj godzin�(1 - 8):" << endl;
	cin >> godzina;
	if (nazwa == "pon")
	{
		dzien = 1;
	}
	if (nazwa == "wt")
	{
		dzien = 2;
	}
	if (nazwa == "sr")
	{
		dzien = 3;
	}
	if (nazwa == "czw")
	{
		dzien = 4;
	}
	if (nazwa == "pt")
	{
		dzien = 5;
	}
	lekcje.wpiszGodzine(dzien, godzina, ileKlas);
	lekcje.wpiszObjekt (dzien, godzina, ileKlas);
}



