#include <stdio.h>
#include "la_sombra_de_mac_primero.h"
#include <stdlib.h>
#include <time.h>
#define POSICION_INICIO_SOMBRA 20
#define POSICION_COL_SOMBRA 1


int main(){
    srand ((unsigned)time(NULL));
    personaje_t personaje_principal;
    personaje_principal.vida = 0;
    personaje_principal.puntos = 0;
    personaje_principal.tiene_llave = false;
    personaje_principal.interruptor_apretado = false;
    personaje_principal.posicion.fila = 0;
    personaje_principal.posicion.col = 0;

    sombra_t sombra;
    sombra.esta_viva = true;
    sombra.posicion.fila = 0 ;
    sombra.posicion.col= 0;

    coordenada_t coord_aleatoria,coord_personaje,coord_sombra;
    coord_aleatoria = coordenada_aleatoria(MAX_FILAS, MAX_COLUMNAS);
    inicializar_personaje(&personaje_principal, coord_aleatoria);
    personaje_principal.posicion.col = 0;
    inicializar_sombra(&sombra, coord_aleatoria);
    sombra.posicion.col = MAX_COLUMNAS - personaje_principal.posicion.col - POSICION_COL_SOMBRA;
    coord_personaje = personaje_principal.posicion;
    coord_sombra = sombra.posicion;

    juego_t mostrar_juego;
    mostrar_juego.personaje.posicion = coord_personaje;
    mostrar_juego.sombra.posicion = coord_sombra;
    imprimir_terreno(mostrar_juego);
    
    char movimiento;
    bool fin_del_juego = false;

    while(!fin_del_juego){ 
        printf("Ingrese un movimiento\n");
        scanf(" %c",&movimiento);
        pedir_movimiento(&movimiento);
        mover_personaje(&personaje_principal,&sombra,movimiento);
        mostrar_juego.personaje = personaje_principal;
        mostrar_juego.sombra = sombra;
        system("clear");
        imprimir_terreno(mostrar_juego);
    }

    return 0;
 }


