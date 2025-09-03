#include <stdio.h>
int main(){
    int n, m;
    printf("Enter rows and columns:\n");
    scanf("%d%d", &n, &m);    

    int mat[n][m];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int row = -1;
    int j = m - 1;      

    for(int i = 0; i < n; i++){
        while(j >= 0 && mat[i][j] == 1){
            j--;
            row = i;
        }
    }

    if(row == -1)       
        printf("NO '1' IN ANY ROW\n");
    else
        printf("HIGHEST NUMBER OF ONE IN ROW %d\n", row + 1);

    return 0;
}       


