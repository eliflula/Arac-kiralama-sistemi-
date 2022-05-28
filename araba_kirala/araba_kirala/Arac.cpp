#include "Arac.h"

// parametresiz yap�c� fonksiyon
Arac::Arac()
{
	this->aracNo = 0;
	this->fiyat = 0;
	this->plaka = "";
	this->model = "";
	this->marka = "";
	this->durum = 'B';	// ba�lang��ta ara� durumu bo�ta
	this->toplamKiralanma = 0; // ba�lang��ta toplam kiralanma say�s� 0	
}

// parametreli yap�c� fonksiyon
Arac::Arac(int aracNo, int fiyat, string plaka, string marka, string model)
{
	this->aracNo = aracNo;
	this->fiyat = fiyat;
	this->plaka = plaka;
	this->model = model;
	this->marka = marka;
	this->durum = 'B';	// ba�lang��ta ara� durumu bo�ta
	this->toplamKiralanma = 0; // ba�lang��ta toplam kiralanma say�s� 0
}

