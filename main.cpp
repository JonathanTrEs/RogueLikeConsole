#include "tablero.h"

int main()
{
	bool salir = false;
	bool valido = false;
	int opc = 0;
	int alto = 0;
	int ancho = 0;
	system("clear");
	while(!salir)
	{
cout << setw(70)<<" _____                    __    _ _       " << endl;
cout << setw(70)<<"| __  |___ ___ _ _ ___   |  |  |_| |_ ___ " << endl;
cout << setw(70)<<"|    -| . | . | | | -_|  |  |__| | '_| -_|" << endl;
cout << setw(70)<<"|__|__|___|_  |___|___|  |_____|_|_,_|___|" << endl;
cout << setw(69)<<"          |___|                          " << endl << endl;
		cout << setw(62)<<"1.Generar Mazmorra aleatorio" << endl;
		cout << setw(65)<<"2.Cargar Mazmorra desde fichero" << endl;
		cout << setw(41)<<"3.Salir" << endl << endl;;
		cout << setw(42) <<"Opcion: " ;
		cin >> opc;
		system("clear");
		switch(opc)
		{
			case 1:
			{
cout << setw(70)<<" _____                    __    _ _       " << endl;
cout << setw(70)<<"| __  |___ ___ _ _ ___   |  |  |_| |_ ___ " << endl;
cout << setw(70)<<"|    -| . | . | | | -_|  |  |__| | '_| -_|" << endl;
cout << setw(70)<<"|__|__|___|_  |___|___|  |_____|_|_,_|___|" << endl;
cout << setw(69)<<"          |___|                          " << endl << endl;
				valido = false;
				while(!valido)
				{
					cout << setw(70) <<"Ancho de la Mazmorra(mayor que 30)" << endl;
					cout << setw(43)<<"Ancho: ";
					cin >> ancho;
					if(ancho < 30)
					{
						cout << setw(50) <<"Ancho invalido" << endl;
					}
					else
						valido = true;
				}
				valido = false;
				while(!valido)
				{
					cout << setw(68) <<"Alto de la Mazmorra(mayor de 30)" << endl;
					cout << setw(42)<<"Alto: ";
					cin >> alto;
					if(alto < 30)
					{
						cout << setw(49) <<"Alto invalido" << endl;
					}
					else
						valido = true;
				}
				system("clear");
				tablero A(alto, ancho);
				A.tablero_random();
				A.mover();
			}
				break;
			case 2:
			{
cout << setw(70)<<" _____                    __    _ _       " << endl;
cout << setw(70)<<"| __  |___ ___ _ _ ___   |  |  |_| |_ ___ " << endl;
cout << setw(70)<<"|    -| . | . | | | -_|  |  |__| | '_| -_|" << endl;
cout << setw(70)<<"|__|__|___|_  |___|___|  |_____|_|_,_|___|" << endl;
cout << setw(69)<<"          |___|                          " << endl << endl;
				valido = false;
				while(!valido)
				{
					cout << setw(70) <<"Ancho de la Mazmorra(mayor que 30)" << endl;
					cout << setw(43)<<"Ancho: ";
					cin >> ancho;
					ancho++;
					if(ancho < 30)
					{
						cout << setw(50)<<"Ancho invalido" << endl;
					}
					else
						valido = true;
				}
				valido = false;
				while(!valido)
				{
					cout << setw(68) <<"Alto de la Mazmorra(mayor de 25)" << endl;
					cout << setw(42)<<"Alto: ";
					cin >> alto;
					alto++;
					if(alto < 24)
					{
						cout <<setw(49) <<"Alto invalido" << endl;
					}
					else
						valido = true;
				}
				tablero A(alto,ancho);
				A.leer_fichero();
				system("clear");
				A.mover();
			}
				break;
			case 3:
				cout << "Adios" << endl;
				salir = true;
				break;
			default:
				cout << "Opcion incorrecta" << endl;
		}
	}
	return 0;
}
