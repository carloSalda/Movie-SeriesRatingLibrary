#include <iostream>
using namespace std;
#ifndef VIDEO_H
#define VIDEO_H


class Video {
protected:
    int IdVideo;
    string Titulo;
    string Genero;
    int Duracion;
    int Calificacion;

public:
    void setIdVideo(int idvideo);
    int getIdVideo();
    void setTitulo(string titulo);
    string getTitulo();
    void setGenero(string genero);
    string getGenero();
    void setDuracion(int duracion);
    int getDuracion();
    void setCalificacion(int calificacion);
    int getCalificacion();

    Video(int idvideo, string titulo, string genero, int duracion, int calificacion);

    virtual void mostrarDatos();
};

#endif