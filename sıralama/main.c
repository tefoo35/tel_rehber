#include <stdio.h>

int main()
{
int i, j, enKucuk, temp;
int dizi[5]={8,4,5,9,2};
     for (i=0; i<5; i++)
     {
         enKucuk = i;
         for (j=i+1; j<5; j++)
         {
             if (dizi[j] < dizi [enKucuk])
             enKucuk = j;
         }
         temp = dizi[i];
         dizi[i] = dizi[enKucuk];
         dizi[enKucuk] = temp;
         printf("%d",dizi[i]);
     }

   return 0;
}
