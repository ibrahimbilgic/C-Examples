#include<stdio.h>
int main()
{
    int is[15],p[15],bs[15],i,j,n,toplambs=0,pos,temp;
    float avg_bs;

    printf("Toplam kac islem islenecek?");
    scanf("%d",&n);

    printf("\nIsleme sureclerini giriniz:\n");
    for(i=0;i<n;i++){
        printf("P[%d]:",i+1);
        scanf("%d",&is[i]);
        p[i] = i+1; //pozisyon değerleri korumak icin
    }

    //selection sort ile isleme süresünü kücükten büyüge siraliyoruz
    for ( i = 0; i < n; i++)
    {
        pos = i;
        for (j = i+1; j < n; j++)
        {
            if(is[j]<is[pos]){
                pos = j;
            }
        }
        temp = is[i];
        is[i] = is[pos];
        is[pos]=temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;

        
    }
    bs[0] = 0; // ilk islem icin bekleme süresi -> 0

    // diger süreclerin bekleme süreleri
    for(i=1;i<n;i++){
        bs[i] = 0;
        for(j=0;j<i;j++){
            bs[i] += is[j];
        }
        toplambs += bs[i];
    }
    avg_bs = (float)toplambs/n; //ortalama bekleme suresi hesapla

    printf("\n Islem\t Isleme suresi\tBekleme suresi");
    for(i=0;i<n;i++){
        printf("\nP[%d]\t\t%d\t\t%d",p[i],is[i],bs[i]);
    }    
    printf("\n\nOrtalama Bekleme suresi=%.2f",avg_bs);
    return 0;
}
