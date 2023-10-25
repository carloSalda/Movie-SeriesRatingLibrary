#include <iostream>
#include "video.h"
using namespace std;

void Video::setIdVideo(int idvideo) {
    IdVideo = idvideo;
}

int Video::getIdVideo() {
    return IdVideo;
}

void Video::setTitulo(string titulo) {
    Titulo = titulo;
}

string Video::getTitulo() {
    return Titulo;
}

void Video::setGenero(string genero) {
    Genero = genero;
}

string Video::getGenero() {
    return Genero;
}

void Video::setDuracion(int duracion) {
    Duracion = duracion;
}

int Video::getDuracion() {
    return Duracion;
}

void Video::setCalificacion(int calificacion) {
    Calificacion = calificacion;
}

int Video::getCalificacion() {
    return Calificacion;
}

Video::Video(int idvideo, string titulo, string genero, int duracion, int calificacion) {
    IdVideo = idvideo;
    Titulo = titulo;
    Genero = genero;
    Duracion = duracion;
    Calificacion = calificacion;
}

void Video::mostrarDatos() {
    cout << "ID Video - " << IdVideo << endl;
    cout << "Titulo - " << Titulo << endl;
    cout << "Genero - " << Genero << endl;
    cout << "Duracion - " << Duracion << endl;
    cout << "Calificacion - " << Calificacion << endl;
}
