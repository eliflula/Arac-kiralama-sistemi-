#ifndef ARAC_H
#define ARAC_H

#include <iostream>		
using namespace std; 	// string sýnýfý için

//////////////////// Araç Sýnýfý ////////////////////////////
class Arac
{
	public:
		Arac();		// parametresiz yapýcý fonksiyon
		Arac(int aracNo, int fiyat, string plaka, string marka, string model);		// parametreli yapýcý fonksiyon
		int fiyat; 	// kiralama fiyatý
		string plaka;
		string marka;
		string model;
		char durum;		// kiralanmýþ mý boþta mý
		int aracNo;
		int toplamKiralanma;
};

#endif
