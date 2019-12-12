#include "stdafx.h"
#include "ArbolPlaylist.h"


ArbolPlaylist::ArbolPlaylist()
{
	this->raiz = 0;
}

void ArbolPlaylist::insertar(string nombre, NodoArbolBinario* arbol) {
	/*RECORDAR EL ATRIBUTO DE PLAYLIST*/

	if (arbol == 0) {
		NodoArbolBinario* nuevo = new NodoArbolBinario(nombre);
		arbol = nuevo;
	}
	else {
		char* palabra1 = (char*)arbol->getNombre().c_str();
		char* palabra2 = (char*)nombre.c_str();
		if (0 <= strcmp(palabra2, palabra1)) {
			//Insertar a la derecha
			insertar(nombre, arbol->getDerecho());
		}
		else {
			//Insertar a la izquierda
			insertar(nombre, arbol->getIzquierdo());
		}


	}
}

void ArbolPlaylist::recorridoConsola() {
	this->recorridoConsola(this->raiz);
}

void ArbolPlaylist::recorridoConsola(NodoArbolBinario* root) {
	int contador = 1;
	if (this->raiz == 0) {
		cout << "No tienes listas de reproduccion disponibles." << endl;
		return;
	}
	if (root == 0) {
		return;
	}
	else {
		this->recorridoConsola(root->getIzquierdo());
		cout << contador << ". " << root->getNombre() << endl;
		this->recorridoConsola(root->getDerecho());
		contador++;
	}
}

void ArbolPlaylist::buscarPlayList(string nombre) {
	this->buscarPlayList(nombre, this->raiz);
}

NodoArbolBinario* ArbolPlaylist::buscarPlayList(string nombre, NodoArbolBinario* root) {
	if (this->raiz == 0) {
		cout << "No tienes listas de reproduccion disponibles." << endl;
		return NULL;
	}
	if (root == 0) {
		return NULL;
	}
	else {
		char* palabra1 = (char*)nombre.c_str();
		char* palabra2 = (char*)root->getNombre().c_str();

		if (strcmp(palabra1, palabra2) == 0 && nombre == root->getNombre()) {
			cout << "Hemos encontrado tu playlist!" << endl;
			cout << root->getNombre() << endl;
		}
		else if (strcmp(palabra1, palabra2) <= 0) {
			if (root == 0) {

			}
			else {
				buscarPlayList(nombre, root->getDerecho());
			}
		}
		else {
			if (root == 0) {

			}
			else
			{
				buscarPlayList(nombre, root->getIzquierdo());
			}
		}
	}

}

void ArbolPlaylist::menu_reportesRecorrido() {
	bool validador = 0;
	int seleccion = 0;
	while (validador) {
		system("clr");
		cout << "------Tu decides como ves tus listas de reproduccion!------" << endl;
		cout << "1. Deseas ver todas tus playlist?" << endl;
		cout << "2. Prefieres ver tus playlist en orden alfabetico?" << endl;
		cout << "3. Lista desordenada" << endl;
		cout << "4. Buscas una lista en especifico?" << endl;
		cin >> seleccion;
		switch (seleccion)
		{

		default:
			break;
		}

	}
}

ArbolPlaylist::~ArbolPlaylist()
{
}
