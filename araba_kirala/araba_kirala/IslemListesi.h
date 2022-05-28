#ifndef ISLEMLISTESI_H
#define ISLEMLISTESI_H
#include <cstdlib> 	// bellek fonsksiyonlar� i�in 
#include <iostream>
#include <fstream>		// dosya i�lemleri i�in
#include <ctime>		// tarih i�lemleri i�in		
using namespace std; 	// string s�n�f� i�in

//////////////// Islem Listesi i�in Node tan�m� ////////////////

struct islemNode
{
	int islemNo;
	int islemTutari; 
	struct tm islemTarihi;
	islemNode* sonraki;	
};

class IslemListesi
{
	public:
		IslemListesi();		// yap�c� fonksiyon
		void islemEkle(int islemTutari);
		void islemEkle(int islemTutari, int gun, int ay, int yil);
		int tutarOku(int islemNo);
		void guncelle();
		void islemListesiniDosyayaYaz();
		void islemListesiniDosyadanOku();
		int islemSayisi;
		islemNode* bas;	
};

#endif
