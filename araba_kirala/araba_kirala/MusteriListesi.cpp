#include "MusteriListesi.h"


// yap�c� fonksiyon
MusteriListesi::MusteriListesi()
{
	this->bas = NULL;		// Listenin ba��n� olu�tur ve NULL ata
	this->musteriSayisi = 0;	// Listede bulunan ara� adetini s�f�rla
}


// Ara� listesine ara� ekleme fonksiyonu
void MusteriListesi::musteriEkle(AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, 
						string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	aracListesi.aracGetir(aracNo).durum = 'K';
	int musteriNo = this->musteriSayisi + 1;	// Yeni eklenen m��teri listenin sonuna eklenir
	musteriNode* yeniNode = new musteriNode();		// yeni Node i�in haf�zada yer ay�r
	yeniNode->musteri = new Musteri(musteriNo, tc, ad, soyad, dogumTarihi, dogumYeri, cinsiyet,
				ehliyetVerilis, ehliyetGecerlilik, kanGrubu);		// yeni Node un m��teri verisini ata
	yeniNode->musteri->arac = aracListesi.aracOku(aracNo);			// m��terinin arac�n� ata
	yeniNode->musteri->kiralamaSuresi = kiralamaSuresi;		// kiralama s�resini ata
    yeniNode->sonraki = this->bas;  		// Yeni Node un i�aret etti�i Node, m��teri listesinin ba��d�r
    this->bas = yeniNode;  	// m��teri listesinin ba��n� de�i�tirip yeni eklenen Node yap
    this->musteriSayisi++; 	// m��teri say�s�n� 1 artt�r
}

// M��teri listesinden m��teri silme fonksiyonu
bool MusteriListesi::musteriSil(int musteriNo, AracListesi& aracListesi)
{
	// M��teri listesi bo�sa bir �ey yapma
   if (this->bas == NULL) 
      return false; 
      
   // Listenin ba��ndan ba�layarak istenilen arac no yu bulana kadar listede ilerle
   struct musteriNode* temp = this->bas; 

	// Bu m��teri no listede yoksa false d�n
	if(musteriNo > this->musteriSayisi)
	{
		return false;
	}
	// Listede varsa ve silinecek m��teri listenin ba�� ise
    else if (musteriNo == this->musteriSayisi) 
    { 
        this->bas = temp->sonraki;   // Listenin ba��n� ba�tan bir sonraki m��teri olarak g�ncelle
		temp->musteri->aracTeslimEt(aracListesi);		// arac� b�rak
        free(temp);               	 // Eski liste ba��n� sil
        this->musteriSayisi--;			 // m��teri say�s�n� azalt
        return true; 
    } 
    // Silicenek m��teri, listenin ba�� de�il ise
  	else
  	{
	    // Silinecek Node un bir �ncesi Node u bul
	    while(temp->sonraki->musteri->musteriNo != musteriNo)
		{     
			temp->musteri->musteriNo--;	// m��teri no'lar�n� azaltarak git
			temp = temp->sonraki; 		
		}
	    temp->musteri->musteriNo--;
	  
	    // Silinecek node un bir sonraki Node unu bul
	    struct musteriNode *sonraki = temp->sonraki->sonraki;
		// Arac� teslim et  
	    temp->sonraki->musteri->aracTeslimEt(aracListesi);
	    // Node u sil
	    free(temp->sonraki);
	  	// Silinen Node un �ncesini sonras�na ba�la
	    temp->sonraki = sonraki;  
	    // M��teri say�s�n� azalt
	    this->musteriSayisi--;		  
		return true;  		
	}	
}

// M��teri listesinden bir ara� oku (d�n)
Musteri& MusteriListesi::musteriGetir(int musteriNo)
{
	// M��teri nesnesi d�ner
	// M��teri listesinin ba��ndan ba�layarak istenilen m��teri no yu bulana kadar ilerler
	musteriNode* simdikiNode = this->bas;  
    while (simdikiNode != NULL)  
    {  
        if (simdikiNode->musteri->musteriNo ==  musteriNo)  
            return(*simdikiNode->musteri);  
        simdikiNode = simdikiNode->sonraki;  
    }  
}

// Musteri listesinden Musteri g�ncelleme fonksiyonu
bool MusteriListesi::musteriGuncelle(int musteriNo, AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, 
								string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
								struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	// E�er g�ncellenmek istenen m��teri listede yoksa false d�n
	if(musteriNo > this->musteriSayisi)
	{
		return false;
	}
	// listede varsa g�ncelle
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

