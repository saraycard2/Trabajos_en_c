#include <stdio.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

int main (){
	int matriz [MAX_FILAS][MAX_COLUMNAS];
	for (int i = 0; i <MAX_FILAS; i++){
		for(int j =0; j<MAX_COLUMNAS;j++){
			matriz[i][j] = 0;
		}

	}

	for (int i = 0; i <MAX_FILAS; i++){
		for(int j =0; j<MAX_COLUMNAS;j++){
			printf(" %i",matriz[i][j]);
		}
		printf("\n");

	}

	return 0;
}