#pragma once
#include <string>

// Clase base que representa a un participante en un partido.
class Participante {
protected:
    std::string nombre; // Nombre del participante
    int habilidad; // Nivel de habilidad del participante

public:
    // Constructor por defecto que inicializa el nombre a una cadena vacía y la habilidad a cero.
    Participante();
    // Constructor que toma un nombre y una habilidad para inicializar la instancia.
    Participante(std::string nombre, int habilidad);
    // Método para obtener el nombre del participante.
    std::string getNombre() const;
    // Metodo para obtener la habilidad del participante
    int getHabilidad() const;
};

// Implementación del constructor por defecto.
Participante::Participante() : nombre(""), habilidad(0) {}

// Implementación del constructor que toma un nombre y una habilidad.
Participante::Participante(std::string nombre, int habilidad) : nombre(nombre), habilidad(habilidad) {}

// Implementación del método para obtener el nombre del participante.
std::string Participante::getNombre() const {
    return nombre;
}

// Implementación del método para obtener la habilidad del participante.
int Participante::getHabilidad() const {
    return habilidad;
}
