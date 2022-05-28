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
	this->arac.durum = 'B';  // araç boþta
	this->arac.toplamKiralanma += 	this->kiralamaSuresi;		// Seçilen aracýn toplam kiralanma süresini arttýr
	aracListesi.aracGetir(this->arac.aracNo).durum = 'B';		// Gerçek listedeki araç boþta
	aracListesi.aracGetir(this->arac.aracNo).toplamKiralanma += this->kiralamaSuresi;		// Gerçek listedeki aracýn toplam kiralanma süresini arttýr
}
