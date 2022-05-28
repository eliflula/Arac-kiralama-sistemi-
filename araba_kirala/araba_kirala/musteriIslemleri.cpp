#include "musteriIslemleri.h"


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

