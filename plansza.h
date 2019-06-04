#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

class gra
{
	struct Move
	{
		int x = 0;
		int y = 0;
	};
	char gracz;
	char** macierz;
	int rozmiar;
	int ilosc_w_rzedzie;
public:

	void graczSI()
	{
		int wiersz, kolumna;
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

	bool sprawdz_remis()
	{
		int k = 0;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] != ' ')
					k++;
			}
		}
		if (k == rozmiar * rozmiar)
			return true;
		else
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
		//wyswietl();
	}
	void okresl_ilosc()
	{
		cout << "Podaj ilosc pol potrzebna do wygranej: ";
		do {
			cin >> ilosc_w_rzedzie;
		} while (ilosc_w_rzedzie > rozmiar || ilosc_w_rzedzie < 2);
	}
	bool czy_zajete(int wiersz, int kolumna)
	{
		if (macierz[wiersz][kolumna] == 'X' || macierz[wiersz][kolumna] == 'O')
		{
			cout << "To pole jest zajete. Wybierz inne pole" << endl;
			return false;
		}
		return true;
	}

	bool kto_zaczyna(char wybor)
	{
		if (wybor == 'T' || wybor == 't')
			return true;
		else if (wybor == 'N' || wybor == 'n')
			return false;
	}
	void wybierz_pole()
	{
		int wiersz, kolumna;
		cout << "Wprowadz wartosc z przedzialu 1 do " << rozmiar << endl;
		do {
			do {
				cout << "Podaj wspolrzedna wiersza: ";
				cin >> wiersz;
				wiersz--;
			} while (wiersz < 0 || wiersz >= rozmiar);
			do {
				cout << "Podaj wspolrzedna kolumny: ";
				cin >> kolumna;
				kolumna--;
			} while (kolumna < 0 || kolumna >= rozmiar);
			czy_zajete(wiersz, kolumna);
		} while (macierz[wiersz][kolumna] != ' ');

		macierz[wiersz][kolumna] = 'X';

	}

	//algorytm minimax
	
	Move minimax()
	{
		int score = numeric_limits<int>::max();
		Move move;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] == ' ')
				{
					macierz[i][j] = 'O';

					int temp = maxSearch(0);

					if (temp < score)
					{
						score = temp;
						move.x = i;
						move.y = j;
					}
					macierz[i][j] = ' ';
				}
			}
		}

		return move;
	}
	int maxSearch(int glebokosc)
	{
		
		int score = sprawdz_wygrana();
		if (score == 10 || score == -10)
			return score;
		if (sprawdz_remis())
			return 0;
		if (glebokosc > (8-rozmiar))
			return -1;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] == ' ')
				{
					macierz[i][j] = 'X';
					score = max(score, minSearch(glebokosc + 1));
					macierz[i][j] = ' ';
				}
			}
		}

		return score;
	}
	int minSearch(int glebokosc)
	{
		int score = sprawdz_wygrana();
		if (score == 10 || score == -10)
			return score;
		if (sprawdz_remis())
			return 0;
		if (glebokosc > (8-rozmiar))
			return -1;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] == ' ')
				{
					macierz[i][j] = 'O';
					score = min(score, maxSearch(glebokosc + 1));
					macierz[i][j] = ' ';
				}
			}
		}

		return score;
	}
	void aiMove()
	{
		Move aimove = minimax();
		//cout << aimove.x << " wiersz " << aimove.y << " kolumna \n";
		macierz[aimove.x][aimove.y] = 'O';
	}
};




#endif PLANSZA_H