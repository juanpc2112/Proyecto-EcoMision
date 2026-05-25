#include "Zona.h"

Zona::Zona(std::string nombre,
           std::string codigo,
           std::string tipoZona) {

    this->nombre = nombre;
    this->codigo = codigo;
    this->tipoZona = tipoZona;

    contaminada = false;
}

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

        if(elementos[i]->getCategoria() == "Natural") {

            contador++;
        }
    }

    return contador;
}

void Zona::agregarElemento(ElementoInteractivo* elemento) {

    if(tipoZona == "Tecnologica" &&
       elemento->getCategoria() == "Natural") {

        std::cout << "No se puede agregar un elemento natural "
                  << "a una zona tecnologica\n";

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

        int semillas = contarSemillas();

        std::cout << "\nSemillas disponibles en la zona: "
                  << semillas
                  << "\n";
    }
}

void Zona::interactuarElemento(int indice,
                               Explorador* explorador) {

    if(indice < 0 || indice >= elementos.size()) {

        std::cout << "Indice invalido\n";
        return;
    }

    elementos[indice]->interactuar(explorador);

    delete elementos[indice];

    elementos.erase(elementos.begin() + indice);

    recalcularContaminacion();

    std::cout << "El elemento desaparecio de la zona\n";
}

void Zona::interactuarElemento(std::string nombreElemento,
                               Explorador* explorador) {

    for(int i = 0; i < elementos.size(); i++) {

        if(elementos[i]->getNombre() == nombreElemento) {

            elementos[i]->interactuar(explorador);

            delete elementos[i];

            elementos.erase(elementos.begin() + i);

            recalcularContaminacion();

            std::cout << "El elemento desaparecio de la zona\n";

            return;
        }
    }

    std::cout << "Elemento no encontrado\n";
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
