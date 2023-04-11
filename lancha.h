#pragma once

#include <iostream>

using namespace std;

class lancha
{
	private:
		//Atributos de la lancha
		int velocidad;
		int distancia;
		int nitro;
		string nombre;


	public:
		//Metodos get
		int getVelocidad();
		int getDistancia();
		int getNitro();
		string getNombre();

		//Metodos set
		void setVelocidad(int pVelocidad);
		void setDistancia(int pDistancia);
		void setNitro(int pNitro);
		void setNombre(string pNombre);

		//Constructor
		lancha(int pVelocidad, int pDistancia, int pNitro, string pNombre);
};

