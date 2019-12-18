#include "stdafx.h"
#include "ArbolPlaylist.h"


ArbolPlaylist::ArbolPlaylist()
{
	this->raiz = 0;
}

void ArbolPlaylist::insertar(string nombre, Cancion* canciones) {

	if (this->raiz == 0) {
		this->raiz = new NodoArbolBinario(nombre, canciones);
		return;
	}
	else {
		this->insertar(nombre, this->raiz, canciones);
	}

}

void ArbolPlaylist::insertar(string nombre, NodoArbolBinario* arbol, Cancion* canciones) {
	/*RECORDAR EL ATRIBUTO DE PLAYLIST*/
	if (arbol != 0) {
		char* palabra1 = (char*)arbol->getNombre().c_str();
		char* palabra2 = (char*)nombre.c_str();
		
		if (nombre.size() < arbol->getNombre().size()) {
			if (arbol->getDerecho() != 0) {

				insertar(nombre, arbol->getDerecho(), canciones);
			}
			else {
				cout << "Si es el pequeño" << arbol->getNombre() << " " << nombre << endl;
				system("pause");
				arbol->setDerecho(new NodoArbolBinario(nombre, canciones));
			}
		}
		else if (strcmp(palabra2, palabra1) > 0) {
			if (arbol->getIzquierdo() != 0) {
				insertar(nombre, arbol->getIzquierdo(), canciones);
			}
			else {
				arbol->setIzquierdo(new NodoArbolBinario(nombre, canciones));
			}
		}
	}
	else {
		arbol = new NodoArbolBinario(nombre, canciones);
	}




}

void ArbolPlaylist::recorridoConsola() {
	this->recorridoConsola(this->raiz);

}

void ArbolPlaylist::recorridoConsola(NodoArbolBinario* root) {
	int contador = 1;
	if (root != 0) {
		this->recorridoConsola(root->getIzquierdo());
		cout << contador << ". " << root->getNombre() << endl;
		this->recorridoConsola(root->getDerecho());
		contador++;

	}


}

void ArbolPlaylist::buscarPlayList(string nombre) {
	this->buscarPlayList(nombre, this->raiz);


}

void ArbolPlaylist::buscarPlayList(string nombre, NodoArbolBinario* nodo) {
	if (nodo == 0) {
		cout << "out" << endl;
		return;
	}
	else {
		cout << nodo->getNombre() << endl;
		const char* nombre1 = (char*)nombre.c_str();
		const char* nombre2 = (char*)nodo->getNombre().c_str();

		if (strcmp(nombre1, nombre2) && nodo->getNombre() == nombre) {
			cout << "Se encontraron coincidencias" << endl;
			nodo->getCanciones()->graficarPlaylist();

		}
		else if (strcmp(nombre1, nombre2) < 0) {
			//buscar por la izquierda

			cout << "buscado" << endl;
			if (nodo->getIzquierdo() != 0) {
				this->buscarPlayList(nombre, nodo->getIzquierdo());
			}

		}
		else {

			cout << "buscador" << endl;
			if (nodo->getDerecho() != 0) {
				this->buscarPlayList(nombre, nodo->getDerecho());
			}

		}
	}

}

void ArbolPlaylist::mostrarenConsola() {
	this->mostrarenConsola(this->raiz);
	//this->buscarPlayList("avanzado.json", this->raiz);
}

void ArbolPlaylist::mostrarenConsola(NodoArbolBinario* nodo) {
	if (nodo == 0) {

		return;
	}
	else {
		cout << nodo->getNombre() << endl;
		this->mostrarenConsola(nodo->getIzquierdo());
		this->mostrarenConsola(nodo->getDerecho());
	}
}

void ArbolPlaylist::reporte_playlist() {
	this->reporte_playlist(this->raiz);
}

void ArbolPlaylist::reporte_playlist(NodoArbolBinario* nodo) {
	if (nodo == 0) {
		return;
	}
	else {
		ofstream WriteFile("reportePlaylist.dot");
		WriteFile << "digraph reporte{" << endl;
		WriteFile << "node [shape = circle];" << endl;


		if (nodo->getIzquierdo() != 0) {
			//WriteFile << nodo->getNombre() << "->" << nodo->getIzquierdo()->getNombre() << endl;
			controla += nodo->getNombre()+"->" + nodo->getIzquierdo()->getNombre()+"\n";
		}
		else {
			this->reporte_playlist(nodo->getIzquierdo());
			this->reporte_playlist(nodo->getDerecho());
		}

		if (nodo->getDerecho() != 0) {
			controla += nodo->getNombre() + "->" + nodo->getDerecho()->getNombre() + "\n";

		}
		else {
			this->reporte_playlist(nodo->getIzquierdo());
			this->reporte_playlist(nodo->getDerecho());
		}
		this->reporte_playlist(nodo->getIzquierdo());
		this->reporte_playlist(nodo->getDerecho());
	//	controla += nodo->getNombre() + "->" + nodo->getIzquierdo()->getNombre() + "\n";
		//controla += nodo->getNombre() + "->" + nodo->getDerecho()->getNombre() + "\n";

		WriteFile << controla << endl;
		WriteFile << "}" << endl;
		WriteFile.close();
		system("dot -Tpng reportePlaylist.dot -o Playlist.png");
		system("Playlist.png");
		//controla = "";
		system("pause");
	}

}
ArbolPlaylist::~ArbolPlaylist()
{
}
