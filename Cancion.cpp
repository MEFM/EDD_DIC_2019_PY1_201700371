#include "stdafx.h"
#include "Cancion.h"


void Cancion::insertarAlbum(string name, string file, float rating) {
	
	if (this->primero==0) {
		this->primero = new NodoCancion(name, file, rating);
	}
	else {
		NodoCancion* nuevo = new NodoCancion(name, file, rating);
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void Cancion::insertarPlaylist(string tipo, string name, string album) {
	NodoCancion* nuevo = new NodoCancion(name, album);

	if (tipo=="Stack") {
		if (this->primero == 0) {
			this->primero = nuevo;
		}
		else {
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}
	}
	else if (tipo == "Queque") {
		if (this->primero == 0) {
			this->primero = this->ultimo = nuevo;
			this->primero = this->ultimo;
		}
		else {
			nuevo->setAnteior(this->ultimo);
			this->ultimo = nuevo;
			this->primero = this->ultimo;
		}
	}
	else if (tipo == "Shuffle") {
		//Insertar de forma desordenada
		/*preguntarle a cutz como hacerlo*/
	}
	else if (tipo == "Circular") {
		if (this->primero == 0) {
			this->primero = this->ultimo = nuevo;
		}
		else {
			nuevo->setSiguiente(this->primero);
			this->primero->setAnteior(nuevo);
			this->primero = nuevo;
			this->primero->setAnteior(this->ultimo);
			this->ultimo->setSiguiente(this->primero);
		}
	}
}