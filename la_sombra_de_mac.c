#include "la_sombra_de_mac_primero.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define POSICION_MIN 0
#define SIN_ELEMENTO -1
#define MOVERSE_ARRIBA 'W'
#define MOVERSE_ABAJO 'S'
#define MOVERSE_IZQUIERDA 'A'
#define MOVERSE_DERECHA 'D'
#define PERSONAJE_MAC 'M'
#define SOMBRA_BLOO 'S'
#define VIDAS_PERSONAJE 3
#define PUNTOS_PERSONAJE 0

bool coordenadas_iguales(coordenada_t a, coordenada_t b){

    return ((a.fila == b.fila) && (a.col == b.col));
}

bool es_movimiento_valido(char movimiento){

    return (movimiento == MOVERSE_ARRIBA || movimiento == MOVERSE_ABAJO || movimiento == MOVERSE_IZQUIERDA || movimiento == MOVERSE_DERECHA);
}

bool esta_dentro_rango(coordenada_t posicion, int max_alto, int max_ancho){

    return (((posicion.fila >= POSICION_MIN) && (posicion.col < max_ancho))&&((posicion.col >= POSICION_MIN) && (posicion.fila < max_alto)));
}

void inicializar_personaje(personaje_t* ref_personaje, coordenada_t arranque_personaje){

    (*ref_personaje).vida = VIDAS_PERSONAJE;
    (*ref_personaje).puntos = PUNTOS_PERSONAJE;
    (*ref_personaje).tiene_llave = false;
    (*ref_personaje).interruptor_apretado = false;
    (*ref_personaje).posicion.fila = arranque_personaje.fila;
    (*ref_personaje).posicion.col = arranque_personaje.col;
}

void inicializar_sombra(sombra_t* ref_sombra, coordenada_t arranque_sombra){

    (*ref_sombra).esta_viva = true;
    (*ref_sombra).posicion.fila = arranque_sombra.fila;
    (*ref_sombra).posicion.col = arranque_sombra.col;
}

void pedir_movimiento(char* ref_movimiento){

    while (!es_movimiento_valido(*ref_movimiento)){
        printf("Ingrese movimiento valido solo puede ser W,S,D,A \n ");
        scanf(" %c",ref_movimiento);
    }    
}

/*
 *pre: Recibe un movimiento para verificar si cumple con las regals, para la sombra se invierte el movimiento en las filas.
 *post: se encarga de verificar si el movimiento pasado esta dentro del rango de la matriz para poder realizarlo. 
*/
bool movimiento_posible(char movimiento, coordenada_t posicion, bool es_sombra){

    if (movimiento == MOVERSE_IZQUIERDA && es_sombra == false){
        (posicion).col = (posicion).col - 1;
    }
    else if (movimiento == MOVERSE_DERECHA && es_sombra == false){
        (posicion).col = (posicion).col + 1;
    }
    else if (movimiento == MOVERSE_IZQUIERDA && es_sombra == true){
        (posicion).col = (posicion).col + 1;
    }
    else if (movimiento == MOVERSE_DERECHA && es_sombra == true){
        (posicion).col = (posicion).col - 1;
    }
    else if (movimiento == MOVERSE_ARRIBA){
        (posicion).fila = (posicion).fila - 1;
    }
    else{
        (posicion).fila = (posicion).fila + 1;
    }
    
    return esta_dentro_rango(posicion, MAX_FILAS, MAX_COLUMNAS);
}

/*
 *pre: recibe un movimiento posible de la sombra y el personaje 
 *post: se encarga de hacer el movimiento de ambos independientemente
*/
void realizar_movimiento(char movimiento, coordenada_t* posicion, bool es_sombra)
{
    if (movimiento == MOVERSE_IZQUIERDA){  
            if (!es_sombra){
                posicion->col = posicion->col - 1;
            }
            else{
                posicion->col = posicion->col + 1;
            }            
        }
        else if (movimiento == MOVERSE_DERECHA){
            if (!es_sombra){
                posicion->col = posicion->col + 1;
            }
            else{
                posicion->col = posicion->col - 1;
            }
        }
        else if (movimiento == MOVERSE_ARRIBA){
            posicion->fila = posicion->fila - 1;
        }
        else{
            posicion->fila = posicion->fila + 1;
        }
}

void mover_personaje(personaje_t* ref_personaje, sombra_t* ref_sombra, char movimiento){

    if (movimiento_posible(movimiento, ((*ref_personaje).posicion), false)){
        realizar_movimiento(movimiento, (&((*ref_personaje).posicion)), false);
    }

    if (movimiento_posible(movimiento, ((*ref_sombra).posicion), true)){
        realizar_movimiento(movimiento, (&((*ref_sombra).posicion)), true);
    }
    
}

coordenada_t coordenada_aleatoria(int max_alto, int max_ancho){

    coordenada_t coord_aleatoria;

    coord_aleatoria.fila = rand() %max_alto + 0;
    coord_aleatoria.col = rand() %max_ancho + 0;

    return coord_aleatoria;
}

int buscar_elemento(elemento_t elementos[MAX_ELEMENTOS], int tope, coordenada_t posicion)
{
    int i = 0;
    int posicion_elemento = SIN_ELEMENTO;
    bool aux_corte = false;

    while ((i < tope) && (aux_corte == false)){
        if (coordenadas_iguales(elementos[i].posicion, posicion)){
            posicion_elemento = i;
            aux_corte = true;
        }
        i++;
    }

    return posicion_elemento;
}

void imprimir_terreno(juego_t juego){

	char terreno[MAX_FILAS][MAX_COLUMNAS];

	for (int i = 0; i < MAX_FILAS; i++){
		for (int j = 0; j < MAX_COLUMNAS; j++){
			terreno[i][j] = '_';
		}
	}

    terreno[juego.personaje.posicion.fila][juego.personaje.posicion.col] = PERSONAJE_MAC;  
    terreno[juego.sombra.posicion.fila][juego.sombra.posicion.col] = SOMBRA_BLOO;

	for (int i = 0; i < MAX_FILAS; i++){
		for (int j = 0; j < MAX_COLUMNAS; j++){
			printf(" %c ", terreno[i][j]);
		}

		printf("\n");
	}
}