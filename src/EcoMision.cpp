#include "EcoMision.h"

EcoMision::EcoMision() {

}

// ─────────────────────────────────────────
//  MENU PRINCIPAL
// ─────────────────────────────────────────

void EcoMision::iniciar() {

    int opcion;

    do {

        std::cout << "\n===== ECO MISION =====\n";
        std::cout << "1. Crear reserva\n";
        std::cout << "2. Crear explorador\n";
        std::cout << "3. Registrar zona en una reserva\n";
        std::cout << "4. Agregar elemento a una zona\n";
        std::cout << "5. Listar reservas\n";
        std::cout << "6. Listar exploradores\n";
        std::cout << "7. Controlar explorador\n";
        std::cout << "8. Ver historial de una zona\n";
        std::cout << "9. Salir\n";
        std::cout << "Opcion: ";

        std::cin >> opcion;

        switch(opcion) {

            case 1:
                crearReserva();
                break;

            case 2:
                crearExplorador();
                break;

            case 3:
                registrarZona();
                break;

            case 4:
                agregarElemento();
                break;

            case 5:
                listarReservas();
                break;

            case 6:
                listarExploradores();
                break;

            case 7:
                controlarExplorador();
                break;

            case 8:
                verHistorialZona();
                break;

            case 9:
                std::cout << "Saliendo del sistema...\n";
                break;

            default:
                std::cout << "Opcion invalida\n";
        }

    } while(opcion != 9);
}

// ─────────────────────────────────────────
//  CREACION
// ─────────────────────────────────────────

void EcoMision::crearReserva() {

    std::string nombre;

    std::cout << "Ingrese el nombre de la reserva: ";
    std::cin >> nombre;

    reservas.push_back(new Reserva(nombre));

    std::cout << "Reserva \"" << nombre << "\" creada correctamente\n";
}

void EcoMision::crearExplorador() {

    std::string nombre;

    std::cout << "Ingrese el nombre del explorador: ";
    std::cin >> nombre;

    if(buscarExplorador(nombre) != nullptr) {

        std::cout << "Ya existe un explorador con ese nombre\n";
        return;
    }

    exploradores.push_back(new Explorador(nombre));

    std::cout << "Explorador \"" << nombre << "\" creado correctamente\n";
}

void EcoMision::registrarZona() {

    if(reservas.empty()) {

        std::cout << "Primero debe crear una reserva\n";
        return;
    }

    Reserva* reserva = seleccionarReserva();

    if(reserva == nullptr) return;

    std::string codigo;
    std::string nombre;
    int opcionTipo;
    std::string tipoZona;

    std::cout << "Ingrese el codigo de la zona: ";
    std::cin >> codigo;

    std::cout << "Ingrese el nombre de la zona: ";
    std::cin >> nombre;

    std::cout << "\nSeleccione el tipo de zona\n";
    std::cout << "1. Natural\n";
    std::cout << "2. Tecnologica\n";
    std::cout << "Opcion: ";

    std::cin >> opcionTipo;

    tipoZona = (opcionTipo == 1) ? "Natural" : "Tecnologica";

    Zona* nuevaZona = new Zona(nombre, codigo, tipoZona);

    reserva->agregarZona(codigo, nuevaZona);
}

void EcoMision::agregarElemento() {

    if(reservas.empty()) {

        std::cout << "No hay reservas creadas\n";
        return;
    }

    Reserva* reserva = seleccionarReserva();

    if(reserva == nullptr) return;

    std::string codigoZona;

    std::cout << "Ingrese el codigo de la zona: ";
    std::cin >> codigoZona;

    Zona* zona = reserva->buscarZona(codigoZona);

    if(zona == nullptr) {

        std::cout << "Zona no encontrada\n";
        return;
    }

    std::cout << "\nSeleccione el tipo de elemento\n";
    std::cout << "1. Animal Herido\n";
    std::cout << "2. Agua Contaminada\n";
    std::cout << "3. Residuo Contaminante\n";
    std::cout << "4. Estacion de Energia\n";
    std::cout << "5. Semilla Nativa\n";
    std::cout << "Opcion: ";

    int opcion;
    std::cin >> opcion;

    ElementoInteractivo* elemento = nullptr;

    switch(opcion) {

        case 1:
            elemento = new AnimalHerido();
            break;

        case 2:
            elemento = new AguaContaminada();
            break;

        case 3:
            elemento = new ResiduoContaminante();
            break;

        case 4:
            elemento = new EstacionEnergia();
            break;

        case 5: {
            std::string tipo;
            std::cout << "Ingrese el tipo de semilla: ";
            std::cin >> tipo;
            elemento = new SemillaNativa(tipo);
            break;
        }

        default:
            std::cout << "Opcion invalida\n";
            return;
    }

    zona->agregarElemento(elemento);
}

