#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class NodoArbolBinario
{
private:
	NodoArbolBinario * derecho;
	NodoArbolBinario * izquierdo;
	string nombre_artista;
	//Recordar de hacer la propiedad de la playlist
	/*
		Este método es jodidamente importante perro recordate de hacerlo bien mano!!
	*/
public:
	NodoArbolBinario(string);
	NodoArbolBinario();
	NodoArbolBinario *getDerecho();
	NodoArbolBinario *getIzquierdo();
	void setDerecho(NodoArbolBinario*);
	void setIzquierdo(NodoArbolBinario*);

	string getNombre();
	void setNombre(string);
	~NodoArbolBinario();
};

