#include "tienda.h"
#include "excepcionProductoNoExiste.h"
#include "excepcionProductoYaExiste.h"
#include "excepcionTipoIncorrecto.h"

namespace TP3{

    Tienda::Tienda(std::string nombre, std::string direccionInternet, std::string direccion, std::string telefono){
        strcpy(this->nombre, nombre.c_str());
        strcpy(this->direccionInternet, direccionInternet.c_str());
        strcpy(this->direccion, direccion.c_str());
        strcpy(this->telefono, telefono.c_str());
    }

    Tienda::Tienda() {
        std::string temp = "";
        strcpy(this->nombre, temp.c_str());
        strcpy(this->direccionInternet, temp.c_str());
        strcpy(this->direccion, temp.c_str());
        strcpy(this->telefono, temp.c_str());
    }

    Tienda::~Tienda() {
        for (Producto *producto : this->catalogo) {
            delete producto;
        }
    }

    void Tienda::agregarProducto(Producto *productoNuevo){
        for (Producto *producto : this->catalogo){
            if (producto->conseguirNumero()==productoNuevo->conseguirNumero() || producto->conseguirNombre()==productoNuevo->conseguirNombre())
                throw ExcepcionProductoYaExiste();
        }
        this->catalogo.push_back(productoNuevo);
    }

    void Tienda::eliminarProducto(int numero){
        int referencia = 0;
        int contador = 0;
        for (Producto *producto : this->catalogo) {
            if (producto->conseguirNumero()==numero) {
                this->catalogo.erase(catalogo.begin() + contador);
                delete producto;
                referencia = 1;
            }
            contador++;
        }
        if (referencia==0){
            throw ExcepcionProductoNoExiste();
        }    
    }

    void Tienda::modificarProducto(int numero, int tipo, std::string valor){
        int referencia = 0;
        std::string nombre;
        int existencias;
        for (Producto *producto : this->catalogo) {
            if (producto->conseguirNumero()==numero) {
                switch (tipo) {
                    case 1:
                        producto->modificarNombre(valor);
                        referencia=1;
                        break;
                    case 2:
                        int existencias= stoi(valor);
                        producto->modificarExistencias(existencias);
                        referencia=1;
                        break;
                }
            }
        }
        if (referencia==0){
            throw ExcepcionProductoNoExiste();
        }  
    }

    void Tienda::guardarEnStreamBinario(std::ostream *streamSalida){
        streamSalida->write((char *)nombre, sizeof(nombre));
        streamSalida->write((char *)direccionInternet, sizeof(direccionInternet));
        streamSalida->write((char *)direccion, sizeof(direccion));
        streamSalida->write((char *)telefono, sizeof(telefono));
        for (Producto *producto : this->catalogo) {
            streamSalida->write((char *)producto, sizeof(Producto));
        }

    }

    void Tienda::cargarDesdeStreamBinario(std::istream *streamEntrada){

        streamEntrada->seekg( 0, std::ios::end );
        int cantidadBytesEnArchivo = streamEntrada->tellg();
        int cantidadInformacion= cantidadBytesEnArchivo - sizeof(nombre) - sizeof(direccionInternet) - sizeof(direccion) - sizeof(telefono);
        int cantidadProductos = (cantidadBytesEnArchivo-cantidadInformacion) / sizeof(Producto);

        streamEntrada->seekg( 0, std::ios::beg ); 
        streamEntrada->read((char *)nombre, sizeof(nombre));
        streamEntrada->read((char *)direccionInternet, sizeof(direccionInternet));
        streamEntrada->read((char *)direccion, sizeof(direccion));
        streamEntrada->read((char *)telefono, sizeof(telefono));

        for (int indice=0; indice<cantidadProductos-1; indice++){
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
        throw ExcepcionProductoNoExiste();
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