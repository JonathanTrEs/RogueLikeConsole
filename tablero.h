#pragma once

#include <iostream> //flujo de entrada y salida
#include <fstream> //flujo de ficheros
#include <iomanip> //para setw
#include <stdio.h>
#include <stdlib.h>//system clear

#include "ea.h"
#include "personaje.h"
#include "objeto.h"

//-----para leer sin pulsar enter------
#include <unistd.h>
#include <termio.h>
#include <sys/ioctl.h>
//----------

#define STDINFD  0
#undef getc


char inkey(void);
using namespace std;
    
class tablero
{
   private:
      char** tabla; //MATRIZ DEL TABLERO
      int filas; //alto del tablero
      int columnas; //ancho del tablero
      ea* v_ea[9]; //vector de elementos arquitectonicos, habitaciones y puertas
      int acceso[2]; // punto de acceso
      personaje* v_personaje[13]; //vector de personajes, heroe, trols y dragones
      objeto* v_objeto[7]; //vector de objetos, amuleto, pociones y espadas.
   public:
      tablero(int,int);
      ~tablero();
      void tablero_random();
      void acceso_random();
      void mostrar_tablero();
      char ocupado(int,int);
      void mover();
      void leer_fichero();
};
      
      

