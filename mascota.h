#define _CRT_SCURE_NO_WARNINGS
#pragma once


class Mascota
{


public:
	Mascota();
	void setnombres(std::string nombre);
	void setdiversion(int diversion);
	void sethambre(int hambre);
	void setsucio(int sucio);
	void setedad(int edad);
	void setsalud(int salud);
	void setcarinio(int carinio);
	void setsuenio(int suenio);
	const char* getnombres() {
		return _nombre;
	}
	int  getdiversion();
	int  gethambre();
	int  getsucio();
	int  getedad();
	int  getsalud();
	int  getsuenio();
	int  getCarinio();
	void Cargarmascota();
	void Alimentar();
	void Jugar();
	void Bañar();
	void acariciar();
	void Dormir();

private:
	char _nombre[30];
	int  _amor;
	int  _diversion;
	int  _hambre;
	int  _sucio;
	int  _edad;
	int  _salud;
	int _suenio;


};

