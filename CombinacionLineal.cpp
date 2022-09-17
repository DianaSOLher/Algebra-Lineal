#include <stdlib.h>
#include <stdio.h>

//Variables globales
char bandera='F';
//Funcion que calcula resultado mediante Gauss-Jordan
void GJ (float matrizAu[15][15],int dimension, int Vk){
	double mayor;//variable para almacenar el mayor de la columna k
    int indice;//indice del mayor-->indice de may
    double aux; 
    double pivote; 
	int k,j,i,l;
	for( k=0; k<dimension; k++)
	{
        mayor=abs(matrizAu[k][k]); 
        indice=k; 
        //recorrer filas de la columna k para buscar el indice del mayor
        for( l=k+1; l<dimension; l++){ 
            if(mayor<abs(matrizAu[l][k])){ 
                mayor=abs(matrizAu[l][k]); 
                indice=l; 
            } 
             
        } 
        //cambiar filas
        if(k!=indice){ 
            for(i=0; i<Vk+1; i++){ 
                aux=matrizAu[k][i]; 
                matrizAu[k][i]=matrizAu[indice][i]; 
                matrizAu[indice][i]=aux; 
            } 
             
        } 
        if(matrizAu[k][k]==0 && matrizAu[k][Vk]!=0)
		{ 
            printf("No hay solucion -> no es combinacion lineal"); 
            bandera='V';
            break; 
        } 
        else if(matrizAu[k][k]!=0 ){ 
             
            for(int i=0;i<dimension;i++){//recorrer fila
                if(i!=k){ 
                    pivote=-matrizAu[i][k]; 
                    for(int j=k;j<Vk+1;j++){//recorrer elementos de una fila

                        matrizAu[i][j]=matrizAu[i][j]+pivote*matrizAu[k][j]/matrizAu[k][k]; 
                    } 
                } 
                else{ 
                    pivote=matrizAu[k][k]; 
                    for(int j=k;j<Vk+1;j++){ 
                        matrizAu[i][j]=matrizAu[i][j]/pivote;
                    }
                } 
            } 
        } 
    }
}
int main(){
	int dimension=0;
	int vectorU[dimension];
	int vectores[10][10];
	int Vk;
	int i=0,j=0,z=0,k=0,w=0,x=0;
	float matrizAu[15][15];
	float aux[15][15];
	float aux2,aux3,pivote;
	int libres=0;
	int contador=0; 
	float resultado[15];
	
	printf("\nDimension del vector R^");
	scanf("%i",&dimension);
	printf("\nVector del que se buscara si es combinacion lineal:\n");
	for(i=0; i<dimension; i++)
	{
		printf("\tU[%i]:",i);
		scanf("%i",&vectorU[i]);
	}
	printf("\nNumero de vectores con los que se buscara la combinacion: ");
	scanf("%i",&Vk);
	for(i=0; i<Vk;i++ )
	{
		printf("\nVector %i:\n",i+1);
		for(j=0;j<dimension;j++)
		{
			printf("\tV%i[%i]:",i+1,j);
			scanf("%i",&vectores[i][j]);
		}
	}
	//Crea Matriz Aumentada:
//	printf("\nMatriz Aumentada:\n");
	for(i=0; i<dimension; i++)
	{
		for(j=0; j<Vk+1; j++)
		{
			if(j==Vk)
			{
				matrizAu[i][j]=vectorU[z];
				aux[i][j]=vectorU[z];
				z++;
			}
			else
			{
				matrizAu[i][j]=vectores[j][i];
				aux[i][j]=vectores[j][i];
			}
		}
	}
	//Muestra Matriz Aumentada:
/*	for(i=0; i<dimension; i++)
	{
		for(j=0; j<Vk+1; j++)
		{	
			printf(" %.2f ",matrizAu[i][j]);
		}
		printf("\n");
	}
	*/
	//Gauss Jordan para encontrar que tipo de solucion es:
	printf("\nGauss Jordan:\n");
	GJ(matrizAu,dimension,Vk);

	//Muestra Gauss-Jordan
	for(i=0; i<dimension; i++)
	{
		for(j=0; j<Vk+1; j++)
		{	
			printf(" %.2f ",matrizAu[i][j]);
		}
		printf("\n");
	}
	
	
	for(i=0; i<dimension; i++)
	{
		for(j=0; j<Vk+1; j++)
		{
			if(i==j && matrizAu[i][j]==1)
			{
				contador=contador+1;
				
			}		
			printf(" %.2f ",matrizAu[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n\tVector U[");
	for(i=0;i<dimension;i++)
	{
		printf(" %i ",vectorU[i]);
	}
	printf(" ] ");
	if(bandera=='V')
	{
		printf(" No es combinacion lineal de los vectores: \n");
		for(i=0; i<Vk; i++)
		{
			for(j=0; j<dimension; j++)
			{
				printf(" %i ",vectores[i][j]);
			}
			printf("\n");
		}
	}
	
		if(bandera=='F' && contador<Vk)
		{	
			libres=Vk-contador;
			printf("\nEs combinacion lineal de los vectores: \n");
			for(i=0; i<Vk; i++)
			{
				printf("\tV%i: ",i+1);
				for(j=0; j<dimension; j++)
				{
					printf(" %i ",vectores[i][j]);
				}
				printf("\n");
			}
			z=0;
			x=0;
			aux2=0.0;
			aux3=0.0;
			for(i=0; i<dimension; i++)
			{
				for(j=0; j<Vk+1; j++)
				{
					if(i==j)
					{
						z=z+1;	
						if(z==contador)
						{
							
							
							
							for(k=0; k<Vk-z;k++)
							{
								x=k;
							  for(w=k+1; w<Vk; w++)
								{
									x=x+1;								
								}
							}												
							
						}				
					}
				}
			}
			
			printf("\nSea Yn=1: ");
			for(k=0; k<dimension;k++)
			{
				aux2=0;
		   	  	for(w=contador; w<Vk; w++)
				{
					aux2=aux2+matrizAu[k][w];
				}
				resultado[k]=aux2;
			}	
			printf("\n Con:\n[ ");
			for(i=0; i<dimension; i++)
			{
				if(i>contador-1)
				{
					printf(" 1.00 ");	
				}
				else if(i<contador)
				{
					aux3=matrizAu[i][i]-resultado[i];	
					printf(" %.2f ",aux3);
				}
			}
			printf("]");
		}
		else if(bandera=='F' && contador==Vk)
		{
			z=0;
			printf("\nEs combinacion lineal de los vectores\n");
			for(i=0; i<Vk; i++)
			{
				printf("\tV%i[ ",i+1);
				for(j=0; j<dimension; j++)
				{
					printf(" %i ",vectores[i][j]);
				}
				printf("]\n");
			}
			printf("\n Con:  \n[");
			for(i=0; i<dimension; i++)
			{
				for(j=0; j<Vk+1; j++)
				{
					if(i==j)
					{
						printf(" %.2f ",matrizAu[i][Vk]);
						z++;
					}
				}
			}
			printf("]");
		}
		
	
	return 0;
}
