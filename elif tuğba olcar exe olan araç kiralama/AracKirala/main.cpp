#include <iostream>
#include <cstdlib> 	// bellek fonsksiyonlarý için 
#include <ctime>		// tarih iþlemleri için	
#include <fstream>		// dosya iþlemleri için	

using namespace std;  // string sýnýfý için

///////////////// Yönetici þifresi /////////////////////////

string yoneticiSifresi = "123456";

//////////////////// Araç Sýnýfý ////////////////////////////
class Arac
{
	public:
		Arac();		// parametresiz yapýcý fonksiyon
		Arac(int aracNo, int fiyat, string plaka, string marka, string model);		// parametreli yapýcý fonksiyon
		int fiyat; 	// kiralama fiyatý
		string plaka;
		string marka;
		string model;
		char durum;		// kiralanmýþ mý boþta mý
		int aracNo;
		int toplamKiralanma;
};

//////////////// Araç Listesi için Node tanýmý ////////////////

struct aracNode
{
	Arac* arac; 
	aracNode* sonraki;	
};

//////////////// Araç Listesi Sýnýfý ////////////////

class AracListesi
{
	public:
		AracListesi();		// yapýcý fonksiyon
		void aracListesiniEkranaBas();
		void kiralanabilirAracListesiniEkranaBas();
		void aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi);
		bool aracSil(int aracNo);
		bool aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model);
		Arac& aracGetir(int aracNo);		// referansla getirir
		Arac aracOku(int aracNo);			// deðer ile okur
		aracNode *bas;		// listenin ilk node'u
		int aracSayisi;
};

//////////////////// Müþteri Sýnýfý ////////////////////////////

class Musteri
{
	public:
		Musteri();	// parametresiz yapýcý fonksiyon
		Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);		// parametreli yapýcý fonksiyon
		void aracTeslimEt(AracListesi& aracListesi);
		unsigned long long int tc;
		string ad;
		string soyad;
		struct tm dogumTarihi;
		string dogumYeri;
		char cinsiyet;
		struct tm ehliyetVerilis;
		struct tm ehliyetGecerlilik;
		string kanGrubu;
		Arac arac;
		int kiralamaSuresi;
		int musteriNo;
};

//////////////// Müsteri Listesi için Node tanýmý ////////////////

struct musteriNode
{
	Musteri* musteri; 
	musteriNode* sonraki;	
};


//////////////// Musteri Listesi Sýnýfý ////////////////

class MusteriListesi
{
	public:
		MusteriListesi();		// yapýcý fonksiyon
		void musteriListesiniEkranaBas();
		void musteriEkle(AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, 
						string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);
		bool musteriSil(int musteriNo, AracListesi& aracListesi);
		bool musteriGuncelle(int musteriNo, AracListesi aracListesi, int aracNo,int kiralamaSuresi, unsigned long long int tc, string ad, string soyad, 
							struct tm dogumTarihi, string dogumYeri, char cinsiyet, struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);
		Musteri& musteriGetir(int musteriNo);
		musteriNode *bas;
		int musteriSayisi;
};	

//////////////// Islem Listesi için Node tanýmý ////////////////

struct islemNode
{
	int islemNo;
	int islemTutari; 
	struct tm islemTarihi;
	islemNode* sonraki;	
};

//////////////// Islem Listesi Sýnýfý ////////////////

class IslemListesi
{
	public:
		IslemListesi();		// yapýcý fonksiyon
		void islemEkle(int islemTutari);
		void islemEkle(int islemTutari, int gun, int ay, int yil);
		int tutarOku(int islemNo);
		void guncelle();
		void islemListesiniDosyayaYaz();
		void islemListesiniDosyadanOku();
		int islemSayisi;
		islemNode* bas;	
};	

//////////////// Araç Ýþlemleri ////////////////
void aracKayitEt(AracListesi& aracListesi);
void kayitliAracSil(AracListesi& aracListesi);
void kayitliAracGuncelle(AracListesi& aracListesi);
void aracListesiniDosyayaAktar(AracListesi& aracListesi);
void aracAra(AracListesi& aracListesi);

