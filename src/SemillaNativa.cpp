#include "SemillaNativa.h"
#include "Explorador.h"

SemillaNativa::SemillaNativa(
    std::string tipoSemilla)

    : ElementoInteractivo(
        "SemillaNativa",
        "Natural") {

    this->tipoSemilla = tipoSemilla;
}

void SemillaNativa::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador recolecto "
              << "una semilla de "
              << tipoSemilla
              << std::endl;

    explorador->recolectarSemilla(tipoSemilla);

    explorador->aumentarPuntaje(10);
}
