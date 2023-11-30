#include "Jugador.h"
#include "Portero.h"
#include "Partido.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    // Garantizar que la secuencia de números aleatorios generada por std::rand() sea diferente en cada ejecución.
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Declarar variables para contar goles
    int golesJugador1 = 0;
    int golesJugador2 = 0;

    // Ingresar nombres de jugadores y porteros
    std::string nombreJugador1, nombrePortero1, nombreJugador2, nombrePortero2;
    std::cout << "Ingrese el nombre del primer jugador: ";
    std::getline(std::cin, nombreJugador1);
    std::cout << "Ingrese el nombre del primer portero: ";
    std::getline(std::cin, nombrePortero1);
    std::cout << "Ingrese el nombre del segundo jugador: ";
    std::getline(std::cin, nombreJugador2);
    std::cout << "Ingrese el nombre del segundo portero: ";
    std::getline(std::cin, nombrePortero2);

    // Crear partidos
    Partido* partido1 = new Partido();
    Partido* partido2 = new Partido();

    // Actualizar los partidos con los nombres de jugadores y porteros
    partido1->actualizarPartido(nombreJugador1, nombrePortero1);
    partido2->actualizarPartido(nombreJugador2, nombrePortero2);
  
    // Ejecutar penales y contar goles
    for (int i = 0; i < 5; ++i) {
        partido1->ejecutarPenal();
        partido2->ejecutarPenal();
    }

    // Sumar los goles del primer jugador
    golesJugador1 += partido1->getGolesEquipoLocal();

    // Sumar los goles del segundo jugador
    golesJugador2 += partido2->getGolesEquipoLocal();


    // Calcular y mostrar resultado final
    std::cout << "\nResultado Final:\n";
    std::cout << nombreJugador1 << ": " << golesJugador1 << " goles\n";
    std::cout << nombreJugador2 << ": " << golesJugador2 << " goles\n";

    // Determinar y mostrar al ganador
    if (golesJugador1 > golesJugador2) {
        std::cout << nombreJugador1 << " es el ganador.\n";
    } else if (golesJugador1 < golesJugador2) {
        std::cout << nombreJugador2 << " es el ganador.\n";
    } else {
        std::cout << "¡Empate!\n";
    }

    // Liberar memoria
    delete partido1;
    delete partido2;

    return 0;
}
