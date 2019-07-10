// soru2.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	//De�i�ken tan�mlar�m�z� yapt�k.
	int a, b, c, i;
	int sayac = 0, toplam = 0;
	int iSay, jSay; 

	for (i = 100; i <= 999; i++) // Say� de�erimizi 100'den ba�latarak 999'a kadar bir d�ng�ye sokuyoruz.
	{
		// A�a��da say�lar�m�z�n basamak de�erlerini bulmam�z� sa�layacak form�ller yaz�yoruz. 
		a = i % 10; // Birler basama��
		b = (i % 100) / 10; // Onlar basama��
		c = (i - 10 * b - a) / 100; // Y�zler basama��

		if (a != b && b != c && a != c) // Say�lar�m�za rakamlar�n�n farkl� olmas� �art�n� sa�l�yoruz.
		{
			cout << " " << i; // Say�lar�m�z� yazd�r�yoruz.
			sayac++;
		}
	}

	cout << "\n3 BASAMAKLI RAKAMLARI FARKLI " << sayac << " SAYI VARDIR."; // Say�lar�n adetini yazd�r�yoruz.

	for (iSay = 100; iSay<999; iSay++) // 3 basamakl� say�lar aras�nda yeni bir d�ng� kuruyoruz.
	{
		toplam = 0; // Toplam bir de�er bulaca��m�z i�in bu toplam de�erini ilk olarak 0'a e�itliyoruz.

		for (jSay = 1; jSay <= iSay / 2; jSay++) // Say�lar�m�z�n b�lenlerini hesaplayacak d�ng�y� ba�lat�yoruz.
		{
			if (iSay%jSay == 0) // M�kemmel say�lar�m�z� hesaplayacak i�lemi ger�ekle�tiriyoruz.
				toplam += jSay;
		}

		if (toplam == iSay) //M�kemmel say� olma �art�n� sa�layacak d�ng�y� kuruyoruz.
			cout << "\n3 BASAMAKLI MUKEMMEL SAYILAR : " << toplam; // Ve toplam m�kemmel say�lar�m�z� yazd�r�yoruz.
	}

	getch();

	return 0;
}



