#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Cancion.h"

using namespace std;

class NodoArbolBinario
{
private:
	NodoArbolBinario * derecho;
	NodoArbolBinario * izquierdo;
	string nombre_artista;
	Cancion* canciones;
	//Recordar de hacer la propiedad de la playlist
	/*
		Este método es jodidamente importante perro recordate de hacerlo bien mano!!
	*/
public:
	NodoArbolBinario(string, Cancion*); // agregar la 
	NodoArbolBinario();
	NodoArbolBinario *getDerecho();
	NodoArbolBinario *getIzquierdo();
	Cancion* getCanciones();
	void setDerecho(NodoArbolBinario*);
	void setIzquierdo(NodoArbolBinario*);
	void setCanciones(Cancion* canciones);

	string getNombre();
	void setNombre(string);
	~NodoArbolBinario();
};

