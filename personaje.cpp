#include "personaje.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////// CLASE PERSONAJE //////////////////////////////////////////////////////////////////////////
char personaje::ocupado(int i,int j, char** tablero)
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
/////////////////////////////////////////////////////////////////////////////////// CLASE HEROE //////////////////////////////////////////////////////////////////////////////7

//CONSTRUCTOR
heroe::heroe()
{
  posicion[0] = 0;
  posicion[1] = 0;
  vida = 5;
  beneficio = 0;
  fuerza = 5;
  anterior = 'X';
  amuleto = false;
}
//SETTERS
//set posicion
void heroe::set_posicion(int i, int j)
{
  posicion[0] = i;
  posicion[1] = j;
}

//GETTERS
int heroe::get_pos_x()
{
  return posicion[0];
}

int heroe::get_pos_y()
{
  return posicion[1];
}

int heroe::get_anterior()
{
  return anterior;
}

int heroe::get_vida()
{
  return vida;
}

int heroe::get_fuerza()
{
  return fuerza;
}

bool heroe::get_amuleto()
{
  return amuleto;
}

int heroe::get_beneficio()
{
  return beneficio;
}

//QUITAR
void heroe::quitar()
{
  vida--;
}

//PINTAR
void heroe::pintar(char** tablero)
{
  tablero[posicion[0]][posicion[1]] = '@';
}

