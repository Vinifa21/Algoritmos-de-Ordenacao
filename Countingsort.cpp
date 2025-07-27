// valido para números inteiros

int maior_vetor(int arr[], int size) {

    int maior_valor = arr[0];
    for (int i = 0; i < size; i++) {
        if(arr[i] > maior_valor) {
            maior_valor = arr[i];
        }
    }

    return maior_valor;
}



void CountingSort(int arr[], int S[], int size) {
    int maior_valor = maior_vetor(arr, size);

    int C[maior_valor + 1]; // crio e zero vetor com tamanho do maior elemento de arr + 1
    for (int i = 0; i < maior_valor + 1; i++) {
        C[i] = 0;
    }
    for (int i = 0; i < size ; i++) {
        S[i] = 0;
    }

    // preencho C[0] com o número de vezes em que 0 aparece ...
    for (int i = 0; i < size; i++) {
        C[arr[i]] = C[arr[i]] + 1;
    }

    //calcula a soma acumulada do vetor
    for (int i = 1; i <= maior_valor; i++) {
        C[i] = C[i] + C[i - 1];
    }

    //ordena arr no vetor S
    for (int i = 0; i < size; i++) {
        C[arr[i]] = C[arr[i]] - 1;
        S[C[arr[i]]] = arr[i];
    }

    // vetor ordenado (S) é passado por referencia para a main

}
