#include "stdafx.h"
#include "Cancion.h"


void Cancion::insertarAlbum(string name, string file, float rating) {

	if (this->primero == 0) {
		this->primero = new NodoCancion(name, file, rating);
	}
	else {
		NodoCancion* nuevo = new NodoCancion(name, file, rating);
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void Cancion::insertarPlaylist(string tipo, string name, string album) {
	NodoCancion* nuevo = new NodoCancion(name, album);

	if (tipo == "Stack") {
		if (this->primero == 0) {
			this->primero = nuevo;
		}
		else {
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}
	}
	else if (tipo == "Queque") {
		if (this->primero == 0) {
			this->primero = this->ultimo = nuevo;
			this->primero = this->ultimo;
		}
		else {
			nuevo->setAnteior(this->ultimo);
			this->ultimo = nuevo;
			this->primero = this->ultimo;
		}
	}
	else if (tipo == "Shuffle") {
		//Insertar de forma desordenada
		/*preguntarle a cutz como hacerlo*/
	}
	else if (tipo == "Circular") {
		if (this->primero == 0) {
			this->primero = this->ultimo = nuevo;
		}
		else {
			nuevo->setSiguiente(this->primero);
			this->primero->setAnteior(nuevo);
			this->primero = nuevo;
			this->primero->setAnteior(this->ultimo);
			this->ultimo->setSiguiente(this->primero);
		}
	}
}

void Cancion::graficarPlaylist(string tipo) {
	if (this->primero == 0) {
		cout << "No tienes musica para mostrar :(." << endl;
	}
	else {

		if (tipo == "Stack") {
			
		}
		else if (tipo == "Queque") {
			
		}
		else if (tipo == "Shuffle") {
			//Graficar lista desordenada
		}
		else if (tipo == "Circular") {
			
		}
	}
}

void Cancion::graficarCancionesAlbum() {
	if (this->primero == 0) {
		cout << "No tienes musica para mostrar :(." << endl;
	}
	else {
		ofstream WriteFile("ListaCanciones.dot");
		int x = 0;
		WriteFile << "digraph listadoble{" << endl;
		WriteFile << "node[shape=square];" << endl;
		WriteFile << "rankdir = LR;" << endl;

		NodoCancion* auxiliar = this->primero;
		while (auxiliar != 0) {
			WriteFile << "x" << auxiliar << "[label =\"" << auxiliar->getName() << "\"];" << endl;
			WriteFile << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
			auxiliar = auxiliar->getSiguiente();
		}

		WriteFile.close();
		system("dot -Tpng ListaCanciones.dot -o simplecanciones.png");
		system("simplecanciones.png");
	}
}