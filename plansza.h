#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>


using namespace std;

class gra
{
	char gracz;
	char** macierz;
	int rozmiar;
	int ilosc_w_rzedzie;
	int kolumna, wiersz;

public:

	void graczSI()
	{
		//int wiersz, kolumna;
		do {
			wiersz = rand() % rozmiar;
			kolumna = rand() % rozmiar;

		} while (macierz[kolumna][wiersz] != ' ');
		if (gracz == 'X') macierz[kolumna][wiersz] = 'O';
		else macierz[kolumna][wiersz] = 'X';
	}

	int sprawdz_wygrana()
	{

		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{

				if (macierz[i][j] == 'X' || macierz[i][j] == 'O')
				{
					if (i < rozmiar + 1 - ilosc_w_rzedzie)
					{
						int dol = sprawdz_w_dol(i, j);
						if (dol != 0) return dol;
					}
					if (j < rozmiar + 1 - ilosc_w_rzedzie)
					{
						int prawo = sprawdz_w_prawo(i, j);
						if (prawo != 0) return prawo;
					}
					if (i < rozmiar + 1 - ilosc_w_rzedzie && j < rozmiar + 1 - ilosc_w_rzedzie)
					{
						int skos_prawo = sprawdz_po_skosie_prawo(i, j);
						if (skos_prawo != 0) return skos_prawo;
					}
					if (i < rozmiar + 1 - ilosc_w_rzedzie && j > rozmiar - 1 - ilosc_w_rzedzie)
					{
						int skos_lewo = sprawdz_po_skosie_lewo(i, j);
						if (skos_lewo != 0) return skos_lewo;
					}

				}
			}
		}
		return false;
	}
	int sprawdz_w_dol(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie)
			return 10;
		if (licznikO == ilosc_w_rzedzie)
			return -10;
		return 0;
	}
	int sprawdz_w_prawo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz][kolumna + i] == 'X') licznikX++;
			if (macierz[wiersz][kolumna + i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie)
			return 10;
		if (licznikO == ilosc_w_rzedzie)
			return -10;
		return 0;
	}
	int sprawdz_po_skosie_prawo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna + i] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna + i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie)
			return 10;
		if (licznikO == ilosc_w_rzedzie)
			return -10;
		return 0;
	}
	int sprawdz_po_skosie_lewo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna - i] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna - i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie)
			return 10;
		if (licznikO == ilosc_w_rzedzie)
			return -10;
		return 0;
	}
	void wyswietl()
	{
		system("cls");
		for (int i = 0; i < rozmiar; i++, cout << endl)
		{
			cout << "|";
			for (int j = 0; j < rozmiar; j++)
			{
				cout << macierz[i][j] << " |";
			}
			cout << endl;
			for (int i = 0; i < 3 * rozmiar; i++)
			{
				cout << ".";
			}
		}
	}
	void stworz_plansze(int rozmiar)
	{
		this->rozmiar = rozmiar;
		macierz = new char*[rozmiar];

		for (int i = 0; i < rozmiar; i++)
		{
			macierz[i] = new char[rozmiar];
			for (int j = 0; j < rozmiar; j++)
			{
				macierz[i][j] = ' ';
			}
		}
		wyswietl();
	}
	void wybierz_gracza()
	{
		do
		{
			cout << "Wybierz X lub O: ";
			cin >> gracz;
			if (gracz == 'X' || gracz == 'O')
			{
				cout << "Wybrales gracza " << gracz << endl;
				break;
			}
			else
				cout << "Niepoprawnie wpisany znak, sprobuj jeszcze raz." << endl;
		} while (gracz != 'X' || gracz != 'O');


		cout << "Podaj ilosc tych samych znakow w rzedzie, potrzebna do wygranej: " << endl;
		do {
			cin >> ilosc_w_rzedzie;
		} while (ilosc_w_rzedzie > rozmiar || ilosc_w_rzedzie < 2);
	}
	bool czy_zajete(int wiersz, int kolumna)
	{
		if (macierz[wiersz][kolumna] == 'X' || macierz[wiersz][kolumna] == 'O')
		{
			cout << "To pole jest zajete. Wybierz inne pole." << endl;
			return false;
		}
		else
			return true;
	}
	void wybierz_pole()
	{
		//int wiersz, kolumna;
		cout << "Wprowadz wartosc z przedzialu 1 do " << rozmiar << ": " << endl;
		do {
			do {
				cout << "Podaj wspolrzedna wiersza: " << endl;
				cin >> wiersz;
				wiersz--;
			} while (wiersz < 0 || wiersz >= rozmiar);
			do {
				cout << "Podaj wspolrzedna kolumny: " << endl;
				cin >> kolumna;
				kolumna--;
			} while (kolumna < 0 || kolumna >= rozmiar);
			czy_zajete(wiersz, kolumna);
		} while (macierz[wiersz][kolumna] != ' ');

		macierz[wiersz][kolumna] = gracz;

	}
	int max(int wartosc1, int wartosc2)
	{
		if (wartosc1 > wartosc2)
			return wartosc1;
		return wartosc2;
	}

	int min(int wartosc1, int wartosc2)
	{
		if (wartosc1 < wartosc2)
			return wartosc1;
		return wartosc2;
	}

	int minimax(char **macierz, int glebokosc, bool czy_max)
	{
		int wynik = sprawdz_wygrana();

		if (wynik == 10)
			return wynik;
		if (wynik == -10)
			return wynik;

		int bestValue = -1000;
		if (czy_max)
		{

			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					if (macierz[i][j] == ' ')
					{
						macierz[i][j] = 'X';
						int wartosc = minimax(macierz, glebokosc + 1, false);// value = minmax(board,depth+1,false)
						bestValue = max(bestValue, wartosc);// bestVal = max(bestVal, value)

						macierz[i][j] = ' ';
					}
				}
			}
			return bestValue;
		}
		else
		{
			int bestValue = 1000;
			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					if (macierz[i][j] == ' ')
					{
						macierz[i][j] = 'O';
						int wartosc = minimax(macierz, glebokosc + 1, false);// value = minmax(board,depth+1,false)
						bestValue = min(bestValue, wartosc);// bestVal = max(bestVal, value)

						macierz[i][j] = ' ';
					}
				}
			}
			return bestValue;
		}
	}
	gra znajdz_najlepszy_ruch(char **macierz)
	{
		int bestValue = -1000;
		gra bestMove;
		bestMove.wiersz = -1;
		bestMove.kolumna = -1;

		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] == ' ')
				{
					macierz[i][j] = 'X';
					int moveVal = minimax(macierz, 0, false);
					macierz[i][j] = ' ';

					if (moveVal > bestValue)
					{
						bestMove.wiersz = i;
						bestMove.kolumna = j;
						bestValue = moveVal;
					}
				}
			}
		}
		return bestMove;
	}
}


#endif PLANSZA_H
