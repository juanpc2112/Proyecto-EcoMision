#include "ElementoInteractivo.h"

ElementoInteractivo::ElementoInteractivo(
    std::string nombre,
    std::string categoria) {

    this->nombre = nombre;

    this->categoria = categoria;
}

std::string ElementoInteractivo::getNombre() {

    return nombre;
}

std::string ElementoInteractivo::getCategoria() {

    return categoria;
}

ElementoInteractivo::~ElementoInteractivo() {

}
