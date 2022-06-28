#include "producto.h"
#include <iostream>

using namespace TP3;

Producto::Producto(int numero, std::string nombre, int existencias)
{
    this->numero = numero;
    strcpy(this->nombre, nombre.c_str());
    this->existencias = existencias;
}

Producto::Producto()
{
    this->numero = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;
}


ostream& operator << (ostream &o, const Producto *producto)
{
    o << " " << producto->numero << " " << producto->nombre << " " << producto->existencias;  
    return o;
}