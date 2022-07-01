#include <gtest/gtest.h>
#include "../src/tienda.h"
#include "../src/producto.h"
#include <string>

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

TEST(Test_Tienda, Test_Tienda_ConstructorBinario){
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

TEST(Test_Tienda, Test_Tienda_AgregarProducto){
    std::string nombre = "Ejemplo";
    std::string direccionInt = "ejemplo@gmail.com";
    std::string direccion = "Cartago Centro";
    std::string telefono = "88888888";

    Tienda *nuevaTienda = new Tienda(nombre, direccionInt, direccion, telefono);

    int numero = 1;
    std::string nombre = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(numero, nombre, existencias);
    Producto *nuevoProducto2 = new Producto(2, nombre, existencias);
    
    nuevaTienda->agregarProducto(nuevoProducto);
    nuevaTienda->agregarProducto(nuevoProducto2);

    int esperado = 2;
    int actual = nuevaTienda->cantidadCatalogo();

    EXPECT_EQ(actual, esperado);
}

TEST(Test_Tienda, Test_Tienda_ModificarProducto){
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

    std::string nombreEsperado = "Ejemplo";
    std::string nombreActual = "Ejemplo";

    EXPECT_EQ(actual, esperado);
}

TEST(Test_Tienda, Test_Tienda_EliminarProducto){
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

TEST(Test_Tienda, Test_Tienda_GuardarenArchivoBinario){
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

TEST(Test_Tienda, Test_Tienda_Operador){
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