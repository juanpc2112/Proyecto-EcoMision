#include "EstacionEnergia.h"
#include "Explorador.h"

EstacionEnergia::EstacionEnergia()
    : ElementoInteractivo(
        "EstacionEnergia",
        "Tecnologico") {

}

void EstacionEnergia::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador uso "
              << "una estacion de energia\n";

    explorador->recuperarEnergia(30);

    explorador->aumentarPuntaje(10);
}
