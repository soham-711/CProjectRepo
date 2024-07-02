#include<stdio.h>
#include<stdlib.h>
float determinant(int a, int b, int c, int d){
    float result=(a*d)-(b*c);
    return result;
}
int main(){
    int a11,a12,a13,a21,a22,a23,a31,a32,a33,i,j,n,p,q,d1,d2,d3;
    float k,l,m,det_result;
    printf("\nEnter the vaue of your first linear equation:(aX+bY+cZ=d)=>=>=>=> a,b,c and d: ");
    scanf("%d%d%d%d",&a11,&a12,&a13,&d1);
    printf("\nEnter the vaue of your second linear equation:(aX+bY+cZ=d)=>=>=>=> a,b,c and d: ");
    scanf("%d%d%d%d",&a21,&a22,&a23,&d2);
    printf("\nEnter the vaue of your first linear equation:(aX+bY+cZ=d)=>=>=>=> a,b,c and d: ");
    scanf("%d%d%d%d",&a31,&a32,&a33,&d3);
    float A[3][3]={{a11,a12,a13},{a21,a22,a23},{a31,a32,a33}};
    float b[3][1]={{d1},{d2},{d3}};
    float B[3][3],C[3][3],D[3][1]={0},E[3][3];
    char X[3][1]={{'x'},{'y'},{'z'}};
    printf("\n\n--Now Matrix representation of linear eqation--\n\n");
    printf("Matrix [A] = \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%0.1f\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n\nMatix [b] = \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%0.1f\t\t",b[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatrix [X] = \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%c",X[i][j]);
        }
        printf("\n");
    }
    if(a11==a21 && a12==a22 && a13==a23){
        det_result=0;
    }
    else if(a11==0 && a12==0 && a13==0)
    {
        det_result=0;
    }
    else
    {
k=a11*determinant(a22,a23,a32,a33);
l=a12*determinant(a21,a23,a31,a33);
m=a13*determinant(a21,a22,a31,a32);
det_result=k-l+m;
    }
printf("\n\nDeterminent of matrix [A]:=>=> |A|= %0.2f",det_result);

printf("\n\n--:Now calculate Co-factors of matrix [A]:-- \n");
B[0][0] = determinant(a22, a23, a32, a33);
B[0][1] = -determinant(a21, a23, a31, a33);
B[0][2] = determinant(a21, a22, a31, a32);
B[1][0] = -determinant(a12, a13, a32, a33);
B[1][1] = determinant(a11, a13, a31, a33);
B[1][2] = -determinant(a11, a12, a31, a32);
B[2][0] = determinant(a12, a13, a22, a23);
B[2][1] = -determinant(a11, a13, a21, a23);
B[2][2] = determinant(a11, a12, a21, a22);
printf("Co-factors of [A]= \n");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%0.1f\t",B[i][j]);
    }
    printf("\n");
}
printf("\n\n--Now calculate Adjoint of matrix [A]--\n");
C[0][0]=B[0][0];
C[0][1]=B[1][0];
C[0][2]=B[2][0];
C[1][0]=B[0][1];
C[1][1]=B[1][1];
C[1][2]=B[2][1];
C[2][0]=B[0][2];
C[2][1]=B[1][2];
C[2][2]=B[2][2];
printf("Adj of [A]= \n");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%0.1f\t",C[i][j]);
    }
    printf("\n");
}
E[0][0]=B[0][0]/det_result;
E[0][1]=B[1][0]/det_result;
E[0][2]=B[2][0]/det_result;
E[1][0]=B[0][1]/det_result;
E[1][1]=B[1][1]/det_result;
E[1][2]=B[2][1]/det_result;
E[2][0]=B[0][2]/det_result;
E[2][1]=B[1][2]/det_result;
E[2][2]=B[2][2]/det_result;
printf("\n\nNow inverse of matrix [A]=>=>[A^-1]= \n");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%0.2f\t",E[i][j]);
    }
    printf("\n");
}
printf("\n\nNow calculate [A] inverse . [B]: \n");
for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            D[i][j] = 0;
        }
    }
for(i=0;i<3;i++)
{
    for(j=0;j<1;j++)
    {
       for(n=0;n<3;n++)
       {
        D[i][j] += C[i][n]*b[n][j];
       } 
    }
}
printf("[A^-1][B]= \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            D[i][j]=D[i][j]/det_result;
        }
    }
    for(i=0;i<3;i++)
{

    for(j=0;j<1;j++)
    {
        printf("%0.1f\t\t",D[i][j]);
    }
    printf("\n");
}
printf("\n\n--:Now compare [A^-1][B] with matrix [X]:--\n");
for(i=0;i<3;i++)
{
    for(j=0;j<1;j++)
    {
        printf("The value of %c is : %0.1f.\n",X[i][j],D[i][j]);
    }
}
return 0;
}