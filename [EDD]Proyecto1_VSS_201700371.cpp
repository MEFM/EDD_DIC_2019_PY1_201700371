// [EDD]Proyecto1_VSS_201700371.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* strtof */
#include <conio.h>
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <array>
#include <list>
#include "ArbolPlaylist.h"
#include "Artista.h"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;
void cargaArchivos();
void biblioteca();
void playList();

ArbolPlaylist* arbolIngreso = new ArbolPlaylist();

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
			Cancion* canciones = new Cancion();

			for (json::iterator it = j.begin(); it != j.end(); ++it) {
				//std::cout << it.key() << " : " << it.value() << "\n";

				if (it.value() == "Stack") {
					//Stack generica
					for (const auto& el : j["Songs"]) {
						string año = el["Year"];
						int year = stoi(año, nullptr, 10);
						string album = el["Album"];
						string cancion = el["Song"];
						string artista = el["Artist"];
						canciones->insertarPlaylist("Stack", cancion, album, artista);
						arbolIngreso->insertar(nombre_archivo, canciones);

					}
				}
				else if (it.value() == "Queque") {
					//Queque generica
					for (const auto& el : j["Songs"]) {

						string año = el["Year"];
						int year = stoi(año, nullptr, 10);
						string album = el["Album"];
						string cancion = el["Song"];
						string artista = el["Artist"];
						canciones->insertarPlaylist("Queque", cancion, album, artista);
						arbolIngreso->insertar(nombre_archivo, canciones);

					}
				}
				else if (it.value() == "Shuffle") {
					//Doble enlazada
					for (const auto& el : j["Songs"]) {
						string año = el["Year"];
						int year = stoi(año, nullptr, 10);
						string album = el["Album"];
						string cancion = el["Song"];
						string artista = el["Artist"];
						canciones->insertarPlaylist("Shuffle", cancion, album, artista);
						arbolIngreso->insertar(nombre_archivo, canciones);

					}
				}
				else if (it.value() == "Circular") {
					//Doble enlazada circular
					for (const auto& el : j["Songs"]) {
						string año = el["Year"];
						int year = stoi(año, nullptr, 10);
						string album = el["Album"];
						string cancion = el["Song"];
						string artista = el["Artist"];
						canciones->insertarPlaylist("Circular", cancion, album, artista);
						arbolIngreso->insertar(nombre_archivo, canciones);


					}
				}

			}


			canciones->graficarPlaylist();


		}
		else if (seleccion == 2) {
			//Hay solo un nodo artista
			string nombre_archivo = "";
			cout << "Ingrese nombre de la Libreria.json" << endl;
			cin >> nombre_archivo;
			ifstream reader(nombre_archivo);
			json j;
			reader >> j;
			reader.close();
			Artista* artista = new Artista();
			BibliotecaArtista* biblioteca = new BibliotecaArtista();
			Album* album;
			string nombreArtista;
			string nombreAlbum;
			string año;
			int year;
			string mes;
			string nombreCancion;
			string file;
			string rat;
			float rating = strtof(rat.c_str(), 0);
			for (const auto& el : j["Library"]) {

				//biblioteca = new BibliotecaArtista();

				nombreArtista = el["Artist"]["Name"].get<string>();
				for (const auto& ell : el["Artist"]["Albums"]) {
					Cancion* canciones = new Cancion();
					/*IMPORTANTE*/
					/*Album es el nodo de CuboDisperso*/
					año = ell["Year"].get<string>();
					nombreAlbum = ell["Name"].get<string>();
					mes = ell["Month"].get<string>();
					year = atoi(año.c_str());

					for (const auto& elll : ell["Songs"]) {
						//Atributos cancion, constructor secundario
						nombreCancion = elll["Name"].get<string>();
						file = elll["File"].get<string>();
						rat = elll["Rating"].get<string>();
						rating = strtof(rat.c_str(), 0);
						canciones->insertarAlbum(nombreCancion, file, rating);
					}

					album = new Album(nombreAlbum, mes, file, year, canciones);
					biblioteca->insertar(mes, year, album);
					cout << "---------------"<<nombreArtista<<"--------------" << endl;
					cout << "-----------------------------" << endl;

					biblioteca->imprimir();
					


				}
				artista->insertarOrdenado(nombreArtista, biblioteca);
				
				//artista->getDisco()->imprimir();


			}
			artista->imprimirConsola();


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
			validador = false;
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