//////////////// Müþteri iþlemleri ////////////////
void musteriKayitEt(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi);
void kayitliMusteriSil(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void kayitliMusteriGuncelle(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void musteriListesiniDosyayaAktar(MusteriListesi& musteriListesi, AracListesi& aracListesi);

//////////////// Dosya iþlemleri ////////////////
void musteriListesiniDosyayaYaz(MusteriListesi musteriListesi, AracListesi aracListesi);	// karýþýklýk olmasýn diye araç listesi de yazýlýr
void aracListesiniDosyayaYaz(AracListesi aracListesi);
void musteriListesiniDosyadanOku(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void aracListesiniDosyadanOku(AracListesi& aracListesi);

////////////// Menü Fonksiyonlarý //////////////////
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


///////////////////////////////////// MAIN /////////////////////////////////////
int main(int argc, char** argv) {	
	menu(yoneticiSifresi);	
	return 0;
}

//////////////// Arac Sýnýfý ////////////////////
// parametresiz yapýcý fonksiyon
Arac::Arac()
{
	this->aracNo = 0;
	this->fiyat = 0;
	this->plaka = "";
	this->model = "";
	this->marka = "";
	this->durum = 'B';	// baþlangýçta araç durumu boþta
	this->toplamKiralanma = 0; // baþlangýçta toplam kiralanma sayýsý 0	
}

// parametreli yapýcý fonksiyon
Arac::Arac(int aracNo, int fiyat, string plaka, string marka, string model)
{
	this->aracNo = aracNo;
	this->fiyat = fiyat;
	this->plaka = plaka;
	this->model = model;
	this->marka = marka;
	this->durum = 'B';	// baþlangýçta araç durumu boþta
	this->toplamKiralanma = 0; // baþlangýçta toplam kiralanma sayýsý 0
}


//////////////// Araç Listesi Sýnýfý //////////////////

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

////////////////// Musteri Sýnýfý //////////////////

Musteri::Musteri()
{
	this->musteriNo = 0;
	this->tc = 0;
	this->ad = "";
	this->soyad = "";
	this->cinsiyet = '\0';
	this->kanGrubu = '\0';	

}
Musteri::Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu)
{
	this->musteriNo = musteriNo;
	this->tc = tc;
	this->ad = ad;
	this->soyad = soyad;
	this->dogumTarihi = dogumTarihi;
	this->dogumYeri = dogumYeri;
	this->cinsiyet = cinsiyet;
	this->ehliyetVerilis = ehliyetVerilis;
	this->ehliyetGecerlilik = ehliyetGecerlilik;
	this->kanGrubu = kanGrubu;
}

void Musteri::aracTeslimEt(AracListesi& aracListesi)
{
	this->arac.durum = 'B';  // araç boþta
	aracListesi.aracGetir(this->arac.aracNo).durum = 'B';		// Gerçek listedeki araç boþta
}

///////////////// Musteri Listesi Sýnýfý //////////////////////

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
	aracListesi.aracGetir(aracNo).durum = 'K';						// Gerçek listedeki aracýn durumunu Kiralýk yap
	aracListesi.aracGetir(aracNo).toplamKiralanma += kiralamaSuresi;		// Gerçek listedeki aracýn toplam kiralanma süresini arttýr
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

/////////////////////// Islem Listesi Sýnýfý //////////////////

// yapýcý fonksiyon
IslemListesi::IslemListesi()
{
	this->bas = NULL;		// Listenin baþýný oluþtur ve NULL ata
	this->islemSayisi = 0;	// Listede bulunan islem adetini sýfýrla
}

void IslemListesi::islemEkle(int islemTutari)
{
	// Bugünün tarihini al
	struct tm bugununTarihi;
	time_t simdi = time(0);
	bugununTarihi = *localtime(&simdi);	// yýllar 1900 den sonra geçen seneler, ay ise ocaktan itibaren geçen aylarý gösterir
	
	islemNode* yeniNode = new islemNode();		// yeni Node için hafýzada yer ayýr
	yeniNode->islemTutari = islemTutari;		// yeni Node un ücret verisini ata
	yeniNode->islemNo = islemSayisi + 1;		// yeni Node islem no 'yu ata
	// iþlem tarihini bugünün tarihi yap
	yeniNode->islemTarihi.tm_year =  bugununTarihi.tm_year;	
	yeniNode->islemTarihi.tm_mon =  bugununTarihi.tm_mon;	
	yeniNode->islemTarihi.tm_mday =  bugununTarihi.tm_mday;	
    yeniNode->sonraki = this->bas;  		// Yeni Node un iþaret ettiði Node, müþteri listesinin baþýdýr
    this->bas = yeniNode;  	// Listesinin baþýný deðiþtirip yeni eklenen Node yap
    this->islemSayisi++; 	// müþteri sayýsýný 1 arttýr
}

void IslemListesi::islemEkle(int islemTutari, int gun, int ay, int yil)
{
	islemNode* yeniNode = new islemNode();		// yeni Node için hafýzada yer ayýr
	yeniNode->islemTutari = islemTutari;		// yeni Node un ücret verisini ata
	yeniNode->islemNo = islemSayisi + 1;		// yeni Node islem no 'yu ata
	// iþlem tarihini bugünün tarihi yap
	yeniNode->islemTarihi.tm_year =  yil-1900;	
	yeniNode->islemTarihi.tm_mon =  ay-1;	
	yeniNode->islemTarihi.tm_mday =  gun;	
    yeniNode->sonraki = this->bas;  		// Yeni Node un iþaret ettiði Node, müþteri listesinin baþýdýr
    this->bas = yeniNode;  	// Listesinin baþýný deðiþtirip yeni eklenen Node yap
    this->islemSayisi++; 	// müþteri sayýsýný 1 arttýr	
}


void IslemListesi::guncelle()
{
	// Bugünün tarihini al
	struct tm bugununTarihi;
	time_t simdi = time(0);
	bugununTarihi = *localtime(&simdi);	// yýllar 1900 den sonra geçen seneler, ay ise ocaktan itibaren geçen aylarý gösterir
	
	// Liste boþsa bir þey yapma
   if (this->bas == NULL) 
      return; 
      
   // Listenin baþýndan baþlayarak listede ilerle ve 1 ayý geçmiþ iþlemleri sil
   	struct islemNode* temp = this->bas; 
   	struct islemNode* temp2;
   	struct islemNode* temp3; 
   	
	// 1 ayý geçmiþ silinecek iþlem listenin baþý ise (son eklenen iþlem ise) bütün listeyi sil
    if (difftime(mktime(&bugununTarihi), mktime(&temp->islemTarihi)) / (60 * 60 * 24) > 30) 
    { 
		while (temp != NULL)  
		{  
		    temp2 = temp->sonraki;  
		    free(temp);  
		    temp = temp2;  
		}  

        this->bas = NULL;		// Listenin baþýný oluþtur ve NULL ata
		this->islemSayisi = 0;	// Listede bulunan islem adetini sýfýrla
    }
    // 1 ayý geçmiþ iþlem listenin ortasýnda ise onu ve önceki iþlemleri sil
	else
	{
		islemNode* sonGuncelNode;
		for(int i = this->islemSayisi; i >= 1; i--)
		{
			islemNode* simdikiNode = this->bas;  
			islemNode* sonrakiNode;
			
		    while (simdikiNode != NULL)  
		    {  
		    	sonrakiNode = simdikiNode->sonraki;
		    	
		        if (simdikiNode->islemNo ==  i)
		        {
					if (difftime(mktime(&bugununTarihi), mktime(&simdikiNode->islemTarihi)) / (60 * 60 * 24) > 30) 
					{
						free(simdikiNode);
						this->islemSayisi--;
					}
					else
					{
						sonGuncelNode = simdikiNode;
					}
				}
	
		        simdikiNode = sonrakiNode;  
		    }  
		}
		sonGuncelNode->sonraki = NULL;
	} 
	
	// Ýslem numaralarini düzelt
	islemNode* simdikiNode = this->bas;
	for(int i = this->islemSayisi; i>=1; i--)
	{
		 simdikiNode->islemNo = i;
	}
	
	// güncellenen halini dosyaya yaz
	this->islemListesiniDosyayaYaz();
}

void IslemListesi::islemListesiniDosyayaYaz()
{
	// dosyayý oluþtur (üzerine yazma modunda)
	std::ofstream dosya;
	dosya.open("IslemListesi.csv");
	// baþlýk yaz
	dosya << "Islem No;Tutar;Tarih;\n";
	// Bütün islem verilerini yaz.
	for(int i = 1; i<=this->islemSayisi; i++)
	{
		islemNode* simdikiNode = this->bas;  
	    while (simdikiNode != NULL)  
	    {  
	        if (simdikiNode->islemNo ==  i)
	        {
	        	dosya << simdikiNode->islemNo << ";";
				dosya << simdikiNode->islemTutari << ";";
				dosya << simdikiNode->islemTarihi.tm_mday << "." << (simdikiNode->islemTarihi.tm_mon+1) << "." << (simdikiNode->islemTarihi.tm_year + 1900) << ";\n";
			}

	        simdikiNode = simdikiNode->sonraki;  
	    }  
	}
	dosya.close();	
}


void IslemListesi::islemListesiniDosyadanOku()
{
	// dosyayý aç
	FILE *dosya = fopen ("IslemListesi.csv","r"); // okuma modunda aç	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi,islemNo,islemTutari;
		struct tm islemTarihi;
		
		// baþlýðý oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		// dosyanýn sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yazýlmýþ veriyi oku. 
			// %[^;] formatý noktalý virgül dýþýnda ne varsa okumaya yarar (string tipi veriler için)
			returnSayisi = fscanf(dosya,"%d;%d;%d.%d.%d;",&islemNo,&islemTutari,&islemTarihi.tm_mday,&islemTarihi.tm_mon,&islemTarihi.tm_year);
			// 5 adet veri okunur. Eðer okunan veri sayýsý 5ten azsa dosya sonuna ulaþýlmýþ demektir.
			if(returnSayisi == 5)
			{
				// yeni iþlem verisi okunabildiyse onu listesine ekle 
				this->islemEkle(islemTutari,islemTarihi.tm_mday,islemTarihi.tm_mon,islemTarihi.tm_year);
			}
			else
				break;		
		}
		fclose(dosya);	
	}	
}

