#pragma once
#include <string>
#include <stdlib.h>

using namespace std;
class Cancion
{
	class NodoCancion {
	private:
		NodoCancion* siguiente;
		NodoCancion* anterior;
		string name;
		string file;
		float rating;
	public:
		NodoCancion(string name, string file, float rating) {
			this->siguiente = 0;
			this->anterior = 0;
			this->name = name;
			this->file = file;
			this->rating = rating;
		}
		NodoCancion* getSiguiente() {
			return this->siguiente;
		}
		NodoCancion* getAnterior() {
			return this->anterior;
		}
		string getName() {
			return this->name;
		}
		string getFile() {
			return this->file;
		}
		float getRating() {
			return this->rating;
		}

		void setSiguiente(NodoCancion* nuevo) {
			this->siguiente = nuevo;
		}
		void setAnteior(NodoCancion* nuevo) {
			this->anterior = nuevo;
		}
		void setName(string nombre) {
			this->name = nombre;
		}
		void setFile(string archivo) {
			this->file = archivo;
		}
		void setRating(float valor) {
			this->rating = valor;
		}
	};

private:
	NodoCancion* primero;
	char* p[] = "";
	NodoCancion* ultimo;
public:
	Cancion() {
		this->primero = 0;
		this->ultimo = 0;
	}
	void insertar();
};

