#ifndef ARACISLEMLERI_H
#define ARACISLEMLERI_H

#include <iostream>
#include "AracListesi.h"
#include "dosyaIslemleri.h"

using namespace std;

// Araç Ýþlemleri
void aracKayitEt(AracListesi& aracListesi);
void kayitliAracSil(AracListesi& aracListesi);
void kayitliAracGuncelle(AracListesi& aracListesi);
void aracListesiniDosyayaAktar(AracListesi& aracListesi);
void aracAra(AracListesi& aracListesi);

#endif
