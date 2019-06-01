#include <iostream>
#include "plansza.h"
#include <cmath>
#include "minmax.h"

using namespace std;

int main()
{
	int rozmiar;
	gra kolkokrzyzyk;
	int wybor;
	char kto_zaczyna;
	char **macierz;
	
	cout << "Witaj w grze kolko i krzyzyk." << endl;
	cout << "Podaj rozmiar planszy: ";
	cin >> rozmiar;
	kolkokrzyzyk.stworz_plansze(rozmiar);
	kolkokrzyzyk.okresl_ilosc();

	cout << "Wybierz tryb gry: " << endl << "1 - Latwy" << endl << "2 - Trudny" << endl;
	cout << "Twoj wybor: ";
	cin >> wybor;
	cout << "Czy chcesz zaczac gre? (t/n): ";
	cin >> kto_zaczyna;
	switch (wybor)
	{
	case 1:
	{
		for (int i = 0; i < rozmiar*rozmiar / 2; i++)
		{
			if (kolkokrzyzyk.kto_zaczyna(kto_zaczyna))
			{
				kolkokrzyzyk.wybierz_pole();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == 10)
						cout << "Koniec gry. Wygrywa X!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
				kolkokrzyzyk.graczSI();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == -10)
						cout << "Koniec gry. Wygrywa O!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
			}
			if (!kolkokrzyzyk.kto_zaczyna(kto_zaczyna))
			{
				kolkokrzyzyk.graczSI();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == -10)
						cout << "Koniec gry. Wygrywa O!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
			}
			
		}
		break;
	}
	case 2:
	{
		double n = rozmiar * rozmiar;
		n = ceil(n / 2.0);
		for (int i = 0; i <n ; i++)
		{
			if (kolkokrzyzyk.kto_zaczyna(kto_zaczyna))
			{
				kolkokrzyzyk.wybierz_pole();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == 10)
						cout << "Koniec gry. Wygrywa X!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
				
				kolkokrzyzyk.aiMove();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == -10)
						cout << "Koniec gry. Wygrywa O!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
			}
			if (!kolkokrzyzyk.kto_zaczyna(kto_zaczyna))
			{
				kolkokrzyzyk.aiMove();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == -10)
						cout << "Koniec gry. Wygrywa O!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
				kolkokrzyzyk.wybierz_pole();
				kolkokrzyzyk.wyswietl();
				if (kolkokrzyzyk.sprawdz_wygrana())
				{
					if (kolkokrzyzyk.sprawdz_wygrana() == 10)
						cout << "Koniec gry. Wygrywa X!" << endl;
					break;
				}
				if (kolkokrzyzyk.sprawdz_remis())
				{
					cout << "Remis" << endl;
					break;
				}
			}
				
		}
		break;
	}
	}
	system("pause");
}