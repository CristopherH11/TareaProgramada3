#include <gtest/gtest.h>
#include "../src/tienda.h"
#include "../src/producto.h"
#include "../src/excepcionProductoNoExiste.h"
#include "../src/excepcionProductoYaExiste.h"
#include "../src/excepcionTipoIncorrecto.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace TP3;

TEST(Test_Tienda, Test_Tienda_Constructor){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);

    std::string nombreEsperado = "Ejemplo";
    std::string nombreActual = nuevaTienda->conseguirNombre();

    std::string direccionIntEsperada = "ejemplo@gmail.com";
    std::string direccionIntActual = nuevaTienda->conseguirDireccionInternet();

    std::string direccionEsperada = "Cartago Centro";
    std::string direccionActual = nuevaTienda->conseguirDireccion();

    std::string telefonoEsperado = "88888888";
    std::string telefonoActual = nuevaTienda->conseguirTelefono();

    EXPECT_EQ(nombreActual, nombreEsperado);
    EXPECT_EQ(direccionIntActual, direccionIntEsperada);
    EXPECT_EQ(direccionActual, direccionEsperada);
    EXPECT_EQ(telefonoActual, telefonoEsperado);

}


TEST(Test_Tienda, Test_Tienda_Agregar_Producto){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);

    int numero = 1;
    std::string nombre2 = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(numero, nombre2, existencias);
    Producto *nuevoProducto2 = new Producto(2, "Fresa", existencias);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

    int esperado = 2;
    int actual = nuevaTienda->cantidadCatalogo();

    EXPECT_EQ(actual, esperado);
}

TEST(Test_Tienda, Test_Tienda_Modificar_Producto){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);


    Producto *nuevoProducto = new Producto(1, "Papaya", 50);
    Producto *nuevoProducto2 = new Producto(2, "Banano", 30);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

    nuevaTienda->modificarProducto(1, 2);
    nuevaTienda->modificarProducto(2, 1);

    std::string nombreEsperado = "Platano";
    std::string nombreActual = nuevaTienda->conseguirProducto(2)->conseguirNombre();

    int existenciasEsperadas = 100;
    int existenciasActuales = nuevaTienda->conseguirProducto(1)->conseguirExistencias();

    EXPECT_EQ(nombreActual, nombreEsperado);
    EXPECT_EQ(existenciasEsperadas, existenciasActuales);
}

TEST(Test_Tienda, Test_Tienda_Eliminar_Producto){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);

    int numero = 1;
    std::string nombre2 = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(1, nombre2, existencias);
    Producto *nuevoProducto2 = new Producto(2, "Fresa", existencias);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

    nuevaTienda->eliminarProducto(1);

    int esperado = 1;
    int actual = nuevaTienda->cantidadCatalogo();

    EXPECT_EQ(actual, esperado);

}

TEST(Test_Tienda, Test_Tienda_Operador){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);

    Producto *nuevoProducto = new Producto(1, "Papaya", 100);
    nuevaTienda->agregarProducto(nuevoProducto);

    std::ostringstream streamSalida {};

    streamSalida << nuevaTienda;

    std::string esperado = "Ejemplo\nejemplo@gmail.com\nCartago Centro\n88888888\n1. Papaya: 100\n";
    std::string actual = streamSalida.str();

    EXPECT_EQ(actual, esperado);

}

TEST(Test_Tienda, Test_Tienda_Cargar_y_Guardar_en_Binario){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda1 = new Tienda(nombre, direccionInt, direccion, telefono);

    Producto *productoNuevo = new Producto(1, "Papaya", 100);
    nuevaTienda1->agregarProducto(productoNuevo);

    std::ofstream archivoSalida;

    archivoSalida.open("archivo_test.dat", std::ios::out|std::ios::binary);

    if (!archivoSalida.is_open())
    {
        std::cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
        FAIL();
    }
    
    nuevaTienda1->guardarEnStreamBinario(&archivoSalida);

    archivoSalida.close();

    Tienda *nuevaTienda2 = new Tienda();

    std::ifstream archivoEntrada;

    archivoEntrada.open("archivo_test.dat", std::ios::in|std::ios::binary);

    if (!archivoEntrada.is_open())
    {
        std::cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
        FAIL();
    }

    nuevaTienda2->cargarDesdeStreamBinario(&archivoEntrada);

    archivoEntrada.close();

    std::ostringstream streamEsperado {};
    streamEsperado << nuevaTienda1;

    std::ostringstream streamActual {};
    streamActual << nuevaTienda2;

    std::string esperado = streamEsperado.str();
    std::string actual = streamActual.str();

    delete nuevaTienda1;
    delete nuevaTienda2;

    EXPECT_EQ(actual, esperado);
}

TEST(Test_Tienda, Test_ExcepcionProductoYaExiste){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);


    Producto *nuevoProducto = new Producto(1, "Papaya", 50);
    Producto *nuevoProducto2 = new Producto(1, "Banano", 30);
    
    nuevaTienda->agregarProducto(nuevoProducto);

    EXPECT_THROW({
        nuevaTienda->agregarProducto(nuevoProducto2);
    }, ExcepcionProductoYaExiste);

}

TEST(Test_Tienda, Test_ExcepcionProductoNoExiste){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);


    Producto *nuevoProducto = new Producto(1, "Papaya", 50);
    Producto *nuevoProducto2 = new Producto(2, "Banano", 30);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

    EXPECT_THROW({
            nuevaTienda->eliminarProducto(3);
        }, ExcepcionProductoNoExiste);

        EXPECT_THROW({
            nuevaTienda->modificarProducto(3, 1);
        }, ExcepcionProductoNoExiste);
}

TEST(Test_Tienda, Test_ExcepcionTipoIncorrecto){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);


    Producto *nuevoProducto = new Producto(1, "Papaya", 50);
    Producto *nuevoProducto2 = new Producto(2, "Banano", 30);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

        EXPECT_THROW({
            nuevaTienda->modificarProducto(2, 0);
        }, ExcepcionTipoIncorrecto);
}