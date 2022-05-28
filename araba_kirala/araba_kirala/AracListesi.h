#ifndef ARACLISTESI_H
#define ARACLISTESI_H

#include "Arac.h"
#include <cstdlib> 	// bellek fonsksiyonlarý için 

//////////////// Araç Listesi için Node tanýmý ////////////////

struct aracNode
{
	Arac* arac; 
	aracNode* sonraki;	
};

//////////////// Araç Listesi Sýnýfý ////////////////

class AracListesi
{
	public:
		AracListesi();		// yapýcý fonksiyon
		void aracListesiniEkranaBas();
		void kiralanabilirAracListesiniEkranaBas();
		void aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi);
		bool aracSil(int aracNo);
		bool aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model);
		Arac& aracGetir(int aracNo);		// referansla getirir
		Arac aracOku(int aracNo);			// deðer ile okur
		aracNode *bas;		// listenin ilk node'u
		int aracSayisi;
};

#endif
