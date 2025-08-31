#include<stdio.h>
int main(){
    int n,m,i,j;
    int indx=-1;
    int maxcount=-1;
    printf("Enter row and column");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
       
    }
    for(i=0;i<m;i++){
        int countrow=0;
        for(j=0;j<n;j++){
            countrow=countrow+arr[i][j];
        }
        if(countrow>maxcount){
            maxcount=countrow;
            indx=i;
        }
    }
    printf("%d",indx);
}
