#include "stdafx.h"
#include "Artista.h"

void Artista::insertarOrdenado(string nombre, BibliotecaArtista* discografia) {
	NodoArtista* nuevo = new NodoArtista(nombre, discografia);

	if (this->primero == 0) {
		this->primero = nuevo;
		this->ultimo = nuevo;
	}
	else
	{
		nuevo->setSiguiente(this->primero);
		this->primero->setAnterior(nuevo);
		this->primero = nuevo;
	}
}

void Artista::insertarOrdenado(string nombre) {
	NodoArtista* nuevo = new NodoArtista(nombre);

	if (this->primero == 0) {
		this->primero = nuevo;
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void Artista::imprimirConsola() {
	if (this->primero == 0) {
		cout << "Agrega artistas para ver discografias!" << endl;
	}
	else {
		NodoArtista* aux = this->primero;
		
		while (aux != 0) {
			cout << aux->getNombre() << endl;
			aux = aux->getSiguiente();
		}
	}
}

void Artista::graficarLista() {
	if (this->primero == 0) {
		cout << "Agrega artistas para ver reporte de artista!" << endl;
	}
	else {
		NodoArtista* auxiliar = this->primero;
		ofstream WriteFile("ListaArtista.dot");
		WriteFile << "digraph listadoble{" << endl;
		WriteFile << "node[shape = square];" << endl;
		WriteFile << "rankdir = LR";
		WriteFile << "subgraph a{" << endl;
		WriteFile << "label = \"Artistas\"" << endl;
		while (auxiliar->getSiguiente() != 0) {
			WriteFile << "x" << auxiliar << "[label =\"" << auxiliar->getNombre() << "\"];" << endl;
			WriteFile << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
			WriteFile << "x" << auxiliar->getAnterior() << " ->" << "x" << auxiliar << ";" << endl;
			auxiliar = auxiliar->getSiguiente();
		}
		WriteFile << "}" << endl;
		WriteFile << "}" << endl;
		WriteFile.close();
		system("dot -Tpng ListaArtista.dot -o ReporteArtista.dot");
		system("ReporteArtista.dot");
	}
}

void Artista::buscarArtista(string nombre) {
	if (this->primero == 0) {
		cout << "No tienes artistas agregados en este momento." << endl;
	}
	else {
		NodoArtista* iterador = this->primero;

		while (true) {
			if (nombre == iterador->getNombre()) {
				this->mostrarArtista(iterador);
				break;
			}
			else if (nombre != iterador->getNombre() && iterador->getSiguiente() == 0) {
				cout << "El artista no esta dentro de tu lista de artistas!" << endl;
				break;
			}
			iterador = iterador->getSiguiente();
		}

	}
}

void Artista::mostrarArtista(NodoArtista* artista) {
	cout << "Mostrandote a tu artista favorito!" << endl;
	cout << "				MUSIC++				" << endl;
	cout << "___________________________________" << endl;
	cout << "-	" << artista->getNombre() << "" << endl;
	artista->getDiscografia()->mostrarI();
	cout << "Deseas ver el contenido de un album en especifico?" << endl;
	cout << "Puedes hacerlo escribiendo el nombre abajo. :D" << endl;
	string nombreAlbum = "";
	cin >> nombreAlbum;
	artista->getDiscografia()->buscarAlbum(nombreAlbum);
	cout << "Puedes ver su discografia si lo deseas... [S]/[N]" << endl;
	string seleccion = "";
	cin >> seleccion;
	if (seleccion == "s" || seleccion == "S" || seleccion == "SI" || seleccion == "sI") {
		artista->getDiscografia()->graficar();
	}
}

bool Artista::buscarCancion(string artista, string album, string cancion) {
	if (this->primero == 0) {
		cout << "No hay artistas." << endl; //No hay artistas
		return false;
	}
	else {
		NodoArtista* iterador = this->primero;
		while (true) {
			if (artista == iterador->getNombre()) {
				break;
			}
			else if (iterador == 0) {
				return false; // No existe el artista
			}
			iterador = iterador->getSiguiente();//Itera hasta encontrar, o no, al artista.
		}
		return iterador->getDiscografia()->buscarCancion(album,cancion);
	}
	return false;
}

