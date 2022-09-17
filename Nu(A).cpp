//
#include <stdlib.h>
#include <stdio.h>

//Variables globales
char bandera='F';
char ind= 'F';
char matriz = 'F';
float matrizAu[25][25];
float B[25][25];
int vectores[10][10];
int n=0;
int m=0;
//Funcion Gauss Jordan
void GJ(float gauss[25][25],int di,int Vek)
{
	
	double mayor;//variable para almacenar el mayor de la columna k
    int indice;//indice del mayor-->indice de may
    double aux; 
    double pivote; 
	int k,j,i,l;
	ind='F';
	bandera='F';
	for( k=0; k<di; k++)
	{
        mayor=abs(gauss[k][k]); 
        indice=k; 
        //recorrer filas de la columna k para buscar el indice del mayor
        for( l=k+1; l<di; l++){ 
            if(mayor<abs(gauss[l][k])){ 
                mayor=abs(gauss[l][k]); 
                indice=l; 
            } 
             
        } 
        //cambiar filas
        if(k!=indice){ 
            for(i=0; i<Vek; i++){ 
                aux=gauss[k][i]; 
                gauss[k][i]=gauss[indice][i]; 
                gauss[indice][i]=aux; 
            } 
             
        } 
        if(gauss[k][k]==0 && gauss[k][Vek]!=0)
		{ 
            //printf("No hay Dependencia o Independencia lineal"); 
            bandera='V';
            ind='V';
            break; 
        } 
        else if(gauss[k][k]!=0 ){ 
             
            for(int i=0;i<di;i++){//recorrer fila
                if(i!=k){ 
                    pivote=-gauss[i][k]; 
                    for(int j=k;j<Vek;j++){//recorrer elementos de una fila

                        gauss[i][j]=gauss[i][j]+pivote*gauss[k][j]/gauss[k][k]; 
                    } 
                } 
                else{ 
                    pivote=gauss[k][k]; 
                    for(int j=k;j<Vek;j++){ 
                        gauss[i][j]=gauss[i][j]/pivote;
                    }
                } 
            } 
        } 
    }
    if(matriz =='A')
    {
    	for(i=0; i<di; i++)
		{
			for(j=0; j<Vek; j++)
			{	
				matrizAu[i][j]=gauss[i][j];
			}
		}
	}
	else if(matriz == 'B')
	{
		for(i=0; i<di; i++)
		{
			for(j=0; j<Vek; j++)
			{	
				B[i][j]=gauss[i][j];
			}
		}
	}
}

