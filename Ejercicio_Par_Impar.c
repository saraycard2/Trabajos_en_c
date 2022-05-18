#include <stdio.h>



int main(){

	int numero;
	printf("Ingresa un numero\n");
	scanf("%i",&numero);

	for(int i = 10; i>numero; i--){
		if(i%2==0){
			printf("El numero %i es par\n", i);
		}else{
			printf("El numero %i es impar\n", i);
		}
	}


	return 0;
}