#ifndef ECOMISION_H
#define ECOMISION_H

#include <iostream>
#include <string>
#include <vector>

#include "Reserva.h"
#include "Explorador.h"
#include "Zona.h"
#include "AguaContaminada.h"
#include "AnimalHerido.h"
#include "EstacionEnergia.h"
#include "ResiduoContaminante.h"
#include "SemillaNativa.h"

class EcoMision {

private:

    std::vector<Reserva*> reservas;

    std::vector<Explorador*> exploradores;

//menu principal
    void crearReserva();
    void crearExplorador();
    void registrarZona();
    void agregarElemento();
    void listarReservas();
    void listarExploradores();
    void controlarExplorador();
    void verHistorialZona();
    void buscarZonaMenu();
//menu del explorador
    void menuExplorador(Explorador* explorador);
    void moverExplorador(Explorador* explorador);
    void interactuarEnZona(Explorador* explorador);
    void plantarEnZona(Explorador* explorador);
    Reserva* seleccionarReserva();
    Explorador* buscarExplorador(std::string nombre);

public:

    EcoMision();

    ~EcoMision();

    void iniciar();
};

#endif
