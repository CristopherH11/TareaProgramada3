#ifndef EXCEPCIONPRODUCTOYAEXISTE_H
#define EXCEPCIONPRODUCTOYAEXISTE_h

#include <exception>

class ExcepcionProductoYaExiste : public std::exception {
    public:
    ExcepcionProductoYaExiste() noexcept = default;
    ~ExcepcionProductoYaExiste() = default;

    virtual const char* what() const noexcept {
        return "Ya hay un producto con alguno de estos datos";
    }

};

#endif
