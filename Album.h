#pragma once
#include <string>
#include <stdlib.h>
#include "Cancion.h"

using namespace std;

class Album
{

private:

	string nombre;
	string month;
	string file;
	int year;
	Cancion* canciones;
public:

	Album(string nombre,string month, string file, int year,Cancion* canciones) {
		this->nombre = nombre;
		this->month = month;
		this->file = file;
		this->year = year;
		this->canciones = canciones;
	}

	string getNombre();
	string getMonth();
	string getFile();
	int getYear();
	Cancion* getCanciones();
	void setMonth(string);
	void setFile(string);
	void setNombre(string);
	void setYear(int);
	void setCanciones(Cancion*);
};

