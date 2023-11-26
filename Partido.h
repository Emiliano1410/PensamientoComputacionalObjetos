#pragma once
#include "Participante.h"
#include "Portero.h"
#include <iostream>

class Partido {
private:
    Participante* equipoLocal;
    Portero* porteroVisitante;
    int golesEquipoLocal;

public:
    Partido();
    Partido(Participante* equipoLocal, Portero* porteroVisitante);
    void ejecutarPenal();
    int getGolesEquipoLocal() const;
};

Partido::Partido() : equipoLocal(nullptr), porteroVisitante(nullptr), golesEquipoLocal(0) {}

Partido::Partido(Participante* equipoLocal, Portero* porteroVisitante)
    : equipoLocal(equipoLocal), porteroVisitante(porteroVisitante),             golesEquipoLocal(0) {}

void Partido::ejecutarPenal() {
    std::string lado;
    do {
        std::cout << "Turno de " << equipoLocal->getNombre() << ". ¿A qué lado quieres tirar? (izquierda/derecha/centro): ";
        std::cin >> lado;

        // Comprobación de entrada
        if (lado != "izquierda" && lado != "derecha" && lado != "centro") {
            std::cout << "Entrada no válida. Por favor, ingresa 'izquierda', 'derecha' o 'centro'.\n";
        }
    } while (lado != "izquierda" && lado != "derecha" && lado != "centro");

    std::cout << equipoLocal->getNombre() << " va a tirar hacia " << lado      << ".\n";

    if (porteroVisitante->atajar()) {
        std::cout << "¡Atajó el portero " << porteroVisitante->getNombre()         << "!\n";
    } else {
        std::cout << "¡Gol para " << equipoLocal->getNombre() << "!\n";
        golesEquipoLocal++;  // Incrementar el contador de goles
    }
}

int Partido::getGolesEquipoLocal() const {
    return golesEquipoLocal;
}