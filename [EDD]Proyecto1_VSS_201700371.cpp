// [EDD]Proyecto1_VSS_201700371.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <array>
#include <list>

#include "json.hpp"

using json = nlohmann::json;

using namespace std;
void cargaArchivos();
void biblioteca();
void playList();

void menu_principal() {
	system("cls");
	bool validador = true;
	int seleccion = 0;

	while (validador) {
		cout << "------------------------MUSIC++------------------------" << endl;
		cout << "1. Cargar archivo." << endl;
		cout << "2. Biblioteca." << endl;
		cout << "3. Playlist." << endl;
		cout << "Ingrese el numero de su selección." << endl;
		try
		{
			cin >> seleccion;
		}
		catch (const std::exception&)
		{
			system("cls");
			cout << "No ingresar caracteres diferentes a numeros, por favor." << endl;
			menu_principal();
		}
		switch (seleccion)
		{
		case 1:
			cargaArchivos();
			break;
		case 2:
			biblioteca();
			break;
		case 3:
			playList();
			break;
		default:
			break;
			break;
		}
	}
}

void cargaArchivos() {
	system("cls");
	bool validador = true;
	int seleccion = 0;
	while (validador) {
		system("cls");
		cout << "Seccion de carga de archivos JSON." << endl;
		cout << "----------------------------------" << endl;
		cout << "1. Archivo de PlayList." << endl;
		cout << "2. Archivo de Biblioteca." << endl;
		cout << "3. Regresar al menu principal." << endl;
		cin >> seleccion;

		if (seleccion == 1) {
			string nombre_archivo = "";
			cout << "Ingrese nombre de la PlayList.json" << endl;
			cin >> nombre_archivo;
			ifstream reader(nombre_archivo);
			json j;
			reader >> j;
			reader.close();


			for (json::iterator it = j.begin(); it != j.end(); ++it) {
				//std::cout << it.key() << " : " << it.value() << "\n";

				if (it.value() == "Stack") {
					//Stack generica
					for (const auto& el : j["Songs"]) {
						cout << el["Year"] << endl;
						cout << el["Album"] << endl;
						cout << el["Song"] << endl;
						cout << el["Artist"] << endl;
					}
				}
				else if (it.value() == "Queque") {
					//Queque generica
					for (const auto& el : j["Songs"]) {
						cout << el["Year"] << endl;
						cout << el["Album"] << endl;
						cout << el["Song"] << endl;
						cout << el["Artist"] << endl;

					}
				}
				else if (it.value() == "Shuffle") {
					//Doble enlazada
					for (const auto& el : j["Songs"]) {
						cout << el["Year"] << endl;
						cout << el["Album"] << endl;
						cout << el["Song"] << endl;
						cout << el["Artist"] << endl;

					}
				}
				else if (it.value() == "Circular") {
					//Doble enlazada circular
					for (const auto& el : j["Songs"]) {
						cout << el["Year"] << endl;
						cout << el["Album"] << endl;
						cout << el["Song"] << endl;
						cout << el["Artist"] << endl;

					}
				}

			}



			system("pause");

		}
		else if (seleccion == 2) {
			string nombre_archivo = "";
			cout << "Ingrese nombre de la Libreria.json" << endl;
			cin >> nombre_archivo;
			ifstream reader(nombre_archivo);
			json j;
			reader >> j;
			reader.close();
			for (const auto& el : j["Library"]) {
				cout << el["Artist"]["Name"] << endl;
				for (const auto& ell : el["Artist"]["Albums"]) {
					cout << ell["Name"] << endl;
					cout << ell["Year"] << endl;
					cout << ell["Month"] << endl;
					for (const auto& elll : ell["Songs"]) {
						cout << elll["Name"] << endl;
						cout << elll["File"] << endl;
						cout << elll["Rating"] << endl;
					}
				}
			
			}



			system("pause");

		}
		else if (seleccion == 3) {
			menu_principal();
		}
	}

}

void biblioteca() {
	//Código para insertar los datos del cubo disperso
	bool validador = true;
	int seleccion = 0;

	while (validador) {
		cout << "1. Artista." << endl;
		cout << "2. Archivo de Biblioteca." << endl;
		cout << "3. Regresar al menu principal." << endl;
		cin >> seleccion;

		switch (seleccion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}

void playList() {
	//Ingeniarlas para que sirva la lista doble-enlazada
}

int main()
{


	menu_principal();
	return 0;
}

