#pragma once
#include <iostream>

class Nodo{
    private:
        int dato;
        Nodo* sig;
    public:
        Nodo(int dato);
        int getDato();
        void setDato(int dato);
        Nodo* getSiguiente();
        void setSiguiente(Nodo* sig);
        ~Nodo();
};