#ifndef ZONA_H
#define ZONA_H

#include <iostream>
#include <string>
#include <vector>

#include "ElementoInteractivo.h"
#include "Explorador.h"

class Zona {

private:

    std::string nombre;
    std::string codigo;
    std::string tipoZona;

    bool contaminada;

    std::vector<ElementoInteractivo*> elementos;

    void recalcularContaminacion();

    int contarSemillas();

public:

    Zona(std::string nombre,
         std::string codigo,
         std::string tipoZona);

    void agregarElemento(ElementoInteractivo* elemento);

    void mostrarElementos();

    void interactuarElemento(int indice,
                             Explorador* explorador);

    void interactuarElemento(std::string nombreElemento,
                             Explorador* explorador);

    std::string getNombre();

    std::string getCodigo();

    std::string getTipoZona();

    bool estaContaminada();

    void setContaminada(bool estado);
};

#endif
