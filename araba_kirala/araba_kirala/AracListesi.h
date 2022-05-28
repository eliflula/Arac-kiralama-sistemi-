#ifndef ARACLISTESI_H
#define ARACLISTESI_H

#include "Arac.h"
#include <cstdlib> 	// bellek fonsksiyonlar� i�in 

//////////////// Ara� Listesi i�in Node tan�m� ////////////////

struct aracNode
{
	Arac* arac; 
	aracNode* sonraki;	
};

//////////////// Ara� Listesi S�n�f� ////////////////

class AracListesi
{
	public:
		AracListesi();		// yap�c� fonksiyon
		void aracListesiniEkranaBas();
		void kiralanabilirAracListesiniEkranaBas();
		void aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi);
		bool aracSil(int aracNo);
		bool aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model);
		Arac& aracGetir(int aracNo);		// referansla getirir
		Arac aracOku(int aracNo);			// de�er ile okur
		aracNode *bas;		// listenin ilk node'u
		int aracSayisi;
};

#endif
