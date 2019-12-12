#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>

class ListaDoble {
	class Nodo {
	private:
		Nodo * siguiente;
		Nodo * anterior;
		T informacion;
	public:
		Nodo(T informacion) {
			this->siguiente = 0;
			this->anterior = 0;
			this->informacion = informacion;
		}

		Nodo *getSiguiente() {
			return this->siguiente;
		}
		Nodo *getAnterior() {
			return this->anterior;
		}
		void setSiguiente(Nodo *nuevo) {
			this->siguiente = nuevo;
		}
		void setAnterior(Nodo *nuevo) {
			this->anterior = nuevo;
		}

		T getInformacio() {
			return this->informacion;
		}
		void getInformacio(T informacion) {
			this->informacion = informacion;
		}


		
	};

private:
	Nodo * primero;
	Nodo * ultimo;
	int tamaño;
public:
	ListaDoble() {
		this->primero = this->ultimo = 0;
		this->tamaño = 0;
	}

	void insertar(T informacion);
	void mostrarInformacion();
	void graficar();
	void insertarOrdenado(T informacion);

};

template<class T>

void ListaDoble<T>::insertar(T información) {
	Nodo * nuevo = new Nodo(información);
	if (this->primero == 0) {
		this->primero = this->ultimo = nuevo;
		this->tamaño++;
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero->setAnterior(nuevo);
		this->primero = nuevo;
		this->tamaño++;
	}
}

template<class T>
void ListaDoble<T>::mostrarInformacion() {
	if (this->primero == 0) {
		cout << "Esta lista esta vacía, no hay nada para mostrar" << endl;
	}
	else {
		Nodo * auxiliar = this->primero;

		while (auxiliar != 0) {
			cout << auxiliar->getDato()<< endl;
			auxiliar = auxiliar->getSiguiente();
		}
	}
}

template<class T>
void ListaDoble<T>::graficar() {
	if (this->primero == 0) {
		cout << "Lo siento, no hay nada para mostrar" << endl;
	}
	else {
		fstream WriteFile("listaDoble.dot");
		WriteFile << "digraph lista{" << endl;
		WriteFile << "node[shape = square];" << endl;
		WriteFile << "rankdir = LR;" << endl;

		Nodo *auxiliar = this->primero;

		while (auxiliar->getSiguiente() != 0)
		{
			WriteFile << "x" << auxiliar << "[label =\"" << auxiliar->getDato() << "\"];" << endl;
			WriteFile << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
		}


		WriteFile << "}" << endl;
		WriteFile.close();
		system("dot -Tpng listaDoble.dot -o lista.png");
		system("lista.png");
	}
}

template<class T>

void ListaDoble<T>::insertarOrdenado(T informacion) {
	if (this->primero == 0) {
		this->primero = this->ultimo = new Nodo(informacion);
	}
	else {
		char* palabra1;
		char* palabra2;


	}
}