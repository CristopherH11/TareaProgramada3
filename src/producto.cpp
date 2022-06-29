#include "producto.h"
#include <iostream>

using namespace TP3;

Producto::Producto(int numero, std::string nombre, int existencias) {
    this->numero = numero;
    strcpy(this->nombre, nombre.c_str());
    this->existencias = existencias;
}

Producto::Producto() {
    this->numero = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;
}

int Producto::conseguirNumero(){
    return this->numero;

}

void Producto::modificarNombre(){
    
    std::cin << "Escribe el nuevo nombre del producto" << endl;
    std::cout >> this->nombre;
}

void Producto::modificarExistencias(){
    std::cin << "Escribe la nueva cantidad de existencias del producto del producto" << endl;
    std::cout >> this->existencias;

}

ostream& operator << (ostream &o, const Producto *producto) {
    o << " " << producto->numero << ". " << producto->nombre << ": " << producto->existencias;  
    return o;
}