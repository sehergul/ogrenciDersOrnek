#include <iostream>
#define OgrenciSayisi 2
#define DersSayisi 3

using namespace std;

class Ders{
public:
    void DersOzeti();
    void Bilgiler(string,float,float);
    bool DersBasarisi(float);
private:
    string DersinKodu;
    bool DersBasariDurumu;
    float Vize, Final, DersOrtalamasi;};


void Ders::Bilgiler(string Kod, float Viz, float Fin){
    DersinKodu = Kod;
    Vize= Viz;
    Final= Fin;
    DersOrtalamasi= Vize*0.4 + Final*0.6;
    DersBasariDurumu = DersBasarisi (DersOrtalamasi);}

bool Ders::DersBasarisi(float DersOrt){
    if(DersOrt>=60)
        DersBasariDurumu=true;
    else
        DersBasariDurumu=false;
    return DersBasariDurumu;}

void Ders::DersOzeti(){
    cout << "Dersin adý: " << DersinKodu << endl;
    cout << "Vize: " << Vize << endl;
    cout << "Final: " << Final << endl;
    cout << "Ortalama: " << DersOrtalamasi << endl;
    cout << "Basari durumu: " << DersBasariDurumu << endl;}

class Ogrenci{
public:
    string OgrencininAdi, OgrencininSoyadi;
    int OkulNumarasi;
    Ders KayitliOlduguDersler[DersSayisi];
    void DersBilgileri(Ders [],int);
    void KimlikBilgileri()const;
    Ogrenci(string=" ",string=" ", int=0);
    }Kisiler[OgrenciSayisi]; //Ogrenci sinifinin objecti demek

Ogrenci::Ogrenci(string Adi, string Soyad,int OkulNo){ //constructor default
    OgrencininAdi=Adi;
    OgrencininSoyadi=Soyad;
    OkulNumarasi=OkulNo;}

void Ogrenci::KimlikBilgileri()const{
    cout << "Adi: " << OgrencininAdi << endl;
    cout << "Soyadi: " << OgrencininSoyadi << endl;
    cout << "Okul no: " << OkulNumarasi << endl;}

void Ogrenci::DersBilgileri(Ders Dersler[],int adet){
    for(int i=0;i<DersSayisi;i++)
        Dersler[i].DersOzeti();}


int main(){
    string Ad, Soyad, DersKodu;
    int No;
    float Vize, Final;
    puts("Ogrenci bilgileri");
    for(int i=0; i<OgrenciSayisi;i++){
        cout << i+1 << ".ogrencinin okul numarasini, adini ve soyadini giriniz: ";
        cin >> No >> Ad >> Soyad;
        Kisiler[i].OgrencininAdi = Ad;
        Kisiler[i].OgrencininSoyadi=Soyad;
        Kisiler[i].OkulNumarasi=No;}

    for(int j=0;j<OgrenciSayisi;j++){
        cout << "\n" << Kisiler[j].OgrencininAdi << " " << Kisiler[j].OgrencininSoyadi << " ogrencisine ait ders bilgileri" << endl;
        for(int i=0;i<DersSayisi;i++){
            cout << i+1 << ".ders kodu, vize ve final giriniz: ";
            cin >> DersKodu >> Vize >> Final;
            Kisiler[j].KayitliOlduguDersler[i].Bilgiler(DersKodu,Vize,Final);}}

    for(int j=0;j<OgrenciSayisi;j++){
        Kisiler[j].KimlikBilgileri();
        for(int i=0;i<DersSayisi;i++)
            Kisiler[j].KayitliOlduguDersler[i].DersOzeti();}


    return 0;
}
