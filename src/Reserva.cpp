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

    listaZonas.push_back(zona);

    std::cout << "Zona agregada correctamente\n";
}

Zona* Reserva::buscarZona(std::string codigo) {

    if(zonas.count(codigo) == 0) {

        return nullptr;
    }

    return zonas[codigo];
}

void Reserva::mostrarZonas() {

    if(listaZonas.size() == 0) {

        std::cout << "No hay zonas registradas\n";
        return;
    }

    std::cout << "\nZonas de la reserva " << nombre << ":\n";

    for(int i = 0; i < listaZonas.size(); i++) {

        std::cout << i + 1
                  << ". "
                  << "Codigo: "
                  << listaZonas[i]->getCodigo()
                  << " | Nombre: "
                  << listaZonas[i]->getNombre()
                  << " | Tipo: "
                  << listaZonas[i]->getTipoZona()
                  << (listaZonas[i]->estaContaminada() ? " [CONTAMINADA]" : "")
                  << "\n";
    }
}

std::string Reserva::getNombre() {

    return nombre;
}

Reserva::~Reserva() {

    for(int i = 0; i < listaZonas.size(); i++) {

        delete listaZonas[i];
    }

    listaZonas.clear();

    zonas.clear();
}
