#include "AracListesi.h"

// yap�c� fonksiyon
AracListesi::AracListesi()
{
	this->bas = NULL;		// Listenin ba��n� olu�tur ve NULL ata
	this->aracSayisi = 0;	// Listede bulunan ara� adetini s�f�rla
}

// Ara� listesine ara� ekleme fonksiyonu
void AracListesi::aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi)
{
	int aracNo = this->aracSayisi + 1;	// Yeni eklenen ara� listenin sonuna eklenir
	aracNode* yeniNode = new aracNode();		// yeni Node i�in haf�zada yer ay�r
	yeniNode->arac = new Arac(aracNo, fiyat, plaka, marka, model);		// yeni Node un ara� verisini ata
	yeniNode->arac->durum = durum;
	yeniNode->arac->toplamKiralanma = toplamKiralanmaSuresi;
    yeniNode->sonraki = this->bas;  		// Yeni Node un i�aret etti�i Node, ara� listesinin ba��d�r
    this->bas = yeniNode;  	// ara� listesinin ba��n� de�i�tirip yeni eklenen Node yap
    this->aracSayisi++; 	// ara� say�s�n� 1 artt�r
}

// Ara� listesinden ara� silme fonksiyonu
bool AracListesi::aracSil(int aracNo)
{
	// Sefer listesi bo�sa bir �ey yapma
   if (this->bas == NULL) 
      return false; 
      
   // Listenin ba��ndan ba�layarak istenilen arac no yu bulana kadar listede ilerle
   struct aracNode* temp = this->bas; 
	// Bu ara� no listede yoksa false d�n
	if(aracNo > this->aracSayisi)
	{
		return false;
	}
	// Listede varsa ve silinecek arac, listenin ba�� ise
    else if (aracNo == this->aracSayisi) 
    { 
        this->bas = temp->sonraki;   // Listenin ba��n� ba�tan bir sonraki ara� olarak g�ncelle
        free(temp);               	 // Eski liste ba��n� sil
        this->aracSayisi--;			 // arac say�s�n� azalt
        return true; 
    } 
    // Silicenek ara�, listenin ba�� de�il ise
  	else
  	{
	    // Silinecek Node un bir �ncesi Node u bul
	    while(temp->sonraki->arac->aracNo != aracNo)
		{     
			temp->arac->aracNo--;	// ara� no'lar�n� azaltarak git
			temp = temp->sonraki; 		
		}
	    temp->arac->aracNo--;
	  
	    // Silinecek node un bir sonraki Node unu bul
	    struct aracNode *sonraki = temp->sonraki->sonraki;  
	    // Node u sil
	    free(temp->sonraki);
	  	// Silinen Node un �ncesini sonras�na ba�la
	    temp->sonraki = sonraki;  
	    // Ara� say�s�n� azalt
	    this->aracSayisi--;		  
		return true;  		
	}	
}

// Ara� listesinden bir ara� getir (referansla d�n)
Arac& AracListesi::aracGetir(int aracNo)
{
	// Arac nesnesi d�ner
	// Ara� listesinin ba��ndan ba�layarak istenilen ara� no yu bulana kadar ilerler
	aracNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->arac->aracNo ==  aracNo)  
            return(*simdikiNode->arac);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Ara� listesinden bir ara� getir (de�erle d�n)
Arac AracListesi::aracOku(int aracNo)
{
	// Arac nesnesi d�ner
	// Ara� listesinin ba��ndan ba�layarak istenilen ara� no yu bulana kadar ilerler
	aracNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->arac->aracNo ==  aracNo)  
            return(*simdikiNode->arac);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Ara� listesinden ara� g�ncelleme fonksiyonu
bool AracListesi::aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model)
{
	// E�er g�ncellenmek istenen ara� listede yoksa false d�n
	if(aracNo > this->aracSayisi)
	{
		return false;
	}
	// listede varsa g�ncelle
	else
	{
		aracGetir(aracNo).fiyat = fiyat;
		aracGetir(aracNo).plaka = plaka;
		aracGetir(aracNo).marka = marka;
		aracGetir(aracNo).model = model;
	}
}

void AracListesi::aracListesiniEkranaBas()
{
	Arac simdikiArac;
	cout << "###### Arac Listesi ######\n";
	printf("%-10s%-10s%-10s%-10s%-20s%-20s\n","Arac No","Fiyat","Durum","Plaka","Marka","Model");
	for(int i = 1; i <= this->aracSayisi; i++)
	{
		simdikiArac = this->aracGetir(i);
		printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",simdikiArac.aracNo,simdikiArac.fiyat,simdikiArac.durum,
				simdikiArac.plaka.c_str(),simdikiArac.marka.c_str(),simdikiArac.model.c_str());
	}		
}

void AracListesi::kiralanabilirAracListesiniEkranaBas()
{
	Arac simdikiArac;
	cout << "###### Kiralanabilir Arac Listesi ######\n";
	printf("%-10s%-10s%-10s%-10s%-20s%-20s\n","Arac No","Fiyat","Durum","Plaka","Marka","Model");
	for(int i = 1; i <= this->aracSayisi; i++)
	{
		simdikiArac = this->aracGetir(i);
		// E�er ara� durumu bo�taysa ekrana bas
		if(simdikiArac.durum == 'B')
		{
			printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",simdikiArac.aracNo,simdikiArac.fiyat,simdikiArac.durum,
					simdikiArac.plaka.c_str(),simdikiArac.marka.c_str(),simdikiArac.model.c_str());			
		}
	}
		
}