//QUITAR VIDA
void heroe::quitar_vida(int& i, int& j, char** tablerito)
{
	i = 0;
	j = 0;
	bool salir = false;
	if((tablerito[posicion[0]][posicion[1]-1] == 'D') && !salir)
	{
		if(fuerza < 20)
		{
		  vida --;
		}
		else
		{
		   i = posicion[0];
		   j = posicion[1]-1;
		}
		salir = true;
	}
	if((tablerito[posicion[0]-1][posicion[1]] == 'D') && !salir)
	{
		if(fuerza < 20)
		{
		  vida --;
		}
		else
		{
		  i = posicion[0]-1;
		  j = posicion[1];
		}
		salir = true;
	}
	if((tablerito[posicion[0]][posicion[1]+1] == 'D') && !salir)
	{
		if(fuerza < 20)
		{
		  vida --;
		}
		else
		{
		  i = posicion[0];
		  j = posicion[1]+1;
		}
		salir = true;
	}
	if((tablerito[posicion[0]+1][posicion[1]] == 'D') && !salir)
	{
		if(fuerza < 20)
		{
		  vida --;
		}
		else
		{
		  i = posicion[0]+1;
		  j = posicion[1];
		}
		salir = true;
	}
}
//MOVER
void heroe::mover(char mov,char** tablerito)
{
	char ocu;
	int aux_x = 0;
	int aux_y = 0;
	int p_c = 0;
	char aux_anterior;
	aux_x = posicion[0];
	aux_y = posicion[1];
	aux_anterior = anterior;
	//MOVIMIENTO A LA IZQUIERDA
	if(mov == 'j')
	{
		ocu = ocupado(posicion[0], posicion[1]-1,tablerito);
		if(ocu == ' ' || ocu == '+' || ocu == '#' || ocu == 'X')
		{
			anterior = ocu;
			posicion[1]= posicion[1] -1;
		}
		if(ocu == '&')
		{
			anterior = ' ';
			amuleto = true;
			beneficio = beneficio+3;
			posicion[1] = posicion[1] -1;
		}
		if(ocu == 'P')
		{
		    anterior = ' ';
		    posicion[1] = posicion[1]-1;
		    beneficio = beneficio+1;
		    fuerza = fuerza+5;
		}
		if(ocu == 'E')
		{
		  anterior = ' ';
		  posicion[1] = posicion[1]-1;
		  fuerza = fuerza + 10;
		}
		if(ocu == '*' || ocu == 'D' || ocu == 'T')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO HACIA LA DERECHA
	if(mov == 'l')
	{
		ocu = ocupado(posicion[0], posicion[1]+1,tablerito);
		if(ocu == ' ' || ocu == '+' || ocu == '#' || ocu == 'X')
		{
			anterior = ocu;
			posicion[1]= posicion[1] +1;
		}
		if(ocu == '&')
		{
			anterior = ' ';
			amuleto = true;
			beneficio = beneficio+3;
			posicion[1] = posicion[1] +1;
		}
		if(ocu == 'P')
		{
		    anterior = ' ';
		    posicion[1] = posicion[1]+1;
		    beneficio = beneficio+1;
		    fuerza = fuerza+5;
		}
		if(ocu == 'E')
		{
		  anterior = ' ';
		  posicion[1] = posicion[1]+1;
		  fuerza = fuerza + 10;
		}
		if(ocu == '*' || ocu == 'D' || ocu == 'T')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO HACIA ARRIBA
	if(mov == 'i')
	{
		ocu = ocupado(posicion[0]-1, posicion[1],tablerito);
		if(ocu == ' ' || ocu == '+' || ocu == '#' || ocu == 'X')
		{
			anterior = ocu;
			posicion[0]= posicion[0]-1;
		}
		if(ocu == '&')
		{
			anterior = ' ';
			amuleto = true;
			beneficio = beneficio+3;
			posicion[0] = posicion[0] -1;
		}
		if(ocu == 'P')
		{
		    anterior = ' ';
		    posicion[0] = posicion[0]-1;
		    beneficio = beneficio+1;
		    fuerza = fuerza+5;
		}
		if(ocu == 'E')
		{
		  anterior = ' ';
		  posicion[0] = posicion[0]-1;
		  fuerza = fuerza + 10;
		}
		if(ocu == '*' || ocu == 'D' || ocu == 'T')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO HACIA ABAJO
	if(mov == 'k')
	{
		ocu = ocupado(posicion[0]+1, posicion[1],tablerito);
		if(ocu == ' ' || ocu == '+' || ocu == '#' || ocu == 'X')
		{
			anterior = ocu;
			posicion[0]= posicion[0]+1;
		}
		if(ocu == '&')
		{
			anterior = ' ';
			amuleto = true;
			beneficio = beneficio+3;
			posicion[0] = posicion[0] +1;
		}
		if(ocu == 'P')
		{
		    anterior = ' ';
		    posicion[0] = posicion[0]+1;
		    beneficio = beneficio+1;
		    fuerza = fuerza+5;
		}
		if(ocu == 'E')
		{
		  anterior = ' ';
		  posicion[0] = posicion[0]+1;
		  fuerza = fuerza + 10;
		}
		if(ocu == '*' || ocu == 'D' || ocu == 'T')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	tablerito[aux_x][aux_y] = aux_anterior;
	tablerito[posicion[0]][posicion[1]] = '@';
}

//MOVER POR EL PASILLO
void heroe::mover_pasillo(char mov,char** tablerito)
{
	char ocu;
	int aux_x = 0;
	int aux_y = 0;
	char aux_anterior;
	aux_x = posicion[0];
	aux_y = posicion[1];
	aux_anterior = anterior;
	//MOVIMIENTO A LA IZQUIERDA
	if(mov == 'j')
	{
		ocu = ocupado(posicion[0], posicion[1] -1,tablerito);
		if(ocu == '#' || ocu == '+')
		{
			anterior = ocu;
			posicion[1] = posicion[1] -1;
		}
		if(ocu == ' ' || ocu == '*')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO HACIA ARRIBA
	if(mov == 'i')
	{
		ocu = ocupado(posicion[0] -1, posicion[1],tablerito);
		if(ocu == '#' || ocu == '+')
		{
			anterior = ocu;
			posicion[0] = posicion[0] -1;
		}
		if(ocu == ' ' || ocu == '*')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO A LA DERECHA 
	if(mov == 'l')
	{
		ocu = ocupado(posicion[0], posicion[1] +1,tablerito);
		if(ocu == '#' || ocu == '+')
		{
			anterior = ocu;
			posicion[1] = posicion[1] +1;
		}
		if(ocu == ' ' || ocu == '*')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	//MOVIMIENTO HACIA ABAJO
	if(mov == 'k')
	{
		ocu = ocupado(posicion[0] +1, posicion[1],tablerito);
		if(ocu == '#' || ocu == '+')
		{
			anterior = ocu;
			posicion[0] = posicion[0] +1;
		}
		if(ocu == ' ' || ocu == '*')
		{
			cout << "No te puedes mover en esa direccion" << endl;
		}
	}
	tablerito[aux_x][aux_y] = aux_anterior;
	tablerito[posicion[0]][posicion[1]] = '@';
}
////////////////////////////////////////////////////////////////////////////// CLASE TROL /////////////////////////////////////////////////////////////////////////////////7

//CONSTRUCTOR
trol::trol()
{
  vida = 3;
  fuerza = 10;
  pos[0] = 0;
  pos[1] = 0;
  mov = 'D';
}

//GENERAR PERSONAJE
void trol::generar_personaje(int i, int j, int ancho, int alto,char** tablero)
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

//GETTERS
int trol::get_pos_x()
{
  return pos[0];
}

int trol::get_pos_y()
{
  return pos[1];
}

int trol::get_vida()
{
  return vida;
}

//PINTAR
void trol::pintar(char** tablero)
{
  if(vida > 0)
  {
    tablero[pos[0]][pos[1]] = 'T';
  }
}

//QUITAR VIDA
void trol::quitar_vida(int& fuer,int& posy,char** tablero) //devuelvo en posy lo que le tengo que quitar a la vida del personaje
{
  
  if(posy == pos[1])
  {
    if(fuer >= 10)
    {
      vida--;
    }
    if(fuer < 10)
    {
      posy = -4;
    }
  }
  if(vida < 1)
  {
     tablero[pos[0]][pos[1]] = ' ';
  }
}
//MOVER TROL
void trol::mover(char qwe,char** tablero)
{
  char ocu = 'a';
  int aux_i = pos[0];
  int aux_j = pos[1];
  
  if(mov == 'D')
  {
    ocu = ocupado(pos[0],pos[1]+1,tablero);
    if(ocu == ' ')
    {
      pos[1] = pos[1]+1;
    }
    if(ocu == '&' || ocu == '*' || ocu == '+' || ocu == 'E' || ocu == 'P')
    {
      mov = 'I';
      ocu = ocupado(pos[0],pos[1]-1,tablero);
      if(ocu == ' ')
      {
	pos[1] = pos[1]-1;
      }
    }
  }    
  if(mov == 'I')
  {
    ocu = ocupado(pos[0],pos[1]-1,tablero);
    if(ocu == ' ')
    {
      pos[1] = pos[1]-1;
    }
    if(ocu == '&' || ocu == '*' || ocu == '+' || ocu == 'E' || ocu == 'P')
    {
      mov = 'D';
      ocu = ocupado(pos[0],pos[1]+1,tablero);
      if(ocu == ' ')
      {
	pos[1] = pos[1]+1;
      }
    }
  }
  tablero[aux_i][aux_j] = ' ';
  pintar(tablero);
}

/////////////////////////////////////////////////////////////////////////////// CLASE DRAGON //////////////////////////////////////////////////////////////////////////////
//CONSTRUCTOR
dragon::dragon()
{
  vida = 1;
  fuerza = 20;
  pos[0] = 0;
  pos[1] = 0;
}

//GETTERS
int dragon::get_pos_x()
{
  return pos[0];
}

int dragon::get_pos_y()
{
  return pos[1];
}

int dragon::get_vida()
{
  return vida;
}

//GENERAR PERSONAJE
void dragon::generar_personaje(int i, int j, int ancho, int alto,char** tablero)
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
void dragon::pintar(char** tablero)
{
  if(vida > 0)
  {
    tablero[pos[0]][pos[1]] = 'D';
  }
}

//MOVER
void dragon::mover(char qwe,char** tablero)
{
  int mov = 0;
  bool salir = false;
  char ocu = 'a';
  int aux_i = pos[0];
  int aux_j = pos[1];
  
  int rodeado[4]; //para si el personaje no se puede mover a ningun lado
  for(int i = 0; i < 4; i++)
  {
    rodeado[i] = 0;
  }
  
  while(!salir)
  {
    mov = 0+rand()%(4-0);
    if(mov == 0)
    {
      ocu = ocupado(pos[0],pos[1]-1,tablero);
      if(ocu == ' ')
      {
	pos[1] = pos[1]-1;
	salir = true;
      }
      rodeado[0] = 1;
    }
    if(mov == 1)
    {
      ocu = ocupado(pos[0]-1,pos[1],tablero);
      if(ocu == ' ')
      {
	pos[0] = pos[0]-1;
	salir = true;
      }
      rodeado[1] = 1;
    }
    if(mov == 2)
    {
      ocu = ocupado(pos[0],pos[1]+1,tablero);
      if(ocu == ' ')
      {
	pos[1] = pos[1]+1;
	salir = true;
      }
      rodeado[2] = 1;
    }
    if(mov == 3)
    {
      ocu = ocupado(pos[0]+1,pos[1],tablero);
      if(ocu == ' ')
      {
	pos[0] = pos[0]+1;
	salir = true;
      }
      rodeado[3] = 1;
    }
    if(rodeado[0] == 1 && rodeado[1] == 1 && rodeado[2] == 1 && rodeado[3] == 1)
    {
      salir = true;
    }
  }
  tablero[aux_i][aux_j] = ' ';
  pintar(tablero);
}
  
  
//QUITAR VIDA
void dragon::quitar_vida(int& i,int& j,char** tablero)
{
  vida--;
  tablero[pos[0]][pos[1]] = ' ';
}