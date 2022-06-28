#include "tienda.h"
#include <iostream>

using namespace TP3;

Tienda::Tienda()
{

}

Tienda::~Tienda()
{
    for (Producto *producto : this->catalogo)
    {
        delete empleado;
    }
}