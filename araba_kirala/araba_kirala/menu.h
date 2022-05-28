#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "musteriIslemleri.h"
#include "aracIslemleri.h"
#include "MusteriListesi.h"
#include "AracListesi.h"
#include "dosyaIslemleri.h"
using namespace std;

////////////// Bu dosya Men� Fonksiyonlar�n� i�erir //////////////////
// Bu fonksiyonlar men�de kullan�l�r. 

// ana men� fonksiyonu (parametre olarak ger�ek y�netici �ifresini al�r)
void menu(string yoneticiSifresi);
// �ifreli y�netici giri�i
void yoneticiGirisi(string yoneticiSifresi);

// M��teri i�lemleri alt men� fonksiyonu
void musteriIslemleriAltMenu(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi);

// Ara� ��lemleri alt men� fonksiyonu
void aracIslemleriAltMenu(AracListesi& aracListesi);

// Para D�k�m�
void paraDokumuYaz(IslemListesi islemListesi);

// Ara� Talep Miktarlar�
void aracTalepMiktarlariniYaz(AracListesi& aracListesi);


#endif
