#include<stdlib.h>
#include<stdio.h>
int main(){
    int t;  
    printf("ENTER HOW MANY TEST CASES YOU WANT TO DO: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n; 
        printf("HOW MANY ELEMENTS FOR %d ARRAY...\n",i+1);
        scanf("%d",&n);
        int arr[n];     
        printf("ENTER POSITIVE ELEMENTS IN ARRAY...\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        int c=0;
        for(int j=0;j<n;j++){
            c=c^arr[j];
        }
        printf("%d\n",c);
    }
    return 0;
}
