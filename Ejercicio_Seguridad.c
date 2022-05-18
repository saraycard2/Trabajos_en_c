// El chanutron necesita un nuevo sistema de seguridad para docentes y colabs. El mismo se
// organizará por niveles:
// ●
// ●
// Nivel 1000: Quienes pueden corregir parciales, finales y poner calificación → ManuC.
// Nivel 1: Quienes pueden corregir trabajos prácticos → Todos los que rayan.
// Crear un programa que solicite nombre y apellido del usuario (sus iniciales), verifique si es un
// docente/colab y lo salude con su nombre para:
// 1. Los usuarios con nivel mayor a 1.
// 2. El resto de los usuarios.
// 3. Para mayor seguridad, se necesita que el programa realice preguntas extras para
// aquellos usuarios nivel 1000. Las cuales son:
// a. Número de documento.
// b. Padrón FIUBA.
// c. Inicial de su materia favorita del secundario.
// d. Código de seguridad de su tarjeta de crédito.
#include <stdio.h>


const char INICIAL_NOMBRE_MANU = 'M';
const char INICIAL_APELLIDO_MANU = 'C';
const int DNI_MANU = 1;
const int PADRON_MANU = 2;
const char MAT_PREFERIDA_MANU = 'A';
const int COD_SEGURIDAD_MANU = 123;



int main (){
	char nombre;
	char apellido;

	printf("Ingrese inicial de su nombre (en letra mayuscula)\n");
	scanf(" %c", &nombre);
	printf("Ingrese inicial de su apellido (en letra mayuscula)\n");
	scanf(" %c", &apellido);

    if (nombre == INICIAL_NOMBRE_MANU && apellido == INICIAL_APELLIDO_MANU){
        int dni_manu;
        int padron_manu;
        char materia_preferida;
        int codigo;

        printf("Ingrese DNI \n");
        scanf("%i", &dni_manu);

        printf("Ingrese padron \n");
        scanf("%i",&padron_manu);

        printf("Ingrese Materia \n");
        scanf(" %c", &materia_preferida);

        printf("Ingrese codigo \n");
        scanf("%i", &codigo);

        if ((dni_manu == DNI_MANU) && (padron_manu == PADRON_MANU) && (materia_preferida == MAT_PREFERIDA_MANU) && (codigo == COD_SEGURIDAD_MANU)){
            printf("Bienvenido Manu\n");
    
        }        

        else{
            printf("No sos manu, chau \n");
        }


    return 0;
}