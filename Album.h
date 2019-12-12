#pragma once
#include <string>
#include <stdlib.h>
#include "Cancion.h"

using namespace std;

class Album
{
	class NodoAlbum {
	private:
		NodoAlbum* siguiente;
		NodoAlbum* anterior;
		string name;
		string month;
		int anio;
		Cancion* canciones;
	public:
		NodoAlbum(string nombre, string mes, int anio, Cancion *cancion) {
			this->name = nombre;
			this->month = mes;
			this->anio = anio;
			this->canciones = cancion;
		}

		NodoAlbum* getSiguiente() {
			return this->siguiente;
		}
		NodoAlbum* getAnterior() {
			return this->anterior;
		}
		string getName() {
			return this->name;
		}
		string getMonth() {
			return this->month;
		}
		int getAnio() {
			return this->anio;
		}
		Cancion* getCanciones() {
			return this->canciones;
		}

		void setSiguiente(NodoAlbum * nuevo) {
			this->siguiente = nuevo;
		}
		void setAnterior(NodoAlbum* nuevo) {
			this->anterior = nuevo;
		}
		void setName(string name) {
			this->name = name;
		}
		void setMont(string month) {
			this->month = month;
		}
		void setAnio(int anio) {
			this->anio = anio;
		}
		void setCanciones(Cancion* canciones) {
			this->canciones = canciones;
		}
	};

private:
	NodoAlbum* primero;
	NodoAlbum* ultimo;
public:
	Album() {
		this->primero = 0;
		this->ultimo = 0;
	}

	

};

