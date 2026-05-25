#ifndef SEMILLANATIVA_H
#define SEMILLANATIVA_H

#include "ElementoInteractivo.h"

class SemillaNativa : public ElementoInteractivo {

private:

    std::string tipoSemilla;

public:

    SemillaNativa(std::string tipoSemilla);

    void interactuar(Explorador* explorador);
};

#endif
