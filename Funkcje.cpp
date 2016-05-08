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

/*Godzina::Godzina(int i) 						//na razie nie dzia³a, nie wiem jak zrobiæ, ¿eby dzia³a³o 
{
	tablica = new Objekt [i];
}
*/
