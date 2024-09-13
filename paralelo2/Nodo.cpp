#include "Nodo.h"
#include <iostream>

Nodo::Nodo(int dato){
    this -> dato = dato;
    this -> sig = nullptr;
}
int Nodo::getDato(){
    return this -> dato;
}
Nodo* Nodo::getSiguiente(){
    return this -> sig;
}
void Nodo::setDato(int dato){
    this -> dato = dato;
}
void Nodo::setSiguiente(Nodo* sig){
    this -> sig = sig;
}
Nodo::~Nodo(){
    std::cout<<"Se destruye el nodo cono valor: "<<this -> dato<<std::endl;
}

