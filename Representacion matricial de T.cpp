#include <stdio.h>
#include <stdlib.h>
//Variables Globales
float Id[15][15];

//Funcion Gauss Jordan
void gauss_jordan(float M[15][15],int n)
{ 
    double may;//variable para almacenar el mayor de la columna k
    int ind;//indice del mayor-->indice de may
    double aux,aux2; 
    double pivote; 
     
    for(int k=0;k<n;k++)
	{//recorrer columnas de la matriz reducida
        may=abs(M[k][k]); 
        ind=k; 
        //recorrer filas de la columna k para buscar el indice del mayor
        for(int l=k+1;l<n;l++)
		{ 
            if(may<abs(M[l][k]))
			{ 
                may=abs(M[l][k]); 
                ind=l; 
            } 
        }
        //cambiar filas
        if(k!=ind)
		{ 
            for(int i=0;i<n+1;i++)
			{ 
                aux=M[k][i]; 
                M[k][i]=M[ind][i]; 
                M[ind][i]=aux; 
                
                aux2=Id[k][i]; 
                Id[k][i]=Id[ind][i]; 
                Id[ind][i]=aux2; 
        	}
        } 
        if(M[k][k]==0)
		{ 
            printf("no tiene solucion"); 
            break; 
        } 
        else
		{ 
             
            for(int i=0;i<n;i++)
			{//recorrer fila
                if(i!=k)
				{ 
                    pivote=-M[i][k]; 
                    for(int j=k;j<n+1;j++)
					{//recorrer elementos de una fila

                        M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k]; 
                        Id[i][j]=Id[i][j]+pivote*Id[k][j]/Id[k][k]; 
                    } 
                } 
                else
				{ 
                    pivote=M[k][k]; 
                    for(int j=k;j<n+1;j++)
					{ 
                        M[i][j]=M[i][j]/pivote;
                        Id[i][j]=Id[i][j]/pivote;
                    }
                } 
            } 
        } 
	}
	
} 
int main (void)
{
	int m,n2;
	int i,j;
	int Alfa[15][15];
	int Beta[15][15];
	int Ax[15][15];
	float AlfaCan[15][15];
	float BetaCan[15][15]; 

	
	printf("\nT:R^n -> R^m");
	printf("\nn: ");
	//Columnas de Ax
	scanf("%i",&n2);
	printf("m: ");
	//filas de Ax
	scanf("%i",&m);
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n2; j++)
		{
			printf("\nAx[%i][%i] = ",i,j);
			scanf("%i",&Ax[i][j]);
		}
		printf("\n");
	}
	
	printf("\nVectores base Alfa:\n");
	for(i=0; i<n2;i++ )
	{
		printf("\nVAlfa %i:\n",i+1);
		for(j=0;j<n2;j++)
		{
			printf("\tVA%i[%i]:",i+1,j);
			scanf("%i",&Alfa[i][j]);
		}
	}
	printf("\nVectores base Beta:\n");
	for(i=0; i<m;i++ )
	{
		printf("\nVBeta %i:\n",i+1);
		for(j=0;j<m;j++)
		{
			printf("\tVB%i[%i]:",i+1,j);
			scanf("%i",&Beta[i][j]);
		}
	}
	//Muestra Matriz Ax
	for(i=0; i<m; i++)
	{
		for(j=0; j<n2; j++)
		{
			printf(" %i ",Ax[i][j]);
		}
		printf("\n");
	}
	//Crear Matriz Alfa->Canonica y la muestra
	printf("\nMatriz Alfa->Canonica\n");
	for(i=0; i<n2;i++ )
	{
		for(j=0;j<n2;j++)
		{
			AlfaCan[i][j] = Alfa[j][i];
			printf(" %f ",AlfaCan[i][j]);
		}
		printf("\n");
	}
	
	//Crear Matriz Beta->Canonica y crea Matriz identidad 
	printf("\nMatriz Beta->Canonica\n");
	for(i=0; i<m;i++ )
	{
		for(j=0;j<m;j++)
		{
			BetaCan[i][j] = Beta[j][i];
			printf(" %f ",BetaCan[i][j]);
			if(i==j)
			{
				Id[i][j] = 1;
			}
			else
			{
				Id[i][j] = 0;
			}
		}
		printf("\n");
	}
	
	gauss_jordan(BetaCan,m);

	//Imprime inversa
	printf("\nInversa:\n");
	for(i=0; i<m;i++ )
	{
		for(j=0;j<m;j++)
		{
			printf(" %.2f ",Id[i][j]);
		}
		printf("\n");
	}
	
}
