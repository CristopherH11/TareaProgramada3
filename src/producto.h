#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <cstring>

namespace TP3 {

    class Producto {
        
        protected:

        int numero;
        char nombre[20];
        int existencias;

        public:

        Producto(int numero, std::string nombre, int existencias);
        Producto();
        ~Producto();

        int conseguirNumero();
        std::string conseguirNombre();
        int conseguirExistencias();

        void modificarNombre(std::string nombre);
        void modificarExistencias(int existencias);

        friend std::ostream& operator << (std::ostream &o, const Producto *producto);

    };
}
#endif