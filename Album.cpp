#include "stdafx.h"
#include "Album.h"


string Album::getNombre() {
	return this->nombre;
}
string Album::getFile() {
	return this->file;
}
string Album::getMonth() {
	return this->month;
}
int Album::getYear() {
	return this->year;
}

Cancion* Album::getCanciones() {
	return this->canciones;
}

void Album::setCanciones(Cancion* canciones) {
	this->canciones = canciones;
}

void Album::setMonth(string mes) {
	this->month = mes;
}
void Album::setFile(string file) {
	this->file = file;
}
void Album::setNombre(string name) {
	this->nombre = name;
}
void Album::setYear(int year) {
	this->year = year;
}
