#pragma once
#include "NodoArbolBinario.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

class ArbolPlaylist
{

private:
	NodoArbolBinario * raiz;
	//recordarme de agregarle el atributo de playlist
	void insertar(string, NodoArbolBinario*, Cancion*);
	void recorridoConsola(NodoArbolBinario*);
	NodoArbolBinario* buscarPlayList(string, NodoArbolBinario*);
public:
	void insertar(string, Cancion*);
	void recorridoConsola();
	void reporte_playlist();
	void menu_reportesRecorrido();
	void buscarPlayList(string);
	ArbolPlaylist();
	~ArbolPlaylist();
};

