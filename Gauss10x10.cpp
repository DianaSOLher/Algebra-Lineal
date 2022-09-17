//Programadora: Solis Hernandez Viridiana
//Solucion de sistema de ecuaciones mediante Gauss-Jordan
#include <stdio.h>
#include <string>

int main()
{
	int ecuaciones,variables;
	int i=0,j=0,z=0;
	float matriz[10][10];
	printf("Ingresa numero de ecuaciones (max 10): ");
	scanf("%i",&ecuaciones);
	printf("\nIngresa numero de variables (max 10): ");
	scanf("%i",&variables);
	
	//Pedimos datos de matriz
	for(i=1; i<=ecuaciones; i++)
	{
		for(j=1; j<=variables; j++)
		{
			printf("A[%i][%i]: ",i,j);
			scanf("%f",&matriz[i][j]);
		}
	}
	//Para encontrar diagonal 
	
	for(j=1; j<=variables; j++) 
	{
      for(i=1; i<=ecuaciones; i++) 
	  {
	  	/* if(matriz[i][j] != 0)
	  	 {
	  		
		  }*/
		  //cuando i y j son iguales de la matriz(ij) y el numero es diferente
		  // de cero, dividimos toda la fila entre ese numero para conseguir 
		  // el 1 que nos permitira realizar pivoteo
		 if(i==j && matriz[i][j]!=0)
		 {
		 	//cuando el numero es negativo
		 	if(matriz[i][j]>0)
		 	{
		 		for(int z=1; z<=variables; z++)
				{
				matriz[i][z] = matriz[i][z] / matriz[i][j];	  	
				} 	
			 }
			else if(matriz[i][j]<0)
			{
				for(z=1; z<=variables; z++)
				{
				/*	aij
					aiz
					a11	a12 a13 a14
					a21 a22 a23 a24
					a31 a32 a33	a34
				*/
					matriz[i][z] = (matriz[i][z] / matriz[i][j])*(-1);	  	
				} 	
			}
		 }
		else if(i==j && matriz[i][j]==0)
		{
			for(z=1; z<=ecuaciones; z++)
		 	{
		 		if()
			 }
		}
		 //pivote
		 if(i==j)
		 {
		 	for(z=1; z<=ecuaciones; z++)
		 	{
		 		
			 }
		 }
         if(i!=j) 
		 {
		 	
            b=a[i][j]/a[j][j];
            for(k=1; k<=n+1; k++) 
			{ 
               a[i][k]=a[i][k]-b*a[j][k];
            }
         }
      }
   }
   /*
   cout<<"\nThe solution is:\n";
   for(i=1; i<=n; i++) {
      x[i]=a[i][n+1]/a[i][i];
      cout<<"x"<<i << "="<<x[i]<<" ";
   }
*/
}
