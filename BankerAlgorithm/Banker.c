#include<stdio.h>
int main()
{
    // Banker Algoritması için örnek uygulama

    //P0, P1, P2, P3, P4 islemleri tanımlansın
    // kaynaklar k1=12, k2=13, k3=14

    int n,m,i,j,k;
    n=5;
    m=3;
    int alloc[5][3] = {{ 2, 1, 1 }, // allocation matrix
						{ 2, 2, 3 }, 
						{ 3, 2, 3 }, 
						{ 0, 3, 1 }, 
						{ 4, 3, 2 }};
    int max[5][3] = { { 3, 5, 5 }, 
					{ 5, 3, 4 }, // P1 
					{ 4, 4, 4 }, // P2 
					{ 2, 6, 5 }, // P3 
					{ 4, 4, 4 } }; // P4 

	int avail[3] = { 1, 2, 4 }; // Bos Kaynak Vektörü

    int f[n],ans[n],ind=0;
    for(k=0;k<n;k++){
        f[k] = 0;
    }
    //ihtiyaç duyulan kaynak matrisi
    int need[n][m];

    printf("Ihtıyac duyulan kaynak matrisis : \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d     ",need[i][j]);
        }
        printf("\n");
    }

    int y = 0;

    for (i = 0; i < n; i++)
    {
        if(f[i] == 0){
            printf("P%d false! \n",i);
            int flag = 0;
            for(j=0;j<m;j++){
                if(need[i][j] > avail[j]){
                    //Her bir matris elemani icin karsilastirma yapilir.
                    printf("Ihtiyac %d > %d oldugu icin bu islemi atla\n",need[i][j],avail[j]);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                printf("P%d <= bos kaynak! \n",i);
                ans[ind++] = i;
                for(y=0;y<m;y++){
                    avail[y] += alloc[i][y];
                }
                f[i] = 1;
                printf("P%d true oldu!\n",i);
            }
        }
    }
    printf("Safe durumu olusmasi icin islem uygulama sirasi : \n");
    for(i=0;i<n;i++){
        printf("P%d   ",ans[i]);
    }
    
    
    return 0;
}
