#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double aylikOdemeHesapla (double,double,double); //double t�r�nden fonksiyon tan�mlad�k.
int main(int argc, char *argv[]) {
	int i; //integer t�r�nden bir i de�i�keni tan�mlad�k.
	double krediTutari, faizOrani, taksitSayisi, toplamKrediOdemesi=0; //double t�r�nden de�i�kenlerimizi tan�mlad�k.
	double kalanAnaParaBorcu=krediTutari, odenenFaizTutari, odenenAnaParaTutari; //double t�r�nden, de�i�kenlerimizi tan�mlad�k.
	
	//�dev metninde belirtildi�i gibi gerekli girdilerimizi ald�k.
	printf("Toplam Kredi Miktari : "); 
	scanf("%lf", &krediTutari);
	
	printf("Faiz Orani  : ");
	scanf("%lf", &faizOrani);
	
	printf("Taksit Sayisi  : ");
	scanf("%lf", &taksitSayisi);
	
	double aylikTaksitTutari = aylikOdemeHesapla (krediTutari, faizOrani ,taksitSayisi); //Hesaplamalar i�in double de�i�kenler

	printf("\nTaksit No \t\t   Taksit Tutari \t Odenen Faiz Tutari \t Odenen Ana Para Tutari \t Kalan Ana Para Borcu"); //Bulunan de�erleri yazd�rmak i�in
	
	kalanAnaParaBorcu=krediTutari; //Atama i�lemi
	
	for (i=1; i<=taksitSayisi; i++) { //taksit say�s�>=i ise
	
		//kredi i�lemleri
		odenenFaizTutari = kalanAnaParaBorcu * (faizOrani/100); 
		odenenAnaParaTutari = aylikTaksitTutari - odenenFaizTutari ;
		kalanAnaParaBorcu = kalanAnaParaBorcu  - odenenAnaParaTutari;
		
		printf("\n   %d\t\t\t\t%.2lf\t\t         %.2lf\t\t\t  %.2lf\t\t\t      %.2lf", i, aylikTaksitTutari, odenenFaizTutari, odenenAnaParaTutari, kalanAnaParaBorcu); //Bulunan de�erleri yazd�rmak i�in	
		
   	    toplamKrediOdemesi = toplamKrediOdemesi + odenenAnaParaTutari; //Atama i�lemi yap�ld�
	   
	}
	
	//Ayl�k �deme ve toplam kredi �demesini yazd�rmak i�in
    printf("\n\nAylik Odemeniz : \t%.2lf", aylikTaksitTutari);
	printf("\nToplam Kredi Odemesi : \t%.2lf", aylikTaksitTutari*taksitSayisi);
	
	return 0;
	
}

double aylikOdemeHesapla (double krediTutari, double faiz, double taksitSayisi) { //Fonksiyonumuzu �a��rd�k.
	//Faiz oran� hesaplama
	double faizOrani = faiz/100; 
	return  krediTutari * (faizOrani*pow(1+faizOrani,taksitSayisi) / (pow(1+faizOrani,taksitSayisi)-1) ); //Tutarlar� hesaplay�p d�nd�r�yor.
} 
