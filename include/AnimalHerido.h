#ifndef ANIMALHERIDO_H
#define ANIMALHERIDO_H

#include "ElementoInteractivo.h"

class AnimalHerido : public ElementoInteractivo {

public:

    AnimalHerido();

    void interactuar(Explorador* explorador) ;
};

#endif
