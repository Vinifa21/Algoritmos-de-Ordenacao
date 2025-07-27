#include <vector>
#include <cmath>
#include <algorithm>

// utiliza vector, para ajudar na manipulação dos buckets

void Bucketsort(std::vector<double>& L, std::vector<double>& S) {
    int n = L.size();
    std::vector<std::vector<double>> B(n);  // Vetores para buckets

    // Distribuição dos elementos nos buckets
    for (int i = 0; i < n; ++i) {
        int index;
        if (L[i] == 1.0)
            index = n - 1;
        else
            index = std::min(static_cast<int>(n * L[i]), n - 1);

        B[index].push_back(L[i]);
    }

    // Ordena cada bucket
    for (int i = 0; i < n; ++i) {
        std::sort(B[i].begin(), B[i].end());
    }

    // Concatena os buckets em um único vetor S; passado por referencia
    for (int i = 0; i < n; ++i) {
        for (double val : B[i]) {
            S.push_back(val);
        }
    }

}
