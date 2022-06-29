#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>

namespace TP3 {

    class Tienda {

        char nombre[15];
        char direccionInternet[24];
        char direccion[24];
        char telefono[8];
        std::vector<Producto *> catalogo;

        public:
        Tienda();
        ~Tienda();

        void agregarProducto(Producto *nuevoProducto);
        void eliminarProducto(int numero);
        void modificarProducto(int numero, int tipo);

        void guardarEnStreamBinario(ostream *streamSalida);
        void cargarDesdeStreamBinario(istream *streamEntrada);

        friend ostream& operator << (ostream &o, const Producto *producto);
    };
}

#endif