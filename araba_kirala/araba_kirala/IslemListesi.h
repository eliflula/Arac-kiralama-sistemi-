#ifndef ISLEMLISTESI_H
#define ISLEMLISTESI_H
#include <cstdlib> 	// bellek fonsksiyonlarý için 
#include <iostream>
#include <fstream>		// dosya iþlemleri için
#include <ctime>		// tarih iþlemleri için		
using namespace std; 	// string sýnýfý için

//////////////// Islem Listesi için Node tanýmý ////////////////

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
		IslemListesi();		// yapýcý fonksiyon
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
