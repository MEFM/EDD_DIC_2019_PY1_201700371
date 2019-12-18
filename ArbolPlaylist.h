#pragma once
#include "NodoArbolBinario.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

class ArbolPlaylist
{

private:
	NodoArbolBinario* raiz;
	//recordarme de agregarle el atributo de playlist
	void recorridoConsola(NodoArbolBinario*);
	void mostrarenConsola(NodoArbolBinario*);

public:
	string controla = "";
	void insertar(string, NodoArbolBinario*, Cancion*);
	int recorr = 0;
	void insertar(string, Cancion*);
	void recorridoConsola();
	void reporte_playlist(NodoArbolBinario*);
	void reporte_playlist();
	void mostrarenConsola();
	void buscarPlayList(string);
	void buscarPlayList(string, NodoArbolBinario*);
	string recolector(NodoArbolBinario*);


	ArbolPlaylist();
	~ArbolPlaylist();
};