//////////////////// Arac Islemleri ///////////////////

void aracKayitEt(AracListesi& aracListesi)
{
	string plaka;
	cout << "##### Arac Kayit Et #####" << endl << endl;
	cout << "Plaka: ";
	cin >> plaka;
	// Bütün araçlara bak. Ayný plakaya sahip bir araç varsa onu kaydetme.
	for(int i = 1; i<= aracListesi.aracSayisi;i++)
	{
		if(plaka.compare(aracListesi.aracOku(i).plaka) == 0)
		{
			cout << "Hata! Kayit yapilamadi." << endl;
			cout << "Bu plakaya sahip baska bir arac kayitlidir." << endl;
			return;
		}
	}
	
	// Müþteri daha önce kayýtlý deðilse 
	string marka,model;
	int fiyat;
	
	cout << "Marka: "; cin >> marka;
	cout << "Model: "; cin >> model;
	cout << "Gunluk kiralama fiyati: "; cin >> fiyat;
	
	// Aracý listeye ekle. Yeni eklenen aracýn durumu her zaman boþtadýr ve toplam kiralanma süresi 0'dýr.
	aracListesi.aracEkle(fiyat,plaka,marka,model,'B',0);
	cout << "\nArac kaydi basariyla yapilmistir." << endl;
}


