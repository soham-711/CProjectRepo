#include<stdio.h>
#include<math.h>
int main()
{
    int a11,a12,a13,a21,a22,a23,a31,a32,a33,b1,b2,b3,i,j;
   float sub3,sub1,sub2,p,q,r,s,a,k;
    printf("\nenter the value of your first liniar equation:(aX + bY + cZ =b1) =>=>=>=>=> a,b,c and b1...");
    scanf("%d%d%d%d",&a11,&a12,&a13,&b1);
    printf("\nenter the value of your second liniar equation:(aX + bY + cZ =b2) =>=>=>=>=> a,b,c and b2...");
    scanf("%d%d%d%d",&a21,&a22,&a23,&b2);
    printf("\nenter the value of your third liniar equation:(aX + bY + cZ =b3) =>=>=>=>=> a,b,c and b3...");
    scanf("%d%d%d%d",&a31,&a32,&a33,&b3);
    float A[3][3]={{a11,a12,a13},{a21,a22,a23},{a31,a32,a33}},b[3][1]={{b1},{b2},{b3}};
    float Ab[3][4]={{a11,a12,a13,b1},{a21,a22,a23,b2},{a31,a32,a33,b3}};
    char X[3][1]={{'x'},{'y'},{'z'}};
    printf("\n\n--Now Matrix representation--\n");
    printf("A= \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%0.2f\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNext..b= \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%0.2f\t",b[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNext..X= \n");
     for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("%c\t",X[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNext...Ab= \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%0.2f\t",Ab[i][j]);
        }
        printf("\n");
    }
     printf("\n\nNext...row operation for second row: \n");
     printf("After row operation second row: \n");
     k=Ab[1][0]/Ab[0][0];
    for(j=0;j<4;j++)
    {
        sub1=k*Ab[0][j];
        Ab[1][j]=Ab[1][j]-sub1;
        printf("%0.2f\t",Ab[1][j]);
    }
    printf("\n");
    printf("\n\nAfter mordifing second row using row operation: \n");    
        
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%0.2f\t",Ab[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNext...row operation for third row: \n");
    printf("After row operation third row: \n");
    a=Ab[2][0]/Ab[0][0];
    for(j=0;j<4;j++)
        {
            sub2=a*Ab[0][j];
          Ab[2][j]=Ab[2][j]-sub2;
          printf("%0.2f\t",Ab[2][j]);
        }
        printf("\n");
        printf("\n\nAfter mordifing third row using row operation: \n");   
        for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%0.2f\t",Ab[i][j]);
        }
        printf("\n");
    }
    s=Ab[2][1]/Ab[1][1];
    if(Ab[2][1]==0)
    {
        printf("Matrix Ab is an Upper traingular Matrix..\n");
    }
    else
    {
        for(j=0;j<4;j++)
        {
            sub3= s*Ab[1][j];
            Ab[2][j]=Ab[2][j]-sub3;
        }
        
        printf("\n\nNow Ab is an Upper traingular matrix..\n");

        for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%0.2f\t",Ab[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNow calculating (A'X = b') we find the value of X , Y , Z : \n");
    r=(Ab[2][3]/Ab[2][2]);
    q=(Ab[1][3]-(Ab[1][2]*r))/Ab[1][1];
     p=(Ab[0][3]-((Ab[0][1]*q)+(Ab[0][2])*r))/Ab[0][0];
    printf("Value of X , Y , Z in this linear equation is: x = %0.2f & y = %0.2f & z = %0.2f",p,q,r);
    return 0;  
    }
    printf("Now calculating (A'X = b') we find the value of X , Y , Z : \n");
    r=(Ab[2][3]/Ab[2][2]);
    q=(Ab[1][3]-(Ab[1][2]*r))/Ab[1][1];
    p=(Ab[0][3]-((Ab[0][1]*q)+(Ab[0][2])*r))/Ab[0][0];
    printf("Value of X , Y , Z ('Using Gauss Elimination')in this linear equation is: x = %0.2f & y = %0.2f & z = %0.2f",p,q,r);
    return 0;
}