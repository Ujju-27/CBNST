#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define size 20

int main()
{
	 double arr[size][size], x[size], ratio;
	 int i,j,k,n;
	
	 /* Reading number of unknowns */
	 printf("Enter number of unknown values: ");
	 scanf("%d", &n);
	 
	 /* Reading Augmented Matrix */
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   printf("Enter the coefficients of matrix: ");
			   printf("\narr[%d][%d] = ",i,j);
			   scanf("%lf", &arr[i][j]);
		  }
	 }
	/* Applying Gauss Elimination */
	 for(i=1;i<=n-1;i++)
	 {
		  if(arr[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = arr[j][i]/arr[i][i];
			   
			   for(k=1;k<=n+1;k++)
			   {
			  		arr[j][k] = arr[j][k] - ratio*arr[i][k];
			   }
		  }
	 }
	 /* Obtaining Solution by Back Subsitution */
	 x[n] = arr[n][n+1]/arr[n][n];
	
	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = arr[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  	x[i] = x[i] - arr[i][j]*x[j];
		  }
		  x[i] = x[i]/arr[i][i];
	 }
	 
	 printf("\nSolution of the given Equations :\n");
	 for(i=1;i<=n;i++)
	 {
	  	printf("x[%d] = %0.6lf\n",i, x[i]);
	 }
	 return(0);
}
