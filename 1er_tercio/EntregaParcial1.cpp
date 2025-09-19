#include <iostream>
#include <cmath>

//Integrantes Devid Poll Arteche y Juan Felipe Rodriguez

// Definir la estructura de un punto en 2D
struct Point {
    double x, y;
};

// Función para calcular la distancia entre dos puntos (uso de referencias constantes para eficiencia)
double calcularDistancia(const Point &p1, const Point &p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n) {
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        for (int i = 0; i < n; i++) {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};
        puntos[1] = {3, 4};
        puntos[2] = {6, 8};
        puntos[3] = {9, 12};
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    indiceMasCercano = 0;
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);

    for (int i = 1; i < n; i++) {
        double distanciaActual = calcularDistancia(puntos[i], pUsuario);
        if (distanciaActual < distanciaMinima) {
            distanciaMinima = distanciaActual;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// BONUS: calcular la distancia total de los puntos recorridos en orden
double calcularDistanciaTotal(Point puntos[], int n) {
    double total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return total;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia) {
    std::cout << "El punto más cercano es: (" 
              << puntos[indiceMasCercano].x << ", " 
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " 
              << distancia << std::endl;
}

int main() {
    int n;
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n];
    leerPuntos(puntos, n);

    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distanciaMinima = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distanciaMinima);

    // BONUS: distancia total recorrida
    std::cout << "La distancia total recorriendo los puntos en orden es: " 
              << calcularDistanciaTotal(puntos, n) << std::endl;

    return 0;
}