void kayitliAracSil(AracListesi& aracListesi)
{
	int aracNo;
	cout << endl;
	aracListesi.aracListesiniEkranaBas();
	cout << "\nSilmek istediginiz aracin no'su: "; cin >> aracNo;
	if(aracListesi.aracSil(aracNo))
		cout << aracNo <<" No'lu' aracin kaydi silinmistir."<<endl;
	else
		cout << "\nHata! Silme islemi yapilamadi. Bu arac no'ya sahip bir arac yoktur."<<endl;
}


void kayitliAracGuncelle(AracListesi& aracListesi)
{
	int aracNo;
	aracListesi.aracListesiniEkranaBas();
	cout << "\nBilgilerini guncellemek istediginiz aracýn no'su: "; cin >> aracNo;
	// Eðer arac listede varsa güncelle , yoksa güncelleme
	if(aracNo <= aracListesi.aracSayisi)
	{
		string plaka,marka,model;
		int fiyat;
		
		cout << "Plaka: "; cin >> plaka;
		cout << "Marka: "; cin >> marka;
		cout << "Model: "; cin >> model;
		cout << "Gunluk kiralama fiyati: "; cin >> fiyat;
		aracListesi.aracGuncelle(aracNo,fiyat,plaka,marka,model);	
		cout << "\nArac bilgileri guncelleme basariyla yapilmistir." << endl;		
	}
	else
	{
		cout << "\nHata! Guncelleme islemi yapilamadi. Bu arac no'ya sahip bir arac yoktur."<<endl;
	}
}


void aracListesiniDosyayaAktar(AracListesi& aracListesi)
{
	aracListesiniDosyayaYaz(aracListesi);
	cout << "\nArac listesi dosyaya yazildi." << endl;
}


void aracAra(AracListesi& aracListesi)
{
	int aracAraCevap;
	string plaka,marka,model;
	// Arac Arama alt menüsü, üst menüye dön komutu gelmediði sürece tekrar eder
	while(true)
	{
		cout << "\n######### Arac Ara #########" << endl;
		cout << "0- Ust Menuye Geri Don" << endl << "1- Plakaya Gore Arac Ara" << endl 
			<< "2- Markaya Gore Arac Ara" << endl << "3- Modele Gore Arac Ara"  << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&aracAraCevap);
		
		// Araç arama için kullanýcýdan komut alýnýr. geçersiz bir deðer girilmesi durumunda uyarý verilir.
		switch(aracAraCevap)
		{
			case 0: 
				return;
			case 1: 
				// Plakaya gore arac ara
				cout << "\nAramak istediginiz aracin plakasi: "; cin >> plaka;
				cout << "\n###### Plakaya Gore Arac Listesi ######\n";
				printf("%-10s%-10s%-10s%-10s%-20s%-20s\n","Arac No","Fiyat","Durum","Plaka","Marka","Model");
				for(int i = 1; i <= aracListesi.aracSayisi; i++)
				{
					// Eðer araç plakasý eþleþiyorsa ekrana bas
					if(plaka.compare(aracListesi.aracOku(i).plaka) == 0)
					{
						printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",aracListesi.aracOku(i).aracNo,aracListesi.aracOku(i).fiyat,aracListesi.aracOku(i).durum,
								aracListesi.aracOku(i).plaka.c_str(),aracListesi.aracOku(i).marka.c_str(),aracListesi.aracOku(i).model.c_str());		
						break;	
					}
				}
				break;
			case 2:
				// Markaya gore arac ara
				cout << "\nArama yapmak istediginiz marka: "; cin >> marka;
				cout << "\n###### Markaya Gore Arac Listesi ######\n";
				printf("%-10s%-10s%-10s%-10s%-20s%-20s\n","Arac No","Fiyat","Durum","Plaka","Marka","Model");
				for(int i = 1; i <= aracListesi.aracSayisi; i++)
				{
					// Eðer araç markasý eþleþiyorsa ekrana bas
					if(marka.compare(aracListesi.aracOku(i).marka) == 0)
					{
						printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",aracListesi.aracOku(i).aracNo,aracListesi.aracOku(i).fiyat,aracListesi.aracOku(i).durum,
								aracListesi.aracOku(i).plaka.c_str(),aracListesi.aracOku(i).marka.c_str(),aracListesi.aracOku(i).model.c_str());		
					}
				}
				break;
			case 3:
				// Modele gore arac ara
				cout << "\nArama yapmak istediginiz model: "; cin >> model;
				cout << "\n###### Modele Gore Arac Listesi ######\n";
				printf("%-10s%-10s%-10s%-10s%-20s%-20s\n","Arac No","Fiyat","Durum","Plaka","Marka","Model");
				for(int i = 1; i <= aracListesi.aracSayisi; i++)
				{
					// Eðer araç markasý eþleþiyorsa ekrana bas
					if(model.compare(aracListesi.aracOku(i).model) == 0)
					{
						printf("%-10d%-10d%-10c%-10s%-20s%-20s\n",aracListesi.aracOku(i).aracNo,aracListesi.aracOku(i).fiyat,aracListesi.aracOku(i).durum,
								aracListesi.aracOku(i).plaka.c_str(),aracListesi.aracOku(i).marka.c_str(),aracListesi.aracOku(i).model.c_str());		
					}
				}
				break;
			default:
				cout << "Hata. Lutfen gecerli bir deger giriniz." << endl;		
		}
	}
}


