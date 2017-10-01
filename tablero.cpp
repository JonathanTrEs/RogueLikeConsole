#include "tablero.h"
#include <stdlib.h> 

//CONSTRUCTOR
tablero::tablero(int c,int f)
{
   filas = c;
   columnas = f;
   acceso[0] = 0;
   acceso[1] = 0;
   
   //RESERVAR MEMORIA PARA LOS ELEMENTOS ARQUITECTONICOS
   for(int i=0; i<9; i++)
   {
      if(i<3)
      {
	 v_ea[i] = new habitacion;
      }
      if(i>=3)
      {
	 v_ea[i] = new puerta;
      }
   }
   
   //RESERVAR MEMORIA PARA LOS PERSONAJES
   for(int i=0; i<13;i++)
   {
     if(i == 0)
     {
       v_personaje[i] = new heroe;
     }
     else if(i>0 && i<4)
     {
       v_personaje[i] = new trol;
     }
     else
     {
       v_personaje[i] = new dragon;
     }
   }
   
   //RESERVAR MEMORIA PARA LOS OBJETOS
   for(int i =0;i<7; i++)
   {
     if(i ==0)
     {
       v_objeto[i] = new amuleto;
     }
     else if(i>0 && i<4)
     {
       v_objeto[i] = new pocima;
     }
     else
     {
       v_objeto[i] = new espada;
     }
   }
   
   //RESERVAR MEMORIA PARA EL TABLERO
   tabla = new char *[c];
   for(int i=0; i<c; i++)
   {
      tabla[i] = new char [f];
   }
   //INICIALIZAR TABLERO
   for(int i=0; i<c; i++)
   {
      for(int j=0; j<f; j++)
      {
	 tabla[i][j] = ' ';
      }
   }
   for(int j = 0; j <f;j++)
   {
     tabla[0][j] = '_';
     tabla[c-1][j] = '_';
   }
   for(int i = 1; i <c;i++)
   {
     tabla[i][0] = '|';
     tabla[i][f-1] = '|';
   }
}

//DESTRUCTOR
tablero::~tablero()
{
   //LIBERAR MEMORIA DEL TABLERO
   for(int i=0; i<filas; i++)
   {
      delete [] tabla[i];
   }
   delete [] tabla;

//    //LIBERAR MEMORIA DE LOS EA
//    for(int i=0; i<9; i++)
//    {
//       delete [] 
//    }
}

//MOSTRAR TABLERO
void tablero::mostrar_tablero()
{
cout <<setw(70)<< " _____                    __    _ _       " << endl;
cout <<setw(70)<< "| __  |___ ___ _ _ ___   |  |  |_| |_ ___ " << endl;
cout <<setw(70)<< "|    -| . | . | | | -_|  |  |__| | '_| -_|" << endl;
cout <<setw(70)<< "|__|__|___|_  |___|___|  |_____|_|_,_|___|" << endl;
cout <<setw(69)<< "          |___|                          " << endl << endl;
   for(int i=0; i<filas; i++)
   {
      cout << endl;
      for(int j=0; j<columnas; j++)
      {
	 cout << tabla[i][j];
      }
   }
   cout << endl <<endl;
   cout << setw(45)<<"Vida: " ;
   
   for(int i = 0; i < v_personaje[0]->get_vida();i++)
   {
     cout << "♥ ";
   }
    cout << setw(10) << "Fuerza: " << v_personaje[0]->get_fuerza() << endl;
   cout << setw(48) << "Amuleto: ";
   if(v_personaje[0]->get_amuleto())
		cout << "&";
   else
		cout << " ";
   cout << setw(19)<<"Beneficio: " << v_personaje[0]->get_beneficio() << setw(10);
   cout <<endl<<endl;
}

//ACCESO RANDOM
void tablero::acceso_random()
{
  acceso[0] = (v_ea[0]->get_esquina_y()+1)+rand()%((v_ea[0]->get_esquina_y()+(v_ea[0]->get_tamano_alto()-1))-(v_ea[0]->get_esquina_y()+1)); // alto acceso
  acceso[1] = (v_ea[0]->get_esquina_x()+1)+rand()%((v_ea[0]->get_esquina_x()+(v_ea[0]->get_tamano_ancho()-1))-(v_ea[0]->get_esquina_x()+1)); //alto acceso
  tabla[acceso[0]][acceso[1]] = 'X';
}

