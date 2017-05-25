#include <stdio.h>
#include <stdlib.h>

 typedef struct {
 char isim[100];
 long int kod;
 long int numara;
 }telefon;

int main(){
  menu();

    return 0;
}
int menu(){
  int x;
  int kod=1;
while(1){
    printf("\t\t\t\t\t----------------------------------\n\t\t\t\t\t|eklemek icin 1,\t\t|\n\t\t\t\t\t|listelemek icin 2,\t\t|\n\t\t\t\t\t|kaydi duzenlemek icin 3,\t|\n\t\t\t\t\t|numara ile arama yapmak icin 4,|\n\t\t\t\t\t|isme gore arama yapmak icin 5,\t|\n\t\t\t\t\t|kayit silmek icin 6,\t\t|\n\t\t\t\t\t|ciklmak icin 7,\t\t|\n\t\t\t\t\t|basiniz\t\t\t|\n\t\t\t\t\t---------------------------------- ");
    scanf("%d",&x);
if(x==1){ekle(kod);kod++; }
else if(x==2) goster();
else if(x==3) update();
else if(x==4)noarama();
else if(x==5)isimarama();
else if(x==6)sil();
else if(x==7)cikis();
else exit(1);
}
}
int cikis(){
exit(1);
}


int ekle(int kod){
    int i;
    FILE *dosya;
    telefon tel;


    dosya=fopen("TelefonRehber.txt","a");
printf("isim giriniz");
  scanf("%s",tel.isim);
   printf("tel no girin");
    scanf("%d",&tel.numara);
    printf("kodu girin:");
    scanf("%d",&tel.kod);

fprintf(dosya,"\n%s\t%d\t%d",&tel.isim,tel.numara,tel.kod);
    fclose(dosya);
    system("CLS");}


int goster(){
    FILE *dosya;
telefon tel;
int bas;

    dosya=fopen("TelefonRehber.txt","r");

 while(!feof(dosya)){
    fscanf(dosya,"%s\t\t%d\t\t%d",&tel.isim,&tel.numara,&tel.kod);
if(tel.numara==1954213952){//kayıt olmayınca rastgele kayıt olusturuyordu bunu engelledim
    printf("kayit yok");
    printf("\nana menuyu donmek icin bir tusa basiniz");
    scanf("%d",&bas);
    system("CLS");
    menu();
}
    printf("\nadi=%s",tel.isim);
    printf("\nno=%d",tel.numara);
    printf("\nid=%d\n\n",tel.kod);


    }
      scanf("%d",&bas);
fclose(dosya);
system("CLS");}

int isimarama(){

FILE *dosya;
telefon tel;
int x;
char aranacakad[15];
int bulunan=0;
int tekrar;

            dosya=fopen("TelefonRehber.txt","r");
            printf("\naranacak adi girin\t");
            scanf("%s",aranacakad);
            while(!feof(dosya)){


        fscanf(dosya, "%s%d%d", &tel.isim, &tel.numara, &tel.kod);
char bas;
        if(!strcmp(tel.isim,aranacakad))//aranan isim bulunuyor

        { // bbulundu!
            printf("adi\t\tnumara\t\tkodu\n");
            printf("----            ------          -----\n");
            printf("%s\t\t", tel.isim);
            printf("%d\t\t", tel.numara);
            printf("%d\n", tel.kod);
            bulunan ++;


        }
        printf("\n cikmak icin bir tusa basin");
        scanf("%s",&bas);
            system("CLS");
            menu();}

     if(bulunan==0){
            printf("bulunamadi,tekrar denemek icin 1,ana menuye donmek icin 2 basiniz\n");
              scanf("%d",&tekrar);
            if(tekrar==1)isimarama();
            else if(tekrar==2){system("CLS");menu();}
            else exit(1);
    }
    else exit(1);



    return 0;
}