///////////////////////// Musteri Islemleri //////////////////////////

void musteriKayitEt(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi)
{		
	unsigned long long int tc;
	cout << "##### Musteri Kayit Et #####" << endl << endl;
	cout << "T.C. No: ";
	cin >> tc;
	// Bütün müþterilere bak. Ayný TC'ye sahip bir müþteri varsa onu kaydetme.
	for(int i = 1; i<= musteriListesi.musteriSayisi;i++)
	{
		if(tc == musteriListesi.musteriGetir(i).tc)
		{
			cout << "Hata! Kayit yapilamadi." << endl;
			cout << "Bu T.C. No'lu' baska bir musteri kayitlidir." << endl;
			return;
		}
	}
	
	// Müþteri daha önce kayýtlý deðilse 
	string ad,soyad,dogumYeri,kanGrubu;
	struct tm dogumTarihi,ehliyetVerilis,ehliyetGecerlilik;
	char cinsiyet;
	int aracNo, kiralamaSuresi;
	
	cout << "Ad: "; cin >> ad;
	cout << "Soyad: "; cin >> soyad;
	cout << "Dogum Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&dogumTarihi.tm_mday,&dogumTarihi.tm_mon,&dogumTarihi.tm_year);
	cout << "Dogum Yeri: "; cin >> dogumYeri;
	cout << "Cinsiyet (Erkek icin E, Kadin icin K giriniz): "; cin >> cinsiyet;
	cout << "Ehliyet Verilis Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&ehliyetVerilis.tm_mday,&ehliyetVerilis.tm_mon,&ehliyetVerilis.tm_year);
	cout << "Ehliyet Son Gecerlilik Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&ehliyetGecerlilik.tm_mday,&ehliyetGecerlilik.tm_mon,&ehliyetGecerlilik.tm_year);	
	cout << "Kan Grubu: "; cin >> kanGrubu;
	
	// Arac Seçimi Ýçin Boþta olan araçlarý ekrana bas
	cout << endl;
	aracListesi.kiralanabilirAracListesiniEkranaBas();
	cout << "\nKiralamak Istenilen Arac No: "; cin >> aracNo;
	cout << "Kiralama Suresi (gun): "; cin >> kiralamaSuresi;
	musteriListesi.musteriEkle(aracListesi,aracNo,kiralamaSuresi,tc,ad,soyad,dogumTarihi,dogumYeri,cinsiyet,ehliyetVerilis,ehliyetGecerlilik,kanGrubu);
	// Son eklenen iþlem ücretini hesaplayýp iþlemlere ekle
	islemListesi.islemEkle(aracListesi.aracOku(aracNo).fiyat*kiralamaSuresi);
	// Ýslem Listesini yaz
	islemListesi.islemListesiniDosyayaYaz();
	cout << "\nMusteri kaydi basariyla yapilmistir." << endl;
}



void kayitliMusteriSil(MusteriListesi& musteriListesi, AracListesi& aracListesi)
{
	int musteriNo;
	musteriListesi.musteriListesiniEkranaBas();
	cout << "\nSilmek istediginiz musterinin no'su: "; cin >> musteriNo;
	if(musteriListesi.musteriSil(musteriNo,aracListesi))
		cout << musteriNo <<" No'lu musterinin kaydi silinmistir ve kiralamis oldugu arac teslim edilmistir."<<endl;
	else
		cout << "\nHata! Silme islemi yapilamadi. Bu musteri no'ya sahip bir musteri yoktur."<<endl;
}

