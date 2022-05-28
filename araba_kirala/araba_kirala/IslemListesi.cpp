#include "IslemListesi.h"

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
