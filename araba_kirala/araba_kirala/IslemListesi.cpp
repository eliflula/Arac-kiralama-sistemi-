#include "IslemListesi.h"

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
