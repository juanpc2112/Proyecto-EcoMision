#ifndef ELEMENTOINTERACTIVO_H
#define ELEMENTOINTERACTIVO_H

#include <iostream>
#include <string>

class Explorador;

class ElementoInteractivo {

protected:

    std::string nombre;

    std::string categoria;

public:

    ElementoInteractivo(std::string nombre,
                        std::string categoria);

    virtual void interactuar(Explorador* explorador) = 0;

    std::string getNombre();

    std::string getCategoria();

    virtual ~ElementoInteractivo();
};

#endif
