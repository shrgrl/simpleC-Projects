// soru3.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;
int main()
{
	// De�i�ken de�erlerimizi tan�ml�yoruz.
	int sayi;
	int tahmin;
	int hak = 0;
	int secenek;

	// Rastgele �retilecek say� aral���n� belirliyoruz.
	srand(time(NULL));
	sayi = 1000 + rand() % 8999;

	do {
		hak++; // Kulland���m�z tahmin haklar�n�n say�lar�n� her defas�nda 1 art�rarak say� tahmin ediyoruz.
		cout << "Bir sayi tahmininde bulununuz : ";
		cin >> tahmin;

		if (sayi<tahmin && hak<20) // 20 tahmin hakk� tan�yarak say�n�n tahminden k���k olma durumunu belirliyoruz.
		{
			cout << "Buyuk Tahminde Bulundun!\n"; // Belirlenen �arta g�re verilen metni yazd�r�yoruz.
		}
		
		else if (sayi>tahmin && hak<20) // 20 tahmin hakk� tan�yarak say�n�n tahminden b�y�k olma durumunu belirliyoruz.
			cout << "Kucuk Tahminde Bulundun!\n"; // Belirlenen �arta g�re verilen metni yazd�r�yoruz.
		
		else if (sayi == tahmin) // Do�ru tahmin etme durumu.
			cout << hak << ". hakkinizda bildiniz!\n"; // Tahminimizi ka��nc� seferde tutturdu�umuzu yazd�r�yoruz.
		
		else
			cout << "Dogru tahminde bulunamadiniz!.\n"; // Tahmin haklar� doldu�u halde bilememi�sek bu metni yazd�r�yoruz.
	}

	while (tahmin != sayi && hak<20); // Tahmin say�ya e�it olmad��� s�rece 20 defa tekrarlama �art� d�ng�s�.

	getch();

	return 0;
}

