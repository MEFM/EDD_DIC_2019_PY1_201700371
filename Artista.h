#pragma once
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Album.h"
#include "CuboDisperso.h"

using namespace std;

class Artista
{
	class NodoArtista {
	private:
		NodoArtista* siguiente;
		NodoArtista* anterior;
		string nombre;
		CuboDisperso<Album*>* discografia;
		//Crear clase cancion
	public:
		NodoArtista* getSiguiente() {
			return this->siguiente;
		}
		NodoArtista* getAnterior() {
			return this->anterior;
		}
		void setSiguiente(NodoArtista* nuevo) {
			this->siguiente = siguiente;
		}
		void setAnterior(NodoArtista* nuevo) {
			this->anterior = nuevo;
		}

		string getNombre() {
			return this->nombre;
		}
		void setNombre(string name) {
			nombre = name;
		}

		NodoArtista(string nombre, CuboDisperso<Album*> * discografia) {
			this->siguiente = 0;
			this->anterior = 0;
			this->nombre = nombre;
			this->discografia = discografia;
		}

	};
private:
	NodoArtista* primero;
	NodoArtista* ultimo;
	
public:
	Artista() {
		this->primero = 0;
		this->ultimo = 0;
	}

	void insertarOrdenado(string nombre, CuboDisperso<Album*> * discografia);
	void imprimirConsola();
	void graficarLista();
	

};

