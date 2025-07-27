// valido para números inteiros
// é um countingsort adapdtado, que agrupa pelos digitos

#include <stdio.h>
#include <stdlib.h>

#define tamanho 30000

int maior_vetor(int arr[], int size) {
    int maior_valor = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maior_valor) {
            maior_valor = arr[i];
        }
    }
    return maior_valor;
}

void CountingSort_R(int arr[], int S[], int size, int digito) {
    int C[10] = {0}; // sempre de 0 a 9

    // Contagem das ocorrências dos dígitos
    for (int i = 0; i < size; i++) {
        int index = (arr[i] / digito) % 10;
        C[index]++;
    }

    // Soma acumulada
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Construção do vetor ordenado
    for (int i = size - 1; i >= 0; i--) {
        int index = (arr[i] / digito) % 10;
        C[index]--;
        S[C[index]] = arr[i];
    }

    // Cópia de S[] de volta para arr[]
    for (int i = 0; i < size; i++) {
        arr[i] = S[i];
    }
}

void Radixsort(int arr[], int S[]) {
    int maior_valor = maior_vetor(arr, tamanho);
    int digito = 1;

    while (maior_valor / digito > 0) {
        CountingSort_R(arr, S, tamanho, digito);
        digito *= 10;
    }
}
