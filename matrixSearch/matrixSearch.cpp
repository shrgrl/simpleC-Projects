# include<fstream>
# include<iostream>

using namespace std;

void MatrisOku(char[],int[][100],int&,int&);
void SonucYaz(char[],int[][2],int);
int Arama(const int [][100],const int[][100],int[][2],int,int,int,int); 

/* ilk parametre AnaMatris,ikinci parametre arananMatris,
 ucuncu parametre bulunan sonu�larin indislerinin yazildigi matris.
 Diger parametrelerde sirasiyla ana matrisin ve aranan matrisin satir ve sutun degeleri.
 fonksiyon geriye aranan matrsinin ana matris icersinde kac defa gectigini dondurecek.
 */

int main()
{
  char dosyaAdi1[]="AnaMatris.txt";
  char dosyaAdi2[]="ArananMatris.txt";
  char dosyaAdi3[]="Sonuc.txt";
  int anaMatris[100][100]; // maksimum 100*100 boyutunda oldugunu varsayin
  int arananMatris[100][100]; //// maksimum 100*100 boyutunda oldugunu varsayin
  int sonuclar[100][2]; // aranan matrisin maksimum 100 defa bulunabilecegini varsayin
  
  int satir,sutun; //ana matrisin satir ve sutun degerleri
  int arananSatir, arananSutun; // aranan matrisin satir ve sutun degerleri
  int sonucSayisi;
  
  
  MatrisOku(dosyaAdi1,anaMatris,satir,sutun); // Dosyadan Ana matrisi oku
  MatrisOku(dosyaAdi2,arananMatris,arananSatir,arananSutun); // Dosyadan Aranan matrisi oku
  
  sonucSayisi=Arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun); // Arama Islemi
  
  SonucYaz(dosyaAdi3,sonuclar,sonucSayisi);
}

/* �rnek dosyadan okuma ve yazma kodlar�:

Dosyaya veri yazd�rmak i�in:

int sayi = 5;
ofstream yazdir("dosyaAdi.txt", ios::app); 
yazdir << sayi << endl;// 5 degerini dosyaya yazdirir
yazdir.close();// dosyaya yazma i�lemi sonlandirilir


Dosyadan veri okumak i�in:

ifstream oku;
oku.open(�dosyaAdi.txt�);
oku>>degiskenAdi; // burada tek deger okunup degiskene atandi. Birden fazla deger okumak icin dongu kullaniniz.
oku.close();//dosyadan okuma islemi sonlandirilir

*/


//A�a��daki fonksiyonlar�n i�ini doldurarak �devinizi kodlay�n�z.
void MatrisOku(char dosyaAdi[],int matris[][100],int &satir,int &sutun)
{   
 ifstream oku; // okuma �zerinde bir dosya a�
 oku.open(dosyaAdi);
 oku>>satir>>sutun; // ilk iki sat�r okumak i�in (dizinin iki boyutu)
 for(int i = 0; i < satir; i++)
 {
    for(int j = 0; j < sutun; j++ )
	{
	    oku >> matris[i][j]; // dosyadan dizinin elemanlar� oku ve diziye at (dosyan�n ���nc� sat�r ve sonra
		cout << matris[i][j]<< ' '; // debug amac�yla diziyi ekrana yazd�rd�k
	}
	cout << '\n';
 } //65.sat�r
 cout << '\n';
 oku.close(); // dosya kapat 
}//60.sat�r
void SonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi)
{
 ofstream yazdir(dosyaAdi, ios::app); // yazma amac�yla bir dosya a�
 yazdir << sonucSayisi << endl;// ilk sat�rda sounsay�s�s yazd�r ve alt sat�ra ge�
 for(int i = 0; i < sonucSayisi; i++)
 {
    for(int j = 0; j < 2; j++ )
	{
	        yazdir << sonuclar[i][j] << ' ';
		cout << sonuclar[i][j]<< ' ';
 	}
	yazdir << endl;
	cout << '\n';
 }//81.sat�r
 yazdir.close();	
}//77.sat�r
int Arama(const int anaMatris[][100],const int arananMatris[][100],int sonuc[][2],int satir,int sutun,int arananSatir,int arananSutun)
{
 int count=0; // souncSay�s�
 int bulundu, i,j,p,q; // arama algoritma i�in 4 tane d�ng� sayac� tan�mlad�k ve e�er arana matris
//bulundu ise bulundu degi�kenin de�eri bir olsun bool veri tipinde de tan�mlasak olurdu
 for(i=0; i<satir; i++)
 {
   for(j=0; j<sutun; j++)
   {// ana Matrisi i�inde tara 
      bulundu=1;
      for(p=0; p<arananSatir; p++)
      { //elemanlari tek tek aliyoruz ve bizim aranan matris boyutlar�na g�re arama yap�yoruz
         for(int q=0; q< arananSutun; q++)
         {
            if(anaMatris[i+p][j+q] != arananMatris[p][q])//eger eleman komular�na e�it de�ilse 
            {
               bulundu=0;//yani aranan matris bulunamd�  
               break; // ve birsonraki elemana ge�iyoruz 
              
            }
         }
      }
      if(bulundu==1) // e�er matris bulund� ise 
      {
      	   ++count; // sonucsay�s� art�r
           printf("aranan matris bu indislerde bulundu : %d, %d\n",i ,j); // debug amac�yla sonu�lar ekrana da g�z�ks�n
           sonuc[count-1][0]=i; // sonu�lar sonuc matrise aktard�k (sonu� dosyas�)
           sonuc[count-1][1]=j;
           
       
      }
   }
   if(bulundu==1)
   {
   	    ++count;
        printf("\naranan matris bu indislerde bulundu %d, %d\n",i ,j);
        sonuc[count-1][0]=i;
        sonuc[count-1][1]=j;
        
      
   }
 }
 return count;	// sonu� say�s�s d�nd�r
}
