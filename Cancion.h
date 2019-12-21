#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
class NodoCancion {
private:
	NodoCancion* siguiente;
	NodoCancion* anterior;
	//Para los dos tipos de instancia
	string name;
	//Para instancias de tipo libreria
	string file;
	float rating;

	//Para instancias de tipo playlist
	string album;
	string tipo;
	string artista;

public:
	NodoCancion(string name, string file, float rating) {
		this->siguiente = 0;
		this->anterior = 0;
		this->name = name;
		this->file = file;
		this->rating = rating;
	}
	NodoCancion(string name, string tipo, string album, string artista) {
		this->siguiente = 0;
		this->anterior = 0;
		this->tipo = tipo;
		this->name = name;
		this->album = album;
		this->artista = artista;
	}
	NodoCancion* getSiguiente() {
		return this->siguiente;
	}
	NodoCancion* getAnterior() {
		return this->anterior;
	}
	string getName() {
		return this->name;
	}
	string getFile() {
		return this->file;
	}
	string getAlgum() {
		return this->album;
	}
	string getTipo() {
		return this->tipo;
	}
	string getArtista() {
		return this->artista;
	}
	float getRating() {
		return this->rating;
	}

	void setSiguiente(NodoCancion* nuevo) {
		this->siguiente = nuevo;
	}
	void setAnteior(NodoCancion* nuevo) {
		this->anterior = nuevo;
	}
	void setName(string nombre) {
		this->name = nombre;
	}
	void setFile(string archivo) {
		this->file = archivo;
	}
	void setAlbum(string album) {
		this->album = album;
	}
	void setTipo(string tipo) {
		this->tipo = tipo;
	}
	void setArtista(string artista) {
		this->artista = artista;
	}
	void setRating(float valor) {
		this->rating = valor;
	}
};
class Cancion
{
	

private:
	NodoCancion* primero;
	NodoCancion* ultimo;
public:
	Cancion() {
		this->primero = 0;
		this->ultimo = 0;
	}
	//Lista simplemente enlzada
	void insertarAlbum(string name, string file, float rating);
	//Diferentes tipos de estructura dependiendo el tipo
	void insertarPlaylist(string tipo, string name, string album, string artista);
	void graficarPlaylist();
	void graficarCancionesAlbum();
	//Graficas, reportes (da lo mismo)
	void mostrarCancionesAlbum();
	void mostrarCancionesPlaylist();

	bool confirmacionCancion(string);
	

};

