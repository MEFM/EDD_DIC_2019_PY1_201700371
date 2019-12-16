#include "stdafx.h"
#include "BibliotecaArtista.h"

NodoBiblio* BibliotecaArtista::crearA�o(int a�o) {//Crear columna
	NodoBiblio* year = this->raiz;
	NodoBiblio* auxiliar = new NodoBiblio("", a�o, 0);

	NodoBiblio* anio = this->insertarA�o(auxiliar, year);
	return anio;
}

NodoBiblio* BibliotecaArtista::crearMes(string mes) {//Crear fila
	NodoBiblio* month = this->raiz;
	NodoBiblio* auxiliar = new NodoBiblio(mes, -1, 0);

	NodoBiblio* newMes = this->insertarMes(auxiliar, month);
	return newMes;
}

NodoBiblio* BibliotecaArtista::buscarA�o(int a�o) {//Buscar columna
	NodoBiblio* temporal = this->raiz;
	while (temporal != 0) {
		if (temporal->a�o = a�o) {
			return temporal;
		}
		temporal = temporal->siguiente;
	}
	return 0;
}

NodoBiblio* BibliotecaArtista::buscarMes(string mes) {//Buscar fila
	NodoBiblio* temporal = this->raiz;
	while (temporal != 0) {
		if (temporal->month == mes) {
			return temporal;
		}
		temporal = temporal->abajo;
	}
	return 0;
}

NodoBiblio* BibliotecaArtista::insertarA�o(NodoBiblio* nuevo, NodoBiblio* cabecera) {//insertar columna
	NodoBiblio* aux = cabecera;
	bool validador = false;

	while (true) {
		if (aux->a�o == nuevo->a�o) {
			aux->month = nuevo->month;
			aux->album = nuevo->album;
			return aux;
		}
		else if (aux->a�o > nuevo->a�o) {
			validador = true;
			break;
		}
		if (aux->siguiente != 0) {
			aux = aux->siguiente;
		}
		else {
			break;
		}
	}

	if (validador) {
		nuevo->siguiente = aux;
		aux->anterior->siguiente = nuevo;
		nuevo->anterior = aux->anterior;
		aux->anterior = nuevo;
	}
	else {
		aux->siguiente = nuevo;
		nuevo->anterior = aux;
	}
	return nuevo;
}

NodoBiblio* BibliotecaArtista::insertarMes(NodoBiblio* nuevo, NodoBiblio* cabecera) {//insertar fila
	NodoBiblio* aux = cabecera;
	bool validador = false;

	while (true) {
		if (aux->month == nuevo->month) {
			aux->a�o = nuevo->a�o;
			aux->album = nuevo->album;
			return nuevo;
			//unicamente si el mes esta repetido
		}
		else {
			validador = true;
		}
		if (aux->siguiente != 0) {
			aux = aux->abajo;
		}
		else {
			break;
		}
	}
	if (!validador) {
		aux->abajo = nuevo;
		nuevo->arriba = aux;
	}
	return nuevo;
}

void BibliotecaArtista::insertar(string mes, int a�o, Album* album) {
	NodoBiblio* nuevo = new NodoBiblio(mes, a�o, album);

	if (this->buscarA�o(a�o) == 0 && this->buscarMes(mes) == 0) {

		this->insertarA�o(nuevo, this->crearA�o(a�o));
		this->insertarMes(nuevo, this->crearMes(mes));
	}
	else if (this->buscarA�o(a�o) != 0 && this->buscarMes(mes) == 0) {

		this->insertarMes(nuevo, this->crearMes(mes));
		this->insertarA�o(nuevo, this->buscarA�o(a�o));
	}
	else if (this->buscarA�o(a�o) == 0 && this->buscarMes(mes) != 0) {

		this->insertarMes(nuevo, this->buscarMes(mes));
		this->insertarA�o(nuevo, this->crearA�o(a�o));
	}
	else if (this->buscarA�o(a�o) != 0 && this->buscarMes(mes) != 0) {

		this->insertarMes(nuevo, this->buscarMes(mes));
		this->insertarA�o(nuevo, this->buscarA�o(a�o));
	}
}

void BibliotecaArtista::imprimir() {
	if (this->raiz == 0) {
		cout << "Lamentablemente este artista no tiene discografia disponible. :((" << endl;
	}
	else {
		NodoBiblio* temporal = this->raiz;
		NodoBiblio* temporal2 = 0;
		int numerador = 1;
		while (temporal != 0) {
			temporal2 = temporal;
			while (temporal2 != 0) {
				cout << temporal->album->getNombre() << endl;
				temporal2 = temporal->siguiente;
			}
			temporal = temporal->abajo;
		}
	}
}

void BibliotecaArtista::buscarAlbum(string nombre_album) {
	if (this->raiz == 0) {
		cout << "No hay nada hecho por este artista :(, que sad." << endl;
	}
	else {
		NodoBiblio* temporal = this->raiz;
		NodoBiblio* temporal2 = 0;
		Cancion* canciones = 0;
		while (temporal != 0) {
			temporal2 = temporal;
			while (temporal2 != 0) {
				if (temporal->album->getNombre() == nombre_album) {
					//Enviar nodo para examinarlo!!!!
					cout << temporal->album->getNombre();
					canciones = temporal->album->getCanciones();
					//representante->album = temporal->album;
					break;
				}
				else if (temporal->album->getNombre() != nombre_album
					&& temporal->abajo == 0) {
					cout << "Sorry, no hay canciones para mostrar en este album." << endl;
					return;
				}
				temporal2 = temporal2->siguiente;
			}
			temporal = temporal->abajo;
		}

		cout << "Estas son las canciones del album que has elegido " << endl;
		canciones->mostrarCancionesAlbum();
		cout << "_----.----__----.----___----.----___----.----___----.----_" << endl;
	}
}