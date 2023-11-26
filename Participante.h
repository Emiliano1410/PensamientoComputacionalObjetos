#pragma once
#include <string>

class Participante {
protected:
    std::string nombre;
    int habilidad;

public:
    Participante();
    Participante(std::string nombre, int habilidad);
    std::string getNombre() const;
    int getHabilidad() const;
};

Participante::Participante() : nombre(""), habilidad(0) {}

Participante::Participante(std::string nombre, int habilidad) : nombre(nombre), habilidad(habilidad) {}

std::string Participante::getNombre() const {
    return nombre;
}

int Participante::getHabilidad() const {
    return habilidad;
}