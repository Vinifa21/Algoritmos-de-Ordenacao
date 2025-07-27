// low e high são os indices dos elementos mais a esq e mais a dir do array (definem o range q o quick vai trabalhar)
int partition(double arr[], int low, int high) {
    double pivo = arr[high];
    int max_esq = low - 1; // maior indice do lado esq
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] <= pivo) { // j pertence ao lado esq?
            max_esq = max_esq +1;
            swap(arr[j], arr[max_esq]);
        }
    }
    swap(arr[high], arr[max_esq + 1]); // pivo vai para sua posição ordenada
    return max_esq + 1; // retorno o novo q, que sera o divisor entre os arrays do prox quick
}


void Quicksort(double arr[], int low, int high){
    int q;
    if(high > low) {
        q = partition(arr, low, high); // particiona o array
        Quicksort(arr, low, q-1);// chamada recursiva para o subarray à esq do pivo
        Quicksort(arr, q+1, high);// chamada recursiva para o subarray à dir do pivo
    }
}
