/* Programa que usa 3 algoritmos de ordenação em um vetor com 10 mil valores
gerados aleatoriamente, além de cronometrar o tempo de cada ordenação */
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

# define tamanho 30000
using namespace std;

void preenche_vetor(std::vector<double>& vetor) {
    std::random_device rd;              // fonte de aleatoriedade
    std::mt19937 gen(rd());             // gerador Mersenne Twister
    std::uniform_real_distribution<double> distrib(0.0, 200.0); // intervalo real [0, 200)

    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = distrib(gen);        // agora gera doubles aleatórios
    }
}


void imprime(vector<double>& vetor) {
    for (double val : vetor) {
        cout << val << " ";
    }
    cout << endl;
}


#include "Bucketsort.cpp"

int main(){
    vector<double> vetor(tamanho); // CORRETO
    vector<double> vetor_ordenado;


    preenche_vetor(vetor);
    //imprime(vetor); //descomentar essa linha para ver o vetor inicial
    cout << "comeca a ordenar." << endl;

    // inicia tempo
    clock_t begin = clock();
    Bucketsort(vetor, vetor_ordenado); // passo veotr ordenado por referencia
    begin = clock() - begin; // encerra tempo

     imprime(vetor_ordenado); // Descomentar essa linha para ver o vetor ordenado
    cout << "O vetor com " << tamanho << " levou  " << ((float)begin) / CLOCKS_PER_SEC << " segundos para ser ordenado usando  o Bucketsort"<< endl; // tempo

    return 0;
}

