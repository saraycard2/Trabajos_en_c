#include <stdio.h>

int main(){

	int numero_ingresado = 0;
	int numero_manu = numero_ingresado + 3 % 10; 

	while(numero_ingresado != numero_manu){
		numero_manu = numero_ingresado + 3 % 10; 
		printf("Ingrese un numero del 0 al 9\n");
		scanf("%i",&numero_ingresado);

		while(numero_ingresado < 0 || numero_ingresado > 9){
			printf("Che, el numero no esta en el rango. Decime otro\n");
			scanf("%i", &numero_ingresado);
		}
		if(numero_ingresado != numero_manu){
			printf("Uff le erraste\n");
		}

	}
	
	printf("Ganaste!\n");

	return 0;
}