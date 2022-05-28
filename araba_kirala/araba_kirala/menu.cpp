#include "menu.h"

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
			 << endl << "5- Arac Ara" << endl << "6- Butun Araclari Listele";
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
