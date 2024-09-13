#include <iostream>
#include "Nodo.h"
Nodo* buscarNodo(Nodo* head, int dato){
    Nodo* aux = head;
    while(aux != nullptr){
        if(aux -> getDato() == dato){
            return aux;
        }
        aux = aux -> getSiguiente();
    }
    return nullptr;
}
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
    aux2 ->setSiguiente(aux -> getSiguiente());
    delete aux;
    return head;

}
Nodo* insertarNodo(Nodo* head, int dato){
    Nodo* nuevo = new Nodo(dato);
    if(head == nullptr){return nuevo;}
    if(head -> getDato() > dato){
        nuevo -> setSiguiente(head);
        return nuevo;
    }
    Nodo* aux = head -> getSiguiente();
    Nodo* aux2 = head;
    while(aux != nullptr){
        if(aux -> getDato() > dato){
            nuevo -> setSiguiente(aux);
            aux2 -> setSiguiente(nuevo);
            return head;
        }
        aux2 = aux;
        aux = aux -> getSiguiente();
    }
    aux2 -> setSiguiente(nuevo);
    return head;

}
void imprimirLista(Nodo* head){
    Nodo* aux = head;
    while(aux != nullptr){
        std::cout<<aux -> getDato()<<" ";
        aux = aux -> getSiguiente();
    }
    std::cout<<std::endl;
    return;
}
Nodo* ordenarLista(Nodo* head){
    if(head == nullptr){return head;}
    Nodo* newHead = new Nodo(head -> getDato());
    Nodo* nuevaLista = eliminarNodo(head, head->getDato());
    if(nuevaLista == nullptr){return newHead;}
    Nodo* aux = nuevaLista -> getSiguiente();
    while(aux != nullptr){
        
    }
}
int main(){
    Nodo* n1 = new Nodo(15);
    Nodo* n2 = new Nodo(5);
    Nodo* n3 = new Nodo(20);
    n1 -> setSiguiente(n2);
    n2 -> setSiguiente(n3);
    imprimirLista(n1);
    Nodo* aux = insertarNodo(n1, 20);
    imprimirLista(aux);
    aux = eliminarNodo(aux, 20);
    imprimirLista(aux);
    return 0;
}