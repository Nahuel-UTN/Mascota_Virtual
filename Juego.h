#pragma once
#include <SFML/Graphics.hpp>
#include "mascota.h"

using namespace sf;

class Juego
{

public:
	Juego(int x, int y, const char *nombre);
	Juego();
	void Ventana1();
	void CargarNada();
	void Acciones(Clock &reloj);
	void ContarTiempo(float tiempo);
	void cargarSprites();
	void MostrarEstadistica(int estadistica, float Y);
	void Reloj(Clock &reloj, Clock &relojacciones);
	void MovimientoPersonaje();
	void Fondo();
	void Barra();




private:
	RenderWindow* _ventana1;
	Mascota Back;
	Texture Pusheen[9];
	Sprite Pusheen_Sprites[9];
	Texture Carteles[3];
	Sprite Carteles_Sprites[3];
	Texture Barras[3];
	Sprite Barras_Sprites[3];



};

