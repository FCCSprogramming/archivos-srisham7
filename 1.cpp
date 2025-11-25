#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TFECHA {
    int dia, mes;
};

struct TCARGA {
    int numpasajeros;
    TFECHA* fecha;
};

int main() {
    srand(time(NULL));

    const int DIAS = 360;
    const int CAPACIDAD_MAX = 700;
    const int MIN_REQUERIDO = 0.95 * CAPACIDAD_MAX;

    TCARGA* A;
    A = new TCARGA[DIAS];

    int dia = 1, mes = 1;

    for (int i = 0; i < DIAS; i++) {

        A[i].numpasajeros = 500 + rand() % 201; // entre 500 y 700 pasajeros

        // creear fecha
        A[i].fecha = new TFECHA;
        (*A[i].fecha).dia = dia;
        (*A[i].fecha).mes = mes;

        dia++;
        if (dia > 30) {
            dia = 1;
            mes++;
        }
    }

    int contador = 0;
    for (int i = 0; i < DIAS; i++) {
        if (A[i].numpasajeros >= MIN_REQUERIDO)
            contador++;
    }

    cout << "Se encontraron " << contador
         << " dias con carga minima de "
         << MIN_REQUERIDO << " pasajeros\n\n";

    for (int i = 0; i < DIAS; i++) {
        if (A[i].numpasajeros >= MIN_REQUERIDO) {
            cout <<(*A[i].fecha).dia << " / "
                 << (*A[i].fecha).mes << " : "
                 << A[i].numpasajeros << " pasajeros\n";
        }
    }

    // liberar memoria
    for (int i = 0; i < DIAS; i++)
        delete A[i].fecha;

    delete[] A;

    return 0;
}
