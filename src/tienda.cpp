#include "tienda.h"
#include <iostream>

using namespace TP3;

Tienda::Tienda() {

}

Tienda::~Tienda() {
    for (Producto *producto : this->catalogo) {
        delete producto;
    }
}

void Tienda::agregarProducto(Producto *producto){
    this->catalogo.push_back(producto);
}

void Tienda::eliminarProducto(int numero){
    for (Producto *producto : this->catalogo) {
        if (producto->conseguirNumero==numero) {
            delete producto;
        }
    }
}

void Tienda::modificarProducto(int numero){
    for (Producto *producto : this->catalogo) {
        if (producto->conseguirNumero==numero) {
            switch (tipo){
                case 1:
                    producto->modificarNombre();
                case 2:
                    producto->modificarExistencias();
            }
        }
    }
}

void Tienda::guardarEnStreamBinario(ostream *streamSalida){

    for (Producto *producto : this->catalogo) {
        streamSalida->write((char *)producto, sizeof(Producto));
    }

}

void Tienda::cargarDesdeStreamBinario(istream *streamEntrada){

    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytesEnArchivo-71) / sizeof(Empleado);

    streamEntrada->read((char *)nombre, sizeof(nombre));
    streamEntrada->read((char *)direccion, sizeof(direccion));
    streamEntrada->read((char *)direccionInternet, sizeof(direccionInternet));
    streamEntrada->read((char *)telefono, sizeof(telefono));

    for (int indice=0, indice<cantidadProductos, indice++ ){
        Producto *productoNuevo = new Producto();
        streamEntrada->read((char *)productoNuevo, sizeof(Producto));

        this->agregarProducto(productoNuevo);
    }

}

ostream& operator << (ostream &o, const Tienda *tienda) {
    o << tienda->nombre << std::endl << tienda->direccionInternet << std::endl 
      << tienda->direccion << std::endl << tienda->telefono << std::endl;

    for (Producto *producto : tienda->catalogo) {
        o << producto << std::endl;
    }
    
    return o;
}