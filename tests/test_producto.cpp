#include <gtest/gtest.h>
#include "../src/producto.h"
#include <string>

using namespace TP3;

TEST(Test_Producto, Test_Producto_Constructor){
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