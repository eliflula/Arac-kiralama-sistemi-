#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "musteriIslemleri.h"
#include "aracIslemleri.h"
#include "MusteriListesi.h"
#include "AracListesi.h"
#include "dosyaIslemleri.h"
using namespace std;

////////////// Bu dosya Menü Fonksiyonlarýný içerir //////////////////
// Bu fonksiyonlar menüde kullanýlýr. 

// ana menü fonksiyonu (parametre olarak gerçek yönetici þifresini alýr)
void menu(string yoneticiSifresi);
// þifreli yönetici giriþi
void yoneticiGirisi(string yoneticiSifresi);

// Müþteri iþlemleri alt menü fonksiyonu
void musteriIslemleriAltMenu(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi);

// Araç Ýþlemleri alt menü fonksiyonu
void aracIslemleriAltMenu(AracListesi& aracListesi);

// Para Dökümü
void paraDokumuYaz(IslemListesi islemListesi);

// Araç Talep Miktarlarý
void aracTalepMiktarlariniYaz(AracListesi& aracListesi);


#endif
