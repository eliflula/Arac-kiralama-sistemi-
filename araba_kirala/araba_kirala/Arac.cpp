#include "Arac.h"

// parametresiz yapýcý fonksiyon
Arac::Arac()
{
	this->aracNo = 0;
	this->fiyat = 0;
	this->plaka = "";
	this->model = "";
	this->marka = "";
	this->durum = 'B';	// baþlangýçta araç durumu boþta
	this->toplamKiralanma = 0; // baþlangýçta toplam kiralanma sayýsý 0	
}

// parametreli yapýcý fonksiyon
Arac::Arac(int aracNo, int fiyat, string plaka, string marka, string model)
{
	this->aracNo = aracNo;
	this->fiyat = fiyat;
	this->plaka = plaka;
	this->model = model;
	this->marka = marka;
	this->durum = 'B';	// baþlangýçta araç durumu boþta
	this->toplamKiralanma = 0; // baþlangýçta toplam kiralanma sayýsý 0
}

