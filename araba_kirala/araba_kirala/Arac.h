#ifndef ARAC_H
#define ARAC_H

#include <iostream>		
using namespace std; 	// string s�n�f� i�in

//////////////////// Ara� S�n�f� ////////////////////////////
class Arac
{
	public:
		Arac();		// parametresiz yap�c� fonksiyon
		Arac(int aracNo, int fiyat, string plaka, string marka, string model);		// parametreli yap�c� fonksiyon
		int fiyat; 	// kiralama fiyat�
		string plaka;
		string marka;
		string model;
		char durum;		// kiralanm�� m� bo�ta m�
		int aracNo;
		int toplamKiralanma;
};

#endif
