#include "ea.h"
#include <iostream>
#include <stdlib.h> 

using namespace std;

////////////////////////////////////////////////////////////////////// HABITACION /////////////////////////////////////////////////////////

//CONSTRUCTOR
habitacion::habitacion()
{
   for(int i=0; i<2; i++)
   {
      v_esquina[i] = 0;
   }
}

//GETTERS
int habitacion::get_esquina_x()
{
   return v_esquina[0];
}
int habitacion::get_esquina_y()
{
   return v_esquina[1];
}
int habitacion::get_tamano_ancho()
{
  return v_tamano[0];
}
int habitacion::get_tamano_alto()
{
  return v_tamano[1];
}
      
//SETTERS
void habitacion::set_esquina(int x, int y)
{
   v_esquina[0] = x;
   v_esquina[1] = y;
}
void habitacion::set_tamano(int ancho, int alto)
{
  v_tamano[0] = ancho;
  v_tamano[1] = alto;
}

//GENERAR HABITACION
void habitacion::generar(int n_a, int filas, int columnas, ea* hab)
{
   bool salir = false;
   if(n_a == 0) //SI ES LA HABITACION 1
   {
      while(!salir)
      {
	 
	 //random para el ancho y el alto
	 v_tamano[0] = 6+rand()%((columnas/2)-6); //ancho
	 v_tamano[1] = 6+rand()%((filas/2)-6); //alto
	 if((((columnas/2) - v_tamano[0])-1) != 0  && (((filas/2)-v_tamano[1])-1) != 0)
	 {
	    salir = true;
	 }
      }
      //random para saber donde se coloca la esquina
      v_esquina[0] = 1+rand()%(((columnas/2)-v_tamano[0])-1); //esquina ancho
      v_esquina[1] = 1+rand()%(((filas/2)-v_tamano[1])-1); // esquina alto
   }
   if(n_a == 1) //SI ES LA HABITACION 2
   {
      while(!salir)
      {
	 //random para el ancho y el alto
	 v_tamano[0] = 6+rand()%((columnas/2)-6); //ancho
	 v_tamano[1] = 6+rand()%((filas/2)-6); //alto
	 if((((columnas-v_tamano[0])-1)-((columnas/2)+1)) != 0  && (((filas/2)-v_tamano[1])-1) != 0)
	 {
	    salir = true;
	 }
      }
      //random para saber donde se coloca la esquina
      v_esquina[0] = ((columnas/2)+1)+rand()%(((columnas-v_tamano[0])-1)-((columnas/2)+1)); //esquina ancho
      v_esquina[1] = 1+rand()%(((filas/2)-v_tamano[1])-1); //esquina alto
   }
   if(n_a == 2) //SI ES LA HABITACION 3
   {
     while(!salir)
     {
       //random para el ancho y el alto
       v_tamano[0] = 6+rand()%((columnas-2)-6); //ancho
       v_tamano[1] = 6+rand()%((filas/2)-6); //alto
       if((((columnas-1) - v_tamano[0])-1) != 0  && (((filas/2)-v_tamano[1])-1) != 0)
       {
	 salir = true;
       }
     }
     //random para saber donde se coloca la esquina
     v_esquina[0] = 1+rand()%((columnas-v_tamano[0])-2); //esquina ancho
     v_esquina[1] = ((filas/2)+1)+rand()%((filas-v_tamano[1])-((filas/2)+1)); //esquina alto
   }       
}

//PINTAR
void habitacion::pintar(char** tabla)

{
      for(int i = v_esquina[1]; i < v_esquina[1]+v_tamano[1]; i++)
      {
	 for(int j = v_esquina[0]; j < v_esquina[0]+v_tamano[0]; j++)
	 {
	       if(i == v_esquina[1])
	       {
		  tabla[i][j] = '*';
	       }
	       if(i == (v_esquina[1]+v_tamano[1])-1)
	       {
		  tabla[i][j] = '*';
	       }
	       if(j == v_esquina[0])
	       {
		  tabla[i][j] = '*';
	       }
	       if(j == (v_esquina[0]+v_tamano[0])-1)
	       {
		  tabla[i][j] = '*';
	       }
	 }
      }
}

