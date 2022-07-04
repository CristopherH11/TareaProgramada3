#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>
#include <string>
#include <cstring>

namespace TP3 {

    class Tienda {

        char nombre[15];
        char direccionInternet[24];
        char direccion[24];
        char telefono[9];
        std::vector<Producto *> catalogo;

        public:
        Tienda(std::string nombre, std::string direccionInternet, std::string direccion, std::string telefono);
        Tienda();
        ~Tienda();

        void agregarProducto(Producto *nuevoProducto);
        void eliminarProducto(int numero);
        void modificarProducto(int numero, int tipo);

        void guardarEnStreamBinario(std::ostream *streamSalida);
        void cargarDesdeStreamBinario(std::istream *streamEntrada);

        int cantidadCatalogo();

        std::string conseguirNombre();
        std::string conseguirDireccionInternet();
        std::string conseguirDireccion();
        std::string conseguirTelefono();

        Producto* conseguirProducto(int numero);

        friend std::ostream& operator << (std::ostream &o, const Tienda *tienda);
    };
}

#endif