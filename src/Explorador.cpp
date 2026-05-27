#include "Explorador.h"
#include "Zona.h"

Explorador::Explorador(std::string nombre) {

    this->nombre = nombre;

    energia = 100;

    puntajeAmbiental = 0;

    zonaActual = nullptr;
}

void Explorador::perderEnergia(int cantidad) {

    energia -= cantidad;

    if(energia < 0) {

        energia = 0;
    }

    std::cout << "El explorador perdio "
              << cantidad
              << " de energia\n";
}

void Explorador::recuperarEnergia(int cantidad) {

    energia += cantidad;

    if(energia > 100) {

        energia = 100;
    }

    std::cout << "El explorador recupero "
              << cantidad
              << " de energia\n";
}

void Explorador::aumentarPuntaje(int puntos) {

    puntajeAmbiental += puntos;

    std::cout << "El explorador gano "
              << puntos
              << " puntos ambientales\n";
}

void Explorador::cambiarZona(Zona* nuevaZona) {

    zonaActual = nuevaZona;

    std::cout << "El explorador cambio de zona\n";
}

void Explorador::recolectarSemilla(std::string tipoSemilla) {

    semillasRecolectadas.push_back(tipoSemilla);

    std::cout << "Semilla recolectada correctamente\n";
}

void Explorador::plantarSemilla(std::string tipoSemilla) {

    if(zonaActual == nullptr) {

        std::cout << "El explorador no tiene zona actual\n";
        return;
    }

    if(zonaActual->getTipoZona() != "Natural") {

        std::cout << "Solo se pueden plantar semillas "
                  << "en zonas naturales\n";

        return;
    }

    if(zonaActual->estaContaminada()) {

        std::cout << "La zona esta contaminada\n";
        return;
    }

    for(int i = 0; i < semillasRecolectadas.size(); i++) {

        if(semillasRecolectadas[i] == tipoSemilla) {

            semillasRecolectadas.erase(
                semillasRecolectadas.begin() + i
            );

            std::cout << "Semilla plantada correctamente\n";

            aumentarPuntaje(20);

            return;
        }
    }

    std::cout << "No tienes esa semilla\n";
}

void Explorador::mostrarSemillas() {

    if(semillasRecolectadas.size() == 0) {

        std::cout << "No hay semillas recolectadas\n";
        return;
    }

    std::cout << "\nSemillas del explorador:\n";

    for(int i = 0; i < semillasRecolectadas.size(); i++) {

        std::cout << i + 1
                  << ". "
                  << semillasRecolectadas[i]
                  << std::endl;
    }
}

void Explorador::mostrarEstado() {

    std::cout << "\nEstado de " << nombre << "\n";
    std::cout << "Energia:          " << energia << "/100\n";
    std::cout << "Puntaje ambiental: " << puntajeAmbiental << "\n";

    if(zonaActual != nullptr) {

        std::cout << "Zona actual:       "
                  << zonaActual->getNombre()
                  << " ["
                  << zonaActual->getTipoZona()
                  << "]"
                  << (zonaActual->estaContaminada() ? " [CONTAMINADA]" : "")
                  << "\n";
    }

    else {

        std::cout << "Zona actual:       Sin zona asignada\n";
    }

    mostrarSemillas();

    std::cout << "\n";
}

std::string Explorador::getNombre() {

    return nombre;
}

int Explorador::getEnergia() {

    return energia;
}

int Explorador::getPuntajeAmbiental() {

    return puntajeAmbiental;
}

Zona* Explorador::getZonaActual() {

    return zonaActual;
}
