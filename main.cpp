#include <iostream>
#include <string.h>
#include "Header.h"



int main() 
{
	int ileKlas, b;
	Godzina * wsk;
	cout << "Podaj dla ilu klas chcesz u³o¿yæ plan zajêæ: " << endl;
	cin >> ileKlas;
	Plan lekcje;
	while (1)
	{
		system ("cls");
		cout << "1. Dodaj zajêcia		2.Zobacz plan" << endl;
		cout << "0. WyjdŸ" << endl;
		cin >> b;
		switch (b)
		{
			case 1:
				dodajZajecia(lekcje, ileKlas);
				break;
			case 2:
				wyswietlPlan(lekcje);
				cout << endl;
				system("pause");
				break;
			case 0:
				return 0;
		}
	}

	
}