// ─────────────────────────────────────────
//  LISTADOS
// ─────────────────────────────────────────

void EcoMision::listarReservas() {

    if(reservas.empty()) {

        std::cout << "No hay reservas creadas\n";
        return;
    }

    std::cout << "\n--- Reservas ---\n";

    for(int i = 0; i < (int)reservas.size(); i++) {

        std::cout << i + 1 << ". " << reservas[i]->getNombre() << "\n";
    }

    for(int i = 0; i < (int)reservas.size(); i++) {

        reservas[i]->mostrarZonas();
    }
}

void EcoMision::listarExploradores() {

    if(exploradores.empty()) {

        std::cout << "No hay exploradores creados\n";
        return;
    }

    std::cout << "\n--- Exploradores ---\n";

    for(int i = 0; i < (int)exploradores.size(); i++) {

        exploradores[i]->mostrarEstado();
    }
}

void EcoMision::verHistorialZona() {

    if(reservas.empty()) {

        std::cout << "No hay reservas creadas\n";
        return;
    }

    Reserva* reserva = seleccionarReserva();

    if(reserva == nullptr) return;

    std::string codigoZona;

    std::cout << "Ingrese el codigo de la zona: ";
    std::cin >> codigoZona;

    Zona* zona = reserva->buscarZona(codigoZona);

    if(zona == nullptr) {

        std::cout << "Zona no encontrada\n";
        return;
    }

    zona->mostrarHistorial();

    if(zona->getTipoZona() == "Natural") {

        zona->mostrarInfoNatural();
    }
}

// ─────────────────────────────────────────
//  CONTROLAR EXPLORADOR
// ─────────────────────────────────────────

void EcoMision::controlarExplorador() {

    if(exploradores.empty()) {

        std::cout << "No hay exploradores creados\n";
        return;
    }

    std::string nombre;

    std::cout << "Ingrese el nombre del explorador: ";
    std::cin >> nombre;

    Explorador* explorador = buscarExplorador(nombre);

    if(explorador == nullptr) {

        std::cout << "Explorador no encontrado\n";
        return;
    }

    if(explorador->getZonaActual() == nullptr) {

        if(reservas.empty()) {

            std::cout << "No hay reservas disponibles\n";
            return;
        }

        std::cout << "\nEl explorador no tiene zona asignada\n";
        std::cout << "Seleccione una reserva por su numero para ingresar:\n";

        Reserva* reserva = seleccionarReserva();

        if(reserva == nullptr) return;

        reserva->mostrarZonas();

        std::string codigoZona;

        std::cout << "Ingrese el codigo de la zona inicial: ";
        std::cin >> codigoZona;

        Zona* zona = reserva->buscarZona(codigoZona);

        if(zona == nullptr) {

            std::cout << "Zona no encontrada\n";
            return;
        }

        explorador->cambiarZona(zona);

        std::cout << "Explorador ubicado en "
                  << zona->getNombre() << "\n";
    }

    menuExplorador(explorador);
}

// ─────────────────────────────────────────
//  MENU DEL EXPLORADOR
// ─────────────────────────────────────────

void EcoMision::menuExplorador(Explorador* explorador) {

    int opcion;

    do {

        std::cout << "\n===== MENU EXPLORADOR: "
                  << explorador->getNombre()
                  << " =====\n";

        Zona* zona = explorador->getZonaActual();

        if(zona != nullptr) {

            std::cout << "Zona actual: "
                      << zona->getNombre()
                      << " ["
                      << zona->getTipoZona()
                      << "]"
                      << (zona->estaContaminada() ? " [CONTAMINADA]" : "")
                      << "\n";
        }

        std::cout << "1. Ver estado del explorador\n";
        std::cout << "2. Ver elementos de la zona actual\n";
        std::cout << "3. Interactuar con un elemento\n";
        std::cout << "4. Moverse a otra zona\n";
        std::cout << "5. Plantar semilla\n";
        std::cout << "6. Ver historial de la zona actual\n";
        std::cout << "7. Volver al menu principal\n";
        std::cout << "Opcion: ";

        std::cin >> opcion;

        switch(opcion) {

            case 1:
                explorador->mostrarEstado();
                break;

            case 2:
                if(zona != nullptr) {

                    zona->mostrarElementos();
                }

                else {

                    std::cout << "El explorador no tiene zona asignada\n";
                }

                break;

            case 3:
                interactuarEnZona(explorador);
                break;

            case 4:
                moverExplorador(explorador);
                break;

            case 5:
                plantarEnZona(explorador);
                break;

            case 6:
                if(zona != nullptr) {

                    zona->mostrarHistorial();

                    if(zona->getTipoZona() == "Natural") {

                        zona->mostrarInfoNatural();
                    }
                }

                else {

                    std::cout << "El explorador no tiene zona asignada\n";
                }

                break;

            case 7:
                std::cout << "Volviendo al menu principal...\n";
                break;

            default:
                std::cout << "Opcion invalida\n";
        }

        // Actualizar zona por si cambio al moverse
        zona = explorador->getZonaActual();

    } while(opcion != 7);
}

