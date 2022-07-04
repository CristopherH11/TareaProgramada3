#ifndef EXCEPCIONTIPOINCORRECTO_H
#define EXCEPCIONTIPOINCORRECTO_h

#include <exception>

class ExcepcionTipoIncorrecto : public std::exception {
    public:
    ExcepcionTipoIncorrecto() noexcept = default;
    ~ExcepcionTipoIncorrecto() = default;

    virtual const char* what() const noexcept {
        return "Para modificar el numeor debe ser 1(Nombre) o 2(Existencias)";
    }

};

#endif