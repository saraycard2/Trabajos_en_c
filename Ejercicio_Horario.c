#include <stdio.h>
const char LUNES = 'L';
const char MARTES = 'M';
const char MIERCOLES = 'MIER';
const char JUEVES = 'J'; 
const int RANGO_HORARIO_MAX = '11';
const int RANGO_HORARIO_MIN = '8';


int main(){
    char dia_ingresado;
    printf("ingrese un dia: ");
    scanf("%c", &dia_ingresado);

    int hora_ingresada;
    printf("Ingrese hora");
    scanf("%i",&hora_ingresada);

    if (((dia_ingresado == MARTES)|| (dia_ingresado == JUEVES)) && (hora_ingresada >= RANGO_HORARIO_MIN && hora_ingresada <= RANGO_HORARIO_MAX))
    {
        printf("Cursas Algo1\n");
    }
    else 
    {
        printf("No cursas nada coño");
    }
    return 0;

}