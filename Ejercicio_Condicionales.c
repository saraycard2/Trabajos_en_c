#include <stdio.h>

const char MANU_NOMBRE = 'M';
const char MANU_APELLIDO = 'C';
const int DNI_MANU = 22222222;
const int PADRON_MANU = 111111;
const char MAT_PREFERIDA_MANU = 'A';
const int COD_SEGURIDAD_MANU = 123;
const char APELLIDO_AGUSBO = 'B';
const char APELLIDO_AMPI = 'Z';
const char APELLIDO_CANDE = 'S';
const char APELLIDO_CARO = 'M';
const char APELLIDO_CECI = 'A';
const char APELLIDO_CELESTE = 'D';
/*otra forma de declara ctes -> No genera conflictos con switch*/
#define APELLIDO_RENA 'V'
#define APELLIDO_MDELROSARIO 'P'

int main(){

	char nombre;
	char apellido;

	printf("Ingrese inicial de su nombre (en letra mayuscula)\n");
	scanf(" %c", &nombre);
	printf("Ingrese inicial de su apellido (en letra mayuscula)\n");
	scanf(" %c", &apellido);

	if(nombre == MANU_NOMBRE && apellido == MANU_APELLIDO){
		int dni;
		int padron;
		char materia;
		int cod_seguridad;

		printf("Ingrese numero de documento (sin puntos)\n");
		scanf("%i", &dni);
		printf("Ingrese su padron FIUBA\n");
		scanf("%i", &padron);
		printf("Ingrese inicial DE SU MATERIA FAVORITA DE SECUNDARIO (en letra mayuscula)\n");
		scanf(" %c", &materia);
		printf("Ingrese codigo de seguridad de tarjeta de credito\n");
		scanf("%i", &cod_seguridad);
	
		if((dni == DNI_MANU) && (padron == PADRON_MANU) && (materia == MAT_PREFERIDA_MANU) && (cod_seguridad == COD_SEGURIDAD_MANU)){
			printf("HOLA MANU CAMEJO BIENVENIDOOO\n");
		}
		else{
			printf("JUIRAAA VOS NO SOS MANU CAMEJO\n");
		}
	}

	else{
		switch(nombre){
			case 'A':
				if(apellido == APELLIDO_AGUSBO){
					printf("HOLA AGUSBO\n");
				}
				else if(apellido == APELLIDO_AMPI){
					printf("HOLA AMPI\n");	
				}
				else{
					printf("JUIIIIIRA VOS NO SOS colab\n");
				}
			break;

			case 'C':
				if(apellido == APELLIDO_CANDE){

					printf("HOLA Cande\n");
				}
				else if(apellido == APELLIDO_CARO){
					printf("HOLA Caro\n");	
				}
				else if(apellido == APELLIDO_CECI){
					printf("HOLA Ceci\n");	
				}
				else if(apellido == APELLIDO_CELESTE){
					printf("HOLA Celeste\n");	
				}
				else{
					printf("JUIIIIIRA VOS NO SOS colab\n");
				}
			break;	

			case 'R':

				switch(apellido){
					case APELLIDO_RENA:
						printf("HOLA RENATAA\n");
					break;

					case APELLIDO_MDELROSARIO:
						printf("HOLA MARIA DEL ROSARIO\n");	
					break;

					default: 
						printf("JUIIIIIRA VOS NO SOS colab\n");
				}
			break;	
			
			default: 
				printf("JUIIIIIRA VOS NO SOS colab\n O ingresaste minusculas\n");
		}
	}
	return 0;
}