/* 
  1 de Febrero de 2025
  Tomas Silva
  Estructura de datos
  Programación modular en C++, Complejidad algorítmica
  PONTIFICIA UNIVERSIDAD JAVERIANA
*/

#include <iostream>
#include <ctime>
#include <time.h> 

using namespace std;

//Creacion de la funcion, esta se explicara mas adelante
void Rellenar_Mat(int **a, int **b, int **c, int n, int v); 


int main(){
    //--------------------------------------------------------------------------
    //VALORES INICIALES
    //--------------------------------------------------------------------------
	int N=0;
	int i, j, k, *pA, *pB, ValRand;
	int **M= new int *[N];
	int **B= new int *[N];
	int **MUL= new int *[N];
	//--------------------------------------------------------------------------
	/*
	Solicita al usuario valores para el tamaño de las matrices y el maximo
	a usar en cada seccion de las mismas                                  
	*/
	//--------------------------------------------------------------------------
	 
	cout<<"Digite el tamaño de las matrices: ";
	cin>>N;
	cout<<endl<<"Digite ahora el valor maximo a usar en los campos de ambas matrices: ";
	cin>>ValRand;
	ValRand +=1;
	
	//--------------------------------------------------------------------------
	/*
	La razon par la cual a la variable ValRand se le suma 1 es para poder 
	agregar el valor de forma que el usuario no se confunda, dado que el conteo 
	inicia con 0 y terminaria usualmente en ValRand - 1
	*/
	//--------------------------------------------------------------------------
	
	//INICIALIZACIÓN DE MATRICES (Por medio de la funcion Rellenar_Mat)
	
	Rellenar_Mat(M, B, MUL, N, ValRand);
	
    //IMPRESIÓN DE MATRICES
    //--------------------------------------------------------------------------
	//Matriz M
	//--------------------------------------------------------------------------
	cout<<endl<<"Matriz M"<<endl;
	for(i=0; i<N; i++){
                for(j=0;j<N;j++){
                        cout<<"["<<M[i][j]<<"]";
                }
		cout<<endl;
    }
    //--------------------------------------------------------------------------
	//Matriz B
	//--------------------------------------------------------------------------
	cout<<endl<<"Matriz B"<<endl;
	for(i=0; i<N; i++){
        for(j=0;j<N;j++){
                cout<<"["<<B[i][j]<<"]";
        }
        cout<<endl;
    }

	//MATRIZ DE MULTIPLICACIÓN (Algoritmo clasico de filas por columnas)
    cout<<endl<<"Matriz resultado:"<<endl;
    for(i=0; i<N; i++){
        for(j=0;j<N;j++){
    		int sum=0;
			for(int k=0; k<N; k++){
                sum += M[i][k]*B[k][j];
    		}
            MUL[i][j]=sum;
			cout<<"["<<MUL[i][j]<<"]";
        }
		cout<<endl;
    }
	return 0;
}

//Funcion para inicializar matrices con valores aleatorios (por medio de la funcion rand)
void Rellenar_Mat(int **a, int **b, int **c, int n, int v){
    srand(time(0));
    
    //creando matrices de tamaño n:
	for(int i=0; i<n; i++){
		a[i] = new int [n];
		b[i] = new int [n];
       	c[i] = new int [n];
    }
    //Llenando ambas matrices:
    
	for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            a[i][j]=(rand() % v);
			b[i][j]=(rand() % v);
			c[i][j]=0;
        }
    }
    /* DESCRIPCIÓN DEL PROCEDIMIENTO:
    ----------------------------------------------------------------------------
    Se utiliza la funcion rand con valor de 10 para llenar cada uno de los 
    valores de las matrices a y b con un numero entero al azar en un rango de 0 
    a v-1, que como se explico anteriormente, se le agrego 1 para mantener el 
    valor maximo solicitado por el usuario.
    
    sin embargo, la matriz c, al ser la matriz de multiplicacion, no necesita el
    llenarse con valores al azar, por lo tanto, esta se llena con 0. Esta
    llenara las matrices en el main por medio de apuntadores.
    */
}