void Soluciones(float matrizAux[25][25], int dim, int Vk)
{
	int i=0,j=0,contador=0,libres=0;
	float aux2,aux3,pivote;	
	int z=0;
	int x=0,k=0,w=0;
	float resultado[25];
	for(i=0; i<dim; i++)
	{
		for(j=0; j<Vk; j++)
		{
			if(i==j && matrizAux[i][j]==1)
			{
				contador=contador+1;
				
			}		
			//printf(" %.2f ",matrizAu[i][j]);
		}
		//printf("\n");
	}
	if(ind=='V')
	{
		printf(" No hay solucion sistema incosistente: \n");
		/*for(i=0; i<Vk; i++)
		{
			for(j=0; j<dimension; j++)
			{
				printf(" %i ",vectores[i][j]);
			}
			printf("\n");
		}*/
	}
	
	if(ind=='F' && contador<Vk)
	{	
		libres=Vk-contador;
		
			//	printf("\nInfinidad de soluciones con variables libres=1 : \n");
		/*for(i=0; i<Vk; i++)
		{
			printf("\tV%i: ",i+1);
			for(j=0; j<dimension; j++)
			{
				printf(" %i ",vectores[i][j]);
			}
			printf("\n");
		}*/

		aux2=0.0;
		aux3=0.0;
		
		for(k=0; k<dim;k++)
		{
			aux2=0.00;
	   	  	for(w=contador; w<Vk; w++)
			{
				aux2=aux2+matrizAux[k][w];
			}
			resultado[k]=aux2;
		}	
	/*	printf("\n\tMatriz A:\n");
		for(i=0; i<Vk; i++)
		{
			z=z+1;
			if(z==n)
			{
				printf("\n");
				z=0;
			}
			if(i>contador-1)
			{
				printf(" 1.00 ");	
			}
			else if(i<contador)
			{
				aux3=(-1)*resultado[i];	
				printf(" %.2f ",aux3);
			}
		}*/
	/*	printf("[ ");
		for(i=0; i<dim; i++)
		{
			if(i>contador)
			{
				printf(" 1.00 ");	
			}
			else if(i<contador)
			{
				aux3=(-1)*resultado[i];	
				printf(" %.2f ",aux3);
			}
		}
		printf("]");
		*/
		if(matriz=='A')
		{
			printf("\nDependencia lineal en vectores");
			for(i=0; i<2; i++)
			{
				printf("\nV%i[",i+1);
				for(j=0; j<4; j++)
				{
					printf(" %i ",vectores[i][j]);
				}
				printf("]\n");
			}
			printf("[ ");
			for(i=0; i<dim; i++)
			{
				if(i>contador)
				{
					printf(" 1.00 ");	
				}
				else if(i<contador)
				{
					aux3=(-1)*resultado[i];	
					printf(" %.2f ",aux3);
				}
			}
		}
		else if(matriz=='B')
		{
		
			printf("\n\tMatriz A:\n ");
			z=0;
			
			
			for(i=0; i<m; i++)
			{
				for(j=0; j<n; j++)
				{						
					if(j>contador-1)
					{
						printf(" 1.00 ");	
					}
					else if(j<contador)
					{
						aux3=(-1)*resultado[i];	
						printf(" %.2f ",aux3);
					}
				}
				printf("\n");
			}
		}
		

	}
	else if(ind=='F' && contador==Vk)
	{
		z=0;
		printf("\nIndependencia Lineal\n");
		ind='T';
		/*for(i=0; i<Vk; i++)
		{
			printf("\tV%i[ ",i+1);
			for(j=0; j<dimension; j++)
			{
				printf(" %i ",vectores[i][j]);
			}
			printf("]\n");
		}*/
		printf("\n\tCon:  \n\t[");
		for(i=0; i<dim; i++)
		{
			for(j=0; j<Vk; j++)
			{
				if(i==j)
				{
					printf(" %.2f ",matrizAux[i][Vk]);
					z++;
				}
			}
		}
		printf("]");
	}
}
int main()
{
	int Vcero[10];

	int i=0,j=0,w=0,z=0,k=0,contador=0,libres=0,x=0;
	int dimension=1;
	int Vk;
	float aux2,aux3;
	float aux[15][15];
	float resultado[15];
	//Linealmente independiente o linealmente dependiente
	printf("\nDimension del vector R^");
	scanf("%i",&dimension);
	printf("\nNumero de vectores que forman el conjunto: ");
	scanf("%i",&Vk);	
	
	for(i=0; i<dimension; i++)
	{
		Vcero[i]=0;
	}
	
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
				matrizAu[i][j]=Vcero[z];
				aux[i][j]=Vcero[z];
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
	}*/
	//Gauss Jordan para encontrar que tipo de solucion es:

	printf("\nGauss Jordan Matriz Aumentada:\n");
	matriz='A';
	GJ(matrizAu,dimension,Vk);
	
	//Si hay independencia lineal o dependencia lineal 
	if(ind == 'F')
	{
		Soluciones(matrizAu,dimension,Vk);
		
		n=dimension;
		m=dimension-Vk;
		float A[m][n];
		int variables= m*n;
		int ecuaciones= m*Vk;
		if(m<=0)
		{
			printf("No existe la matriz A");
		}
		else if(m>0)
		{
			//8=m*n=variables
			//4=m*Vk=ecuaciones
			printf("\nMatriz A: \n");
			
			for(i=0; i<ecuaciones; i++)
			{
				for(j=0; j<variables; j++)
				{	
					B[i][j]=0;
				}
			}
			z=0;
			printf("\n");
			for(w=0; w<m; w++)
			{
				for(i=0; i<Vk; i++)
				{
					for(j=0; j<dimension; j++)
					{
						if(w==0)
						{
						B[i][j]=vectores[i][j];
						}
						else if(w!=0)
						{
						z=i+(Vk*w);
						B[z][j+(dimension*w)]=vectores[i][j];
						z++;
						}	
					}
				}
				z=z+dimension;
			}
			
			
			//Imprimir matriz B
			
			for(i=0; i<ecuaciones; i++)
			{
			
				for(j=0; j<variables; j++)
				{
					printf(" %.2f ",B[i][j]);
					
				}
				printf("\n");
			}
			
			//Calcular Gauss
			printf("\nGauss matriz B: ");
			matriz='B';
			GJ(B,ecuaciones,variables);
			
			printf("\n");
			
			for(i=0; i<ecuaciones; i++)
			{
			
				for(j=0; j<variables; j++)
				{
					printf(" %.2f ",B[i][j]);
					
				}
				printf("\n");
			}
			Soluciones(B,ecuaciones,variables);
			
		}
		
	}
	return 0;
}
