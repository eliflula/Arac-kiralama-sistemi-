#ifndef DOSYAISLEMLERI_H
#define DOSYAISLEMLERI_H

#include <fstream>		// dosya i�lemleri i�in
#include "MusteriListesi.h"
#include "AracListesi.h"

void musteriListesiniDosyayaYaz(MusteriListesi musteriListesi, AracListesi aracListesi);	// kar���kl�k olmas�n diye ara� listesi de yaz�l�r
void aracListesiniDosyayaYaz(AracListesi aracListesi);
void musteriListesiniDosyadanOku(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void aracListesiniDosyadanOku(AracListesi& aracListesi);

#endif
