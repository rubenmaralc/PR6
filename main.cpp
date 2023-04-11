// Carrera de lanchas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "lancha.h"
#include <Windows.h>;

using namespace std;

//Variables
string nombre;
int dado;
string eleccionJugador;
int dadoNitro;

//Funciones
//Tirar dado
int lanzarDado() {
	int dado = 1 + (rand() % 6);
	return dado;
}
//Calcula Velocidad
int calculoVelocidad(int pVelocidad, int pDado) {
	int velocidad = pVelocidad + pDado;
	return velocidad;
}
//Calcula distancia
int calculoDistancia(int pDistancia, int pVelocidad) {
	int distancia = pDistancia + pVelocidad * 100;
	return distancia;
}
//Random Nitro
int randomNitro() {
	int nitro = rand() % 2;
	return nitro;
}
// Texto resultado dado
void textoLanzamientoDado(string pNombre, int pDado) {
	cout << "El jugador " << pNombre << " ha sacado un " << pDado << endl;
}
//Victoria o derrota
void final(int distancia1, int distancia2, string nombre1, string nombre2) {
	if (distancia1 > distancia2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "El jugador " << nombre1 << " ha ganado." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "El jugador " << nombre2 << " ha perdido." << endl;
	}
	else if (distancia2 > distancia1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "El jugador " << nombre2 << " ha ganado." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "El jugador " << nombre1 << " ha perdido." << endl;
	}
	else
	{
		cout << "Empate!!!" << endl;
	}
}



int main()
{
	srand(time(NULL));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Escribe el nombre del jugador 1." << endl;
	cin >> nombre;
	lancha jugador1(0, 0, 1, nombre);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Escribe el nombre del jugador 2." << endl;
	cin >> nombre;
	lancha jugador2(0, 0, 1, nombre);
	
	for (size_t i = 1; i <= 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Turno " << i << endl;
		dado = lanzarDado();
		Sleep(1500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		textoLanzamientoDado(jugador1.getNombre(), dado);
		jugador1.setVelocidad(calculoVelocidad(jugador1.getVelocidad(), dado));
		if (jugador1.getNitro() == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Quieres utilizar la NITRO, " << jugador1.getNombre() << "? (si o no)" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cin >> eleccionJugador;
			if (eleccionJugador == "si")
			{
				jugador1.setNitro(0);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "Lanzamos dado de NITRO" << endl;
				Sleep(1500);
				int dadoNitro = randomNitro();
				if (dadoNitro == 0)
				{
					cout << "El resultado es " << dadoNitro << ". La velocidad se divide entre 2." << endl;
					jugador1.setVelocidad(jugador1.getVelocidad() / 2);
					jugador1.setDistancia(calculoDistancia(jugador1.getDistancia(), jugador1.getVelocidad()));
				}
				else
				{
					cout << "El resultado es " << dadoNitro << ". La velocidad se multiplica por 2." << endl;
					jugador1.setVelocidad(jugador1.getVelocidad() * 2);
					jugador1.setDistancia(calculoDistancia(jugador1.getDistancia(), jugador1.getVelocidad()));
				}
			}
			else if (eleccionJugador == "no")
			{
				jugador1.setDistancia(calculoDistancia(jugador1.getDistancia(), jugador1.getVelocidad()));
			}
			else
			{
				cout << "Tienes que especificar si o no." << endl;
			}
		}
		else
		{
			jugador1.setDistancia(calculoDistancia(jugador1.getDistancia(), jugador1.getVelocidad()));
		}
		dado = lanzarDado();
		Sleep(1500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		textoLanzamientoDado(jugador2.getNombre(), dado);
		jugador2.setVelocidad(calculoVelocidad(jugador2.getVelocidad(), dado));
		if (jugador2.getNitro() == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Quieres utilizar la NITRO, " << jugador2.getNombre() << "? (si o no)" << endl;
			cin >> eleccionJugador;
			if (eleccionJugador == "si")
			{
				jugador2.setNitro(0);
				cout << "Lanzamos dado de NITRO" << endl;
				Sleep(1500);
				int dadoNitro = randomNitro();
				if (dadoNitro == 0)
				{
					cout << "El resultado es " << dadoNitro << ". La velocidad se divide entre 2." << endl;
					jugador2.setVelocidad(jugador2.getVelocidad() / 2);
					jugador2.setDistancia(calculoDistancia(jugador2.getDistancia(), jugador2.getVelocidad()));
				}
				else
				{
					cout << "El resultado es " << dadoNitro << ". La velocidad se multiplica por 2." << endl;
					jugador2.setVelocidad(jugador2.getVelocidad() * 2);
					jugador2.setDistancia(calculoDistancia(jugador2.getDistancia(), jugador2.getVelocidad()));
				}
			}
			else if (eleccionJugador == "no")
			{
				jugador2.setDistancia(calculoDistancia(jugador2.getDistancia(), jugador2.getVelocidad()));
			}
			else
			{
				cout << "Tienes que especificar si o no." << endl;
			}
		}
		else
		{
			jugador2.setDistancia(calculoDistancia(jugador2.getDistancia(), jugador2.getVelocidad()));
		}
		Sleep(1500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "Distancia de " << jugador1.getNombre() << " es de " << jugador1.getDistancia() << endl;
		Sleep(1500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Distancia de " << jugador2.getNombre() << " es de " << jugador2.getDistancia() << endl;
		Sleep(1500);
	}
	final(jugador1.getDistancia(), jugador2.getDistancia(), jugador1.getNombre(), jugador2.getNombre());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


