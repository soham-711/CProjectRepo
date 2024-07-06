#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,row,column,count = 0,non_zero_row_count = 0;
    float A[50][50];
    printf("\nEnter the number of row of your matrix: ");
    scanf("%d",&row);
    printf("\nEnter the number of column of your matrix: ");
    scanf("%d",&column);
    printf("\nEnter matrix element row wish one by one: ");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nMatrix [A]:- \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%0.2f\t",A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < row; i++) {
       
        float terget = A[i][i];
        if (terget != 0) {
            for (j = 0; j < column; j++) {
                A[i][j] /= terget;
            }
        }

        
        for (k = i + 1; k < row; k++) {
            float f = A[k][i];
            for (j = 0; j < column; j++) {
                A[k][j] -= f * A[i][j];
            }
        }
    }
    printf("\nAfter row operation:- \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%0.2f\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\nSearch non-zero rows after row operation:-- \n");
    // Count the number of non-zero rows
    for (i = 0; i < row; i++) {
        int is_non_zero_row = 0;
        for (j = 0; j < column; j++) {
            if (A[i][j] != 0) {
                is_non_zero_row = 1;
                break;
            }
        }
        if (is_non_zero_row) {
            non_zero_row_count++;
        }
    }
    printf("Rank of matrix [A] :- %d\n\n", non_zero_row_count);

return 0; 
}