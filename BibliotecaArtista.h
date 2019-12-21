#pragma once
#include <stdlib.h>
#include <string>
#include "Album.h"

using namespace std;

class NodoBiblio {
public:
	NodoBiblio* siguiente;
	NodoBiblio* anterior;
	NodoBiblio* arriba;
	NodoBiblio* abajo;
	NodoBiblio* front;
	NodoBiblio* back;
	string month;
	int año;
	Album* album;

	NodoBiblio(string month, int año, Album* album) {
		this->siguiente = 0;
		this->anterior = 0;
		this->arriba = 0;
		this->abajo = 0;
		this->front = 0;
		this->back = 0;
		this->month = month;
		this->año = año;
		this->album = album;
	}
};

class BibliotecaArtista
{
private:

public:
	BibliotecaArtista() {
		this->raiz = new NodoBiblio("Root", -1, new Album("","","",0,new Cancion()));
	}
	NodoBiblio* raiz;

	NodoBiblio* buscarAño(int);
	NodoBiblio* buscarMes(string);
	NodoBiblio* insertarAño(NodoBiblio*, NodoBiblio*);
	NodoBiblio* insertarMes(NodoBiblio*, NodoBiblio*);
	NodoBiblio* crearMes(string);
	NodoBiblio* crearAño(int);

	void nuevoNivel(); 
	void imprimir();
	void mostrarI();
	void graficar();
	void insertar(string, int, Album*);
	void buscarAlbum(string);
	
	bool buscarCancion(string, string);
};

