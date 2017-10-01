#include "objeto.h"
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////////////// CLASE OBJETO /////////////////////////////////////////////////////////////////////////////////////////////////////////////

char objeto::ocupado(int i,int j,char** tablero)
{
  if(tablero[i][j] == ' ' || tablero[i][j] == 'X')
  {
    return ' ';
  }
  if(tablero[i][j] == '*')  
  {
    return '*';
  }
  if(tablero[i][j] == '+')  
  {
    return '+';
  }
  if(tablero[i][j] == 'D')  
  {
    return 'D';
  }
  if(tablero[i][j] == '&')  
  {
    return '&';
  }
  if(tablero[i][j] == 'T')  
  {
    return 'T';
  }
  if(tablero[i][j] == '@')  
  {
    return '@';
  }
  if(tablero[i][j] == 'P')  
  {
    return 'P';
  }
  if(tablero[i][j] == 'E')  
  {
    return 'E';
  }
}
////////////////////////////////////////////////////////////////////////////////////////// CLASE AMULETO //////////////////////////////////////////////////////////////////////////////////////////////////////////777
//CONSTRUCTOR
amuleto::amuleto()
{
  pos[0] = 0;
  pos[1] = 0;
  beneficio = 3;
}

//GENERAR AMULETO
void amuleto::generar_objeto(int i,int j,int ancho,int alto,char** tablero)
{
  bool salir = false;
  while(!salir)
  {
    pos[0] = (j+1)+rand()%(((j+alto)-1)-(j+1));
    pos[1] =  (i+1)+rand()%(((i+ancho)-1)-(i+1));
    if(ocupado(pos[0],pos[1],tablero) == ' ')
    {
      salir = true;
    }
  }
}

//SETTER
void amuleto::set_pos(int i,int j)
{
  pos[0] = i;
  pos[1] = i;
}

//PINTAR
void amuleto::pintar(char** tablero)
{
  tablero[pos[0]][pos[1]] = '&';
}

/////////////////////////////////////////////////////////////////////////////// CLASE POCION ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
//CONSTRUCTOR
pocima::pocima()
{
  pos[0] = 0;
  pos[1] = 0;
  beneficio = 1;
  fuerza = 5;
}

//GENERAR POCIONES
void pocima::generar_objeto(int i,int j,int ancho,int alto,char** tablero)
{
  bool salir = false;
  while(!salir)
  {
    pos[0] = (j+1)+rand()%(((j+alto)-1)-(j+1));
    pos[1] =  (i+1)+rand()%(((i+ancho)-1)-(i+1));
    if(ocupado(pos[0],pos[1],tablero) == ' ')
    {
      salir = true;
    }
  }
}

//PINTAR
void pocima::pintar(char** tablero)
{
  tablero[pos[0]][pos[1]] = 'P';
}

/////////////////////////////////////////////////////////////////////////////// CLASE ESPADA //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTOR
espada::espada()
{
  pos[0] = 0;
  pos[1] = 0;
  fuerza = 10;
}

//GENERAR ESPADAS
void espada::generar_objeto(int i,int j,int ancho,int alto,char** tablero)
{
  bool salir = false;
  while(!salir)
  {
    pos[0] = (j+1)+rand()%(((j+alto)-1)-(j+1));
    pos[1] =  (i+1)+rand()%(((i+ancho)-1)-(i+1));
    if(ocupado(pos[0],pos[1],tablero) == ' ')
    {
      salir = true;
    }
  }
}

//PINTAR
void espada::pintar(char** tablero)
{
  tablero[pos[0]][pos[1]] = 'E';
}
