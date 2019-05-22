#include <iostream>
#include "plansza.h"

using namespace std;

int main()
{
	int rozmiar;
	gra kolkokrzyzyk;
	int wybor;
	
	cout << "Podaj rozmiar planszy: ";
	cin >> rozmiar;
	kolkokrzyzyk.stworz_plansze(rozmiar);
	kolkokrzyzyk.wybierz_gracza();

	cout << "Wybierz tryb gry: " << endl << "1 - Latwy" << endl << "2 - Trudny" << endl;
	cout << "Twoj wybor: " << endl;
	cin >> wybor;

	switch (wybor)
	{
	case 1:
	{
		do {
			kolkokrzyzyk.wybierz_pole();
			kolkokrzyzyk.graczSI();
			kolkokrzyzyk.wyswietl();
			if (kolkokrzyzyk.sprawdz_wygrana())
			{
				cout << "Koniec gry" << endl;
				break;
			}
		} while (rozmiar*rozmiar / 2); //iloœæ ruchów
		break;
	}
	case 2:
	{
		//algorytm minmax
	}
	}
	
	system("pause");
}