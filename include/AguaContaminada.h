#ifndef AGUACONTAMINADA_H
#define AGUACONTAMINADA_H

#include "ElementoInteractivo.h"

class AguaContaminada : public ElementoInteractivo {

public:

    AguaContaminada();

    void interactuar(Explorador* explorador) ;
};

#endif
