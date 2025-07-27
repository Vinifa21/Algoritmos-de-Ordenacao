void  Shellsort( double arr[]) {// sequencia de Shell
    int gap = tamanho / 2; // gap vai diminuindo até chegar em 1

    while (gap > 0) { // (int)1 / 2  = 0
        for(int i = gap; i < tamanho; i++){
            int j = i;
            while(j >=gap && arr[j -gap] > arr[j]) {
                swap(arr[j], arr[j - gap]);
                j = j - gap;
            }
        }
        gap = gap / 2;
    }
}


void Shellsort_Knuth(double arr[]) {
    int h = 1;
    while (h < tamanho / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < tamanho; i++) {
            int j = i;
            while (j >= h && arr[j - h] > arr[j]) {
                swap(arr[j], arr[j - h]);
                j -= h;
            }
        }
        h /= 3;
    }
}

#include <cmath>

void Shellsort_Sedgwick(double arr[]) {

    int gaps[30];
    int count = 0;

    for (int k = 0; ; k++) {
        int h;
        if (k % 2 == 0) {
            h = 9 * pow(2, k) - 9 * pow(2, k / 2) + 1;
        } else {
            h = 8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1;
        }

        if (h > tamanho) break;
        gaps[count++] = h;
    }


    for (int g = count - 1; g >= 0; g--) {
        int h = gaps[g];
        for (int i = h; i < tamanho; i++) {
            int j = i;
            while (j >= h && arr[j - h] > arr[j]) {
                swap(arr[j], arr[j - h]);
                j -= h;
            }
        }
    }
}





