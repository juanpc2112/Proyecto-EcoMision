#ifndef EXPLORADOR_H
#define EXPLORADOR_H

#include <iostream>
#include <string>
#include <vector>

class Zona;

class Explorador {

private:

    std::string nombre;

    int energia;

    int puntajeAmbiental;

    Zona* zonaActual;

    std::vector<std::string> semillasRecolectadas;

public:

    Explorador(std::string nombre);

    void perderEnergia(int cantidad);

    void recuperarEnergia(int cantidad);

    void aumentarPuntaje(int puntos);

    void cambiarZona(Zona* nuevaZona);

    void recolectarSemilla(std::string tipoSemilla);

    void plantarSemilla(std::string tipoSemilla);

    void mostrarSemillas();

    void mostrarEstado();

    std::string getNombre();

    int getEnergia();

    int getPuntajeAmbiental();

    Zona* getZonaActual();
};

#endif
