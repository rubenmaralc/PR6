#include "lancha.h"

using namespace std;

int lancha::getVelocidad() {
	return velocidad;
}
int lancha::getDistancia() {
	return distancia;
}
int lancha::getNitro() {
	return nitro;
}
string lancha::getNombre() {
	return nombre;
}


void lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}
void lancha::setDistancia(int pDistancia) {
	distancia = pDistancia;
}
void lancha::setNitro(int pNitro) {
	nitro = pNitro;
}
void lancha::setNombre(string pNombre) {
	nombre = pNombre;
}

lancha::lancha(int pVelocidad, int pDistancia, int pNitro, string pNombre)
{
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
	nombre = pNombre;
}
