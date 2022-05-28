#include "AracListesi.h"

// yapýcý fonksiyon
AracListesi::AracListesi()
{
	this->bas = NULL;		// Listenin baþýný oluþtur ve NULL ata
	this->aracSayisi = 0;	// Listede bulunan araç adetini sýfýrla
}

// Araç listesine araç ekleme fonksiyonu
void AracListesi::aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi)
{
	int aracNo = this->aracSayisi + 1;	// Yeni eklenen araç listenin sonuna eklenir
	aracNode* yeniNode = new aracNode();		// yeni Node için hafýzada yer ayýr
	yeniNode->arac = new Arac(aracNo, fiyat, plaka, marka, model);		// yeni Node un araç verisini ata
	yeniNode->arac->durum = durum;
	yeniNode->arac->toplamKiralanma = toplamKiralanmaSuresi;
    yeniNode->sonraki = this->bas;  		// Yeni Node un iþaret ettiði Node, araç listesinin baþýdýr
    this->bas = yeniNode;  	// araç listesinin baþýný deðiþtirip yeni eklenen Node yap
    this->aracSayisi++; 	// araç sayýsýný 1 arttýr
}

// Araç listesinden araç silme fonksiyonu
bool AracListesi::aracSil(int aracNo)
{
	// Sefer listesi boþsa bir þey yapma
   if (this->bas == NULL) 
      return false; 
      
   // Listenin baþýndan baþlayarak istenilen arac no yu bulana kadar listede ilerle
   struct aracNode* temp = this->bas; 
	// Bu araç no listede yoksa false dön
	if(aracNo > this->aracSayisi)
	{
		return false;
	}
	// Listede varsa ve silinecek arac, listenin baþý ise
    else if (aracNo == this->aracSayisi) 
    { 
        this->bas = temp->sonraki;   // Listenin baþýný baþtan bir sonraki araç olarak güncelle
        free(temp);               	 // Eski liste baþýný sil
        this->aracSayisi--;			 // arac sayýsýný azalt
        return true; 
    } 
    // Silicenek araç, listenin baþý deðil ise
  	else
  	{
	    // Silinecek Node un bir öncesi Node u bul
	    while(temp->sonraki->arac->aracNo != aracNo)
		{     
			temp->arac->aracNo--;	// araç no'larýný azaltarak git
			temp = temp->sonraki; 		
		}
	    temp->arac->aracNo--;
	  
	    // Silinecek node un bir sonraki Node unu bul
	    struct aracNode *sonraki = temp->sonraki->sonraki;  
	    // Node u sil
	    free(temp->sonraki);
	  	// Silinen Node un öncesini sonrasýna baðla
	    temp->sonraki = sonraki;  
	    // Araç sayýsýný azalt
	    this->aracSayisi--;		  
		return true;  		
	}	
}

// Araç listesinden bir araç getir (referansla dön)
Arac& AracListesi::aracGetir(int aracNo)
{
	// Arac nesnesi döner
	// Araç listesinin baþýndan baþlayarak istenilen araç no yu bulana kadar ilerler
	aracNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->arac->aracNo ==  aracNo)  
            return(*simdikiNode->arac);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Araç listesinden bir araç getir (deðerle dön)
Arac AracListesi::aracOku(int aracNo)
{
	// Arac nesnesi döner
	// Araç listesinin baþýndan baþlayarak istenilen araç no yu bulana kadar ilerler
	aracNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->arac->aracNo ==  aracNo)  
            return(*simdikiNode->arac);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Araç listesinden araç güncelleme fonksiyonu
bool AracListesi::aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model)
{
	// Eðer güncellenmek istenen araç listede yoksa false dön
	if(aracNo > this->aracSayisi)
	{
		return false;
	}
	// listede varsa güncelle
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
		// Eðer araç durumu boþtaysa ekrana bas
		if(simdikiArac.durum == 'B')
		{
			printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",simdikiArac.aracNo,simdikiArac.fiyat,simdikiArac.durum,
					simdikiArac.plaka.c_str(),simdikiArac.marka.c_str(),simdikiArac.model.c_str());			
		}
	}
		
}

