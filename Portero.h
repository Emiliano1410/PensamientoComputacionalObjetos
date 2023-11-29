#pragma once
#include "Participante.h"
#include <cstdlib>

// Clase derivada que representa a un portero en un partido, heredando de la clase base Participante.
class Portero : public Participante {
public:
    // Constructor por defecto que llama al constructor por defecto de la clase base.
    Portero();
    // Constructor que toma un nombre y una habilidad para inicializar la instancia, llamando al constructor de la clase base.
    Portero(std::string nombre, int habilidad);
    // Método para simular la acción de atajar un tiro penal, devuelve true si el portero logra atajarlo, false si no.
    bool atajar() const;
};

// Implementación del constructor por defecto.
Portero::Portero() : Participante() {}

// Implementación del constructor que toma un nombre y una habilidad.
Portero::Portero(std::string nombre, int habilidad) : Participante(nombre, habilidad) {}

// Implementación del método para simular la acción de atajar un tiro penal.
bool Portero::atajar() const {
    // La probabilidad de atajar es inversamente proporcional a la habilidad del portero.
    int probabilidad = rand() % 100;
    return probabilidad > habilidad;
}
