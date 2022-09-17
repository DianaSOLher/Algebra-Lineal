// ********Cambio de Base *******
//(Canonica->Beta)*VectorCanonico = baseCanonica 
//(Beta->Alfa)*baseCanonica = baseAlfa 
//(Alfa->Beta)*baseCanonica = baseBeta

//Librerias
#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#include<math.h>

//Variables globales
char bandera='F';
char ind= 'F';
char matriz = 'F';
float resultados[25][25];
int z=0,p=0,x=0;
float vector[25][1];
char cambio='F';
float resultadosC[25][25];
float resultadosA[25][25];
float C[25][1];
//Funciones

//Funcion que calcula resultado mediante Gauss-Jordan
void GJ(float gauss[25][25],int di,int Vek)
{
	
	double mayor;//variable para almacenar el mayor de la columna k
    int indice;//indice del mayor-->indice de may
    double aux; 
    double pivote; 
	int contador=0;
	
    
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
	
    
    //Si es matriz Aumentada de Beta o Alfa
    if(matriz =='B' || matriz == 'A')
    {

    	for(i=0; i<di; i++)
		{
			for(j=0; j<Vek; j++)
			{
				if(i==j && gauss[i][j]==1)
				{
					contador=contador+1;
				}		
			}
		}
    	//Mostrar si es solucion li o ld
    	printf("\n");
    	if(ind=='V')
		{
    		if(matriz=='B')
    		{
    			printf(" Beta no es l.i ni l.d \n");
			}
			if(matriz=='A')
			{
				printf(" Alfa no es l.i ni l.d \n");
			}
		}
		else if(ind=='F' && contador<Vek)
		{	
			if(matriz=='B')
    		{
    			printf(" Beta es l.d \n");
			}
			if(matriz=='A')
			{
				printf(" Alfa es l.d \n");
			}
		}
		else if(ind=='F' && contador==Vek)
		{
			if(matriz=='B')
    		{
    			printf(" Beta es l.i \n");
			}
			if(matriz=='A')
			{
				printf(" Alfa es l.i \n");
			}
		}
		
	}
	//Si no es matriz Aumentada
	else if(matriz =='C')
	{	
		
		//Imprimir gauss
	/*	for(i=0; i < di; i++)
		{
			for(j=0; j<Vek; j++)
			{
				printf(" %.2f ",gauss[i][j]);
			}
			printf("\n");
		}
	*/
		if(cambio=='C')
		{
			for(i=0; i < di; i++ )
			{
				resultadosC[i][x] = gauss[i][Vek-1];
			}
			x=x+1;
		}
		else if(cambio=='B')
		{
			for(i=0; i < di; i++ )
			{
				resultados[i][z] = gauss[i][Vek-1];
			}
			z=z+1;
		}
		else if(cambio=='A')
		{
			for(i=0; i < di; i++ )
			{
				resultadosA[i][p] = gauss[i][Vek-1];
			}
			p=p+1;
		}
		
	}
}

//Crea Matriz Aumentada:
void MatrizAumentada(int vs[25][25], int dm, int Vk )
{
	int i,j;
	float matrizAu[25][25];
	for(i=0; i<dm; i++)
	{
		for(j=0; j<Vk+1; j++)
		{
			if(j==Vk)
			{
				matrizAu[i][j]=0;
			}
			else
			{
				matrizAu[i][j]=vs[j][i];
			}
		}
	}
	
	//Llama funcion gauss
	GJ(matrizAu,dm,Vk);
}
//Multiplica 2 Matrices
void MultiplicaMatrices(float A[25][25], int filasA, int columnasA, float B[25][1], int filasB )
{ 
	int a,b;
	int c,d;
	
	float D[25][1];
	float E[25][1];
	int e,f;
	int i;
	int j;
	int k;
	float mult=0.0;
	float sum=0.0;
	
	a = filasA;
	b = columnasA;
	c = filasB;
	d = 1;
	printf("\n");
	/*	for(i=0; i<filasA; i++)
	{
		for(j=0; j< columnasA; j++)
		{
			printf("A[%i][%i]=%.2f",i,j,A[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<filasB; i++)
	{
			printf("B[%i][0]= %i ",i,vector[i][0]);
	}
	*/
	if(b!=c)
	{
		printf("El numero de columnas en matriz A debe ser igual al de filas del vector");
	}
	else
	{
		//printf("\nMultiplicacion de matrices A*vector:\n");
		e=a;
		f=d;
		
		for(i=0; i<e; i++)
		{
			for(j=0; j<f; j++)
			{
				sum=0.0;
				for(k=0; k<c; k++)
				{
					mult=A[i][k]*B[k][j];
					sum=sum+mult;
					if(cambio=='C')
					{	
						C[i][j]=sum;	
					}
					else if(cambio=='B')
					{	
						D[i][j]=sum;	
					}
					else if(cambio=='A')
					{	
						E[i][j]=sum;	
					}
				}	
			}
			
		}
		printf("[ ");
		if(cambio=='C')
		{
			
			for(i=0; i<e; i++)
			{
				for(j=0; j<f; j++)
				{
					printf(" %.2f ",C[i][j]);
				}
			}
			printf(" ]");
		}
		else if(cambio=='B')
		{
			
			for(i=0; i<e; i++)
			{
				for(j=0; j<f; j++)
				{
					printf(" %.2f ",D[i][j]);
				}
			}
			printf(" ]");
		}
		else if(cambio=='A')
		{
			
			for(i=0; i<e; i++)
			{
				for(j=0; j<f; j++)
				{
					printf(" %.2f ",E[i][j]);
				}
			}
			printf(" ]");
		}
	}
}

