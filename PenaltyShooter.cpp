#include <iostream>
#include <cstdlib>
#include <ctime>

class Jugador {
private:
    std::string nombre;
    int habilidad;

public:
    Jugador(std::string nombre, int habilidad) : nombre(nombre), habilidad(habilidad) {}

    std::string getNombre() const {
        return nombre;
    }

    int getHabilidad() const {
        return habilidad;
    }
};

class Portero {
private:
    std::string nombre;
    int habilidad;

public:
    Portero(std::string nombre, int habilidad) : nombre(nombre), habilidad(habilidad) {}

    std::string getNombre() const {
        return nombre;
    }

    int getHabilidad() const {
        return habilidad;
    }

    bool atajar() const {
        // La probabilidad de atajar es inversamente proporcional a la habilidad del portero.
        int probabilidad = rand() % 100;
        return probabilidad > habilidad;
    }
};

class Partido {
private:
    Jugador* equipoLocal;
    Portero* porteroVisitante;

public:
    Partido(Jugador* equipoLocal, Portero* porteroVisitante)
        : equipoLocal(equipoLocal), porteroVisitante(porteroVisitante) {}

    void ejecutarPenal() {
        std::cout << "Turno de " << equipoLocal->getNombre() << ". ¿A qué lado quieres tirar? (izquierda/derecha/centro): ";
        std::string lado;
        std::cin >> lado;

        std::cout << equipoLocal->getNombre() << " va a tirar hacia " << lado << ".\n";

        if (porteroVisitante->atajar()) {
            std::cout << "¡Atajó el portero " << porteroVisitante->getNombre() << "!\n";
        } else {
            std::cout << "¡Gol para " << equipoLocal->getNombre() << "!\n";
        }
    }
};

int main() {
    // Configuración de semilla para números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Declarar variables para contar goles
    int golesJugador1 = 0;
    int golesJugador2 = 0;

    // Ingresar nombres de jugadores
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

    // Contar goles del primer jugador
    for (int i = 0; i < 5; ++i) {
        if (!portero1->atajar()) {
            golesJugador1++;
        }
    }

    // Contar goles del segundo jugador
    for (int i = 0; i < 5; ++i) {
        if (!portero2->atajar()) {
            golesJugador2++;
        }
    }


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