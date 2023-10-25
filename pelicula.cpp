#include <iostream>
#include "pelicula.h"
using namespace std;

Pelicula::Pelicula(int idvideo, string titulo, string genero, int duracion, int calificacion)
    : Video(idvideo, titulo, genero, duracion, calificacion) {}

void Pelicula::mostrarDatos() {
    cout << "Tipo: Pelicula" << endl;
    Video::mostrarDatos();
}
