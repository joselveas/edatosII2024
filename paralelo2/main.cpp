#include <iostream>
#include "Nodo.h"
// funcion para imprimir la lista
void imprimirLista(Nodo* head){
    if(head == nullptr){return;}
    Nodo* aux = head;
    while(aux != nullptr){
        std::cout<<aux -> getDato()<<" ";
        aux = aux -> getSiguiente();
    }
    std::cout<<std::endl;
    return;
}
// funcion para buscar un nodo
Nodo* buscarNodo(Nodo* head, int dato){
    if(head == nullptr){return nullptr;}
    Nodo* aux = head;
    while(aux != nullptr){
        if(aux -> getDato() == dato){
            return aux;
        }
        aux = aux -> getSiguiente();
    }
    return nullptr;
}
// funcion para insertar un nodo en orden de menor a mayor
Nodo* insertarNodo(Nodo* head, Nodo* nuevoNodo){
    if(head == nullptr){return nuevoNodo;}
    if(nuevoNodo -> getDato() < head -> getDato()){
        nuevoNodo -> setSiguiente(head);
        return nuevoNodo;
    }
    Nodo* aux = head->getSiguiente();
    Nodo* anterior = head;
    while(aux != nullptr){
        if(aux -> getDato()> nuevoNodo -> getDato()){
            nuevoNodo -> setSiguiente(aux);
            anterior -> setSiguiente(nuevoNodo);
            return head;
        }
        anterior = aux;
        aux = aux ->getSiguiente();
    }
    anterior -> setSiguiente(nuevoNodo);
    return head;
}
// funcion para eliminar un nodo
Nodo* eliminarNodo(Nodo* head, int dato){
    Nodo* aux = buscarNodo(head, dato);
    if(aux == nullptr){return head;}
    if(aux == head){
        head = head -> getSiguiente();
        delete aux;
        return head;
    }
    Nodo* aux2 = head;
    while(aux2 -> getSiguiente() != aux){
        aux2 = aux2 -> getSiguiente();
    }
    if(aux -> getSiguiente() == nullptr){
        aux2 -> setSiguiente(nullptr);
        delete aux;
        return head;
    }
    aux2 -> setSiguiente(aux ->getSiguiente());
    delete aux;
    return head;
}
Nodo* ordenarLista(Nodo* head){
    if(head == nullptr){return nullptr;}
    Nodo* aux = head;
    Nodo* nuevaLista = nullptr;
    while(aux != nullptr){
        Nodo* aux2 = aux;
        Nodo* yameaburri = new Nodo(aux ->getDato());
        nuevaLista = insertarNodo(nuevaLista, yameaburri);
        aux = aux -> getSiguiente();
        delete aux2;
    }
    aux = head;
    return nuevaLista;
}
int main(){
    Nodo* n1 = new Nodo(8);
    Nodo* n2 = new Nodo(1);
    Nodo* n3 = new Nodo(10);
    Nodo* n4 = new Nodo(5);
    n1 -> setSiguiente(n2);
    n2 -> setSiguiente(n3);
    n3 -> setSiguiente(n4);
    Nodo* aux = ordenarLista(n1);
    imprimirLista(aux);
    return 0;
}