int main (void)
{
	int dimension,vBeta,vAlfa;
	int Beta[25][25], Alfa[25][25];
	int i,j,w;
	int canonica[25][25];
	
	printf("\nDimension de los vectores R^");
	scanf("%i",&dimension);
	printf("\nNumero de vectores con los que cuenta beta y alfa: ");
	scanf("%i",&vBeta);
	for(i=0; i<vBeta;i++ )
	{
		printf("\nVBeta %i:\n",i+1);
		for(j=0;j<dimension;j++)
		{
			printf("\tVB%i[%i]:",i+1,j);
			scanf("%i",&Beta[i][j]);
		}
	}
	printf("\nVectores con los que cuenta alfa: ");
	vAlfa=vBeta;
	for(i=0; i<vAlfa;i++ )
	{
		printf("\nVAlfa %i:\n",i+1);
		for(j=0;j<dimension;j++)
		{
			printf("\tVA%i[%i]:",i+1,j);
			scanf("%i",&Alfa[i][j]);
		}
	}
	
	printf("\nVector en forma canonica que se transformara la base:\n");
	for(i=0; i<dimension; i++)
	{
		printf("\t(B,A)[%i]:",i);
		scanf("%f",&vector[i][0]);
	}
	
	//Comprobar que Beta es Li
	matriz = 'B';
	MatrizAumentada(Beta, dimension,vBeta);
	
	//Comprobar que Alfa es Li
	matriz = 'A';
	MatrizAumentada(Alfa, dimension,vAlfa);
	
	//Crea base canonica de R^dimension
	for(i=0; i<dimension; i++)
	{
		for(j=0; j<dimension; j++)
		{
			if(i==j)
			{
				canonica[i][j]=vector[i][0];
			}
			else
			{
				canonica[i][j]=0;
			}
		}
	}
	
	//Crear sistemas  para crear Matriz de transicion Canonica -> Beta
	int sistemasCB = dimension;
	cambio='C';
	float baseC[25][25];
	for(w=0; w<sistemasCB; w++)
	{
	//	printf("\nSistema %i:\n",w+1);
		for(i=0; i<dimension; i++)
		{
			for(j=0; j<vBeta+1; j++)
			{
				if(j==vBeta)
				{
					baseC[i][j] = canonica[w][i];
	//				printf(" %.2f ",baseC[i][j]); 
				}
				else
				{
					baseC[i][j] = Beta[j][i];	
	//				printf(" %.2f ",baseC[i][j]); 
				}
					
			}
	//		printf("\n");	
		}
	//	printf("\nGauss %i:\n",w+1);
		matriz = 'C';
		GJ(baseC,dimension,vBeta+1);
	}
	printf("\nMatriz de transicion Canonica -> Beta:\n");
	for(i=0; i<vBeta; i++)
	{
		for(j=0; j<dimension; j++)
		{
			printf(" %.2f ",resultadosC[i][j]);
		}
		printf("\n");
	}
	//Multiplicar Matriz de Transicion por Vector
	printf("\nVector en base Beta:");
	MultiplicaMatrices(resultadosC,dimension,vBeta,vector,dimension);
	
		
	//Crear sistemas  para crear Matriz de transicion Beta -> Alfa
	int sistemasBA = vBeta;
	cambio='B';
	float baseB[25][25];
	for(w=0; w<sistemasBA; w++)
	{
	//	printf("\nSistema %i:\n",w+1);
		for(i=0; i<dimension; i++)
		{
			for(j=0; j<vAlfa+1; j++)
			{
				if(j==vAlfa)
				{
					baseB[i][j] = Beta[w][i];
	//				printf(" %.2f ",baseB[i][j]); 
				}
				else
				{
					baseB[i][j] = Alfa[j][i];	
	//				printf(" %.2f ",baseB[i][j]); 
				}
					
			}
	//		printf("\n");	
		}
	//	printf("\nGauss %i:\n",w+1);
		matriz = 'C';
		GJ(baseB,dimension,vAlfa+1);
	}
	printf("\nMatriz de transicion Beta -> Alfa:\n");
	for(i=0; i<vAlfa; i++)
	{
		for(j=0; j<vBeta; j++)
		{
			printf(" %.2f ",resultados[i][j]);
		}
		printf("\n");
	}
	//Multiplicar Matriz de Transicion por Vector
	printf("\nVector en base Alfa:");
	
	MultiplicaMatrices(resultados,vAlfa,vBeta,vector,dimension);
	
			
	//Crear sistemas  para crear Matriz de transicion Alfa -> Beta
	int sistemasAB = vAlfa;
	cambio='A';
	float baseA[25][25];
	for(w=0; w<sistemasAB; w++)
	{
	//	printf("\nSistema %i:\n",w+1);
		for(i=0; i<dimension; i++)
		{
			for(j=0; j<vBeta+1; j++)
			{
				if(j==vBeta)
				{
					baseA[i][j] = Alfa[w][i];
	//				printf(" %.2f ",baseA[i][j]); 
				}
				else
				{
					baseA[i][j] = Beta[j][i];	
	//				printf(" %.2f ",baseA[i][j]); 
				}
					
			}
	//		printf("\n");	
		}
	//	printf("\nGauss %i:\n",w+1);
		matriz = 'C';
		GJ(baseA,dimension,vBeta+1);
	}
	printf("\nMatriz de transicion Alfa -> Beta:\n");
	for(i=0; i<vBeta; i++)
	{
		for(j=0; j<vAlfa; j++)
		{
			printf(" %.2f ",resultadosA[i][j]);
		}
		printf("\n");
	}
	//Multiplicar Matriz de Transicion por Vector
	printf("\nVector en base Beta:");
	MultiplicaMatrices(resultadosA,vBeta,vAlfa,vector,dimension);
}
