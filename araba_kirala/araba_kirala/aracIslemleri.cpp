#include "aracIslemleri.h"

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

