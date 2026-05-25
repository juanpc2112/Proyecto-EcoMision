#ifndef RESIDUOCONTAMINANTE_H
#define RESIDUOCONTAMINANTE_H

#include "ElementoInteractivo.h"

class ResiduoContaminante : public ElementoInteractivo {

public:

    ResiduoContaminante();

    void interactuar(Explorador* explorador);
};

#endif
