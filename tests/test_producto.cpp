#include <gtest/gtest.h>
#include "../src/producto.h"
#include <string>
#include <sstream>

using namespace TP3;

TEST(Test_Producto, Test_Producto_ConstructoryMetodosConseguir){
    int numero = 1;
    std::string nombre = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(numero, nombre, existencias);

    int numeroEsperado = 1;
    int numeroActual = nuevoProducto->conseguirNumero();

    std::string nombreEsperado = "Papaya";
    std::string nombreActual = nuevoProducto->conseguirNombre();

    int existenciasEsperadas = 100;
    int existenciasActuales = nuevoProducto->conseguirExistencias();

    EXPECT_EQ(numeroActual, numeroEsperado);
    EXPECT_EQ(nombreActual, nombreEsperado);
    EXPECT_EQ(existenciasEsperadas, existenciasActuales);

}

TEST(Test_Producto, Test_Producto_MetodosModificar){
    int numero = 1;
    std::string nombre = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(numero, nombre, existencias);

    nuevoProducto->modificarNombre("Papayas Pequeñas");
    nuevoProducto->modificarExistencias(50);

    std::string nombreEsperado = "Papayas Pequeñas";
    std::string nombreActual = nuevoProducto->conseguirNombre();

    int existenciasEsperadas = 50;
    int existenciasActuales = nuevoProducto->conseguirExistencias();

    EXPECT_EQ(nombreActual, nombreEsperado);
    EXPECT_EQ(existenciasEsperadas, existenciasActuales);

}

TEST(Test_Producto, Test_Producto_Operador){
    int numero = 1;
    std::string nombre = "Papaya";
    int existencias = 100;

    Producto *nuevoProducto = new Producto(numero, nombre, existencias);

    std::ostringstream streamSalida {};

    streamSalida << nuevoProducto;

    std::string Esperado = "1. Papaya: 100";
    std::string Actual = streamSalida.str();

    EXPECT_EQ(Actual, Esperado);

}