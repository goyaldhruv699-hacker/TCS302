#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n;
    printf("ENTER ROWS OR COLUMN FOR A SQUARE MATRIX...\n");
    scanf("%d", &n);
    int mat[n][n];
    printf("ENTER ELEMENTS IN MATRIX...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int row = 0, col = 0, lastrow = n, lastcol = n;
    while (row < lastrow && col < lastcol)
    {
        if (row + 1 == lastrow || col + 1 == lastcol)
        {
            break;
        }
        int prev = mat[row + 1][col];
        for (int i = col; i < lastcol; i++)
        {
            int cur = mat[row][i];
            mat[row][i] = prev;
            prev = cur;
        }
        row++;
        for (int i = row; i < lastrow; i++)
        {
            int cur = mat[i][lastcol - 1];
            mat[i][lastcol - 1] = prev;
            prev = cur; // 25
        }
        lastcol--;
        for (int i = lastcol - 1; i >= col; i--)
        {
            int cur = mat[lastrow - 1][i];
            mat[lastrow - 1][i] = prev;
            prev = cur;
        }
        lastrow--;
        for (int i = lastrow - 1; i >= row; i--)
        {
            int cur = mat[i][col];
            mat[i][col] = prev;
            prev = cur;
        }
        col++;
    }
    printf("ELEMENTS AFTER ROTATION ARE...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        } // 25
        printf("\n");
    }
    return 0;
}
