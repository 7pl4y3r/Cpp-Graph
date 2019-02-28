#include <iostream>
#include <fstream>

class Matrice {

private:

    std::ifstream in;
    int maxDimen = 9;

    bool dimensAreValid(int d1, int d2) {
        return ((d1 <= maxDimen && d2 <= maxDimen) ? true : false);
    }

    void throwMatrixSizeError() {
        std::cout << "Dimensiunea matricei este prea mare!\n";
        std::cout << "n <= 9 && m <= 9\n\n";
    }

public:

    Matrice(char path[]) {
        in.open(path);
    }

    void citesteMatrice(int a[10][10], int &n, int &m) {

        in >> n >> m;

        if (!dimensAreValid(n, m)) {
            throwMatrixSizeError();
            return;
        }

        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> a[i][j];

            in.close();
    }

    void afisareMatrice(int a[10][10], int n, int m) {

        if (!dimensAreValid(n, m)) {
            throwMatrixSizeError();
            return;
        }

        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            std::cout << a[i][j] << ' ';

            std::cout << '\n';
        }

    }

};
