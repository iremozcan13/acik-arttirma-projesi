#include <stdio.h>
#include <stdlib.h>
//typedef ve struct'ý kullanarak teklif biligilerini yazdýk.
typedef struct {
    int teklifveren_no;
    double teklif;
} Teklifler;

//typedef ve struct'ý kullanarak arttýrma bilgilerini yazdýk.
typedef struct {
    int katilimci_sayisi;
    int kazanan_no;
    Teklifler *teklifler; //Teklifler deðiþkeninin bellekteki adresini belirtmesi için pointer kullandýk.
} Arttirma;

//Ödemeyi hesaplamasý için double türünden geriye deðer döndüren bir fonksiyon oluþturduk.
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
//Açýk arttýrma iþlemini gerçekleþtiren geriye deðer döndürmeyen bir fonksiyon oluþturduk.
void acik_arttirma(Arttirma a) {
	//Henüz bir teklif alýnmadýðý için -1'den baþlatýlýr.
    double en_yuksek_teklif = -1.0;
    int kazanan_no = -1;
    int i = 0;
    //En yüksek teklifi ve bu teklifin no'sunu bulmak için for dögüsü baþlatýlýr.
    for (i = 0; i < a.katilimci_sayisi; i++) {
        if (a.teklifler[i].teklif > en_yuksek_teklif) {
            en_yuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i + 1;
        }
    }
    //fonksiyonu çaðýrdýk.
    double odeme = odemeyi_hesapla(a, kazanan_no);
    printf("Kazanan No: %d, En Yuksek Teklif: %f, Odeme: %f\n", kazanan_no, en_yuksek_teklif, odeme);
}
int main(){
//Deðiþkenin baþlangýç deðerlerini belirsiz býrakmamak için  Arttirma türündeki bir struct'ýn tüm elemanlarýna sýfýr deðerini atadýk.
Arttirma a = {};
    //Kullanýcýdan katýlýcý sayýsýný aldýk.
    printf("Katilimci sayisini girin: ");
    scanf("%d", &a.katilimci_sayisi);
   
    //Arttirma struct'ný oluþtururken, bu struct'ýn içindeki teklifler elemanýna deðer atamak için bu diziyi kullandýk.
    Teklifler teklifler_dizi[a.katilimci_sayisi];
    a.teklifler = teklifler_dizi;
    
    //Kullanýcýdan teklifleri aldýk.
    int i = 0;
    //for dögüsünü kullanýcýnýn her bir katýlýmcý için teklif girmesi için kullandýk.
    for (i = 0; i < a.katilimci_sayisi; i++) {
        a.teklifler[i].teklifveren_no = i + 1;
        printf("%d. teklif verenin teklifini girin: ", a.teklifler[i].teklifveren_no);
        scanf("%lf", &a.teklifler[i].teklif);
    }
    //Fonkiyonu çaðýrarak açýk arttýrma iþlemini baþlattýk.
    acik_arttirma(a);
	return 0;
}
