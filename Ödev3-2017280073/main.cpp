#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //OGUZHAN DINCAR-2017280073


    //input.txt dosyasından verileri çekiyorum
    ifstream dosya("input.txt");

    string ogrenciID[50];
    string ogrenciCevap[50];
    int ogrenciSayisi=0;
    int soruSayisi;
        dosya >> soruSayisi;

    cout<<"Soru Sayisi:"<<soruSayisi<<endl;

    string cevaplar;
        dosya >> cevaplar;

    int sayac = cevaplar.length();

    char cevapAnahtari[soruSayisi];
    int i=0,j=0;

    while(i < sayac){
        cevapAnahtari[j] = cevaplar[i];
        i += 2;
        j++;
    } //',' isaretinin islenmemesi icin yaptim.

    cout<<"Cevap Anahtari:";

    for(int x=0;x<soruSayisi;x++){
        cout<<cevapAnahtari[x];
    }

    cout<<endl;

    //input.txt'de bos birakilan sorulara 0 yazdim.

    while(dosya){  //input.txt'de 1.sutun=ogrenciID,2.sutun=ogrenciCevap olarak atadım.
        dosya >>ogrenciID[ogrenciSayisi]>>ogrenciCevap[ogrenciSayisi];
        ogrenciSayisi++;
    }

    int notlar[ogrenciSayisi-1] = {0};   //1 fazladan geldigi icin -1 yazarak durumu duzelttim.
    int dogruCevap[ogrenciSayisi-1] = {0};
    int yanlisCevap[ogrenciSayisi-1] = {0};
    int bos[ogrenciSayisi-1] = {0};
    int y=0;

    //ogrencilerin notlarini hesapliyorum.

    for(i=0;i<ogrenciSayisi-1;i++){
        y=0;
        for(j=0;j<40;j++){
            if(ogrenciCevap[i][j] != ','){
                if(cevapAnahtari[y] == ogrenciCevap[i][j]){ //dogru cevaplari tuttum.
                    dogruCevap[i]++;
                }
                else if(ogrenciCevap[i][j] == '0'){ //bos cevaplari tuttum.
                    bos[i]++;
                }
                else{
                    yanlisCevap[i]++;  //yanlis cevaplari tuttum.
                }
                y++;
                j++;
            }
        }

    }

    cout<<"Ogrencilerin Notlari:"<<endl; //20 soru,80 uzerinden degerlendirilcek

    int z=0;

    //dogru,yanlis ve bos cevaplarin soylendigi gibi puanlarını atadım ve tuttum.
    while(z<ogrenciSayisi-1){
        notlar[z] = dogruCevap[z] * 4;
        notlar[z] = notlar[z] + yanlisCevap[z] * -1;

        if(notlar[z]<0){
           notlar[z] = 0;
        }
        cout<<ogrenciID[z]<<" "<<notlar[z]<<endl;
        z++;
    }

    int enDusukNot=0;
    int enYuksekNot=0;
    int notlarinToplami=0;
    int notlarinMedyani=0;


    for(i=0;i<ogrenciSayisi-1;i++){
        if (notlar[i] > notlar[i+1])
		{
			if (enYuksekNot < notlar[i]) //en yuksek notu buldum.
			enYuksekNot = notlar[i];
		}

		if (notlar[i] < notlar[i+1])
		{
			if (enDusukNot > notlar[i])  //en dusuk notu buldum.
			enDusukNot = notlar[i];
		}
	}

	//notlarin acikligini buldum
	int notlarinAcikligi = enYuksekNot - enDusukNot;

    //notlarin toplamini buldum
    for(i=0;i<ogrenciSayisi-1;i++){
        notlarinToplami = notlarinToplami + notlar[i];
    }

    //notlarin ortalamasini hesapladim
    int notlarinOrtalamasi = notlarinToplami / (ogrenciSayisi-1);


    //notlarin medyan hesabii yapmaya calistim
    if(ogrenciSayisi % 2 == 1){
        notlarinMedyani = notlar[((ogrenciSayisi + 1) / 2) -1];
    }
    else{
        notlarinMedyani = (notlar[(ogrenciSayisi / 2) -1] + notlar[ogrenciSayisi / 2]) / 2;
    }




    //output.txt dosyasi olusturuyoruz ve sonuclari dosyaya yazdiriyoruz.
    ofstream output("output.txt");
    output<<"***Ogrenci Bilgileri***"<<endl;

    i=0;
    while(i<ogrenciSayisi-1){
        output <<i+1<<"."<<ogrenciID[i]<<"=="<<notlar[i]<<endl;
        i++;
    }

    output<<"**********************"<<endl;
    output<<"En Dusuk Not:"<<enDusukNot<< "*****"<<"En Yuksek Not:"<<enYuksekNot<<endl;
    output<<"Notlarin Ortalamasi:"<<notlarinOrtalamasi<<"*****"<<"Notlarin Medyani:"<<notlarinMedyani<<endl;
    output<<"Notlarin Acikligi:"<<notlarinAcikligi<<"*****"<<"Notlarin Toplami:"<<notlarinToplami<<endl;

    cout<<endl;
    cout<<"Dosyaniz Hazirlanmistir Lutfen Kontrol Ediniz..."<<endl;

    output.close();
	
    //kaynak
    //https://www.udemy.com/course/cpluspusprogramlama_nesneyeyonelikprogramlama/


    return 0;
}
