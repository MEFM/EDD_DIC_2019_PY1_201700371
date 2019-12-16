#include "stdafx.h"
#include "NodoArbolBinario.h"


NodoArbolBinario::NodoArbolBinario()
{
}

NodoArbolBinario::NodoArbolBinario(string nombre_artista, Cancion* canciones) {
	this->derecho = 0;
	this->izquierdo = 0;
	this->nombre_artista = nombre_artista;
	this->canciones = canciones;
}

NodoArbolBinario *NodoArbolBinario::getDerecho() {
	return this->derecho;
}

NodoArbolBinario *NodoArbolBinario::getIzquierdo() {
	return this->izquierdo;
}

void NodoArbolBinario::setDerecho(NodoArbolBinario* derecho) {
	this->derecho = derecho;
}

void NodoArbolBinario::setIzquierdo(NodoArbolBinario* izquierdo) {
	this->izquierdo = izquierdo;
}

string NodoArbolBinario::getNombre() {
	return this->nombre_artista;
}

void NodoArbolBinario::setNombre(string nombre) {
	this->nombre_artista = nombre;
}

Cancion* NodoArbolBinario::getCanciones() {
	return this->canciones;
}

void NodoArbolBinario::setCanciones(Cancion* canciones) {
	this->canciones = canciones;
}

NodoArbolBinario::~NodoArbolBinario()
{
}
