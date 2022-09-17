#include <stdio.h>

int main(void)
{
	int filas =2;
	int columnas = 2;
	int contador;
	int Mtotal[50][2];
	int D[50][2];
	int i,j,w,k,z;
	int suma;
	
	printf("Cuantas matrices son :");
	scanf("%i",&contador);
	printf("valores:\n");
	for(i=0; i<contador*2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("\nMtotal[%i][%i]:",i,j);
			scanf("%i",&Mtotal[i][j]);
		}
	}
	D[0][0]=Mtotal[0][0];
	D[0][1]=Mtotal[0][1];
	D[1][0]=Mtotal[1][0];
	D[1][1]=Mtotal[1][1];
	z=0;
	for(w=0; w<contador-1;w++)
	{
		for(i=0; i<filas; i++)
		{
			for(j=0; j<columnas; j++)
			{
				suma=0;
				for(k=0; k<columnas; k++)
				{
					suma = suma + D[i][k]*Mtotal[z+2][j];
					printf("\nD[%i][%i]=%i * Mtotal[%i][%i]=%i ",i,k,D[i][k],z+2,j,Mtotal[z+2][j]);
					z=z+1;
				}
				D[i][j]=suma;
				printf("\nD[%i][%i] = %i",i,j,suma);
				z=z-2;
			}
		}
		z=z+2;
	}
	
	
	for(i=0; i<filas;i++)
	{
		for(j=0; j<columnas; j++)
		{
			printf(" %i ",D[i][j]);
		}
		printf("\n");
	}
	
}
