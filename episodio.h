#include <iostream>
#include "video.h"
using namespace std;
#ifndef EPISODIO_H
#define EPISODIO_H

class Episodio : public Video {
private:
    string Serie;
    int EpisodioNum;
    int TemporadaNum;

public:
    void setSerie(string serie);
    string getSerie();
    void setEpisodioNum(int episodioNum);
    int getEpisodioNum();
    void setTemporadaNum(int temporadaNum);
    int getTemporadaNum();

    Episodio(int idvideo, string titulo, string genero, int duracion, int calificacion, string serie, int episodioNum, int temporadaNum);



    void mostrarDatos();
};
#endif
