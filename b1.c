#include<stdio.h>
#include<stdlib.h>
void main()
{
     int n;
     printf("enter the size of rows\n");
     scanf("%d",&n);
     int arr[n][n],i,j,k,f=0;
     printf("enter the elements.\t");
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            scanf("%d",&arr[i][j]);
         }
     }
    printf("enter the element to search ");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        int a=0,b=n-1;
        while(a<=b)
        {
            int mid=(a+b)/2;
            if(arr[i][mid]==k)
            {
                f=1;
                break;
            }
            else if(arr[i][mid]<k)
            {
                a=mid+1;
            }
            else
            {
                b=mid-1;
            }
        }
        if(f)
        break;
    }
    if(f)
    printf("present");
    else
    printf("not present");
}  
