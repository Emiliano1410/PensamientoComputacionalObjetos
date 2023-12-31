#pragma once
#include "Portero.h"
#include "Jugador.h"
#include <iostream>

// Clase que representa un partido de fútbol con un equipo local, un portero visitante y un marcador de goles.
class Partido {
private:
    Jugador* equipoLocal; // Puntero al jugador que representa al equipo local.
    Portero* porteroVisitante; // Puntero al portero visitante
    int golesEquipoLocal; // Contador de goles del equipo local

public:
    // Constructor por defecto que inicializa los punteros a nullptr y el contador de goles a cero.
    Partido();
    // Constructor que toma los nombres de los jugadores y de los porteros
    Partido(const std::string& nombreJugador, const std::string& nombrePortero);
    // Destructor
    ~Partido();
    // Método para ejecutar un penal, solicitando al usuario el lado del tiro y determinando si se anota un gol o es atajado.
    void ejecutarPenal();
    // Método para obtener el número de goles anotados por el equipo local.
    int getGolesEquipoLocal() const;
    // Método para actualizar los nombres de los jugadores y porteros
    void actualizarPartido(const std::string& nombreJugador, const std::string& nombrePortero);
};

// Implementación del constructor por defecto.
Partido::Partido() : equipoLocal(nullptr), porteroVisitante(nullptr), golesEquipoLocal(0) {}
// Implementación del constructor que toma nombres de jugador y portero como parámetros
Partido::Partido(const std::string& nombreJugador, const std::string& nombrePortero)
    : equipoLocal(new Jugador(nombreJugador, 90)), porteroVisitante(new Portero(nombrePortero, 80)), golesEquipoLocal(0) {}

// Implementación del destructor
Partido::~Partido() {
    delete equipoLocal;
    delete porteroVisitante;
}
// Implementación del método para ejecutar un penal.
void Partido::ejecutarPenal() {
    std::string lado;

    // Ciclo do-while para garantizar una entrada válida del usuario.
    do {
        std::cout << "Turno de " << equipoLocal->getNombre() << ". ¿A qué lado quieres tirar? (izquierda/derecha/centro): ";
        std::cin >> lado;

        // Comprobación de entrada
        if (lado != "izquierda" && lado != "derecha" && lado != "centro") {
            std::cout << "Entrada no válida. Por favor, ingresa 'izquierda', 'derecha' o 'centro'.\n";
        }
    } while (lado != "izquierda" && lado != "derecha" && lado != "centro");

    // Mensaje indicando hacia dónde se va a tirar el penal.
    std::cout << equipoLocal->getNombre() << " va a tirar hacia " << lado << ".\n";

    // Determinar si el portero visitante logra atajar el penal.
    if (porteroVisitante->atajar()) {
        std::cout << "¡Atajó el portero " << porteroVisitante->getNombre() << "!\n";
    } else {
         // Mensaje de gol y aumento del contador de goles.
        std::cout << "¡Gol para " << equipoLocal->getNombre() << "!\n";
        golesEquipoLocal++;  // Incrementar el contador de goles
    }
}

// Implementación del método para obtener el número de goles del equipo local.
int Partido::getGolesEquipoLocal() const {
    return golesEquipoLocal;
}

// Implementacion del metodo para actualizar los nombres de los jugadores y porteros
void Partido::actualizarPartido(const std::string& nombreJugador, const std::string& nombrePortero) {
    delete equipoLocal;  // Liberar memoria del jugador existente
    delete porteroVisitante;  // Liberar memoria del portero existente

    // Crear nuevos jugadores y porteros con los nombres proporcionados
    equipoLocal = new Jugador(nombreJugador, 90);
    porteroVisitante = new Portero(nombrePortero, 80);
}
