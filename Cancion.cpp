#include "stdafx.h"
#include "Cancion.h"


void Cancion::insertarAlbum(string name, string file, float rating) {
	NodoCancion* nuevo = new NodoCancion(name, file, rating);

	if (this->primero == 0) {
		this->primero = new NodoCancion(name, file, rating);
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void Cancion::insertarPlaylist(string tipo, string name, string album, string artista) {
	NodoCancion* nuevo = new NodoCancion(name, tipo, album, artista);

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

void Cancion::graficarPlaylist() {
	if (this->primero == 0) {
		cout << "No tienes musica para mostrar :(." << endl;
	}
	else {
		//this->primero->getTipo() == "Stack"

		if (this->primero->getTipo() == "Stack") {

			NodoCancion* auxiliar = this->primero;

			ofstream WriteFile("ListaReproduccion.dot");
			WriteFile << "digraph listaR{" << endl;
			WriteFile << "node [shape = plaintext]" << endl;
			WriteFile << "nod[" << endl;
			WriteFile << "label = <" << endl;
			WriteFile << "<table border = \"0\" cellborder = \"1\" cellspacing = \"0\">" << endl;
			WriteFile << "<tr><td> </td></tr>" << endl;
			while (auxiliar != 0) {
				WriteFile << "<tr><td>"<< auxiliar->getName()<<", "<< auxiliar->getArtista() <<"</td></tr>" << endl;
				auxiliar = auxiliar->getSiguiente();
			}
			WriteFile << "</table>>" << endl;
			WriteFile << "];" << endl;
			WriteFile << "}" << endl;
			WriteFile.close();
			system("dot -Tpng ListaReproduccion.dot -o Reproduccion.png");
			system("Reproduccion.png");
		}
		else if (this->primero->getTipo() == "Queque") {
			NodoCancion* auxiliar = this->primero;

			ofstream WriteFile("ListaReproduccion.dot");
			WriteFile << "digraph listaR{" << endl;
			WriteFile << "node[shape = square];" << endl;
			WriteFile << "rankdir = LR;" << endl;
			while (auxiliar != 0) {
				WriteFile << "x" << auxiliar << "[label =\"" << auxiliar->getName() << "\"];" << endl;
				WriteFile << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
				auxiliar = auxiliar->getSiguiente();
			}
			WriteFile << "}" << endl;
			WriteFile.close();
			system("dot -Tpng ListaReproduccion.dot -o Reproduccion.png");
			system("Reproduccion.png");

		}
		else if (this->primero->getTipo() == "Shuffle") {
			//Graficar lista desordenada
		}
		else if (this->primero->getTipo() == "Circular") {
			
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
		WriteFile << "}" << endl;
		WriteFile.close();
		system("dot -Tpng ListaCanciones.dot -o simplecanciones.png");
		system("simplecanciones.png");
	}
}

void Cancion::mostrarCancionesAlbum() {
	if (this->primero == 0) {
		cout << "No existen canciones dentro de este album." << endl;
	}
	else {
		NodoCancion* auxiliar = this->primero;
		int contador = 0;
		while (auxiliar != 0)
		{
			cout << contador << ". "<< auxiliar->getName() << endl;
			auxiliar = auxiliar->getSiguiente();
		}
		cout << "Gracias por utilizar Music++" << endl;
	}
}

void Cancion::mostrarCancionesPlaylist() {
	if (this->primero == 0) {
		cout << "No existen canciones dentro de este album." << endl;
	}
	else {
		NodoCancion* auxiliar = this->primero;
		
	}
}