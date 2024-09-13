#include <iostream>
#include "Nodo.h"

Nodo::Nodo(int dato){this -> dato = dato;this -> sig = nullptr;}
int Nodo::getDato(){return this -> dato;}
void Nodo::setDato(int dato){this -> dato = dato;}
Nodo* Nodo::getSiguiente(){return this -> sig;}
void Nodo::setSiguiente(Nodo* sig){this -> sig = sig;}
Nodo::~Nodo(){std::cout<<"Se destruye el nodo con valor: "<<this->dato<<std::endl;}