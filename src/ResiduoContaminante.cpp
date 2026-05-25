#include "ResiduoContaminante.h"
#include "Explorador.h"

ResiduoContaminante::ResiduoContaminante()
    : ElementoInteractivo(
        "ResiduoContaminante",
        "Contaminante") {

}

void ResiduoContaminante::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador limpio "
              << "un residuo contaminante\n";

    explorador->perderEnergia(5);

    explorador->aumentarPuntaje(20);
}
