#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Zona.h"

class Reserva {

private:

    std::string nombre;
    std::unordered_map<std::string, Zona*> zonas;
    std::vector<Zona*> listaZonas;

public:

    Reserva(std::string nombre);

    void agregarZona(std::string codigo,
                     Zona* zona);

    Zona* buscarZona(std::string codigo);

    void mostrarZonas();

    std::string getNombre();

    ~Reserva();
};

#endif
