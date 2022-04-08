#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "mascota.h"
#include <string>

using namespace sf;
using namespace std;

Mascota::Mascota() {

	_amor = 100;
	_diversion = 100;
	_hambre = 100;
	_sucio = 100;
	_edad = 0;
	_salud = 100;
	_suenio = 100;

}

void Mascota::setnombres(std::string nombre) {
	strcpy_s(_nombre, nombre.c_str());
}

void Mascota::setdiversion(int diversion) {
	_diversion = diversion;
}

void Mascota::sethambre(int hambre) {
	_hambre = hambre;
}

void Mascota::setsucio(int sucio)
{
	_sucio = sucio;
}

void Mascota::setedad(int edad) {
	_edad = edad;
}

void Mascota::setsalud(int salud) {
	_salud = salud;
}

void Mascota::setcarinio(int carinio)
{
	_amor = carinio;
}

void Mascota::setsuenio(int suenio)
{
	_suenio = suenio;
}


int  Mascota::getdiversion() {
	return _diversion;
}

int  Mascota::gethambre() {
	return _hambre;
}

int  Mascota::getsucio() {
	return _sucio;
}

int  Mascota::getedad() {
	return _edad;
}

int  Mascota::getsalud() {
	return _salud;
}


int Mascota::getsuenio()
{
	return _suenio;
}

int Mascota::getCarinio()
{
	return _amor;
}

void Mascota::Cargarmascota()
{
	string nombre;

	cout << "INGRESE NOMBRE DE LA MASCOTA: ";
	cin >> _nombre;




}

void Mascota::Alimentar()
{

	_hambre = _hambre + 10;
	if (_hambre > 100) {
	_hambre = 100;
}
	if (_hambre == 0) {
		_hambre = 0;
}
}

void Mascota::Jugar()
{
	_diversion = _diversion + 10;

	if (_diversion > 100) {
		_diversion = 100;
	}
}

void Mascota::Bañar()
{
	_sucio = _sucio + 10;
	if (_sucio > 100) {
		_sucio = 100;
	}
}

void Mascota::acariciar()
{
	_amor = _amor + 25;
	if (_amor > 100)
	{
		_amor = 100;
	}
}


void Mascota::Dormir()
{
	_suenio = _suenio + 10;
	if (_suenio > 100) {
		_suenio = 100;
	}
}
