#pragma once
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Album.h"
#include "BibliotecaArtista.h"

using namespace std;
class NodoArtista {
private:
	NodoArtista* siguiente;
	NodoArtista* anterior;
	string nombre;
	BibliotecaArtista* discografia;
	//Crear clase cancion
public:
	NodoArtista* getSiguiente() {
		return this->siguiente;
	}
	NodoArtista* getAnterior() {
		return this->anterior;
	}
	BibliotecaArtista* getDiscografia() {
		return this->discografia;
	}
	void setSiguiente(NodoArtista* nuevo) {
		this->siguiente = nuevo;
	}
	void setAnterior(NodoArtista* nuevo) {
		this->anterior = nuevo;
	}
	void setDiscografia(BibliotecaArtista* discografia) {
		this->discografia = discografia;
	}

	string getNombre() {
		return this->nombre;
	}
	void setNombre(string name) {
		nombre = name;
	}

	NodoArtista(string nombre, BibliotecaArtista* discografia) {
		this->siguiente = 0;
		this->anterior = 0;
		this->nombre = nombre;
		this->discografia = discografia;
	}
	NodoArtista(string nombre) {
		this->siguiente = 0;
		this->anterior = 0;
		this->nombre = nombre;
	}

};

class Artista
{
private:
	NodoArtista* primero;
	NodoArtista* ultimo;
	BibliotecaArtista* disco;
public:
	
	Artista() {
		this->primero = 0;
		this->ultimo = 0;
	}
	void setDiscog(BibliotecaArtista* d) {
		this->disco = d;
	}
	BibliotecaArtista* getDisco() {
		return disco;
	}
	void insertarOrdenado(string nombre, BibliotecaArtista* discografia);
	void imprimirConsola();
	void graficarLista();
	void buscarArtista(string nombre);
	void mostrarArtista(NodoArtista*);//Este metodo contiene lo que sera la matriz (biblioteca) y las canciones de los albumnes
	void insertarOrdenado(string nombre);

	bool buscarCancion(string, string, string);
};

