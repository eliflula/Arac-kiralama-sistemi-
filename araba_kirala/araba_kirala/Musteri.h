#ifndef MUSTERI_H
#define MUSTERI_H

#include "Arac.h"
#include "AracListesi.h"
#include <iostream>
#include <ctime>		// tarih i�lemleri i�in		
using namespace std; 	// string s�n�f� i�in

//////////////////// M��teri S�n�f� ////////////////////////////

class Musteri
{
	public:
		Musteri();	// parametresiz yap�c� fonksiyon
		Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);		// parametreli yap�c� fonksiyon
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
