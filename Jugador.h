#pragma once
#include "Participante.h"

// Clase derivada que representa a un jugador en un partido, heredando de la clase base Participante.
class Jugador : public Participante {
public:
    // Constructor por defecto que llama al constructor por defecto de la clase base.
    Jugador();
    // Constructor que toma un nombre y una habilidad para inicializar la instancia, llamando al constructor de la clase base.
    Jugador(std::string nombre, int habilidad);
};

// Implementación del constructor por defecto.
Jugador::Jugador() : Participante() {}

// Implementación del constructor que toma un nombre y una habilidad.
Jugador::Jugador(std::string nombre, int habilidad) : Participante(nombre, habilidad) {}
