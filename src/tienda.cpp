#include "tienda.h"

namespace TP3{

    Tienda::Tienda(std::string nombre, std::string direccionInternet, std::string direccion, std::string telefono){
        strcpy(this->nombre, nombre.c_str());
        strcpy(this->direccionInternet, direccionInternet.c_str());
        strcpy(this->direccion, direccion.c_str());
        strcpy(this->telefono, telefono.c_str());
    }

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
        int contador = 0;
        for (Producto *producto : this->catalogo) {
            if (producto->conseguirNumero()==numero) {
                this->catalogo.erase(catalogo.begin() + contador);
                delete producto;
            }
            contador++;
        }
    }

    void Tienda::modificarProducto(int numero, int tipo){
        std::string nombre;
        int existencias;
        for (Producto *producto : this->catalogo) {
            if (producto->conseguirNumero()==numero) {
                switch (tipo) {
                    case 1:
                        std::cout << "Escribe el nuevo nombre: ";
                        std::cin >> nombre;
                        producto->modificarNombre(nombre);
                        break;
                    case 2:
                        std::cout << "Escribe la nueva cantidad de existencias: ";
                        std::cin >> existencias;
                        producto->modificarExistencias(existencias);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void Tienda::guardarEnStreamBinario(std::ostream *streamSalida){

        for (Producto *producto : this->catalogo) {
            streamSalida->write((char *)producto, sizeof(Producto));
        }

    }

    void Tienda::cargarDesdeStreamBinario(std::istream *streamEntrada){

        streamEntrada->seekg( 0, std::ios::end );
        int cantidadBytesEnArchivo = streamEntrada->tellg();
        int cantidadProductos = (cantidadBytesEnArchivo-71) / sizeof(Producto);

        streamEntrada->read((char *)nombre, sizeof(nombre));
        streamEntrada->read((char *)direccion, sizeof(direccion));
        streamEntrada->read((char *)direccionInternet, sizeof(direccionInternet));
        streamEntrada->read((char *)telefono, sizeof(telefono));

        for (int indice=0; indice<cantidadProductos; indice++ ){
            Producto *productoNuevo = new Producto();
            streamEntrada->read((char *)productoNuevo, sizeof(Producto));

            this->agregarProducto(productoNuevo);
        }

    }

    std::string Tienda::conseguirNombre(){
        return this->nombre;

    }

    std::string Tienda::conseguirDireccionInternet(){
        return this->direccionInternet;

    }

    std::string Tienda::conseguirDireccion(){
        return this->direccion;

    }

    std::string Tienda::conseguirTelefono(){
        return this->telefono;

    }

    int Tienda::cantidadCatalogo(){
        return this->catalogo.size();
    }

    Producto* Tienda::conseguirProducto(int numero){
        for (Producto *producto : this->catalogo) {
            if (producto->conseguirNumero()==numero) {
                return producto;
            }
        }
        return nullptr;
    }


    std::ostream& operator << (std::ostream &o, const Tienda *tienda) {
        o << tienda->nombre << std::endl << tienda->direccionInternet << std::endl 
        << tienda->direccion << std::endl << tienda->telefono << std::endl;

        for (Producto *producto : tienda->catalogo) {
            o << producto << std::endl;
        }
        
        return o;
    }
}