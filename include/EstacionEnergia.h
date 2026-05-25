#ifndef ESTACIONENERGIA_H
#define ESTACIONENERGIA_H

#include "ElementoInteractivo.h"

class EstacionEnergia : public ElementoInteractivo {

public:

    EstacionEnergia();

    void interactuar(Explorador* explorador);
};

#endif
