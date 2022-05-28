#include "MusteriListesi.h"


// yapýcý fonksiyon
MusteriListesi::MusteriListesi()
{
	this->bas = NULL;		// Listenin baþýný oluþtur ve NULL ata
	this->musteriSayisi = 0;	// Listede bulunan araç adetini sýfýrla
}


// Araç listesine araç ekleme fonksiyonu
void MusteriListesi::musteriEkle(AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, 
						string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	aracListesi.aracGetir(aracNo).durum = 'K';
	int musteriNo = this->musteriSayisi + 1;	// Yeni eklenen müþteri listenin sonuna eklenir
	musteriNode* yeniNode = new musteriNode();		// yeni Node için hafýzada yer ayýr
	yeniNode->musteri = new Musteri(musteriNo, tc, ad, soyad, dogumTarihi, dogumYeri, cinsiyet,
				ehliyetVerilis, ehliyetGecerlilik, kanGrubu);		// yeni Node un müþteri verisini ata
	yeniNode->musteri->arac = aracListesi.aracOku(aracNo);			// müþterinin aracýný ata
	yeniNode->musteri->kiralamaSuresi = kiralamaSuresi;		// kiralama süresini ata
    yeniNode->sonraki = this->bas;  		// Yeni Node un iþaret ettiði Node, müþteri listesinin baþýdýr
    this->bas = yeniNode;  	// müþteri listesinin baþýný deðiþtirip yeni eklenen Node yap
    this->musteriSayisi++; 	// müþteri sayýsýný 1 arttýr
}

// Müþteri listesinden müþteri silme fonksiyonu
bool MusteriListesi::musteriSil(int musteriNo, AracListesi& aracListesi)
{
	// Müþteri listesi boþsa bir þey yapma
   if (this->bas == NULL) 
      return false; 
      
   // Listenin baþýndan baþlayarak istenilen arac no yu bulana kadar listede ilerle
   struct musteriNode* temp = this->bas; 

	// Bu müþteri no listede yoksa false dön
	if(musteriNo > this->musteriSayisi)
	{
		return false;
	}
	// Listede varsa ve silinecek müþteri listenin baþý ise
    else if (musteriNo == this->musteriSayisi) 
    { 
        this->bas = temp->sonraki;   // Listenin baþýný baþtan bir sonraki müþteri olarak güncelle
		temp->musteri->aracTeslimEt(aracListesi);		// aracý býrak
        free(temp);               	 // Eski liste baþýný sil
        this->musteriSayisi--;			 // müþteri sayýsýný azalt
        return true; 
    } 
    // Silicenek müþteri, listenin baþý deðil ise
  	else
  	{
	    // Silinecek Node un bir öncesi Node u bul
	    while(temp->sonraki->musteri->musteriNo != musteriNo)
		{     
			temp->musteri->musteriNo--;	// müþteri no'larýný azaltarak git
			temp = temp->sonraki; 		
		}
	    temp->musteri->musteriNo--;
	  
	    // Silinecek node un bir sonraki Node unu bul
	    struct musteriNode *sonraki = temp->sonraki->sonraki;
		// Aracý teslim et  
	    temp->sonraki->musteri->aracTeslimEt(aracListesi);
	    // Node u sil
	    free(temp->sonraki);
	  	// Silinen Node un öncesini sonrasýna baðla
	    temp->sonraki = sonraki;  
	    // Müþteri sayýsýný azalt
	    this->musteriSayisi--;		  
		return true;  		
	}	
}

// Müþteri listesinden bir araç oku (dön)
Musteri& MusteriListesi::musteriGetir(int musteriNo)
{
	// Müþteri nesnesi döner
	// Müþteri listesinin baþýndan baþlayarak istenilen müþteri no yu bulana kadar ilerler
	musteriNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->musteri->musteriNo ==  musteriNo)  
            return(*simdikiNode->musteri);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Musteri listesinden Musteri güncelleme fonksiyonu
bool MusteriListesi::musteriGuncelle(int musteriNo, AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, 
								string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
								struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	// Eðer güncellenmek istenen müþteri listede yoksa false dön
	if(musteriNo > this->musteriSayisi)
	{
		return false;
	}
	// listede varsa güncelle
	else
	{
		musteriGetir(musteriNo).arac = aracListesi.aracOku(aracNo);
		musteriGetir(musteriNo).kiralamaSuresi = kiralamaSuresi;
		musteriGetir(musteriNo).ad = ad;
		musteriGetir(musteriNo).soyad = soyad;
		musteriGetir(musteriNo).tc = tc;
		musteriGetir(musteriNo).dogumTarihi = dogumTarihi;
		musteriGetir(musteriNo).dogumYeri = dogumYeri;
		musteriGetir(musteriNo).cinsiyet = cinsiyet;
		musteriGetir(musteriNo).ehliyetVerilis = ehliyetVerilis;
		musteriGetir(musteriNo).ehliyetGecerlilik = ehliyetGecerlilik;
		musteriGetir(musteriNo).kanGrubu = kanGrubu;	
	}
}

void MusteriListesi::musteriListesiniEkranaBas()
{
	Musteri simdikiMusteri;
	cout << "###### Musteri Listesi ######\n";
	printf("%-10s%-15s%-15s%-15s%-10s%-15s%-10s%-15s%-15s\n","No","T.C.","Ad","Soyad","Cinsiyet","Kira Suresi","Plaka","Marka","Model");
	for(int i = 1; i <= this->musteriSayisi; i++)
	{
		simdikiMusteri = this->musteriGetir(i);
		printf("%-10d%-15llu%-15s%-15s%-10c%-15d%-10s%-15s%-15s\n",simdikiMusteri.musteriNo,simdikiMusteri.tc,simdikiMusteri.ad.c_str(),
				simdikiMusteri.soyad.c_str(),simdikiMusteri.cinsiyet,simdikiMusteri.kiralamaSuresi,simdikiMusteri.arac.plaka.c_str(),
				simdikiMusteri.arac.marka.c_str(),simdikiMusteri.arac.model.c_str());
	}		
}

