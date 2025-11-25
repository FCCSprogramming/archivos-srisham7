#include <iostream>
using namespace std;

struct Termino {
    int exponente;
    int coeficiente;
};

void agregarTermino(Termino* &P, int &n, int exp, int coef) {
    Termino* Q ;
    Q = new Termino[n + 1];
    for (int i = 0; i < n; i++) {
        Q[i] = P[i];
    }
    Q[n].exponente = exp;
    Q[n].coeficiente = coef;
    delete[] P;
    P = Q;
    n++;
}

void leerPolinomio(Termino* &P, int &n) {
    cin >> n;
    P = nullptr;
    int exp, coef;
    for (int i = 0; i < n; i++) {
        cin >> coef >> exp;
        agregarTermino(P, i, exp, coef);
    }
}

void simplificar(Termino* &P, int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (P[i].exponente == P[j].exponente) {
                P[i].coeficiente += P[j].coeficiente;
                for (int k = j; k < n - 1; k++) P[k] = P[k + 1];
                n--;
                j--;
            }
        }
    }
}

void ordenar(Termino* &P, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (P[i].exponente < P[j].exponente) {
                Termino t = P[i];
                P[i] = P[j];
                P[j] = t;
            }
        }
    }
}

void multiplicar(Termino* A, int nA, Termino* B, int nB, Termino* &R, int &nR) {
    R = nullptr;
    nR = 0;
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            int exp = A[i].exponente + B[j].exponente;
            int coef = A[i].coeficiente * B[j].coeficiente;
            agregarTermino(R, nR, exp, coef);
        }
    }
    simplificar(R, nR);
    ordenar(R, nR);
}

void mostrar(Termino* P, int n) {
    for (int i = 0; i < n; i++) {
        cout << P[i].coeficiente << "x^" << P[i].exponente;
        if (i < n - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    Termino *P1, *P2, *R;
    int n1, n2, n3;

    cout << "Primer polinomio: ";
    leerPolinomio(P1, n1);
    mostrar(P1, n1);

    cout << "Segundo polinomio: ";
    leerPolinomio(P2, n2);
    mostrar(P2, n2);

    multiplicar(P1, n1, P2, n2, R, n3);

    cout << "Polinomio Resultante: ";
    mostrar(R, n3);

    delete[] P1;
    delete[] P2;
    delete[] R;
    return 0;
}
