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

/*Godzina::Godzina(int i) 						//na razie nie dzia�a, nie wiem jak zrobi�, �eby dzia�a�o 
{
	tablica = new Objekt [i];
}
*/
