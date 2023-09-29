#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char* argv[]) {
    int from = 0, to = 0, array_lenght = 0;
    int array[100];
    bool isCorrect = false;
    int countReverse = 0;
    int num;

    switch (argc)
    {
    case 0:
        return -1;
        break;
    case 1:
        if (!strncmp(argv[1], "--from=", 7)) {
            sscanf(argv[1],"--from=%d", &from);
            break;
        }
        else if (!strncmp(argv[1], "--to=", 5)) {
        sscanf(argv[1],"--to=%d", &to);
        break;
        }
        return -4;
    case 2:
        for (int i = 1; i <=2; ++ i) {
            if (!strncmp(argv[i], "--from=", 7)){
            if (from != 0) return -3;
            sscanf(argv[i],"--from=%d", &from);
            isCorrect = true;
            }
            else if (!strncmp(argv[i], "--to=", 5)) {
            if (to != 0) return -3;
            sscanf(argv[i],"--to=%d", &to);
            isCorrect = true;
            }
        }
    if (!isCorrect) return -4;
    break;
    default:
        return -2;
    }




    while (scanf("%d", &num)) {
        if ( (num > from) && (num < to) ) {
            array[array_lenght] = num;
            array_lenght ++;
        }
    }
    for (int i = 0; i < array_lenght; ++ i) {
        if (array[i] <= from) printf("%d ", array[i]);
        else if (array[i] >= to) fprintf(stderr, "%d ", array[i]);
        int minNumbers = array[i], indMinNumbers = i;
        for (int j = i + 1; j < array_lenght; ++ j) {
            if (array[j] < minNumbers) {
                minNumbers = array[j];
                indMinNumbers = j;
            }
        }
        if (indMinNumbers != i) {
            countReverse ++;
            swap(&array[i], &array[indMinNumbers]);
        }
        
    }

    return countReverse;
}