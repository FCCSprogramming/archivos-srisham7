#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    string archLaguna = "laguna.txt";
    string archArea = "area.txt";

    ifstream in(archLaguna);
    ofstream out(archArea);

    if (!in.is_open()) {
        cout << "No se pudo abrir laguna.txt\n";
        return 1;
    }

    int nt; 
    int nv;

    in >> nt; //triangulos
    in >> nv; //vertices

    //arreglo para los vertices
    float **P = new float*[nv];
    for (int i = 0; i < nv; ++i) {
        P[i] = new float[2];
    }

    //arreglo para los triangulos
    int **T = new int*[nt];
    for (int i = 0; i < nt; ++i) {
        T[i] = new int[3];
    }

    for (int i = 0; i < nv; ++i) {
        in >> P[i][0] >> P[i][1];
    }

    for (int i = 0; i < nt; ++i) {
        in >> T[i][0] >> T[i][1] >> T[i][2];
    }

    // calcular area total
    float areaTotal = 0.0;

    for (int i = 0; i < nt; ++i) {

        int a = T[i][0] - 1;  
        int b = T[i][1] - 1;
        int c = T[i][2] - 1;

        float x1 = P[a][0], y1 = P[a][1];
        float x2 = P[b][0], y2 = P[b][1];
        float x3 = P[c][0], y3 = P[c][1];

        float area = fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;

        areaTotal += area;
    }

    // guardar en archivo
    out << areaTotal;

    // liberar memoria
    for (int i = 0; i < nv; ++i) {
        delete[] P[i];
    }
    delete[] P;

    for (int i = 0; i < nt; ++i) {
        delete[] T[i];
    }
    delete[] T;

    in.close();
    out.close();

    return 0;
}
