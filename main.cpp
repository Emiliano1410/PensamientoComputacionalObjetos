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
    std::cin >> nombreJugador1;
    std::cout << "Ingrese el nombre del primer portero: ";
    std::cin >> nombrePortero1;
    std::cout << "Ingrese el nombre del segundo jugador: ";
    std::cin >> nombreJugador2;
    std::cout << "Ingrese el nombre del segundo portero: ";
    std::cin >> nombrePortero2;

    // Crear jugadores y porteros
    Jugador* jugador1 = new Jugador(nombreJugador1, 90);
    Portero* portero1 = new Portero(nombrePortero1, 80);
    Jugador* jugador2 = new Jugador(nombreJugador2, 85);
    Portero* portero2 = new Portero(nombrePortero2, 75);

    // Crear partidos
    Partido* partido1 = new Partido(jugador1, portero1);
    Partido* partido2 = new Partido(jugador2, portero2);

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
    std::cout << jugador1->getNombre() << ": " << golesJugador1 << " goles\n";
    std::cout << jugador2->getNombre() << ": " << golesJugador2 << " goles\n";

    // Determinar y mostrar al ganador
    if (golesJugador1 > golesJugador2) {
        std::cout << jugador1->getNombre() << " es el ganador.\n";
    } else if (golesJugador1 < golesJugador2) {
        std::cout << jugador2->getNombre() << " es el ganador.\n";
    } else {
        std::cout << "¡Empate!\n";
    }

    // Liberar memoria
    delete jugador1;
    delete portero1;
    delete jugador2;
    delete portero2;
    delete partido1;
    delete partido2;

    return 0;
}
