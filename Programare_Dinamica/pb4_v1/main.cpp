#include <cstdio>
#include <ctype.h>
#include <vector>
#include<iostream>
using namespace std;

const int NMAX = 1000;

struct structura {
    bool exista;
    int index_vector;
    int precedent;
};
vector <int> v[NMAX];
int dp[NMAX][NMAX];
vector <int> vector_solutie;

int main() {

    freopen ("date.in", "r", stdin);
    int n, k, numar_curent;
    char ch;

    scanf ("%d %d\n", &n, &k);
    for (int i = 1; i <= n; i++) {

        numar_curent = 0;
        v[i].push_back(0);
        while (1) {
            scanf ("%c", &ch);
            if (ch == '\n')
                break;
            if (isdigit(ch))
                numar_curent = numar_curent * 10 + (ch - '0');
            else
            if (ch == ' ') {
                v[i].push_back(numar_curent);
                numar_curent = 0;
            }
        }
        v[i].push_back(numar_curent);
    }


    for (int i = 1; i < v[1].size(); i++) {
        dp[1][v[1][i]] = i;//marcam elementele din primul vector,iar pe restul pozitilor este 0
    }

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < v[i].size(); j++)
            for (int d = 1; d <= k; d++)//d este elementul din vectorul anterior
                if (dp[i-1][d] != 0 && d + v[i][j] <= k)
                    dp[i][d + v[i][j]] = j;//marcam sumele care exista, iar restul sunt 0

    if (dp[n][k] == 0)
        printf ("Nu exista solutie.");
    else {
        int linie = n, coloana = k, valoare_vector;
        do {
                //cout<<coloana<<" "<<coloana<<endl;
            valoare_vector = v[linie][dp[linie][coloana]];//nr cu care am adunat ca sa ajungi la suma ta
            vector_solutie.push_back(valoare_vector);

            coloana = coloana - valoare_vector;//scad valoarea pt a determina numarul din care s-a format
            linie--;
        } while(linie != 0);

        for (int i = vector_solutie.size() - 1; i >= 0; i--)
            printf("%d ", vector_solutie[i]);
    }
    printf("\n");

    return 0;
}
