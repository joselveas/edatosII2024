#pragma once
#include <iostream>

class Nodo{
    private:
        int dato;
        Nodo* sig;
    public:
        Nodo(int dato);
        int getDato();
        Nodo* getSiguiente();
        void setDato(int dato);
        void setSiguiente(Nodo* sig);
        ~Nodo();
};