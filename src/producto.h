#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

namespace TP3 {

    class Producto {

        int numero;
        char nombre[20];
        int existencias;

        public:

        Producto(int numero, string nombre, int existencias);
        Producto();

        friend ostream& operator << (ostream &o, const Producto *producto);

    };
}
#endif