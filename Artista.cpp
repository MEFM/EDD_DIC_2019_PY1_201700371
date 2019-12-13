#include "stdafx.h"
#include "Artista.h"

void Artista::insertarOrdenado(string nombre, CuboDisperso<Album*> * discografia) {
	if (this->primero == 0) {
		this->primero = this->ultimo = new NodoArtista(nombre, discografia);
	}
	else {
		NodoArtista* nuevo = new NodoArtista(nombre, discografia);
		NodoArtista* auxiliar = this->primero;
		do {
			char* nombreNuevo = (char*)auxiliar->getNombre().c_str();
			char* nombreSiguiente = (char*)auxiliar->getSiguiente()->getNombre().c_str();
			char* nombreAnterior = (char*)auxiliar->getAnterior()->getNombre().c_str();

			if (strcmp(nombreNuevo, nombreSiguiente) <= 0) {
				if (auxiliar->getAnterior() != 0) {
					auxiliar->getAnterior()->setSiguiente(nuevo);
					auxiliar->getSiguiente()->setAnterior(nuevo);
					auxiliar = nuevo;
					this->primero->setAnterior(this->ultimo);
					this->ultimo->setSiguiente(this->primero);
				}
			}
			else {
				auxiliar->getAnterior()->setSiguiente(nuevo);
				auxiliar->getSiguiente()->setAnterior(nuevo);
				auxiliar = nuevo;
				this->primero->setAnterior(this->ultimo);
				this->ultimo->setSiguiente(this->primero);
			}
			auxiliar = auxiliar->getSiguiente();
		} while (auxiliar->getSiguiente() != this->ultimo);
	}
}