void EcoMision::interactuarEnZona(Explorador* explorador) {

    Zona* zona = explorador->getZonaActual();

    if(zona == nullptr) {

        std::cout << "El explorador no tiene zona asignada\n";
        return;
    }

    zona->mostrarElementos();

    if(zona->getTipoZona() == "Natural") {

        std::cout << "\nModos de interaccion:\n";
        std::cout << "1. Por numero de elemento\n";
        std::cout << "2. Por nombre del elemento\n";
        std::cout << "3. Por categoria del elemento\n";
        std::cout << "Modo: ";

        int modo;
        std::cin >> modo;

        if(modo == 1) {

            std::cout << "Ingrese el numero del elemento: ";
            int indice;
            std::cin >> indice;
            zona->interactuarElemento(indice - 1, explorador);
        }

        else if(modo == 2) {

            std::cout << "Ingrese el nombre del elemento"
                      << " (ej: AnimalHerido, SemillaNativa): ";
            std::string nombre;
            std::cin >> nombre;
            zona->interactuarElemento(nombre, explorador);
        }

        else if(modo == 3) {

            std::cout << "Ingrese la categoria"
                      << " (Natural / Contaminante / Tecnologico): ";
            std::string cat;
            std::cin >> cat;

            std::cout << "Ingrese la posicion dentro de esa categoria"
                      << " (1, 2, ...): ";
            int cual;
            std::cin >> cual;

            zona->interactuarElemento(cat, cual, explorador);
        }

        else {

            std::cout << "Modo invalido\n";
        }
    }

    else {

        std::cout << "\nIngrese el numero del elemento: ";
        int indice;
        std::cin >> indice;
        zona->interactuarElemento(indice - 1, explorador);
    }
}

void EcoMision::moverExplorador(Explorador* explorador) {

    if(reservas.empty()) {

        std::cout << "No hay reservas disponibles\n";
        return;
    }

    std::cout << "\nSeleccione la reserva destino:\n";

    Reserva* reserva = seleccionarReserva();

    if(reserva == nullptr) return;

    reserva->mostrarZonas();

    std::string codigoZona;

    std::cout << "Ingrese el codigo de la zona destino: ";
    std::cin >> codigoZona;

    Zona* zona = reserva->buscarZona(codigoZona);

    if(zona == nullptr) {

        std::cout << "Zona no encontrada\n";
        return;
    }

    explorador->cambiarZona(zona);

    std::cout << "Explorador movido a "
              << zona->getNombre() << "\n";
}

void EcoMision::plantarEnZona(Explorador* explorador) {

    explorador->mostrarSemillas();

    if(explorador->getZonaActual() == nullptr) {

        std::cout << "El explorador no tiene zona asignada\n";
        return;
    }

    std::string tipoSemilla;

    std::cout << "Ingrese el tipo de semilla a plantar: ";
    std::cin >> tipoSemilla;

    explorador->plantarSemilla(tipoSemilla);
}

// ─────────────────────────────────────────
//  UTILIDADES
// ─────────────────────────────────────────

Reserva* EcoMision::seleccionarReserva() {

    std::cout << "\nReservas disponibles:\n";

    for(int i = 0; i < (int)reservas.size(); i++) {

        std::cout << i + 1 << ". "
                  << reservas[i]->getNombre() << "\n";
    }

    std::cout << "Seleccione una reserva por su numero: ";

    int indice;
    std::cin >> indice;

    if(indice < 1 || indice > (int)reservas.size()) {

        std::cout << "Indice invalido\n";
        return nullptr;
    }

    return reservas[indice - 1];
}

Explorador* EcoMision::buscarExplorador(std::string nombre) {

    for(int i = 0; i < (int)exploradores.size(); i++) {

        if(exploradores[i]->getNombre() == nombre) {

            return exploradores[i];
        }
    }

    return nullptr;
}
