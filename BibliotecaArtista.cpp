#include "stdafx.h"
#include "BibliotecaArtista.h"

NodoBiblio* BibliotecaArtista::buscarMes(string mes) {//Buscar fila
	NodoBiblio* temp = raiz;

	while (temp != 0) {
		if (temp->month == mes) {
			return temp;
		}
		temp = temp->abajo;

	}
	return 0;
}

NodoBiblio* BibliotecaArtista::buscarAño(int año) {//Buscar columna
	NodoBiblio* temp = raiz;
	while (temp != 0) {
		if (temp->año == año) {
			return temp;
			break;
		}
		temp = temp->siguiente;

	}
	return 0;
}



NodoBiblio* BibliotecaArtista::insertarAño(NodoBiblio* nuevo, NodoBiblio* cabecera) {//insertar columna
	NodoBiblio* aux = cabecera;
	bool condicion = false;
	while (true) {
		if (aux->año == nuevo->año) {
			aux->month = nuevo->month;
			aux->album = nuevo->album;
			return aux;
		}
		else if (aux->año > nuevo->año)
		{
			condicion = true;
			break;
		}
		if (aux->siguiente != 0)
		{
			aux = aux->siguiente;

		}
		else {
			break;
		}
	}
	if (condicion) {
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
	const char* a = (char*)aux->month.c_str();
	const char* b = (char*)nuevo->month.c_str();
	while (true) {
		if (strcmp(a, b) == 0) {
			aux->año = nuevo->año;
			aux->album = nuevo->album;
			return nuevo;
			//unicamente si el mes esta repetido
		}

		if (aux->abajo != 0) {
			aux = aux->abajo;
		}
		else {
			break;
		}

	}

	aux->abajo = nuevo;
	nuevo->arriba = aux;


	return nuevo;
}



NodoBiblio* BibliotecaArtista::crearAño(int año) {//Crear columna
	NodoBiblio* cabezaColumna = raiz;

	NodoBiblio* aux = new NodoBiblio("0", año, new Album("a", "a", "a", año, new Cancion()));

	NodoBiblio* columna = insertarAño(aux, cabezaColumna);
	return columna;
}

NodoBiblio* BibliotecaArtista::crearMes(string mes) {//Crear fila
	NodoBiblio* cabezaFila = raiz;

	NodoBiblio* aux = new NodoBiblio(mes, 0, new Album("a", mes, "a", 0, new Cancion()));

	NodoBiblio* fila = insertarMes(aux, cabezaFila);

	return fila;
}






void BibliotecaArtista::insertar(string mes, int año, Album* album) {
	NodoBiblio* nuevo = new NodoBiblio(mes, año, album);
	NodoBiblio* nodoAño = buscarAño(año);
	NodoBiblio* nodoMes = buscarMes(mes);

	if (nodoAño == 0 && nodoMes == 0) {
		nodoAño = this->crearAño(año);
		nodoMes = this->crearMes(mes);
		nuevo = insertarAño(nuevo, nodoAño);
		nuevo = insertarMes(nuevo, nodoMes);
		return;
	}
	else if (nodoAño != 0 && nodoMes == 0) {
		nodoMes = this->crearMes(mes);
		nuevo = insertarMes(nuevo, nodoMes);
		nuevo = insertarAño(nuevo, nodoAño);
		return;
	}
	else if (nodoAño == 0 && nodoMes != 0) {
		nodoAño = this->crearAño(año);
		nuevo = insertarMes(nuevo, nodoMes);
		nuevo = insertarAño(nuevo, nodoAño);
		return;
	}
	else if (nodoAño != 0 && nodoMes != 0) {
		nuevo = insertarMes(nuevo, nodoMes);
		nuevo = insertarAño(nuevo, nodoAño);
		return;
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
		while (temporal != 0)
		{
			cout << temporal->año << endl;

			temporal2 = temporal;
			while (temporal2 != 0)
			{
				cout << temporal->album->getNombre() << endl;
				temporal2 = temporal2->siguiente;
			}

			temporal = temporal->abajo;
		}
	}
}

void BibliotecaArtista::mostrarI() {
	if (this->raiz != 0) {
		NodoBiblio* columna = this->raiz;
		while (columna != 0) {
			cout << columna->año << " " << columna->month << " " << columna->album->getNombre() << endl;
			NodoBiblio* dato = columna->siguiente;
			while (dato != 0) {
				cout << "Name album: " << dato->album->getNombre() << endl;
				dato = dato->siguiente;
			}
			columna = columna->abajo;
		}
	}
}

void BibliotecaArtista::buscarAlbum(string nombre_album) {
	if (this->raiz == 0) {
		cout << "No hay nada hecho por este artista :(, que sad." << endl;
	}
	else {
		NodoBiblio* temporal = this->raiz->abajo;
		NodoBiblio* temporal2 = 0;
		Cancion* canciones = 0;
		while (temporal != 0) {
			temporal2 = temporal;
			while (temporal2 != 0) {
				if (temporal->album->getNombre() == nombre_album) {

					//cout << temporal->album->getNombre();
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

void BibliotecaArtista::graficar() {

	ofstream WriteFile("Discografia.dot");
	WriteFile << "digraph discografia{" << endl;
	WriteFile << "node [shape = rectangle]" << endl;
	
	bool vali = true;
	int grupo = 1;

	NodoBiblio* temporal1 = this->raiz;
	NodoBiblio* temporal2 = this->raiz;
	NodoBiblio* constante = this->raiz;
	WriteFile << "x" << temporal1 << "[label = \"" << temporal1->month << "\", width = 1.5, group = 1];" << endl;
	WriteFile << "e0[ shape = point, width = 0 ];" << endl;
	WriteFile << "e1[ shape = point, width = 0 ];" << endl;

	while (temporal1 != 0)
	{
		if (temporal1->arriba != 0) {
			grupo = grupo + 1;
			WriteFile << "x" << temporal1 << "[label = \"" << temporal1->month << "\", width = 1.5, group = 1];" << endl;
		}

		WriteFile << endl;
		WriteFile << endl;
		temporal1 = temporal1->abajo;
	}
	temporal1 = this->raiz;

	while (temporal1 != 0) {
		if (temporal1->abajo == 0) {
			//WriteFile << "x" << temporal1 << "->x" << temporal1->arriba << endl;

		}
		else {
			if (temporal1->arriba != 0) {

				WriteFile << "x" << temporal1 << "->x" << temporal1->arriba << endl;
			}
			WriteFile << "x" << temporal1 << "->x" << temporal1->abajo << endl;
		}
		temporal1 = temporal1->abajo;
	}


	while (temporal2 != 0) {

		if (temporal2->siguiente != 0 && temporal2->anterior == 0) {
			WriteFile << "x" << temporal2 << "[label = \"" << temporal2->month << "\", width = 1.5, group = 1];" << endl;
		}
		else if (temporal2->siguiente != 0 && temporal2->anterior != 0) {
			grupo = grupo + 1;
			WriteFile << "x" << temporal2 << "[label = \"" << temporal2->año << "\", width = 1.5, group = " << grupo << "];" << endl;
		}
		temporal2 = temporal2->siguiente;
	}
	temporal2 = this->raiz;

	while (temporal2 != 0) {

		if (temporal2->siguiente == 0) {
			WriteFile << "x" << temporal2 << "->x" << temporal2->anterior << endl;
		}
		else {

			WriteFile << "x" << temporal2 << "->x" << temporal2->siguiente << endl;

		}

		temporal2 = temporal2->siguiente;
	}

	temporal2 = this->raiz;
	string anidador = "";

	WriteFile << "{rank = same; Root" << endl;
	while (temporal2 != 0) {
		WriteFile << "; x" << temporal2 << endl;
		temporal2 = temporal2->siguiente;
	}
	WriteFile << "}" << endl << endl;

	grupo = 0;
	temporal1 = this->raiz;
	while (temporal1 != 0) {
		grupo = grupo + 1;
		WriteFile << temporal1->album->getNombre() << "[label = \"" << temporal1->album->getNombre() << "\", group = " << grupo << "]" << endl;
		temporal1 = temporal1->siguiente;
	}
	while (temporal2 != 0) {
		WriteFile << temporal2->album->getNombre() << "[label = \"" << temporal2->album->getNombre() << "\", group = 1]" << endl;
		temporal1 = temporal2->abajo;
	}

	temporal2 = this->raiz;
	temporal1 = this->raiz;

	while (temporal1 != 0) {
		WriteFile << "x" << temporal1 << "-> " << temporal1->album->getNombre() << endl;
		temporal1 = temporal1->siguiente;
	}

	while (temporal2 != 0) {
		WriteFile << "x" << temporal2 << "-> " << temporal2->album->getNombre() << endl;
		//WriteFile << "{rank = same; x" << temporal2 << "; " << temporal2->album->getNombre() << "}" << endl;
		temporal2 = temporal2->abajo;
	}
	temporal2 = this->raiz;
	while (temporal2 != 0) {
		//WriteFile << "x" << temporal2 << "-> " << temporal2->album->getNombre() << endl;
		WriteFile << "{rank = same; x" << temporal2 << "; " << temporal2->album->getNombre() << "}" << endl;
		temporal2 = temporal2->abajo;
	}

	temporal2 = this->raiz;
	temporal1 = this->raiz;



	WriteFile << "}" << endl;
	WriteFile.close();
	system("dot -Tpng Discografia.dot -o Discografia.png");
	system("Discografia.png");
}

bool BibliotecaArtista::buscarCancion(string album, string nombre) {
	bool retorno = false;
	if (this->raiz != 0) {
		NodoBiblio* columna = this->raiz;
		while (columna != 0)
		{
			NodoBiblio* dato = columna->siguiente;
			while (dato != 0) 
			{
				if(album == dato->album->getNombre())
				{
					return true;
				}
				dato = dato->siguiente;
			}
			columna = columna->abajo;
		}
		return false;
	}
	else {
		return false;
	}
}