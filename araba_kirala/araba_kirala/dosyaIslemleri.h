#ifndef DOSYAISLEMLERI_H
#define DOSYAISLEMLERI_H

#include <fstream>		// dosya iþlemleri için
#include "MusteriListesi.h"
#include "AracListesi.h"

void musteriListesiniDosyayaYaz(MusteriListesi musteriListesi, AracListesi aracListesi);	// karýþýklýk olmasýn diye araç listesi de yazýlýr
void aracListesiniDosyayaYaz(AracListesi aracListesi);
void musteriListesiniDosyadanOku(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void aracListesiniDosyadanOku(AracListesi& aracListesi);

#endif
