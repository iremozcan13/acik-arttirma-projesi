#include <stdio.h>
#include <stdlib.h>
//typedef ve struct'� kullanarak teklif biligilerini yazd�k.
typedef struct {
    int teklifveren_no;
    double teklif;
} Teklifler;

//typedef ve struct'� kullanarak artt�rma bilgilerini yazd�k.
typedef struct {
    int katilimci_sayisi;
    int kazanan_no;
    Teklifler *teklifler; //Teklifler de�i�keninin bellekteki adresini belirtmesi i�in pointer kulland�k.
} Arttirma;

//�demeyi hesaplamas� i�in double t�r�nden geriye de�er d�nd�ren bir fonksiyon olu�turduk.
double odemeyi_hesapla(Arttirma a, int kazanan_no) {
    double odeme = 0.0;
    int i = 0;
    for (i = 0; i < a.katilimci_sayisi; i++) {
        if (i != kazanan_no) {
            odeme= a.teklifler[i].teklif;
        }
    }
    return odeme;
}
//A��k artt�rma i�lemini ger�ekle�tiren geriye de�er d�nd�rmeyen bir fonksiyon olu�turduk.
void acik_arttirma(Arttirma a) {
	//Hen�z bir teklif al�nmad��� i�in -1'den ba�lat�l�r.
    double en_yuksek_teklif = -1.0;
    int kazanan_no = -1;
    int i = 0;
    //En y�ksek teklifi ve bu teklifin no'sunu bulmak i�in for d�g�s� ba�lat�l�r.
    for (i = 0; i < a.katilimci_sayisi; i++) {
        if (a.teklifler[i].teklif > en_yuksek_teklif) {
            en_yuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i + 1;
        }
    }
    //fonksiyonu �a��rd�k.
    double odeme = odemeyi_hesapla(a, kazanan_no);
    printf("Kazanan No: %d, En Yuksek Teklif: %f, Odeme: %f\n", kazanan_no, en_yuksek_teklif, odeme);
}
int main(){
//De�i�kenin ba�lang�� de�erlerini belirsiz b�rakmamak i�in  Arttirma t�r�ndeki bir struct'�n t�m elemanlar�na s�f�r de�erini atad�k.
Arttirma a = {};
    //Kullan�c�dan kat�l�c� say�s�n� ald�k.
    printf("Katilimci sayisini girin: ");
    scanf("%d", &a.katilimci_sayisi);
   
    //Arttirma struct'n� olu�tururken, bu struct'�n i�indeki teklifler eleman�na de�er atamak i�in bu diziyi kulland�k.
    Teklifler teklifler_dizi[a.katilimci_sayisi];
    a.teklifler = teklifler_dizi;
    
    //Kullan�c�dan teklifleri ald�k.
    int i = 0;
    //for d�g�s�n� kullan�c�n�n her bir kat�l�mc� i�in teklif girmesi i�in kulland�k.
    for (i = 0; i < a.katilimci_sayisi; i++) {
        a.teklifler[i].teklifveren_no = i + 1;
        printf("%d. teklif verenin teklifini girin: ", a.teklifler[i].teklifveren_no);
        scanf("%lf", &a.teklifler[i].teklif);
    }
    //Fonkiyonu �a��rarak a��k artt�rma i�lemini ba�latt�k.
    acik_arttirma(a);
	return 0;
}
