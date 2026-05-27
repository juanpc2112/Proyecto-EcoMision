#include "Zona.h"

Zona::Zona(std::string nombre,
           std::string codigo,
           std::string tipoZona) {

    this->nombre = nombre;
    this->codigo = codigo;
    this->tipoZona = tipoZona;

    contaminada = false;
}

//metodos privados

void Zona::recalcularContaminacion() {

    for(int i = 0; i < elementos.size(); i++) {

        if(elementos[i]->getCategoria() == "Contaminante") {

            contaminada = true;
            return;
        }
    }

    contaminada = false;
}

int Zona::contarSemillas() {

    int contador = 0;

    for(int i = 0; i < elementos.size(); i++) {

        if(elementos[i]->getNombre() == "SemillaNativa") {

            contador++;
        }
    }

    return contador;
}

void Zona::registrarInteraccion(std::string nombreElemento,
                                std::string categoria) {

    historial.push_back(
        "Interactuado con: " + nombreElemento +
        " [" + categoria + "]"
    );
}

//metodos publicos

void Zona::agregarElemento(ElementoInteractivo* elemento) {

    if(tipoZona == "Tecnologica" &&
       elemento->getCategoria() == "Natural") {

        std::cout << "No se puede agregar un elemento natural "
                  << "a una zona tecnologica\n";

        return;
    }

    if(tipoZona == "Natural" &&
       elemento->getCategoria() == "Tecnologico") {

        std::cout << "No se puede agregar un elemento tecnologico "
                  << "a una zona natural\n";

        return;
    }

    elementos.push_back(elemento);

    recalcularContaminacion();

    std::cout << "Elemento agregado correctamente\n";
}

void Zona::mostrarElementos() {

    if(elementos.size() == 0) {

        std::cout << "No hay elementos en esta zona\n";
        return;
    }

    std::cout << "\nElementos de la zona " << nombre;

    if(contaminada) {

        std::cout << " [CONTAMINADA]";
    }

    std::cout << ":\n";

    for(int i = 0; i < elementos.size(); i++) {

        std::cout << i + 1
                  << ". "
                  << elementos[i]->getNombre()
                  << " ["
                  << elementos[i]->getCategoria()
                  << "]\n";
    }

    if(tipoZona == "Natural") {

        mostrarInfoNatural();
    }
}

void Zona::mostrarHistorial() {

    std::cout << "\n--- Historial de interacciones en "
              << nombre << " ---\n";

    if(historial.size() == 0) {

        std::cout << "No se han realizado interacciones en esta zona\n";
        return;
    }

    for(int i = 0; i < historial.size(); i++) {

        std::cout << i + 1 << ". " << historial[i] << "\n";
    }

    std::cout << "Total de interacciones: "
              << historial.size() << "\n";
}

void Zona::mostrarInfoNatural() {

    int semillas = contarSemillas();

    std::cout << "\nSemillas disponibles en la zona: "
              << semillas << "\n";
}

//Sobrecargas
void Zona::interactuarElemento(int indice,
                               Explorador* explorador) {

    if(indice < 0 || indice >= (int)elementos.size()) {

        std::cout << "Indice invalido\n";
        return;
    }

    std::string nombreGuardado  = elementos[indice]->getNombre();
    std::string categoriaGuardada = elementos[indice]->getCategoria();

    elementos[indice]->interactuar(explorador);

    delete elementos[indice];

    elementos.erase(elementos.begin() + indice);

    recalcularContaminacion();

    registrarInteraccion(nombreGuardado, categoriaGuardada);

    std::cout << "El elemento desaparecio de la zona\n";
}


void Zona::interactuarElemento(std::string nombreElemento,
                               Explorador* explorador) {

    for(int i = 0; i < (int)elementos.size(); i++) {

        if(elementos[i]->getNombre() == nombreElemento) {

            std::string categoriaGuardada = elementos[i]->getCategoria();

            elementos[i]->interactuar(explorador);

            delete elementos[i];

            elementos.erase(elementos.begin() + i);

            recalcularContaminacion();

            registrarInteraccion(nombreElemento, categoriaGuardada);

            std::cout << "El elemento desaparecio de la zona\n";

            return;
        }
    }

    std::cout << "Elemento no encontrado\n";
}

void Zona::interactuarElemento(std::string categoria,
                               int cual,
                               Explorador* explorador) {

    int contador = 0;

    for(int i = 0; i < (int)elementos.size(); i++) {

        if(elementos[i]->getCategoria() == categoria) {

            if(contador == cual - 1) {

                std::string nombreGuardado = elementos[i]->getNombre();

                elementos[i]->interactuar(explorador);

                delete elementos[i];

                elementos.erase(elementos.begin() + i);

                recalcularContaminacion();

                registrarInteraccion(nombreGuardado, categoria);

                std::cout << "El elemento desaparecio de la zona\n";

                return;
            }

            contador++;
        }
    }

    std::cout << "No se encontro el elemento numero "
              << cual
              << " de categoria "
              << categoria << "\n";
}


std::string Zona::getNombre() {

    return nombre;
}

std::string Zona::getCodigo() {

    return codigo;
}

std::string Zona::getTipoZona() {

    return tipoZona;
}

bool Zona::estaContaminada() {

    return contaminada;
}

void Zona::setContaminada(bool estado) {

    contaminada = estado;
}

Zona::~Zona() {

    for(int i = 0; i < elementos.size(); i++) {

        delete elementos[i];
    }

    elementos.clear();
}
