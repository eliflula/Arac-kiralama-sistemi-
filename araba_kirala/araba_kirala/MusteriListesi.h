#ifndef MUSTERILISTESI_H
#define MUSTERILISTESI_H

#include "Musteri.h"
#include "AracListesi.h"
#include "IslemListesi.h"
#include <cstdlib> 	// bellek fonsksiyonlar� i�in 

//////////////// M�steri Listesi i�in Node tan�m� ////////////////

struct musteriNode
{
	Musteri* musteri; 
	musteriNode* sonraki;	
};


//////////////// Ara� Listesi S�n�f� ////////////////

class MusteriListesi
{
	public:
		MusteriListesi();		// yap�c� fonksiyon
		void musteriListesiniEkranaBas();
		void musteriEkle(AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, 
						string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);
		bool musteriSil(int musteriNo, AracListesi& aracListesi);
		bool musteriGuncelle(int musteriNo, AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, 
							struct tm dogumTarihi, string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);
		Musteri& musteriGetir(int musteriNo);
		musteriNode *bas;
		int musteriSayisi;
};		
		
#endif
