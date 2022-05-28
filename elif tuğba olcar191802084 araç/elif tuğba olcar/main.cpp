#include <iostream>
#include <cstdlib> 	// bellek fonsksiyonlar� i�in 
#include <ctime>		// tarih i�lemleri i�in	
#include <fstream>		// dosya i�lemleri i�in	

using namespace std;  // string s�n�f� i�in

///////////////// Y�netici �ifresi /////////////////////////

string yoneticiSifresi = "123456";

//////////////////// Ara� S�n�f� ////////////////////////////
class Arac
{
	public:
		Arac();		// parametresiz yap�c� fonksiyon
		Arac(int aracNo, int fiyat, string plaka, string marka, string model);		// parametreli yap�c� fonksiyon
		int fiyat; 	// kiralama fiyat�
		string plaka;
		string marka;
		string model;
		char durum;		// kiralanm�� m� bo�ta m�
		int aracNo;
		int toplamKiralanma;
};

//////////////// Ara� Listesi i�in Node tan�m� ////////////////

struct aracNode
{
	Arac* arac; 
	aracNode* sonraki;	
};

//////////////// Ara� Listesi S�n�f� ////////////////

class AracListesi
{
	public:
		AracListesi();		// yap�c� fonksiyon
		void aracListesiniEkranaBas();
		void kiralanabilirAracListesiniEkranaBas();
		void aracEkle(int fiyat, string plaka, string marka, string model, char durum, int toplamKiralanmaSuresi);
		bool aracSil(int aracNo);
		bool aracGuncelle(int aracNo, int fiyat, string plaka, string marka, string model);
		Arac& aracGetir(int aracNo);		// referansla getirir
		Arac aracOku(int aracNo);			// de�er ile okur
		aracNode *bas;		// listenin ilk node'u
		int aracSayisi;
};

//////////////////// M��teri S�n�f� ////////////////////////////

