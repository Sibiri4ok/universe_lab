#include <stdio.h>
void sort(int array[], int array_lenght) {
    for (int i = 0; i < array_lenght; ++ i) {
        int minNumbers = array[i], indMinNumbers = i;
        for (int j = i + 1; j < array_lenght; ++ j) {
            if (array[j] < minNumbers) {
                minNumbers = array[j];
                indMinNumbers = j;
            }
        }
        int temp = array[i];
        array[i] = array[indMinNumbers];
        array[indMinNumbers] = temp;
        }
}

