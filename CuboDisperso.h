#pragma once
#include <string>


using namespace std;
template<class T>

class CuboDisperso
{
	

private:
	NodoDisperso * raiz;
public:
	class NodoDisperso {
	public:
		NodoDisperso * izquierda;
		NodoDisperso * derecha;
		NodoDisperso * arriba;
		NodoDisperso * abajo;
		NodoDisperso * front;
		NodoDisperso * back;
		T dato;
		int a�o;
		string mes;

		NodoDisperso(T dato, int a�o, string mes) {
			this->izquierda = 0;
			this->derecha = 0;
			this->arriba = 0;
			this->abajo = 0;
			this->front = 0;
			this->back = 0;
			this->dato = dato;
			this->a�o = a�o;
			this->mes = mes;
		}
	};

	CuboDisperso() { this->raiz = new NodoDisperso(0, -1, "Raiz"); }
	void insertar(T dato, int a�o, string mes);

	//buscar cabecera 
	NodoDisperso * buscarAno(int a�o) {
		NodoDisperso *auxiliar = this->raiz;
		while (this->raiz != 0) {
			if (auxiliar->a�o == a�o) {
				return auxiliar;
			}
			
			auxiliar = auxiliar->siguiente;
		}
		return 0;
	}
	NodoDisperso * buscarMes(string mes) {
		NodoDisperso * auxiliar = this->raiz;
		while (this->raiz != 0) {
			if (auxiliar->mes.equals(mes)) {
				return auxiliar;
			}
			auxiliar = auxiliar->abajo;
		}
		return 0;
	}
	
	//Insertar mes y ordenar a�o
	void insertarAnoO(NodoDisperso* nuevo, NodoDisperso * cabeceraM) {
		if (this->raiz == 0) {

		}
	}
	void insertarMes(NodoDisperso* nuevo) {
		if (this->raiz == 0) {

		}
	}


	//Crear cabeceras
	NodoDisperso* crearAno(int a�o) {
		NodoDisperso* nuevoA = new NodoDisperso(0, a�o, "cabezera");
		this->insertarMes(nuevoA);
		return nuevoA;
	}
	NodoDisperso* crearMes(string mes) {
		NodoDisperso* nuevoM = new NodoDisperso(0, -1, mes);
		this->insertarAnoO(nuevoM);
		return nuevoM;
	}

};

template<class T>
void CuboDisperso<T>::insertar(T dato, int a�o, string mes) {
	if (this->buscarAno(a�o) == 0 && this->buscarMes(mes) == 0) {
		//Crear a�o y mes cabeceras
		this->insertarAnoO(this->crearAno(a�o));
		this->insertarMes(this->crearMes(mes));
	}
	else if (this->buscarAno(a�o) == 0 && this->buscarMes(mes) != 0) {
		this->insertarAnoO(this->crearAno(a�o));
		this->insertarMes(this->buscarMes(mes));
	}
	else if (this->buscarAno(a�o) != 0 && this->buscarMes(mes) == 0) {
		this->insertarAnoO(this->buscarAno(a�o));
		this->insertarMes(this->buscarMes(mes));
	}
	else if (this->buscarAno(a�o) != 0 && this->buscarMes(mes) != 0) {
		this->insertarAnoO(this->buscarAno(a�o));
		this->insertarMes(this->buscarMes(mes));
	}
}