void kayitliMusteriGuncelle(MusteriListesi& musteriListesi, AracListesi& aracListesi)
{
	int musteriNo;
	musteriListesi.musteriListesiniEkranaBas();
	cout << "\nBilgilerini guncellemek istediginiz musterinin no'su: "; cin >> musteriNo;
	// Eðer musteri listede varsa güncelle , yoksa güncelleme
	if(musteriNo <= musteriListesi.musteriSayisi)
	{
		unsigned long long int tc;
		string ad,soyad,dogumYeri,kanGrubu;
		struct tm dogumTarihi,ehliyetVerilis,ehliyetGecerlilik;
		char cinsiyet;
		int aracNo, kiralamaSuresi;
		
		cout << "T.C. No: "; cin >> tc;
		cout << "Ad: "; cin >> ad;
		cout << "Soyad: "; cin >> soyad;
		cout << "Dogum Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&dogumTarihi.tm_mday,&dogumTarihi.tm_mon,&dogumTarihi.tm_year);
		cout << "Dogum Yeri: "; cin >> dogumYeri;
		cout << "Cinsiyet (Erkek icin E, Kadin icin K giriniz): "; cin >> cinsiyet;
		cout << "Ehliyet Verilis Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&ehliyetVerilis.tm_mday,&ehliyetVerilis.tm_mon,&ehliyetVerilis.tm_year);
		cout << "Ehliyet Son Gecerlilik Tarihi (gg/aa/yyyy olarak giriniz): "; scanf("%d/%d/%d",&ehliyetGecerlilik.tm_mday,&ehliyetGecerlilik.tm_mon,&ehliyetGecerlilik.tm_year);	
		cout << "Kan Grubu: "; cin >> kanGrubu;

		musteriListesi.musteriGuncelle(musteriNo,aracListesi,musteriListesi.musteriGetir(musteriNo).arac.aracNo,musteriListesi.musteriGetir(musteriNo).kiralamaSuresi,
										tc,ad,soyad,dogumTarihi,dogumYeri,cinsiyet,ehliyetVerilis,ehliyetGecerlilik,kanGrubu);
		cout << "\nMusteri bilgileri guncelleme basariyla yapilmistir." << endl;		
	}
	else
	{
		cout << "\nHata! Guncelleme islemi yapilamadi. Bu musteri no'ya sahip bir musteri yoktur."<<endl;
	}
}


void musteriListesiniDosyayaAktar(MusteriListesi& musteriListesi, AracListesi& aracListesi)
{
	musteriListesiniDosyayaYaz(musteriListesi, aracListesi);
	cout << "\nMusteri listesi dosyaya yazildi. (Karisikliklari onlemek icin arac listesi de dosyaya yazildi.)" << endl;
}

///////////////////// Dosya Islemleri ///////////////////////

void musteriListesiniDosyayaYaz(MusteriListesi musteriListesi, AracListesi aracListesi)
{
	// dosyayý oluþtur (üzerine yazma modunda)
	std::ofstream dosya;
	dosya.open("MusteriListesi.csv");
	// baþlýk yaz
	dosya << "T.C.;Ad;Soyad;Dogum Tarihi;Dogum Yeri;Cinsiyet;Ehliyet Verilis Tarihi;Ehliyet Gecerlilik Tarihi;Kan Grubu;Kiraladigi Arac No;Kiraladigi Aracin Plakasi;Kiraladigi Aracin Markasi;Kiraladigi Aracin Modeli;Kiralama Suresi (gun)\n";
	// Bütün müþteri verilerini yaz.
	Musteri simdikiMusteri;
	for(int i = 1; i<=musteriListesi.musteriSayisi; i++)
	{
		simdikiMusteri = musteriListesi.musteriGetir(i);
		dosya << simdikiMusteri.tc << ";";
		dosya << simdikiMusteri.ad << ";";
		dosya << simdikiMusteri.soyad << ";";
		dosya << simdikiMusteri.dogumTarihi.tm_mday << "/" << simdikiMusteri.dogumTarihi.tm_mon << "/" << simdikiMusteri.dogumTarihi.tm_year << ";";
		dosya << simdikiMusteri.dogumYeri << ";";
		dosya << simdikiMusteri.cinsiyet << ";";
		dosya << simdikiMusteri.ehliyetVerilis.tm_mday << "/" << simdikiMusteri.ehliyetVerilis.tm_mon << "/" << simdikiMusteri.ehliyetVerilis.tm_year << ";";
		dosya << simdikiMusteri.ehliyetGecerlilik.tm_mday << "/" << simdikiMusteri.ehliyetGecerlilik.tm_mon << "/" << simdikiMusteri.ehliyetGecerlilik.tm_year << ";";
		dosya << simdikiMusteri.kanGrubu << ";";
		dosya << simdikiMusteri.arac.aracNo << ";";
		dosya << simdikiMusteri.arac.plaka << ";";
		dosya << simdikiMusteri.arac.marka << ";";
		dosya << simdikiMusteri.arac.model << ";";
		dosya << simdikiMusteri.kiralamaSuresi << ";\n";
	}
	dosya.close();
	// Karýþýklýk çýkmasýn diye araç listesini de dosyaya yaz
	aracListesiniDosyayaYaz(aracListesi);
}

void aracListesiniDosyayaYaz(AracListesi aracListesi)
{
	// dosyayý oluþtur (üzerine yazma modunda)
	std::ofstream dosya;
	dosya.open("AracListesi.csv");
	// baþlýk yaz
	dosya << "Kiralama Ucreti (gun);Plaka;Marka;Model;Durum;Toplam Kiralanma Suresi (gun)\n";
	// Bütün müþteri verilerini yaz.
	Arac simdikiArac;
	for(int i = 1; i<=aracListesi.aracSayisi; i++)
	{
		simdikiArac = aracListesi.aracOku(i);
		dosya << simdikiArac.fiyat << ";";
		dosya << simdikiArac.plaka << ";";
		dosya << simdikiArac.marka << ";";
		dosya << simdikiArac.model << ";";
		if(simdikiArac.durum == 'B')
			dosya << "Bosta" << ";";
		else
			dosya << "Kiralanmis" << ";";
		dosya << simdikiArac.toplamKiralanma << ";\n";
	}
	dosya.close();
}

