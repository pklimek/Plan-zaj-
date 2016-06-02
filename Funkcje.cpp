#include <iostream>
#include <string.h>
#include "Header.h"


Objekt::Objekt (string l, int sala, string prowadzacy, string k)	 	   //definicja konstruktora
{
	nazwaKlasy = l;
	numerSali = sala;
	nauczyciel = prowadzacy;
	przedmiot = k;
}

void Objekt::wyswietl(void)							//definicja funckji
{
	cout << "Klasa: " << nazwaKlasy;
	cout << "	Sala: " << numerSali;
	cout << "	Prowadz¹cy: " << nauczyciel;
	cout << "	Przedmiot: " << przedmiot << endl;
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
			tablica[k] -> wyswietl ();
		}
	}
}

Godzina::~Godzina(void)
{
	if (tablica != NULL)
		delete [] tablica;
}

Plan::Plan ()
{
	tydzien = new Godzina **[5];						  //5 dni tygodnia
	for (int i; i < 5; i++)
	{
		tydzien [i] = new Godzina *[8];					  //maksymalnie 8 godzin dziennie
		for (int k = 0; k < 8; k++)
			tydzien [i][k] = NULL;
	}
}

Plan::~Plan(void)
{
	for (int i = 0; i<5; i++)
	{
		if (tydzien[i] != NULL)
			delete tydzien [i];
	}
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
	if (tydzien[dzien - 1][godzina - 1] != NULL)
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
		cout << "Podaj klasê dla której chcesz wpisaæ zajêcia:";
		cin >> klasa;
		cout << "Podaj przedmiot:";
		cin >> przedmiot;
		cout << "Podaj salê w której odbêd¹ siê zajêcia:";
		cin >> sala;
		cout << "Podaj prowadz¹cego:";
		cin >> prowadzacy;
		tablica [i] = new Objekt(klasa, sala, prowadzacy, przedmiot);
		return ;
	}
	i++;
	if (i >= ileKlas)
	{
		cout << "Wszystkie Klasy maj¹ w tym czasie zajêcia" << endl;
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
	cout << "Podaj dzieñ(pon, wt, sr, czw, pt):" << endl;
	cin >> nazwa;
	cout << "Podaj godzinê(1 - 8):" << endl;
	cin >> godzina;
	if (nazwa == "pon")
		dzien = 1;
	else if (nazwa == "wt")
		dzien = 2;
	else if (nazwa == "sr")
		dzien = 3;
	else if (nazwa == "czw")
		dzien = 4;
	else if (nazwa == "pt")
		dzien = 5;
	lekcje.wpiszGodzine(dzien, godzina, ileKlas);
	lekcje.wpiszObjekt (dzien, godzina, ileKlas);
}


void wyswietlPlan(Plan & lekcje)
{
	for (int k = 0; k < 5; k++)
	{
		switch (k)
		{
			case 0:
			cout << "Poniedzialek:" << endl;
			break;
			case 1:
			cout << "Wtorek:" << endl;
			break;
			case 2:
			cout << "Sroda:" << endl;
			break;
			case 3:
			cout << "Czwartek:" << endl;
			break;
			case 4:
			cout << "Piatek:" << endl;
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			if(!(lekcje.sprawdzNull(k + 1, i + 1)))
			{
				cout << "Godzina: " << i+1 << endl;
				lekcje.wyswietl(k + 1, i + 1);
			}
		}
	}
}



