#include "Musteri.h"

Musteri::Musteri()
{
	this->musteriNo = 0;
	this->tc = 0;
	this->ad = "";
	this->soyad = "";
	this->cinsiyet = '\0';
	this->kanGrubu = '\0';	

}
Musteri::Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	this->musteriNo = musteriNo;
	this->tc = tc;
	this->ad = ad;
	this->soyad = soyad;
	this->dogumTarihi = dogumTarihi;
	this->dogumYeri = dogumYeri;
	this->cinsiyet = cinsiyet;
	this->ehliyetVerilis = ehliyetVerilis;
	this->ehliyetGecerlilik = ehliyetGecerlilik;
	this->kanGrubu = kanGrubu;
}

void Musteri::aracTeslimEt(AracListesi& aracListesi)
{
	this->arac.durum = 'B';  // ara� bo�ta
	this->arac.toplamKiralanma += 	this->kiralamaSuresi;		// Se�ilen arac�n toplam kiralanma s�resini artt�r
	aracListesi.aracGetir(this->arac.aracNo).durum = 'B';		// Ger�ek listedeki ara� bo�ta
	aracListesi.aracGetir(this->arac.aracNo).toplamKiralanma += this->kiralamaSuresi;		// Ger�ek listedeki arac�n toplam kiralanma s�resini artt�r
}
