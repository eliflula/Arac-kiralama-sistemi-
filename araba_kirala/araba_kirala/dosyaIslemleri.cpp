#include "dosyaIslemleri.h"

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

