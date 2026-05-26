#include "AguaContaminada.h"
#include "Explorador.h"

AguaContaminada::AguaContaminada()
    : ElementoInteractivo(
        "AguaContaminada",
        "Contaminante") {

}

void AguaContaminada::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador limpia el agua contaminada "
              << "y pierde energia\n";

    explorador->perderEnergia(15);
}
