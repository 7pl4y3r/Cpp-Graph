#include <iostream>
#include "Matrice.h"


char path[] = "matricea1.txt";
char path1[] = "arce.txt";

int a[10][10], n, m;
int viz[10];
int start = 1;

int main()
{
    Matrice mat(path);
    mat.citesteMatrice(a, n);
    mat.afisareMatrice(a, n);

    std::cout << "BF\n\n";
    mat.BF(a, n, start);

    std::cout << "DF\n";
    mat.DF(a, viz, n, start);

    std::cout << "Dijksta\n";


    return 0;
}
