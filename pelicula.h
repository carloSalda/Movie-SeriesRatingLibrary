#include <iostream>
#include "video.h"
using namespace std;
#ifndef PELICULA_H
#define PELICULA_H

class Pelicula : public Video {
private:

public:
    Pelicula(int idvideo, string titulo, string genero, int duracion, int calificacion);

    void mostrarDatos();
};

#endif
