#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    //First Come First Serve Prensibi ile çalışan algoritma
    int n,is[15],bs[15],tbs=0,i,j;
    float o_bs;

    printf("\n Toplam kac islem islenecej (Max 15) > ");
    scanf("%d",&n);

    printf("\n isleme surelerini girin: \n");

    for(i=0;i<n;i++){
        printf("P[%d]: ",i+1);
        scanf("%d",&is[i]);
    }

    bs[0] = 0;
    for (i = 1; i < n; i++){
        bs[i] = 0;
        for (j = 0; j < i; j++){
            bs[i] = bs[i] + is[j];
        }
    }
    printf("\nIslem\t\tIsleme suresi\tBekleme suresi");
    for(i=0;i<n;i++){
        tbs += bs[i];
        printf("\nP[%d]\t\t%d\t\t%d",i+1,is[i],bs[i]);
    }
    o_bs = (float)tbs/n;
    printf("\n\nOrtalama Bekleme Suresi: %.2f",o_bs);
    
    return 0;
}
