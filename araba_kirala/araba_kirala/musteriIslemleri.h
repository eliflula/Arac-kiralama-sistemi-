#ifndef MUSTERIISLEMLERI_H
#define MUSTERIISLEMLERI_H

#include <iostream>
#include "MusteriListesi.h"
#include "AracListesi.h"
#include "dosyaIslemleri.h"

using namespace std;

// Müþteri iþlemleri
void musteriKayitEt(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi);
void kayitliMusteriSil(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void kayitliMusteriGuncelle(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void musteriListesiniDosyayaAktar(MusteriListesi& musteriListesi, AracListesi& aracListesi);

#endif