void musteriListesiniDosyadanOku(MusteriListesi& musteriListesi, AracListesi& aracListesi)
{
	// Arac listesini oku
	aracListesiniDosyadanOku(aracListesi);

	// dosyayý aç
	FILE *dosya = fopen ("MusteriListesi.csv","r"); // okuma modunda aç	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi;
		unsigned long long int tc;
		char ad[25],soyad[25],dogumYeri[25],kanGrubu[5],plaka[25],marka[25],model[25];
		char cinsiyet;
		struct tm dogumTarihi,ehliyetVerilis,ehliyetGecerlilik;
		int aracNo,kiralamaSuresi;
		
		// baþlýðý oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		// dosyanýn sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yazýlmýþ veriyi oku. 
			// %[^;] formatý noktalý virgül dýþýnda ne varsa okumaya yarar (string tipi veriler için)
			returnSayisi = fscanf(dosya,"%llu;%[^;];%[^;];%d/%d/%d;%[^;];%c;%d/%d/%d;%d/%d/%d;%[^;];%d;%[^;];%[^;];%[^;];%d;",&tc,ad,soyad,&dogumTarihi.tm_mday,
							&dogumTarihi.tm_mon,&dogumTarihi.tm_year,dogumYeri,&cinsiyet,&ehliyetVerilis.tm_mday,&ehliyetVerilis.tm_mon,&ehliyetVerilis.tm_year,
							&ehliyetGecerlilik.tm_mday,&ehliyetGecerlilik.tm_mon,&ehliyetGecerlilik.tm_year,kanGrubu,&aracNo,plaka,marka,model,&kiralamaSuresi);
			// 20 adet veri okunur. Eðer okunan veri sayýsý 20den azsa dosya sonuna ulaþýlmýþ demektir.
			if(returnSayisi == 20)
			{
				// yeni müþteri verisi okunabildiyse onu listesine ekle 
				musteriListesi.musteriEkle(aracListesi,aracNo,kiralamaSuresi,tc,ad,soyad,dogumTarihi,dogumYeri,cinsiyet,ehliyetVerilis,ehliyetGecerlilik,kanGrubu);
			}
			else
				break;		
		}
		fclose(dosya);	
	}

}

// Arac listesini dosyadan okuma fonksiyonu
void aracListesiniDosyadanOku(AracListesi& aracListesi)
{
	// dosyayý aç
	FILE *dosya = fopen ("AracListesi.csv","r"); // okuma modunda aç	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi;
		char plaka[25],marka[25],model[25], s_durum[25];
		int fiyat, toplamKiralanmaSuresi;
		
		// baþlýðý oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		
		// dosyanýn sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yazýlmýþ veriyi oku. 
			// %[^;] formatý noktalý virgül dýþýnda ne varsa okumaya yarar (string tipi veriler için)
			returnSayisi = fscanf(dosya,"%d;%[^;];%[^;];%[^;];%[^;];%d;",&fiyat,plaka,marka,model,s_durum,&toplamKiralanmaSuresi);
			
			// 6 adet veri okunur. Eðer okunan veri sayýsý 6dan azsa dosya sonuna ulaþýlmýþ demektir.
			if(returnSayisi == 6)
			{
				// yeni araç verisi okunabildiyse onu listesine ekle 
				aracListesi.aracEkle(fiyat,plaka,marka,model,s_durum[0],toplamKiralanmaSuresi);
			}
			else
				break;		
		}
		fclose(dosya);	
	}	
}


/////////////////////// Menu ///////////////////////

// menü fonksiyonu
void menu(string yoneticiSifresi)
{
	int cevap;
	MusteriListesi musteriListesi;
	AracListesi aracListesi;
	IslemListesi islemListesi;
	cout << "\n######### Arac Kiralama Sistemi #########\n" << endl;
	yoneticiGirisi(yoneticiSifresi);
	////////////////////////// artýk yönetici giriþi yapýlmýþtýr//////////////////////////
	// açýlýþta musteri, arac ve islem listesini dosyadan okuyarak güncelle
	musteriListesiniDosyadanOku(musteriListesi,aracListesi);
	islemListesi.islemListesiniDosyadanOku();
	// Menü iþlemin tamamlanmasý sonucu kapanmaz. Sürekli yeni iþlemler için açýktýr.
	while(true)
	{		
		cout << "\n######### ANA MENU #########" << endl;
		cout << "1- Musteri Islemleri" << endl << "2- Arac Islemleri" << endl
			 << "3- Para Dokumu" << endl << "4- Arac Talep Miktarlari" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&cevap);
		// Kullanýcýdan alt menü için seçim yapmasý istenir. Geçerli bir seçim yapýp yapmadýðý kontrol edilir.
		switch(cevap)
		{
			case 1: 
				musteriIslemleriAltMenu(musteriListesi, aracListesi, islemListesi);	
				break;
			case 2:
				aracIslemleriAltMenu(aracListesi);
				break;
			case 3:
				paraDokumuYaz(islemListesi);	
				break;
			case 4:
				aracTalepMiktarlariniYaz(aracListesi);
				break;	
			default:
				cout << "Hata. Lutfen gecerli bir deger giriniz." << endl;		
		}
	}
}


