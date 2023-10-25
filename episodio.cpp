#include <iostream>
#include "episodio.h"
using namespace std;

void Episodio::setSerie(string serie) {
    Serie = serie;
}

string Episodio::getSerie() {
    return Serie;
}

void Episodio::setEpisodioNum(int episodioNum) {
    EpisodioNum = episodioNum;
}

int Episodio::getEpisodioNum() {
    return EpisodioNum;
}

void Episodio::setTemporadaNum(int temporadaNum) {
    TemporadaNum = temporadaNum;
}

int Episodio::getTemporadaNum() {
    return TemporadaNum;
}

Episodio::Episodio(int idvideo, string titulo, string genero, int duracion, int calificacion, string serie, int episodioNum, int temporadaNum)
    : Video(idvideo, titulo, genero, duracion, calificacion) {
    Serie = serie;
    EpisodioNum = episodioNum;
    TemporadaNum = temporadaNum;
}

void Episodio::mostrarDatos() {
    cout << "Tipo: Episodio" << endl;
    Video::mostrarDatos();
    cout << "Serie - " << Serie << endl;
    cout << "Episodio - " << EpisodioNum << endl;
    cout << "Temporada - " << TemporadaNum << endl;
}
