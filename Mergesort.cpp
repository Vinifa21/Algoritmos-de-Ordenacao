void merge(double arr[], int low,int q, int high) { // junta os subarrays
    // q = indice do meio da lista // low e high = indices mais baixos e alto da sublista

    int n_left = q - low + 1;
    int n_right = high - q;

    // cria e preenche os subarrays
    double L[n_left], R[n_right];
    for(int i = 0; i < n_left; i++) {
        L[i] = arr[low + i];
    }
    for(int j = 0; j < n_right; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = low; // parametros para os while

    while (i < n_left && j < n_right) {
        if ( L[i] <= R[j]) { // comparo o elemento equivalente dos 2 arrays
            arr[k] = L[i]; // coloco o menor deles na devida posicao no arr original
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
        while (i < n_left) { // se sobrar elementos em L
            arr[k] = L[i];
            i++; k++;
        }

    while (j < n_right) { // se sobrar elementos em R
        arr[k] = R[j];
        j++; k++;
    }

}



void Mergesort(double arr[], int low, int high) {
    // chama recursivamente a funcao merge
    if (low >= high) {  // caso subarray tenha menos que 1 elemento
        return;
    }
    int q = (low + high) / 2;
    Mergesort(arr, low, q); // chamo por recursão
    Mergesort(arr, q + 1, high);
    merge(arr, low, q, high); // junto os subarrays
}


/*
Entrada: chave_primaria

Se não encontrar chave primaria
    retornar "registro não encontrado
obter posição do registro
alterar o registro com os novos dados

Se novo_registro não cabe no espaço antigo
    Tornar registro antigo como inválido
    recria-lo no fim do arquivo
    Atualizar endereço desse registro no arquivo de indices

Se chave_primaria != nova chave_primaria
    remover indice antigo
    adicionar novo índice com chave_primária corrigida

retornar "ìndice alterado com successo"



*/