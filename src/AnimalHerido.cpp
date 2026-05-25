#include "AnimalHerido.h"
#include "Explorador.h"

AnimalHerido::AnimalHerido()
    : ElementoInteractivo(
        "AnimalHerido",
        "Natural") {

}

void AnimalHerido::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador ayudo "
              << "a un animal herido\n";

    explorador->aumentarPuntaje(25);

    explorador->perderEnergia(10);
}
