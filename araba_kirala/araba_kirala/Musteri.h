#ifndef MUSTERI_H
#define MUSTERI_H

#include "Arac.h"
#include "AracListesi.h"
#include <iostream>
#include <ctime>		// tarih iþlemleri için		
using namespace std; 	// string sýnýfý için

//////////////////// Müþteri Sýnýfý ////////////////////////////

class Musteri
{
	public:
		Musteri();	// parametresiz yapýcý fonksiyon
		Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);		// parametreli yapýcý fonksiyon
		void aracTeslimEt(AracListesi& aracListesi);
		unsigned long long int tc;
		string ad;
		string soyad;
		struct tm dogumTarihi;
		string dogumYeri;
		char cinsiyet;
		struct tm ehliyetVerilis;
		struct tm ehliyetGecerlilik;
		string kanGrubu;
		Arac arac;
		int kiralamaSuresi;
		int musteriNo;
};

#endif
