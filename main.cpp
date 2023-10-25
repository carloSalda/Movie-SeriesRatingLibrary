#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include "video.h"
#include "episodio.h"
#include "pelicula.h"

using namespace std;

vector<Video*> leerVideosDesdeArchivo(const string& nombreArchivo) {
    vector<Video*> videos;
    ifstream archivo(nombreArchivo);

    if (archivo) {
        string line;
        while (getline(archivo, line)) {
            istringstream iss(line);
            string tipo;
            if (iss >> tipo) {
                if (tipo == "e") { // Episodio
                    int idvideo, duracion;
                    double calificacion;
                    string titulo, genero, tituloSerie;
                    int episodioNum, temporadaNum;
                    if (iss >> idvideo >> titulo >> genero >> duracion >> calificacion >> tituloSerie >> episodioNum >> temporadaNum) {
                        videos.push_back(new Episodio(idvideo, titulo, genero, duracion, calificacion, tituloSerie, episodioNum, temporadaNum));
                    }
                } else if (tipo == "p") { // Pelicula
                    int idvideo, duracion, calificacion;
                    string titulo, genero;
                    if (iss >> idvideo >> titulo >> genero >> duracion >> calificacion) {
                        videos.push_back(new Pelicula(idvideo, titulo, genero, duracion, calificacion));
                    }
                }
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo '" << nombreArchivo << "'." << endl;
    }

    return videos;
}



void mostrarVideos(const vector<Video*>& videos) {
    cout << "Lista de videos:" << endl;

    for (const auto& video : videos) {
        video->mostrarDatos();
        cout << endl;
    }
}

void mostrarVideosPorCalificacion(const vector<Video*>& videos, int calificacion) {
    cout << "Videos con calificación " << calificacion << ":" << endl;
    bool encontrado = false;

    for (const auto& video : videos) {
        if (video->getCalificacion() == calificacion) {
            video->mostrarDatos();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron videos con calificación " << calificacion << "." << endl;
    }
}

void mostrarEpisodiosPorCalificacion(const vector<Video*>& videos, const string& serie, int calificacion) {
    cout << "Episodios de la serie '" << serie << "' con calificación " << calificacion << ":" << endl;
    bool encontrado = false;

    for (const auto& video : videos) {
        Episodio* episodio = dynamic_cast<Episodio*>(video);
        if (episodio && episodio->getSerie() == serie && episodio->getCalificacion() == calificacion) {
            video->mostrarDatos();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron episodios de la serie '" << serie << "' con calificación " << calificacion << "." << endl;
    }
}

void mostrarPeliculasPorCalificacion(const vector<Video*>& videos, int calificacion) {
    cout << "Peliculas con calificación " << calificacion << ":" << endl;
    bool encontrado = false;

    for (const auto& video : videos) {
        Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
        if (pelicula && pelicula->getCalificacion() == calificacion) {
            video->mostrarDatos();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron peliculas con calificación " << calificacion << "." << endl;
    }
}

void calificarVideo(vector<Video*>& videos, const string& titulo, int calificacion) {
    bool encontrado = false;

    for (const auto& video : videos) {
        if (video->getTitulo() == titulo) {
            video->setCalificacion(calificacion);
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "Se ha calificado el video '" << titulo << "' con " << calificacion << " estrellas." << endl;
    } else {
        cout << "No se encontró ningún video con el título '" << titulo << "'." << endl;
    }
}

int main() {
    vector<Video*> videos = leerVideosDesdeArchivo("datos.txt");
    int opcion;
    do {
        cout << "===== MENÚ =====" << endl;
        cout << "1. Mostrar todos los videos" << endl;
        cout << "2. Mostrar videos por calificación" << endl;
        cout << "3. Mostrar episodios de una serie con calificación" << endl;
        cout << "4. Mostrar películas con calificación" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
              cout << "==========" << endl;
                mostrarVideos(videos);
                break;
            case 2: {
              cout << "==========" << endl;
                int calificacion;
                cout << "Ingrese una calificación: ";
                cin >> calificacion;
                mostrarVideosPorCalificacion(videos, calificacion);
                break;
            }
            case 3: {
              cout << "==========" << endl;
                string serie;
                int calificacion;
                cout << "Ingrese el nombre de la serie: ";
                cin.ignore();
                getline(cin, serie);
                cout << "Ingrese una calificación: ";
                cin >> calificacion;
                mostrarEpisodiosPorCalificacion(videos, serie, calificacion);
                break;
            }
            case 4: {
              cout << "==========" << endl;
                int calificacion;
                cout << "Ingrese una calificación: ";
                cin >> calificacion;
                mostrarPeliculasPorCalificacion(videos, calificacion);
                break;
            }
            case 5: {
              cout << "==========" << endl;
                string titulo;
                int calificacion;
                cout << "Ingrese el título del video: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese una calificación: ";
                cin >> calificacion;
                calificarVideo(videos, titulo, calificacion);
                break;
            }
            case 0:
              cout << "==========" << endl;
                cout << "Gracias por usar el programa!"<<endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 0);

    for (auto video : videos) {
        delete video;
    }

    return 0;
}
