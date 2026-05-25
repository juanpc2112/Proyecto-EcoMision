#include "Reserva.h"

Reserva::Reserva(std::string nombre) {

    this->nombre = nombre;
}

void Reserva::agregarZona(std::string codigo,
                          Zona* zona) {

    if(zonas.count(codigo) > 0) {

        std::cout << "Ya existe una zona "
                  << "con ese codigo\n";

        return;
    }

    zonas[codigo] = zona;

    std::cout << "Zona agregada correctamente\n";
}

Zona* Reserva::buscarZona(std::string codigo) {

    if(zonas.count(codigo) == 0) {

        return nullptr;
    }

    return zonas[codigo];
}

void Reserva::mostrarZonas() {

    if(zonas.size() == 0) {

        std::cout << "No hay zonas registradas\n";
        return;
    }

    std::cout << "\nZonas de la reserva " << nombre << ":\n";

    for(auto zona : zonas) {

        std::cout << "Codigo: "
                  << zona.first
                  << " | Nombre: "
                  << zona.second->getNombre()
                  << " | Tipo: "
                  << zona.second->getTipoZona()
                  << (zona.second->estaContaminada() ? " [CONTAMINADA]" : "")
                  << std::endl;
    }
}

std::string Reserva::getNombre() {

    return nombre;
}
