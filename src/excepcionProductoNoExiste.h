#ifndef EXCEPCIONPRODUCTONOEXISTE_H
#define EXCEPCIONPRODUCTONOEXISTE_H

#include <exception>

class ExcepcionProductoNoExiste : public std::exception {
    public:
    ExcepcionProductoNoExiste() noexcept = default;
    ~ExcepcionProductoNoExiste() = default;

    virtual const char* what() const noexcept {
        return "No existe un producto con ese numero";
    }

};

#endif