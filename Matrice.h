#include <iostream>
#include <fstream>


class Matrice {

private:

    std::ifstream in;
    int maxDimen = 9;

    bool dimensAreValid(int d) {
        return ((d <= maxDimen) ? true : false);
    }

    void throwMatrixSizeError() {
        std::cout << "Dimensiunea matricei este prea mare!\n";
        std::cout << "n <= 9\n\n";
    }

public:

    Matrice(char path[]) {
        in.open(path);
    }

    void citesteMatrice(int a[10][10], int &n) {

        in >> n;

        if (!dimensAreValid(n)) {
            throwMatrixSizeError();
            return;
        }

        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> a[i][j];

            in.close();
    }

    void citArce(int a[20][20], int &n) {

        in>>n;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
                a[i][j] = 500;

        int x, y, cost;
        while(f >> x >> y >> cost)
            a[x][y] = cost;
    }



    /*
     * @param C costul
     * @param T tatii
     * @param viz nodurile vizitate
     * @param x nodul de start
    */
    void dijkstra(int a[10][10], int C[50], int T[50], int viz[20], int n, int x) {

        int i, j, mini, y;


        // salvam costurile in C si daca a[x][i] == 1 atunci x este nodul tata al lui i
        viz[x] = 1;
        for (i = 1; i <= n; i++) {
            C[i] = a[x][i];
            if (x != i && C[i] < 500)
                T[i] = x;
        }


        //
        for (i = 1; i <= n - 1; i++) {

            mini = 500;
            for (j = 1; j <= n; j++)
                if (viz[j] == 0 && C[j] < 500) {
                    mini = C[j];
                    y = j;
                }


            viz[y] = 1;
            for (j = 1; j <= n; j++) {
                if (viz[j] == 0) {
                    if (C[j] > C[y] + a[y][j] && a[y][j] != 500) {
                        C[j] = C[y] + a[y][j];
                        T[j] = y;
                    }

                }

            }

        }

    }


    void drum(int T[50], int i) {

        if (T[i] != 0) {
            drum(T[i], T);
            std::cout << i <<' ';
        }

    }

    void afisareMatrice(int a[10][10], int n) {

        if (!dimensAreValid(n)) {
            throwMatrixSizeError();
            return;
        }

        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            std::cout << a[i][j] << ' ';

            std::cout << '\n';
        }

        std::cout << '\n';
    }

    void BF(int a[10][10], int n, int start) {

        int coada[10], viz[10] = {0}, p, u, x;

        p = u = 1;
        coada[p] = start;
        viz[p] = 1;

        while (p <= u) {

            x = coada[p];
            for (int i = 1; i <= n; i++) {
                if (a[x][i] == 1 && viz[i] == 0) {
                    u++;
                    coada[u] = i;
                    viz[i] = 1;
                }
            }

            std::cout << coada[p] << ' ';
            p++;

        }

        std::cout << std::endl;
    }

    void DF(int a[10][10], int viz[10], int n, int x) {

        std::cout << x << ' ';
        viz[x] = 1;
        for (int i = 1; i <= n; i++)
            if (a[x][i] == 1 && viz[i] == 0)
                DF(a, viz, n, i);

    }

};
