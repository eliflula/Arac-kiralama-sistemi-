#ifndef MUSTERILISTESI_H
#define MUSTERILISTESI_H

#include "Musteri.h"
#include "AracListesi.h"
#include "IslemListesi.h"
#include <cstdlib> 	// bellek fonsksiyonlarý için 

//////////////// Müsteri Listesi için Node tanýmý ////////////////

struct musteriNode
{
	Musteri* musteri; 
	musteriNode* sonraki;	
};


//////////////// Araç Listesi Sýnýfý ////////////////

class MusteriListesi
{
	public:
		MusteriListesi();		// yapýcý fonksiyon
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