class Musteri
{
	public:
		Musteri();	// parametresiz yap�c� fonksiyon
		Musteri(int musteriNo, unsigned long long int tc, string ad, string soyad, struct tm dogumTarihi, string dogumYeri, char cinsiyet,
				struct tm ehliyetVerilis, struct tm ehliyetGecerlilik, string kanGrubu);		// parametreli yap�c� fonksiyon
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

//////////////// M�steri Listesi i�in Node tan�m� ////////////////

struct musteriNode
{
	Musteri* musteri; 
	musteriNode* sonraki;	
};


//////////////// Musteri Listesi S�n�f� ////////////////

class MusteriListesi
{
	public:
		MusteriListesi();		// yap�c� fonksiyon
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

//////////////// Islem Listesi i�in Node tan�m� ////////////////

struct islemNode
{
	int islemNo;
	int islemTutari; 
	struct tm islemTarihi;
	islemNode* sonraki;	
};

//////////////// Islem Listesi S�n�f� ////////////////

class IslemListesi
{
	public:
		IslemListesi();		// yap�c� fonksiyon
		void islemEkle(int islemTutari);
		void islemEkle(int islemTutari, int gun, int ay, int yil);
		int tutarOku(int islemNo);
		void guncelle();
		void islemListesiniDosyayaYaz();
		void islemListesiniDosyadanOku();
		int islemSayisi;
		islemNode* bas;	
};	

//////////////// Ara� ��lemleri ////////////////
void aracKayitEt(AracListesi& aracListesi);
void kayitliAracSil(AracListesi& aracListesi);
void kayitliAracGuncelle(AracListesi& aracListesi);
void aracListesiniDosyayaAktar(AracListesi& aracListesi);
void aracAra(AracListesi& aracListesi);

//////////////// M��teri i�lemleri ////////////////
void musteriKayitEt(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi);
void kayitliMusteriSil(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void kayitliMusteriGuncelle(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void musteriListesiniDosyayaAktar(MusteriListesi& musteriListesi, AracListesi& aracListesi);

//////////////// Dosya i�lemleri ////////////////
void musteriListesiniDosyayaYaz(MusteriListesi musteriListesi, AracListesi aracListesi);	// kar���kl�k olmas�n diye ara� listesi de yaz�l�r
void aracListesiniDosyayaYaz(AracListesi aracListesi);
void musteriListesiniDosyadanOku(MusteriListesi& musteriListesi, AracListesi& aracListesi);
void aracListesiniDosyadanOku(AracListesi& aracListesi);

////////////// Men� Fonksiyonlar� //////////////////
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


///////////////////////////////////// MAIN /////////////////////////////////////
int main(int argc, char** argv) {	
	menu(yoneticiSifresi);	
	return 0;
}

//////////////// Arac S�n�f� ////////////////////
// parametresiz yap�c� fonksiyon
Arac::Arac()
{
	this->aracNo = 0;
	this->fiyat = 0;
	this->plaka = "";
	this->model = "";
	this->marka = "";
	this->durum = 'B';	// ba�lang��ta ara� durumu bo�ta
	this->toplamKiralanma = 0; // ba�lang��ta toplam kiralanma say�s� 0	
}

// parametreli yap�c� fonksiyon
Arac::Arac(int aracNo, int fiyat, string plaka, string marka, string model)
{
	this->aracNo = aracNo;
	this->fiyat = fiyat;
	this->plaka = plaka;
	this->model = model;
	this->marka = marka;
	this->durum = 'B';	// ba�lang��ta ara� durumu bo�ta
	this->toplamKiralanma = 0; // ba�lang��ta toplam kiralanma say�s� 0
}


//////////////// Ara� Listesi S�n�f� //////////////////

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

////////////////// Musteri S�n�f� //////////////////

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
	this->arac.durum = 'B';  // ara� bo�ta
	aracListesi.aracGetir(this->arac.aracNo).durum = 'B';		// Ger�ek listedeki ara� bo�ta
}

///////////////// Musteri Listesi S�n�f� //////////////////////

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
	aracListesi.aracGetir(aracNo).durum = 'K';						// Ger�ek listedeki arac�n durumunu Kiral�k yap
	aracListesi.aracGetir(aracNo).toplamKiralanma += kiralamaSuresi;		// Ger�ek listedeki arac�n toplam kiralanma s�resini artt�r
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

/////////////////////// Islem Listesi S�n�f� //////////////////

// yap�c� fonksiyon
IslemListesi::IslemListesi()
{
	this->bas = NULL;		// Listenin ba��n� olu�tur ve NULL ata
	this->islemSayisi = 0;	// Listede bulunan islem adetini s�f�rla
}

void IslemListesi::islemEkle(int islemTutari)
{
	// Bug�n�n tarihini al
	struct tm bugununTarihi;
	time_t simdi = time(0);
	bugununTarihi = *localtime(&simdi);	// y�llar 1900 den sonra ge�en seneler, ay ise ocaktan itibaren ge�en aylar� g�sterir
	
	islemNode* yeniNode = new islemNode();		// yeni Node i�in haf�zada yer ay�r
	yeniNode->islemTutari = islemTutari;		// yeni Node un �cret verisini ata
	yeniNode->islemNo = islemSayisi + 1;		// yeni Node islem no 'yu ata
	// i�lem tarihini bug�n�n tarihi yap
	yeniNode->islemTarihi.tm_year =  bugununTarihi.tm_year;	
	yeniNode->islemTarihi.tm_mon =  bugununTarihi.tm_mon;	
	yeniNode->islemTarihi.tm_mday =  bugununTarihi.tm_mday;	
    yeniNode->sonraki = this->bas;  		// Yeni Node un i�aret etti�i Node, m��teri listesinin ba��d�r
    this->bas = yeniNode;  	// Listesinin ba��n� de�i�tirip yeni eklenen Node yap
    this->islemSayisi++; 	// m��teri say�s�n� 1 artt�r
}

void IslemListesi::islemEkle(int islemTutari, int gun, int ay, int yil)
{
	islemNode* yeniNode = new islemNode();		// yeni Node i�in haf�zada yer ay�r
	yeniNode->islemTutari = islemTutari;		// yeni Node un �cret verisini ata
	yeniNode->islemNo = islemSayisi + 1;		// yeni Node islem no 'yu ata
	// i�lem tarihini bug�n�n tarihi yap
	yeniNode->islemTarihi.tm_year =  yil-1900;	
	yeniNode->islemTarihi.tm_mon =  ay-1;	
	yeniNode->islemTarihi.tm_mday =  gun;	
    yeniNode->sonraki = this->bas;  		// Yeni Node un i�aret etti�i Node, m��teri listesinin ba��d�r
    this->bas = yeniNode;  	// Listesinin ba��n� de�i�tirip yeni eklenen Node yap
    this->islemSayisi++; 	// m��teri say�s�n� 1 artt�r	
}


void IslemListesi::guncelle()
{
	// Bug�n�n tarihini al
	struct tm bugununTarihi;
	time_t simdi = time(0);
	bugununTarihi = *localtime(&simdi);	// y�llar 1900 den sonra ge�en seneler, ay ise ocaktan itibaren ge�en aylar� g�sterir
	
	// Liste bo�sa bir �ey yapma
   if (this->bas == NULL) 
      return; 
      
   // Listenin ba��ndan ba�layarak listede ilerle ve 1 ay� ge�mi� i�lemleri sil
   	struct islemNode* temp = this->bas; 
   	struct islemNode* temp2;
   	struct islemNode* temp3; 
   	
	// 1 ay� ge�mi� silinecek i�lem listenin ba�� ise (son eklenen i�lem ise) b�t�n listeyi sil
    if (difftime(mktime(&bugununTarihi), mktime(&temp->islemTarihi)) / (60 * 60 * 24) > 30) 
    { 
		while (temp != NULL)  
		{  
		    temp2 = temp->sonraki;  
		    free(temp);  
		    temp = temp2;  
		}  

        this->bas = NULL;		// Listenin ba��n� olu�tur ve NULL ata
		this->islemSayisi = 0;	// Listede bulunan islem adetini s�f�rla
    }
    // 1 ay� ge�mi� i�lem listenin ortas�nda ise onu ve �nceki i�lemleri sil
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
	
	// �slem numaralarini d�zelt
	islemNode* simdikiNode = this->bas;
	for(int i = this->islemSayisi; i>=1; i--)
	{
		 simdikiNode->islemNo = i;
	}
	
	// g�ncellenen halini dosyaya yaz
	this->islemListesiniDosyayaYaz();
}

void IslemListesi::islemListesiniDosyayaYaz()
{
	// dosyay� olu�tur (�zerine yazma modunda)
	std::ofstream dosya;
	dosya.open("IslemListesi.csv");
	// ba�l�k yaz
	dosya << "Islem No;Tutar;Tarih;\n";
	// B�t�n islem verilerini yaz.
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
	// dosyay� a�
	FILE *dosya = fopen ("IslemListesi.csv","r"); // okuma modunda a�	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi,islemNo,islemTutari;
		struct tm islemTarihi;
		
		// ba�l��� oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		// dosyan�n sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yaz�lm�� veriyi oku. 
			// %[^;] format� noktal� virg�l d���nda ne varsa okumaya yarar (string tipi veriler i�in)
			returnSayisi = fscanf(dosya,"%d;%d;%d.%d.%d;",&islemNo,&islemTutari,&islemTarihi.tm_mday,&islemTarihi.tm_mon,&islemTarihi.tm_year);
			// 5 adet veri okunur. E�er okunan veri say�s� 5ten azsa dosya sonuna ula��lm�� demektir.
			if(returnSayisi == 5)
			{
				// yeni i�lem verisi okunabildiyse onu listesine ekle 
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
	// B�t�n ara�lara bak. Ayn� plakaya sahip bir ara� varsa onu kaydetme.
	for(int i = 1; i<= aracListesi.aracSayisi;i++)
	{
		if(plaka.compare(aracListesi.aracOku(i).plaka) == 0)
		{
			cout << "Hata! Kayit yapilamadi." << endl;
			cout << "Bu plakaya sahip baska bir arac kayitlidir." << endl;
			return;
		}
	}
	
	// M��teri daha �nce kay�tl� de�ilse 
	string marka,model;
	int fiyat;
	
	cout << "Marka: "; cin >> marka;
	cout << "Model: "; cin >> model;
	cout << "Gunluk kiralama fiyati: "; cin >> fiyat;
	
	// Arac� listeye ekle. Yeni eklenen arac�n durumu her zaman bo�tad�r ve toplam kiralanma s�resi 0'd�r.
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
	cout << "\nBilgilerini guncellemek istediginiz arac�n no'su: "; cin >> aracNo;
	// E�er arac listede varsa g�ncelle , yoksa g�ncelleme
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
	// Arac Arama alt men�s�, �st men�ye d�n komutu gelmedi�i s�rece tekrar eder
	while(true)
	{
		cout << "\n######### Arac Ara #########" << endl;
		cout << "0- Ust Menuye Geri Don" << endl << "1- Plakaya Gore Arac Ara" << endl 
			<< "2- Markaya Gore Arac Ara" << endl << "3- Modele Gore Arac Ara"  << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&aracAraCevap);
		
		// Ara� arama i�in kullan�c�dan komut al�n�r. ge�ersiz bir de�er girilmesi durumunda uyar� verilir.
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
					// E�er ara� plakas� e�le�iyorsa ekrana bas
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
					// E�er ara� markas� e�le�iyorsa ekrana bas
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
					// E�er ara� markas� e�le�iyorsa ekrana bas
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
	// B�t�n m��terilere bak. Ayn� TC'ye sahip bir m��teri varsa onu kaydetme.
	for(int i = 1; i<= musteriListesi.musteriSayisi;i++)
	{
		if(tc == musteriListesi.musteriGetir(i).tc)
		{
			cout << "Hata! Kayit yapilamadi." << endl;
			cout << "Bu T.C. No'lu' baska bir musteri kayitlidir." << endl;
			return;
		}
	}
	
	// M��teri daha �nce kay�tl� de�ilse 
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
	
	// Arac Se�imi ��in Bo�ta olan ara�lar� ekrana bas
	cout << endl;
	aracListesi.kiralanabilirAracListesiniEkranaBas();
	cout << "\nKiralamak Istenilen Arac No: "; cin >> aracNo;
	cout << "Kiralama Suresi (gun): "; cin >> kiralamaSuresi;
	musteriListesi.musteriEkle(aracListesi,aracNo,kiralamaSuresi,tc,ad,soyad,dogumTarihi,dogumYeri,cinsiyet,ehliyetVerilis,ehliyetGecerlilik,kanGrubu);
	// Son eklenen i�lem �cretini hesaplay�p i�lemlere ekle
	islemListesi.islemEkle(aracListesi.aracOku(aracNo).fiyat*kiralamaSuresi);
	// �slem Listesini yaz
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
	// E�er musteri listede varsa g�ncelle , yoksa g�ncelleme
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
	// dosyay� olu�tur (�zerine yazma modunda)
	std::ofstream dosya;
	dosya.open("MusteriListesi.csv");
	// ba�l�k yaz
	dosya << "T.C.;Ad;Soyad;Dogum Tarihi;Dogum Yeri;Cinsiyet;Ehliyet Verilis Tarihi;Ehliyet Gecerlilik Tarihi;Kan Grubu;Kiraladigi Arac No;Kiraladigi Aracin Plakasi;Kiraladigi Aracin Markasi;Kiraladigi Aracin Modeli;Kiralama Suresi (gun)\n";
	// B�t�n m��teri verilerini yaz.
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
	// Kar���kl�k ��kmas�n diye ara� listesini de dosyaya yaz
	aracListesiniDosyayaYaz(aracListesi);
}

void aracListesiniDosyayaYaz(AracListesi aracListesi)
{
	// dosyay� olu�tur (�zerine yazma modunda)
	std::ofstream dosya;
	dosya.open("AracListesi.csv");
	// ba�l�k yaz
	dosya << "Kiralama Ucreti (gun);Plaka;Marka;Model;Durum;Toplam Kiralanma Suresi (gun)\n";
	// B�t�n m��teri verilerini yaz.
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

	// dosyay� a�
	FILE *dosya = fopen ("MusteriListesi.csv","r"); // okuma modunda a�	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi;
		unsigned long long int tc;
		char ad[25],soyad[25],dogumYeri[25],kanGrubu[5],plaka[25],marka[25],model[25];
		char cinsiyet;
		struct tm dogumTarihi,ehliyetVerilis,ehliyetGecerlilik;
		int aracNo,kiralamaSuresi;
		
		// ba�l��� oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		// dosyan�n sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yaz�lm�� veriyi oku. 
			// %[^;] format� noktal� virg�l d���nda ne varsa okumaya yarar (string tipi veriler i�in)
			returnSayisi = fscanf(dosya,"%llu;%[^;];%[^;];%d/%d/%d;%[^;];%c;%d/%d/%d;%d/%d/%d;%[^;];%d;%[^;];%[^;];%[^;];%d;",&tc,ad,soyad,&dogumTarihi.tm_mday,
							&dogumTarihi.tm_mon,&dogumTarihi.tm_year,dogumYeri,&cinsiyet,&ehliyetVerilis.tm_mday,&ehliyetVerilis.tm_mon,&ehliyetVerilis.tm_year,
							&ehliyetGecerlilik.tm_mday,&ehliyetGecerlilik.tm_mon,&ehliyetGecerlilik.tm_year,kanGrubu,&aracNo,plaka,marka,model,&kiralamaSuresi);
			// 20 adet veri okunur. E�er okunan veri say�s� 20den azsa dosya sonuna ula��lm�� demektir.
			if(returnSayisi == 20)
			{
				// yeni m��teri verisi okunabildiyse onu listesine ekle 
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
	// dosyay� a�
	FILE *dosya = fopen ("AracListesi.csv","r"); // okuma modunda a�	
	if (dosya!=NULL)
	{
		// Veriler
		int returnSayisi;
		char plaka[25],marka[25],model[25], s_durum[25];
		int fiyat, toplamKiralanmaSuresi;
		
		// ba�l��� oku
		char baslik[300];
		fscanf(dosya,"%[^\n]",baslik);
		
		// dosyan�n sonuna gelene kadar okuma yap
		while(true)
		{
			// belirli bir formatta yaz�lm�� veriyi oku. 
			// %[^;] format� noktal� virg�l d���nda ne varsa okumaya yarar (string tipi veriler i�in)
			returnSayisi = fscanf(dosya,"%d;%[^;];%[^;];%[^;];%[^;];%d;",&fiyat,plaka,marka,model,s_durum,&toplamKiralanmaSuresi);
			
			// 6 adet veri okunur. E�er okunan veri say�s� 6dan azsa dosya sonuna ula��lm�� demektir.
			if(returnSayisi == 6)
			{
				// yeni ara� verisi okunabildiyse onu listesine ekle 
				aracListesi.aracEkle(fiyat,plaka,marka,model,s_durum[0],toplamKiralanmaSuresi);
			}
			else
				break;		
		}
		fclose(dosya);	
	}	
}


/////////////////////// Menu ///////////////////////

// men� fonksiyonu
void menu(string yoneticiSifresi)
{
	int cevap;
	MusteriListesi musteriListesi;
	AracListesi aracListesi;
	IslemListesi islemListesi;
	cout << "\n######### Arac Kiralama Sistemi #########\n" << endl;
	yoneticiGirisi(yoneticiSifresi);
	////////////////////////// art�k y�netici giri�i yap�lm��t�r//////////////////////////
	// a��l��ta musteri, arac ve islem listesini dosyadan okuyarak g�ncelle
	musteriListesiniDosyadanOku(musteriListesi,aracListesi);
	islemListesi.islemListesiniDosyadanOku();
	// Men� i�lemin tamamlanmas� sonucu kapanmaz. S�rekli yeni i�lemler i�in a��kt�r.
	while(true)
	{		
		cout << "\n######### ANA MENU #########" << endl;
		cout << "1- Musteri Islemleri" << endl << "2- Arac Islemleri" << endl
			 << "3- Para Dokumu" << endl << "4- Arac Talep Miktarlari" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&cevap);
		// Kullan�c�dan alt men� i�in se�im yapmas� istenir. Ge�erli bir se�im yap�p yapmad��� kontrol edilir.
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


// �ifreyi do�ru girene kadar y�netici sifresi sorar
void yoneticiGirisi(string yoneticiSifresi) 
{
	string yoneticiSifresiGirisi;
	do {
		cout << "Devam etmek icin lutfen yonetici sifresini dogru olarak giriniz: ";
		cin >> yoneticiSifresiGirisi;
	}while(yoneticiSifresiGirisi.compare(yoneticiSifresi) != 0);
	cout << "\nGiris Basarili.\n";
}


// Musteri i�lemleri alt men�s�
void musteriIslemleriAltMenu(MusteriListesi& musteriListesi, AracListesi& aracListesi, IslemListesi& islemListesi)
{
	int musteriIslemleriCevap;
	// Musteri i�lemleri alt men�s�, ana men�ye d�n komutu gelmedi�i s�rece tekrar eder
	while(true)
	{
		cout << "\n######### Musteri Islemleri #########" << endl;
		cout << "0- Ana Menu" << endl << "1- Musteri Kayit Et" << endl << "2- Kayitli Musteri Sil" << endl 
			 << "3- Kayitli Musteri Guncelle" << endl << "4- Musteri Listesini Dosyaya Aktar" << endl << "5- Musteri Listesini Goster" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&musteriIslemleriCevap);
		
		// Musteri i�lemleri i�in kullan�c�dan komut al�n�r. ge�ersiz bir de�er girilmesi durumunda uyar� verilir.
		switch(musteriIslemleriCevap)
		{
			case 0: 
				return;			// ana men�ye d�n komutu geldiyse m��teri i�lemlerinden ��k
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

// Arac i�lemleri alt men�s�
void aracIslemleriAltMenu(AracListesi& aracListesi)
{
	int aracIslemleriCevap;
	// Arac i�lemleri alt men�s�, ana men�ye d�n komutu gelmedi�i s�rece tekrar eder
	while(true)
	{
		cout << "\n######### Arac Islemleri #########" << endl;
		cout << "0- Ana Menu" << endl << "1- Arac Kayit Et" << endl << "2- Kayitli Araci Sil" 
			 << endl << "3- Kayitli Arac Guncelle"  << endl << "4- Arac Listesini Dosyaya Aktar" 
			 << endl << "5- Arac Ara" << endl << "6- Butun Araclari Listele" << endl;
		cout << "\nIslem seciniz: ";
		scanf("%d",&aracIslemleriCevap);
		
		// Ara� i�lemleri i�in kullan�c�dan komut al�n�r. ge�ersiz bir de�er girilmesi durumunda uyar� verilir.
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
	// son 1 ayda ger�ekle�en i�lemler d���ndakileri sil
	islemListesi.guncelle();
	// Toplam geliri hesapla
	int toplamGelir = 0;
	// i�lem listesindeki b�t�n gelirleri topla
	islemNode * simdiki = islemListesi.bas;
	
	for(int i = 1; i<=islemListesi.islemSayisi; i++)
	{
		toplamGelir += simdiki->islemTutari;
        simdiki = simdiki->sonraki;  
    }  
	// Ekrana bas
	cout << "\nIsletmemizde son 1 ayda toplam " << islemListesi.islemSayisi << " kez arac kiralanmistir ve " << toplamGelir << " TL kazanilmistir." << endl;
}


