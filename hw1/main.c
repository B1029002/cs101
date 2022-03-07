#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n=6;
void arr_swap(int *arr){
    int tmp;
    for(int i=0;i<n;i++) {
       for(int j=0;j<i;j++) {
           if(arr[j]>arr[i]) {
               tmp=arr[j];
               arr[j]=arr[i];
               arr[i]=tmp;
           }
       }
    }
}    
void print_value(FILE*fp) {
    int i,j,a[6],b[6];
    for(i=1;i<=n;i++) {
        do {
            a[i-1]=(rand() % 69)+1;
            for(j=1;j<i;j++) {
                if(a[i-1]==a[j-1]) {
                    break;
                }
            }
        }while(j!=i);
        b[i-1] = a[i-1];
    }
    arr_swap(b);
    for(int k=0;k<n;k++) {
        fprintf(fp,"%0*d ",2,b[k]);
    }
    fprintf(fp,"%0*d",2,(rand()%10)+1);
    fprintf(fp,"\n");
}
void print_slash(int i, int l, FILE*fp) {
    for(int j=1;j<=i;j++) {
        fprintf(fp, "[%d]: ",l+j);
        for(int k=0;k<n;k++) {
            fprintf(fp, "-- ");
        }
        fprintf(fp, "--");
        fprintf(fp, "\n");
    }
}


int main() {
    int i;
    int t_line=5;
    int lotto[10];
    time_t curtime;
    time(&curtime);
    srand(time(NULL));
    printf("歡迎光臨長庚樂透蓋買機台\n");
    printf("請問您要買幾組樂透彩: ");
    scanf("%d",&i);
    if(1<=i&&i<=5) {
        printf("已為您購買的%d組樂透組合輸出至 lotto.txt",i);
    }else {
        printf("請重新輸入");
    }
    
    FILE*fp;
    fp=fopen("lotto.txt","w+");
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp,"%s",ctime(&curtime));
    for(int j=1;j<=i;j++) {
        fprintf(fp,"[%d]: ",j);
        print_value(fp);
    }
    if(t_line>1) print_slash(t_line-i,i,fp);
    fprintf(fp,"======== @csieCGU ========");
    fclose(fp);
}