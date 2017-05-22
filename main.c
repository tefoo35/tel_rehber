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
while(1){
    printf("eklemek icin 1,\nlistelemek icin 2,\nkaydi duzenlemek icin 3,\nnumara ile arama yapmak icin 4,\nisme gore arama yapmak icin 5,\nkayit silmek icin 6,\nciklmak icin 6,\nbasiniz ");
    scanf("%d",&x);
if(x==1)ekle();
else if(x==2) goster();
//else if(x==3) update();
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


int ekle(){
    int i;
    FILE *dosya;
    telefon tel;
    tel.kod=0;
    for(i=0;i<1000;i++){
        tel.kod++;
        break;
    }
    dosya=fopen("TelefonRehber.txt","a");
printf("isim ce soyisim giriniz girin");
  scanf("%s",tel.isim);
   printf("tel no girin");
    scanf("%d",&tel.numara);

fprintf(dosya,"\n%s\t%d\t%d",&tel.isim,tel.numara,tel.kod);
    fclose(dosya);}


int goster(){
    FILE *dosya;
telefon tel;

    dosya=fopen("TelefonRehber.txt","r");
 while(!feof(dosya)){

fscanf(dosya,"%s\t\t%d\t\t%d",&tel.isim,&tel.numara,&tel.kod);
    printf("\nadi=%s",tel.isim);
    printf("\nno=%d",tel.numara);
    printf("\nid=%d\n\n",tel.kod);

    }
fclose(dosya);}

int isimarama(){

FILE *dosya;
telefon tel;
int x;
char aranacakad[15];
int bulunan=0;
int tekrar;

            dosya=fopen("TelefonRehber.txt","r");
            printf("\naranacak adý girin\t");
            scanf("%s",&aranacakad);
            while(!feof(dosya)){


        fscanf(dosya, "%s%d%d", &tel.isim, &tel.numara, &tel.kod);

        if(!strcmp(aranacakad, tel.isim))
        { // bbulundu!
            printf("%s\t", tel.isim);
            printf("%d\t", tel.numara);
            printf("%d\n", tel.kod);
            bulunan ++;
            menu();

        }}

     if(bulunan==0){
            printf("bulunamadi,tekrar denemek icin 1,ana menuye donmek icin 2 basiniz\n");
              scanf("%d",&tekrar);
            if(tekrar==1)isimarama();
            else if(tekrar==2)menu();
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

        if(!strcmp(&aranacakno,&tel.numara))
        { // bbulundu!
            printf("%s\t", tel.isim);
            printf("%d\t", tel.numara);
            printf("%d\n", tel.kod);
            bulunan ++;
            menu();

}        }

     if(bulunan==0){
            printf("bulunamadi.tekrar arama yapmak icin 1,ana menuye donmek icin 2 ye basiniz\n");
            scanf("%d",&tekrar);
            if(tekrar==1)noarama();
            else if(tekrar==2)menu();
            else exit(1);
    }
    else exit(1);



    return 0;
}


int sil()
{
    FILE *dosya,*dosya1;
    dosya=fopen("TelefonRehber.txt","r");
    dosya1=fopen("TelefonRehber1.txt","w");
    telefon tel;
char arancak[15];
int okundu=0;
printf("aranacak ismi girin");
scanf("%s",&arancak);
while(!feof(dosya)){

fscanf(dosya,"%s\t%d\t%d",&tel.isim,&tel.numara,&tel.kod);
    if(strcmp(arancak,tel.isim)){

          fprintf(dosya1,"%s\t%d\t%d\t",&tel.isim,tel.numara,tel.kod);
    okundu++;
break;
    }
    else
        printf("bulunamdi");

}
if(okundu!=0){
    printf("silindi");

}
else
    printf("silinmedi");
fclose(dosya);
fclose(dosya1);
remove("TelefonRehber.txt");
rename("TelefonRehber1.txt","TelefonRehber.txt");


    return 1;
}