//ASIGNAR DATOS CUANDO LEES DE FICHERO
void habitacion::asignar_datos(int cual,int filas,int columnas,char** tablerito)
{
  //BUSCAR ESQUINAS DE LAS HABITACIONES-----------------------------------------------
  int mitad_alto = filas/2;
  int mitad_ancho = columnas/2;
  int empezar = 0;
  bool salir = false;
  bool fuera = false;
  int aux_x = 0;
  int aux_y = 0;
  if(cual == 0)//me dice que habitacion es, para saber en que parte del tablero buscar
  {
    while(!salir)
    {
      for(int j = 0;j<mitad_alto;j++)
      {
	if((tablerito[empezar][j] == '*' && tablerito[empezar+1][j] == '*' && tablerito[empezar][j+1] == '*')) //varias condiciones por si es una puerta y no un muro
	{
	  v_esquina[0] = empezar;
	  v_esquina[1] = j;
	  salir = true;
	}
      }
      empezar++;
    }
  }
  if(cual == 1)
  {
    while(!salir)
    {
      for(int j =mitad_alto;j<columnas;j++)
      {
	if((tablerito[empezar][j]== '*' && tablerito[empezar+1][j] == '*' && tablerito[empezar][j+1] == '*') || 
	  (tablerito[empezar][j]== '*' && tablerito[empezar+1][j] == '+' && tablerito[empezar][j+1] == '*'))
	{
	  v_esquina[0] = empezar;
	  v_esquina[1] = j;
	  salir = true;
	}
      }
      empezar++;
    }
  }
  if(cual == 2)
  {
    empezar = mitad_alto;
    while(!salir)
    {
      for(int j =0;j<columnas;j++)
      {
	if((tablerito[empezar][j]== '*' && tablerito[empezar+1][j] == '*' && tablerito[empezar][j+1] == '*') ||
	  (tablerito[empezar][j]== '*' && tablerito[empezar+1][j] == '*' && tablerito[empezar][j+1] == '+'))
	{
	  v_esquina[0] = empezar;
	  v_esquina[1] = j;
	  salir = true;
	}
      }
      empezar++;
    }
  }
	  
//ANCHO Y ALTO
	  aux_x = v_esquina[0];
	  aux_y = v_esquina[1];
	  while(!fuera)//ANCHO Y ALTO
	  {
	    if(tablerito[v_esquina[0]][aux_y] == '*' || tablerito[v_esquina[0]][aux_y] == '+')
	    {
	      v_tamano[0] = (aux_y-v_esquina[1]);
	      aux_y++;
	    }
	    else
	      fuera = true;
	  }
	  aux_x = v_esquina[0];
	  aux_y = v_esquina[1];
	  fuera = false;
	  while(!fuera)
	  {
	    if(tablerito[aux_x][v_esquina[1]] == '*' || tablerito[aux_x][v_esquina[1]] == '+')
	    {
	      v_tamano[1] = (aux_x - v_esquina[0]);
	      aux_x++;
	    }
	    else
	      fuera = true;
	  }
}

///////////////////////////////////////////////////////////////////// PUERTA /////////////////////////////////////////////////////////////
//CONSTRUCTOR
puerta::puerta()
{
   for(int i =0;i<2;i++)
   {
      v_coordenada[i] = 0;
   }
}

//GETTERS
int puerta::get_esquina_x()
{
   return v_coordenada[0];
}

int puerta::get_esquina_y()
{
   return v_coordenada[1];
}

//SETTERS
void puerta::set_coordenada(int x, int y)
{
   v_coordenada[0] = x;
   v_coordenada[1] = y;
}

//PINTAR
void puerta::pintar(char** tabla)
{
   tabla[v_coordenada[1]][v_coordenada[0]] = '+';
}

void puerta::generar(int i, int a, int b,ea* hab)
{
  if(i == 3 || i ==8) //si es la puerta 1 o la 6
  {
    v_coordenada[0] = hab->get_esquina_x()+hab->get_tamano_ancho()-1;
    v_coordenada[1] = (hab->get_esquina_y()+1)+rand()%(((hab->get_esquina_y()+hab->get_tamano_alto())-1)-(hab->get_esquina_y()+1));
  }
  if(i == 5) //si es la puerta 3
  {
    v_coordenada[0] = hab->get_esquina_x();
    v_coordenada[1] = (hab->get_esquina_y()+1)+rand()%(((hab->get_esquina_y()+hab->get_tamano_alto())-1)-(hab->get_esquina_y()+1));
  }
  if(i == 4 || i == 6) //si es la puerta 2 o 4
  {
    v_coordenada[0] = (hab->get_esquina_x()+1)+rand()%(((hab->get_esquina_x()+hab->get_tamano_ancho())-1)-(hab->get_esquina_x()+1));
    v_coordenada[1] = hab->get_esquina_y()+hab->get_tamano_alto()-1;
  }
  if(i == 7)//si es la puerta 5
  {
    v_coordenada[0] = (hab->get_esquina_x()+1)+rand()%(((hab->get_esquina_x()+hab->get_tamano_ancho())-1)-(hab->get_esquina_x()+1));
    v_coordenada[1] = hab->get_esquina_y();
  }
}
