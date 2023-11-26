#pragma once
#include "Participante.h"

class Jugador : public Participante {
public:
    Jugador();
    Jugador(std::string nombre, int habilidad);
};

Jugador::Jugador() : Participante() {}

Jugador::Jugador(std::string nombre, int habilidad) : Participante(nombre, habilidad) {}