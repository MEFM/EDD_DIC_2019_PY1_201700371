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
		int año;
		string mes;

		NodoDisperso(T dato, int año, string mes) {
			this->izquierda = 0;
			this->derecha = 0;
			this->arriba = 0;
			this->abajo = 0;
			this->front = 0;
			this->back = 0;
			this->dato = dato;
			this->año = año;
			this->mes = mes;
		}
	};

	CuboDisperso() { this->raiz = new NodoDisperso(0, -1, "Raiz"); }
	void insertar(T dato, int año, string mes);

	//buscar cabecera 
	NodoDisperso * buscarAno(int año) {
		NodoDisperso *auxiliar = this->raiz;
		while (this->raiz != 0) {
			if (auxiliar->año == año) {
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
	
	//Insertar mes y ordenar año
	void insertarAnoO(NodoDisperso* nuevo, NodoDisperso * cabeceraM) {
		if (this->raiz == 0) {

		}
	}
	void insertarMes(NodoDisperso* nuevo) {
		if (this->raiz == 0) {

		}
	}


	//Crear cabeceras
	NodoDisperso* crearAno(int año) {
		NodoDisperso* nuevoA = new NodoDisperso(0, año, "cabezera");
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
void CuboDisperso<T>::insertar(T dato, int año, string mes) {
	if (this->buscarAno(año) == 0 && this->buscarMes(mes) == 0) {
		//Crear año y mes cabeceras
		this->insertarAnoO(this->crearAno(año));
		this->insertarMes(this->crearMes(mes));
	}
	else if (this->buscarAno(año) == 0 && this->buscarMes(mes) != 0) {
		this->insertarAnoO(this->crearAno(año));
		this->insertarMes(this->buscarMes(mes));
	}
	else if (this->buscarAno(año) != 0 && this->buscarMes(mes) == 0) {
		this->insertarAnoO(this->buscarAno(año));
		this->insertarMes(this->buscarMes(mes));
	}
	else if (this->buscarAno(año) != 0 && this->buscarMes(mes) != 0) {
		this->insertarAnoO(this->buscarAno(año));
		this->insertarMes(this->buscarMes(mes));
	}
}