//OCUPADO
char tablero::ocupado(int i,int j)
{
  if(tabla[i][j] == ' ' || tabla[i][j] == 'X')
  {
    return ' ';
  }
  if(tabla[i][j] == '*')  
  {
    return '*';
  }
  if(tabla[i][j] == '+')  
  {
    return '+';
  }
  if(tabla[i][j] == 'D')  
  {
    return 'D';
  }
  if(tabla[i][j] == '&')  
  {
    return '&';
  }
  if(tabla[i][j] == 'T')  
  {
    return 'T';
  }
  if(tabla[i][j] == '@')  
  {
    return '@';
  }
  if(tabla[i][j] == 'P')  
  {
    return 'P';
  }
  if(tabla[i][j] == 'E')  
  {
    return 'E';
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////GENERAR TABLERO RANDOM
void tablero::tablero_random()
{
   srand(time(NULL));
   ea* aux = NULL; //auxiliar para acceder a las coordenadas de cada habitacion para poner las puertas
   for(int i = 0; i<9; i++)
   {
     if( i == 3 || i == 4)
     {
       aux = v_ea[0];
     }
     if(i == 5 || i == 6)
     {
       aux = v_ea[1];
     }
     if(i == 7 || i == 8)
     {
       aux = v_ea[2];
     }
      v_ea[i]->generar(i,filas,columnas,aux);
      v_ea[i]->pintar(tabla);
   }
   //PASILLOS
   int suma = 0;
   int div = 0;
   int dif = 0; //calcular lo que hay que subir o bajar
   int resto = 0; // calcular lo qeu falta por avanzar
   
   //puerta 1 con la 3
   if(v_ea[3]->get_esquina_y() < v_ea[5]->get_esquina_y()) //si la puerta 1 esta mas arriba que la puerta 3
   {
     suma = v_ea[5]->get_esquina_x() - v_ea[3]->get_esquina_x();
     div = suma/2;
     for(int j = v_ea[3]->get_esquina_x()+1; j < v_ea[3]->get_esquina_x() + div;j++)//avanza hasta la mitad
     {
       tabla[v_ea[3]->get_esquina_y()][j] = '#';
     }
     dif = v_ea[5]->get_esquina_y() - v_ea[3]->get_esquina_y();
     for(int i = v_ea[3]->get_esquina_y(); i <= v_ea[5]->get_esquina_y();i++) //baja del todo
     {
       tabla[i][v_ea[3]->get_esquina_x()+div] = '#';
     }
     resto = suma - dif;
     for(int j = v_ea[3]->get_esquina_x()+div; j < v_ea[5]->get_esquina_x();j++)
     {
       tabla[v_ea[5]->get_esquina_y()][j] = '#';
     }
   }
   else if(v_ea[3]->get_esquina_y() > v_ea[5]->get_esquina_y()) //si la puerta 3 esta mas arriba que la puerta 1
   {
     suma = v_ea[5]->get_esquina_x() - v_ea[3]->get_esquina_x();
     div = suma/2;
     for(int j = v_ea[3]->get_esquina_x()+1;j < v_ea[3]->get_esquina_x()+div;j++)
     {
       tabla[v_ea[3]->get_esquina_y()][j] = '#';
     }
     dif = v_ea[3]->get_esquina_y() - v_ea[5]->get_esquina_y();
     for(int i = v_ea[3]->get_esquina_y(); i >= v_ea[5]->get_esquina_y(); i--)
     {
       tabla[i][v_ea[3]->get_esquina_x() + div] = '#';
     }
     resto = suma - div;
     for(int j = v_ea[3]->get_esquina_x()+div;j < v_ea[5]->get_esquina_x(); j++)
     {
       tabla[v_ea[5]->get_esquina_y()][j] = '#';
     }
   }
   else
   {
     for(int j = v_ea[3]->get_esquina_x()+1;j < v_ea[5]->get_esquina_x(); j++)
     {
       tabla[v_ea[3]->get_esquina_y()][j] = '#';
     }
   }
   
   //puerta 2 con la 5
   if(v_ea[4]->get_esquina_x() < v_ea[7]->get_esquina_x())//si la puerta 2 esta mas a la izquierda que la puerta 5
   {
     for(int i = v_ea[4]->get_esquina_y()+1;i<v_ea[7]->get_esquina_y()-1;i++)
     {
       tabla[i][v_ea[4]->get_esquina_x()] = '#';
     }
     for(int j = v_ea[4]->get_esquina_x(); j <= v_ea[7]->get_esquina_x(); j++)
     {
       tabla[v_ea[7]->get_esquina_y()-2][j] = '#';
     }
     tabla[v_ea[7]->get_esquina_y()-1][v_ea[7]->get_esquina_x()] = '#';
   }
   else if(v_ea[4]->get_esquina_x() > v_ea[7]->get_esquina_x())
   {
     for(int i = v_ea[4]->get_esquina_y()+1;i < v_ea[7]->get_esquina_y()-1;i++)
     {
       tabla[i][v_ea[4]->get_esquina_x()] = '#';
     }
     for(int j = v_ea[4]->get_esquina_x(); j >= v_ea[7]->get_esquina_x();j--)
     {
       tabla[v_ea[7]->get_esquina_y()-2][j] = '#';
     }
     tabla[v_ea[7]->get_esquina_y()-1][v_ea[7]->get_esquina_x()] = '#';
   }
   else
   {
     for(int i = v_ea[4]->get_esquina_y(); i < v_ea[7]->get_esquina_y();i++)
     {
       tabla[i][v_ea[4]->get_esquina_x()] = '#';
     }
   }
   
   //puerta 4 con la 6
   if(v_ea[6]->get_esquina_x() > v_ea[8]->get_esquina_x())
   {
     for(int j = v_ea[8]->get_esquina_x()+1; j <= v_ea[6]->get_esquina_x(); j++)
     {
       tabla[v_ea[8]->get_esquina_y()][j] = '#';
     }
     for(int i = v_ea[8]->get_esquina_y(); i > v_ea[6]->get_esquina_y(); i--)
     {
       tabla[i][v_ea[6]->get_esquina_x()] = '#';
     }
   }
   else
   {
     tabla[v_ea[8]->get_esquina_y()][v_ea[8]->get_esquina_x()+1] = '#'; //me muevo uno a la derecha para no pintar el muro}
     for(int i = v_ea[8]->get_esquina_y(); i > v_ea[6]->get_esquina_y(); i--)
     {
       tabla[i][v_ea[8]->get_esquina_x()+1] = '#';
     }
     for(int j = v_ea[8]->get_esquina_x()+1; j >= v_ea[6]->get_esquina_x(); j--)
     {
       tabla[v_ea[6]->get_esquina_y()+1][j] = '#';
     }
   }
   
   //PERSONAJES
   acceso_random();
   v_personaje[0]->set_posicion(acceso[0],acceso[1]);
   v_personaje[0]->pintar(tabla);
   
   int x = 0;
   int y = 0;
   int an = 0;
   int al = 0;
   for(int i = 1; i < 13; i++)
   {
	x = 0;
	y = 0;
	an = 0;
	al = 0;
     if(i == 1 || i == 4 || i == 5 || i == 6) //si es la habitacion 1
     {
       x = v_ea[0]->get_esquina_x();
       y = v_ea[0]->get_esquina_y();
       an = v_ea[0]->get_tamano_ancho();
       al = v_ea[0]->get_tamano_alto();
     }
     if(i == 2 || i == 7 || i == 8 || i == 9) // si es la habitacion 2
     {
       x = v_ea[1]->get_esquina_x();
       y = v_ea[1]->get_esquina_y();
       an = v_ea[1]->get_tamano_ancho();
       al = v_ea[1]->get_tamano_alto();
     }
     if(i == 3 || i == 10 || i == 11 || i ==12) //si es la habitacion 3
     {
       x = v_ea[2]->get_esquina_x();
       y = v_ea[2]->get_esquina_y();
       an = v_ea[2]->get_tamano_ancho();
       al = v_ea[2]->get_tamano_alto();
     }
      v_personaje[i]->generar_personaje(x,y,an,al,tabla);
      v_personaje[i]->pintar(tabla);
   }
   
   //OBJETOS
   for(int i = 0;i<7;i++)
   {
      x = 0;
      y = 0;
      an = 0;
      al = 0;
      if(i == 1 || i == 4) //si es la habitacion 1
      {
	x = v_ea[0]->get_esquina_x();
       y = v_ea[0]->get_esquina_y();
       an = v_ea[0]->get_tamano_ancho();
       al = v_ea[0]->get_tamano_alto();
      }
      if(i == 2 || i == 5) //si es la habitacion 2
      {
	x = v_ea[1]->get_esquina_x();
	y = v_ea[1]->get_esquina_y();
	an = v_ea[1]->get_tamano_ancho();
	al = v_ea[1]->get_tamano_alto();
      }
      if(i == 0 || i == 3 || i ==6)
      {
	x = v_ea[2]->get_esquina_x();
	y = v_ea[2]->get_esquina_y();
	an = v_ea[2]->get_tamano_ancho();
	al = v_ea[2]->get_tamano_alto();
      }
      v_objeto[i]->generar_objeto(x,y,an,al,tabla);
      v_objeto[i]->pintar(tabla);
   }

}

///////////////////////////////////////////////////////////////////////////////////////////FUNCION MOVER
void tablero::mover()
{
	bool salir = false;
	char opc;
	mostrar_tablero();
	int abajo = -1;
	int adelante = -1;
	while(!salir)
	{
		abajo = -1;
		adelante = -1;
	        cout << setw(57)<<"Movimiento: "; 
		opc = inkey();
		cout << endl;
		for(int i=1;i<13;i++)
		{
		  if(v_personaje[i]->get_vida() > 0) // si el bicho esta muerto no lo mueve
		  {
		    v_personaje[i]->mover(opc,tabla);
		  }
		}
		if(ocupado(acceso[0], acceso[1]) == ' ')
		{
			tabla[acceso[0]][acceso[1]] = 'X';
		}
		switch(opc)
		{
			case 'j':
			case 'l':
			case 'i':
			case 'k':
				if(v_personaje[0]->get_anterior() == '#')
				{
					v_personaje[0]->mover_pasillo(opc,tabla);
				}
				else
					v_personaje[0]->mover(opc,tabla);
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}
		v_personaje[0]->quitar_vida(abajo,adelante,tabla); //quitar vida dragones
		if(abajo != 0 && adelante != 0)
		{
		  for(int i=4;i<13;i++)
		  {
		    if( (v_personaje[i]->get_pos_x() == abajo) && (v_personaje[i]->get_pos_y() == adelante))
		    {
		      v_personaje[i]->quitar_vida(abajo,adelante,tabla);
		    }
		  }
		}
		for(int i=1;i<4;i++) //QUITAR VIDA TROL
		{
		  if(v_personaje[0]->get_pos_x() <= (v_ea[i-1]->get_esquina_x()+v_ea[i-1]->get_tamano_alto())) //PARA VER SI LLAMAMOS A QUITAR VIDA DEL TROL, SOLO SI EL PERSONAJE ESTA EN SU HABITACION
		  {
		    if(v_personaje[i]->get_vida() > 0) //SOLO LLAMA A QUITAR VIDA SI EL BICHO ESTA VIVO
		    {
		      adelante = v_personaje[0]->get_pos_y();
		      abajo = v_personaje[0]->get_fuerza();
		      v_personaje[i]->quitar_vida(abajo,adelante,tabla);
		    }
		  }
		  if(adelante == -4)//si se cambia adelante a -4 es que le tengo que quitar vida al prota
		  {
		    v_personaje[0]->quitar();
		  }
		}
		if(ocupado(acceso[0], acceso[1]) == ' ')
		{
			tabla[acceso[0]][acceso[1]] = 'X';
		}
		if(salir == false)
		{
 			system("clear");
			mostrar_tablero();
		}
		if(((v_personaje[0]->get_beneficio() >= 3) && (v_personaje[0]->get_pos_x() == acceso[0]) && (v_personaje[0]->get_pos_y() == acceso[1]))) //SI TIENE UN BENE DE 3 O SUPERIOR Y ESTA EN LA CASILLA SALIDA
		{
cout << setw(70)<<" _____ _     _               " << endl;
cout << setw(70)<<"|  |  |_|___| |_ ___ ___ _ _ " << endl;
cout << setw(70)<<"|  |  | |  _|  _| . |  _| | |" << endl;
cout << setw(70)<<"\\___/|_|___|_| |___|_| |_  |" << endl;
cout << setw(70)<<"                        |___|" << endl<<endl;
			salir = true;
		}
		else if(v_personaje[0]->get_vida() == 0)
		{
cout << setw(70)<<" _____                  _____             " << endl;
cout << setw(70)<<"|   __|___ _____ ___   |     |_ _ ___ ___ " << endl;
cout << setw(70)<<"|  |  | .'|     | -_|  |  |  | | | -_|  _|" << endl;
cout << setw(80)<<"|_____|__,|_|_|_|___|  |_____|\\_/|___|_|            " << endl << endl;                                                                                                                                                                   
			salir = true;
		}
	}
}


//LEER SIN PULSAR ENTER
char inkey(void) {
  char c;
  struct termio param_ant, params;

  ioctl(STDINFD,TCGETA,&param_ant);

  params = param_ant;
  params.c_lflag &= ~(ICANON|ECHO);
  params.c_cc[4] = 1;

  ioctl(STDINFD,TCSETA,&params);

  fflush(stdin); fflush(stderr); fflush(stdout);
  read(STDINFD,&c,1);

  ioctl(STDINFD,TCSETA,&param_ant);
  return c;
}

//LEER FICHERO
void tablero::leer_fichero()
{
	char nombre [30];
	char caracter;
	ifstream in;
	cout << setw(54)<<"Nombre del Fichero" << endl;
	cout << setw(44) <<"Nombre: ";
	cin >> nombre;
	in.open(nombre);
	if(in.is_open())
	{
		for(int i = 0; i < filas; i++)
		{
			for(int j = 0; j < columnas+1; j++)
			{
				caracter = in.get();
				tabla[i][j] = caracter;
				if(caracter == 'X')
				{
					acceso[0] = i;
					acceso[1] = j;
				}
				if(caracter == '&')
				{
					v_objeto[0]->set_pos(i,j);
				}
			}
		}
	}
	in.close();
	for(int i = 0; i <9;i++) //BUSCA LAS ESQUINAS Y TAMANOS DE LAS HABITACIONES Y LAS COORDENADAS DE LAS PUERTAS
	{
	  v_ea[i]->asignar_datos(i,filas,columnas,tabla);
	}
	
	//METER AL PROTA
	v_personaje[0]->set_posicion(acceso[0],acceso[1]);
	v_personaje[0]->pintar(tabla);
	
   int x = 0;
   int y = 0;
   int an = 0;
   int al = 0;
   for(int i = 1; i < 13; i++)
   {
	x = 0;
	y = 0;
	an = 0;
	al = 0;
     if(i == 1 || i == 4 || i == 5 || i == 6) //si es la habitacion 1
     {
       x = v_ea[0]->get_esquina_x();
       y = v_ea[0]->get_esquina_y();
       an = v_ea[0]->get_tamano_ancho();
       al = v_ea[0]->get_tamano_alto();
     }
     if(i == 2 || i == 7 || i == 8 || i == 9) // si es la habitacion 2
     {
       x = v_ea[1]->get_esquina_x();
       y = v_ea[1]->get_esquina_y();
       an = v_ea[1]->get_tamano_ancho();
       al = v_ea[1]->get_tamano_alto();
     }
     if(i == 3 || i == 10 || i == 11 || i ==12) //si es la habitacion 3
     {
       x = v_ea[2]->get_esquina_x();
       y = v_ea[2]->get_esquina_y();
       an = v_ea[2]->get_tamano_ancho();
       al = v_ea[2]->get_tamano_alto();
     }
      v_personaje[i]->generar_personaje(y,x,an,al,tabla);
      v_personaje[i]->pintar(tabla);
   }
   
   //OBJETOS
   for(int i = 1;i<7;i++)
   {
      x = 0;
      y = 0;
      an = 0;
      al = 0;
      if(i == 1 || i == 4) //si es la habitacion 1
      {
	x = v_ea[0]->get_esquina_x();
       y = v_ea[0]->get_esquina_y();
       an = v_ea[0]->get_tamano_ancho();
       al = v_ea[0]->get_tamano_alto();
      }
      if(i == 2 || i == 5) //si es la habitacion 2
      {
	x = v_ea[1]->get_esquina_x();
	y = v_ea[1]->get_esquina_y();
	an = v_ea[1]->get_tamano_ancho();
	al = v_ea[1]->get_tamano_alto();
      }
      if(i == 0 || i == 3 || i ==6)
      {
	x = v_ea[2]->get_esquina_x();
	y = v_ea[2]->get_esquina_y();
	an = v_ea[2]->get_tamano_ancho();
	al = v_ea[2]->get_tamano_alto();
      }
      v_objeto[i]->generar_objeto(y,x,an,al,tabla);
      v_objeto[i]->pintar(tabla);
   }

}







