int noarama(){
FILE *dosya;
telefon tel;
int x;
int aranacakno[15];
int bulunan=0;
int tekrar;

            dosya=fopen("TelefonRehber.txt","r");
            printf("\naranacak no gir\t");
            scanf("%d",&aranacakno);
            while(!feof(dosya))
{



        fscanf(dosya, "%s%d%d", &tel.isim, &tel.numara, &tel.kod);
char bas;
        if(!strcmp(&aranacakno,&tel.numara))//aranan  no bulunuyor
        { // bbulundu!
               printf("adi\t\tnumara\t\tkodu\n");
            printf("----            ------          -----\n");
            printf("%s\t   \t", tel.isim);
            printf("%d\t   \t", tel.numara);
            printf("%d\n", tel.kod);
            bulunan ++;
            printf("\n cikmak icin bir tusa basin");
            scanf("%s",&bas);
            system("CLS");
            menu();

}        }

     if(bulunan==0){
            printf("bulunamadi.tekrar arama yapmak icin 1,ana menuye donmek icin 2 ye basiniz\n");
            scanf("%d",&tekrar);
            if(tekrar==1)noarama();
            else if(tekrar==2){system("CLS");menu();}
            else exit(1);
    }
    else exit(1);

system("CLS");

    return 0;
}


int sil()
{FILE *dosya,*yeni; //dosya işaretçileri tanımlama
int aranan;
telefon tel;

printf("Silinecek kayit kodu nedir ? :");
scanf("%d",&aranan);//silincek isim aranıyor

dosya=fopen("TelefonRehber.txt","r");
yeni=fopen("rehber1.txt","w");
int bulunan=0,ara;

   while(!feof(dosya)){

      fscanf(dosya,"%s%d%d",tel.isim,&tel.numara,&tel.kod);

      if(tel.kod==aranan){
            fscanf(dosya,"%s%d%d",tel.isim,&tel.numara,&tel.kod);
            bulunan++;

      }
      if(bulunan==0){
        printf("kayit bulunamadi \ntekrar girmek icin 1'e,ana menuye donmek icin 2'ye basiniz");
        scanf("%d",&ara);
        if(ara==1){system("CLS");sil(); }
        else if(ara==2){system("CLS");menu();}
        else
            exit(0);
      }

      fprintf(yeni,"\n%s\t%d\t%d",&tel.isim,tel.numara,tel.kod);//arancak haricindekileri yazdırıyorum

   }
   char bas;
   printf("kayit silindi\n");
   printf("ana menuye donmek icin bir tusa basin");
   scanf("%s",&bas);

fclose(dosya);
fclose(yeni);

remove("TelefonRehber.txt");//asıl dosyayı siliyorum
rename("rehber1.txt","TelefonRehber.txt");//yeni dosyanın adını degistirioyrum
system("CLS");
return 0;
}

int update(){
FILE *dosya,*yeni; //dosya işaretçileri tanımlama
char aranan[15];
telefon tel;
int kod;
printf("update yapilacak kayit adi ? :");
scanf("%s",&aranan);

dosya=fopen("TelefonRehber.txt","r");
yeni=fopen("rehber1.txt","w");
int bulunan=0;
   while(!feof(dosya)){//okuyorum

      fscanf(dosya,"%s%d%d",tel.isim,&tel.numara,&tel.kod);

      if(strstr(tel.isim,aranan)){
            fscanf(dosya,"%s%d%d",tel.isim,&tel.numara,&tel.kod);
            bulunan++;}
           char bas;
  if(bulunan==0){  printf("kayit bulunamadi \ntekrar girmek icin 1'e,ana menuye donmek icin 2'ye basiniz");
        scanf("%d",&bas);
        if(bas==1){system("CLS");update(); }
        else if(bas==2){system("CLS");menu();}
        else
            exit(0);}

      fprintf(yeni,"\n%s\t%d\t%d",&tel.isim,tel.numara,tel.kod);//o kayıt haric digerlerini yeni dosyaya aktarırıyorum

   }


fclose(dosya);
fclose(yeni);
remove("TelefonRehber.txt");
rename("rehber1.txt","TelefonRehber.txt");

//yeniden ekleme kısmı
    dosya=fopen("TelefonRehber.txt","r+");
printf("isim ve soyisim giriniz girin");
  scanf("%s",tel.isim);
   printf("tel no girin");
    scanf("%d",&tel.numara);
   printf("yeni kodu girin");
    scanf("%d",&tel.kod);

fprintf(dosya,"\n%s\t%d\t%d",&tel.isim,tel.numara,tel.kod);
    fclose(dosya);
   system("CLS");}
