#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
//#include<bits/stdc++.h>
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
	//vector<int> wiersze;
	//vector<int> kolumny;


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
		//system("cls");
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
	void wybierz_gracza()
	{
		do {
			cout << "Wybierz gracza X lub O " << endl;
			cin >> gracz;
			if (gracz == 'X' || gracz == 'O')
				break;
			else
				cout << "Wpisano zly znak, prosze sprobowac jeszcze raz" << endl;
		} while (gracz != 'X' || gracz != 'O');

		cout << "Podaj ilosc pol potrzebna do wygranej" << endl;
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
	void wybierz_pole()
	{
		int wiersz, kolumna;
		cout << "Wprowadz wartosc z przedzialu 1 do " << rozmiar << endl;
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
			//czy_zajete(wiersz, kolumna);
		} while (macierz[wiersz][kolumna] != ' ');

		macierz[wiersz][kolumna] = gracz;

	}
	/*void co_wybrales()
	{
		char huPlayer, aiPlayer;
		if (gracz == 'X')
		{
			huPlayer = 'X';
			aiPlayer = 'O';
		}
		else
		{
			huPlayer = 'X';
			aiPlayer = 'O';
		}
	}*/
	//int czy_puste() //Tworzy 2 vectory indeksow wolnych pol
	//{
	//	int wolnych_pol = 0;
	//	for (int i = 0; i < rozmiar; i++)
	//	{
	//		for (int j = 0; j < rozmiar; j++)
	//		{
	//			if (macierz[i][j] == ' ')
	//			{
	//				wolnych_pol++;
	//				wiersze.push_back(i);
	//				kolumny.push_back(j);
	//			}
	//		}

	//	}
	//	//cout << "Wolnych pol: " << wolnych_pol << endl;
	//	return wolnych_pol;
	//}
	//void wypisz_puste() // wypisuje wartosci indeksow wolnych pol z vectorow
	//{
	//	wiersze.clear();
	//	kolumny.clear();
	//	czy_puste();
	//	for (int i = 0; i < wiersze.size(); i++)
	//	{
	//		cout << "A teraz: " << wiersze[i] << "Kolumny: " << kolumny[i] << endl;
	//	}
	//}
	/*int findBestMove(char **macierz)
	{
		int bestMove = NULL;
	}*/
	//	float zwroc_wieksza(float wartosc1, float wartosc2)
//	{
//		if (wartosc1 > wartosc2)
//			return wartosc1;
//		return wartosc2;
//	}
//	float zwroc_mniejsza(float wartosc1, float wartosc2)
//	{
//		if (wartosc1 < wartosc2)
//			return wartosc1;
//		return wartosc2;
//	}
//	int minimax(int depth, bool isMax)
//	{
//		int score = sprawdz_wygrana(); //10 dla gracza, -10 dla komputera, 0 nikt nie wygrywa
//		if (score == 10)
//			return score;
//		if (score == -10)
//			return score;
//		if (czy_puste() == 0)
//			return 0;
//
//		if (isMax)
//		{
//			int best = -1000;
//
//			for (int i = 0; i < rozmiar; i++)
//			{
//				for (int j = 0; j < rozmiar; j++)
//				{
//					if (macierz[i][j] == ' ')
//					{
//						macierz[i][j] = 'X';
//						best = zwroc_wieksza(best, minimax(depth + 1, !isMax));
//						macierz[i][j] = ' ';
//					}
//				}
//			}
//			return best;
//		}
//		else
//		{
//			int best = 1000;
//			for (int i = 0; i < rozmiar; i++)
//			{
//				for (int j = 0; j < rozmiar; j++)
//				{
//					if (macierz[i][j] == ' ')
//					{
//						macierz[i][j] = 'O';
//						best = zwroc_mniejsza(best, minimax(depth + 1, !isMax));
//						macierz[i][j] = ' ';
//					}
//				}
//			}
//			return best;
//		}
//
//
//	}
//	Move finddBestMove(char **macierz)
//	{
//		Move bestMove;
//		bestMove.row = -1;
//		bestMove.col = -1;
//		int bestValue = -1000;
//		int bestRow, bestCol;
//		for (int i = 0; i < rozmiar; i++)
//		{
//			for (int j = 0; j < rozmiar; j++)
//			{
//				macierz[i][j] = 'X';
//				int moveVal = minimax(0, false);
//				macierz[i][j] = ' ';
//				if (moveVal > bestValue)
//				{
//					bestMove.row = i;
//					bestMove.col = j;
//					bestValue = moveVal;
//				}
//			}
//		}
//		cout << "The value of the best move is: " << bestValue << endl;
//		cout << "best row: " << bestMove.row << " best column " << bestMove.col << endl;
//		macierz[bestMove.row][bestMove.col] = 'O';
//		return bestMove;
//	}

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
		if (glebokosc > 5)
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
		if (glebokosc > 5)
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