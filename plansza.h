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

	bool sprawdz_wygrana()
	{
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (macierz[i][j] == 'X' || macierz[i][j] == 'O')
				{
					if (i < rozmiar + 1 - ilosc_w_rzedzie)
						if (sprawdz_w_dol(i, j)) return true;
					if (j < rozmiar + 1 - ilosc_w_rzedzie)
						if (sprawdz_w_prawo(i, j)) return true;
					if (i < rozmiar + 1 - ilosc_w_rzedzie && j < rozmiar + 1 - ilosc_w_rzedzie)
						if (sprawdz_po_skosie_prawo(i, j)) return true;
					if (i < rozmiar + 1 - ilosc_w_rzedzie && j > rozmiar - 1 - ilosc_w_rzedzie)
						if (sprawdz_po_skosie_lewo(i, j)) return true;
				}
			}
		}
		return false;
	}
	bool sprawdz_w_dol(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie || licznikO == ilosc_w_rzedzie)
			return true;
		return false;
	}
	bool sprawdz_w_prawo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz][kolumna + i] == 'X') licznikX++;
			if (macierz[wiersz][kolumna + i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie || licznikO == ilosc_w_rzedzie)
			return true;
		return false;
	}
	bool sprawdz_po_skosie_prawo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna + i] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna + i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie || licznikO == ilosc_w_rzedzie)
			return true;
		return false;
	}
	bool sprawdz_po_skosie_lewo(int wiersz, int kolumna)
	{
		int licznikX = 0, licznikO = 0;
		for (int i = 0; i < ilosc_w_rzedzie; i++)
		{
			if (macierz[wiersz + i][kolumna - i] == 'X') licznikX++;
			if (macierz[wiersz + i][kolumna - i] == 'O') licznikO++;
		}
		if (licznikX == ilosc_w_rzedzie || licznikO == ilosc_w_rzedzie)
			return true;
		return false;
	}
	void wyswietl()
	{
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
		cout << "Wybierz X lub O: ";
		cin >> gracz;
		if (gracz == 'X' || gracz == 'O')
			cout << "Wybrales gracza " << gracz << endl;
		else
			cout << "Niepoprawnie wpisany znak";
		cout << "Podaj ilosc potrzebna do wygranej" << endl;
		do {
			cin >> ilosc_w_rzedzie;
		} while (ilosc_w_rzedzie > rozmiar || ilosc_w_rzedzie < 2);
	}

	void wybierz_pole()
	{
		int wiersz, kolumna;
		cout << "Wprowadz wartosc z przedzialu 1 do " << rozmiar << endl;
		do {
			do {
				cout << "Podaj wspolrzedna x: " << endl;
				cin >> wiersz;
				wiersz--;
			} while (wiersz < 0 || wiersz >= rozmiar);
			do {
				cout << "Podaj wspolrzedna kolumna: " << endl;
				cin >> kolumna;
				kolumna--;
			} while (kolumna < 0 || kolumna >= rozmiar);
		} while (macierz[wiersz][kolumna] != ' ');

		macierz[wiersz][kolumna] = gracz;

	}
};



#endif PLANSZA_H
