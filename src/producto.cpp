#include "producto.h"

namespace TP3{

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

    std::string Producto::conseguirNombre(){
        return this->nombre;

    }

    int Producto::conseguirExistencias(){
        return this->existencias;

    }

    void Producto::modificarNombre(std::string nombre){
        strcpy(this->nombre, nombre.c_str());
    }

    void Producto::modificarExistencias(int existencias){
        this->existencias= existencias;

    }

    std::ostream& operator << (std::ostream &o, const Producto *producto){
        o << producto->numero << ". " << producto->nombre << ": " << producto->existencias;  
        return o;
    }

}