// Þifreyi doðru girene kadar yönetici sifresi sorar
void yoneticiGirisi(string yoneticiSifresi) 
{
	string yoneticiSifresiGirisi;
	do {
		cout << "Devam etmek icin lutfen yonetici sifresini dogru olarak giriniz: ";
		cin >> yoneticiSifresiGirisi;
	}while(yoneticiSifresiGirisi.compare(yoneticiSifresi) != 0);
	cout << "\nGiris Basarili.\n";
}


// Musteri iþlemleri alt menüsü
void musteriIslemleriAltMenu(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi)
{
	int musteriIslemleriCevap;
	// Musteri iþlemleri alt menüsü, ana menüye dön komutu gelmediði sürece tekrar eder
	while(true)
	{
		cout << "\n######### Musteri Islemleri #########" << endl;
		cout << "0- Ana Menu" << endl << "1- Musteri Kayit Et" << endl << "2- Kayitli Musteri Sil" << endl 
			 << "3- Kayitli Musteri Guncelle" << endl << "4- Musteri Listesini Dosyaya Aktar" << endl << "5- Musteri Listesini Goster" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&musteriIslemleriCevap);
		
		// Musteri iþlemleri için kullanýcýdan komut alýnýr. geçersiz bir deðer girilmesi durumunda uyarý verilir.
		switch(musteriIslemleriCevap)
		{
			case 0: 
				return;			// ana menüye dön komutu geldiyse müþteri iþlemlerinden çýk
			case 1: 
				musteriKayitEt(musteriListesi,aracListesi, islemListesi);
				break;
			case 2:
				kayitliMusteriSil(musteriListesi,aracListesi);
				break;
			case 3:
				kayitliMusteriGuncelle(musteriListesi,aracListesi);
				break;
			case 4:
				musteriListesiniDosyayaAktar(musteriListesi,aracListesi);
				break;
			case 5:
				cout << endl;
				musteriListesi.musteriListesiniEkranaBas();
				break;
			default:
				cout << "Hata. Lutfen gecerli bir deger giriniz." << endl;			
		}
	}
}

// Arac iþlemleri alt menüsü
void aracIslemleriAltMenu(AracListesi& aracListesi)
{
	int aracIslemleriCevap;
	// Arac iþlemleri alt menüsü, ana menüye dön komutu gelmediði sürece tekrar eder
	while(true)
	{
		cout << "\n######### Arac Islemleri #########" << endl;
		cout << "0- Ana Menu" << endl << "1- Arac Kayit Et" << endl << "2- Kayitli Araci Sil" 
			 << endl << "3- Kayitli Arac Guncelle"  << endl << "4- Arac Listesini Dosyaya Aktar" 
			 << endl << "5- Arac Ara" << endl << "6- Butun Araclari Listele" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&aracIslemleriCevap);
		
		// Araç iþlemleri için kullanýcýdan komut alýnýr. geçersiz bir deðer girilmesi durumunda uyarý verilir.
		switch(aracIslemleriCevap)
		{
			case 0: 
				return;
			case 1: 
				aracKayitEt(aracListesi);	
				break;
			case 2:
				kayitliAracSil(aracListesi);
				break;
			case 3:
				kayitliAracGuncelle(aracListesi);	
				break;
			case 4:
				aracListesiniDosyayaAktar(aracListesi);
				break;	
			case 5:
				aracAra(aracListesi);
				break;
			case 6:
				cout << endl;
				aracListesi.aracListesiniEkranaBas();
				break;
			default:
				cout << "Hata. Lutfen gecerli bir deger giriniz." << endl;		
		}
	}
}

void aracTalepMiktarlariniYaz(AracListesi& aracListesi)
{
	cout << endl;
	for(int i = 1; i <= aracListesi.aracSayisi; i++)
	{
		printf("%s plakali arac su ana kadar %d gun kiralanmistir.\n",aracListesi.aracOku(i).plaka.c_str(),aracListesi.aracOku(i).toplamKiralanma);		
	}
}

void paraDokumuYaz(IslemListesi islemListesi)
{
	// son 1 ayda gerçekleþen iþlemler dýþýndakileri sil
	islemListesi.guncelle();
	// Toplam geliri hesapla
	int toplamGelir = 0;
	// iþlem listesindeki bütün gelirleri topla
	islemNode * simdiki = islemListesi.bas;
	
	for(int i = 1; i<=islemListesi.islemSayisi; i++)
	{
		toplamGelir += simdiki->islemTutari;
        simdiki = simdiki->sonraki;  
    }  
	// Ekrana bas
	cout << "\nIsletmemizde son 1 ayda toplam " << islemListesi.islemSayisi << " kez arac kiralanmistir ve " << toplamGelir << " TL kazanilmistir." << endl;
}


