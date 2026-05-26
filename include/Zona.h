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

    std::vector<std::string> historial;

    void recalcularContaminacion();

    int contarSemillas();

    void registrarInteraccion(std::string nombreElemento,
                              std::string categoria);

public:

    Zona(std::string nombre,
         std::string codigo,
         std::string tipoZona);

    void agregarElemento(ElementoInteractivo* elemento);

    void mostrarElementos();

    void mostrarHistorial();

    void mostrarInfoNatural();

    // Sobrecarga 1: por indice
    void interactuarElemento(int indice,
                             Explorador* explorador);

    // Sobrecarga 2: por nombre del elemento
    void interactuarElemento(std::string nombreElemento,
                             Explorador* explorador);

    // Sobrecarga 3: por categoria y posicion dentro de esa categoria
    void interactuarElemento(std::string categoria,
                             int cual,
                             Explorador* explorador);

    std::string getNombre();

    std::string getCodigo();

    std::string getTipoZona();

    bool estaContaminada();

    void setContaminada(bool estado);
};

#endif
