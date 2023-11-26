#pragma once
#include "Participante.h"
#include <cstdlib>

class Portero : public Participante {
public:
    Portero();
    Portero(std::string nombre, int habilidad);
    bool atajar() const;
};

Portero::Portero() : Participante() {}

Portero::Portero(std::string nombre, int habilidad) : Participante(nombre, habilidad) {}

bool Portero::atajar() const {
    // La probabilidad de atajar es inversamente proporcional a la habilidad del portero.
    int probabilidad = rand() % 100;
    return probabilidad > habilidad;
}