#include <stdio.h>
void rev(int arr[],int start,int end){
    int temp;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }
}
int main() {
    int n,r;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter element in array:\n");
    for(int i = 0;i < n; i++){
        printf("-> ");
        scanf("%d",&arr[i]);
    }
    
    printf("Enter rotate: ");
    scanf("%d",&r);
    r = r % n;
    
    printf("\nArray before rotation:\n");
    for(int i = 0;i < n; i++){
        printf("%d  ",arr[i]);
    }
    
    rev(arr,0,r - 1);
    rev(arr,r,n-1);
    rev(arr,0,n-1);
    
    printf("Array After rotation:\n");
    for(int i = 0;i < n; i++){
        printf("%d  ",arr[i]);
    }
    return 0;
} 
