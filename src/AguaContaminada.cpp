#include "AguaContaminada.h"
#include "Explorador.h"

AguaContaminada::AguaContaminada()
    : ElementoInteractivo(
        "AguaContaminada",
        "Contaminante") {

}

void AguaContaminada::interactuar(
    Explorador* explorador) {

    std::cout << "El explorador toco agua contaminada "
              << "y perdio energia\n";

    explorador->perderEnergia(15);
}
