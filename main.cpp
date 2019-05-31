#include <iostream>
#include "plansza.h"
#include <cmath>

using namespace std;

int main()
{
	int rozmiar;
	gra kolkokrzyzyk;
	int wybor;
	char **macierz;
	

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
		for (int i = 0; i < rozmiar*rozmiar / 2; i++)
		{
			//kolkokrzyzyk.minimax(0, false);
			//kolkokrzyzyk.finddBestMove();
			//kolkokrzyzyk.wypisz_puste();
			kolkokrzyzyk.wybierz_pole();
			kolkokrzyzyk.wyswietl();
			if (kolkokrzyzyk.sprawdz_wygrana())
			{
				if (kolkokrzyzyk.sprawdz_wygrana() == 10)
					cout << "Koniec gry. Wygrywa X!" << endl;
				break;
			}
			//kolkokrzyzyk.finddBestMove(macierz);
			kolkokrzyzyk.graczSI();
			kolkokrzyzyk.wyswietl();
			if (kolkokrzyzyk.sprawdz_wygrana())
			{
				if (kolkokrzyzyk.sprawdz_wygrana() == -10)
					cout << "Koniec gry. Wygrywa O!" << endl;
				break;
			}
			//kolkokrzyzyk.finddBestMove();

			/*if (kolkokrzyzyk.sprawdz_remis())
			{
				cout << "Remis" << endl;
				break;
			}*/
		}
		break;
	}
	case 2:
	{
		double n = rozmiar * rozmiar;
		n = ceil(n / 2.0);
		for (int i = 0; i <n ; i++)
		{
			//kolkokrzyzyk.minimax(0, false);
			//kolkokrzyzyk.finddBestMove();
			//kolkokrzyzyk.wypisz_puste();
			//kolkokrzyzyk.finddBestMove(macierz);
			
			kolkokrzyzyk.aiMove();
			kolkokrzyzyk.wyswietl();
			if (kolkokrzyzyk.sprawdz_wygrana())
			{
				if (kolkokrzyzyk.sprawdz_wygrana() == -10)
					cout << "Koniec gry. Wygrywa O!" << endl;
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
			
			
			//kolkokrzyzyk.finddBestMove();

			/*if (kolkokrzyzyk.sprawdz_remis())
			{
				cout << "Remis" << endl;
				break;
			}*/
		}
		break;
	}




	}

	system("pause");
}