// Create these functions for work with dynamically allocated fields:
//      1. Create a field of size n
//      2. Sets the values of elements in the field to:
//          a. given value
//          b. random value from k to l
//      3. Prints the field to the standard output
//      4. Frees up the allocated memory

#include <stdio.h>
#include <stdlib.h>

// 1 ~ Create a field of given size
// When using the function createField, or any function where the
//  size of the array is manipulated (malloc, calloc), the address of the
//  array should be passed (&).
void createField(int **outField, int fieldSize) {
    *outField = (int*)malloc(sizeof(*outField) * fieldSize);
}


// 2a ~ Fill the field with a given value
void fillFieldUniformly(int *outField, int fieldSize, int inputValue) {
    for (int i = 0; i < fieldSize; i++)
        outField[i] = inputValue;
}


// 2b ~ Fill the field with random values
//  If the min and max are given incorrectly,
//  the fields are set to 0
void fillFieldRandomly(int *outField, int fieldSize, int min, int max) {
    if (min > max) {
        printf("Invalid input, field set to zero.\n");
        fillFieldUniformly(outField, fieldSize, 0);
        return;
    }

    for (int i = 0; i < fieldSize; i++)
        outField[i] = min + (rand() % (max - min));
}

// 3 ~ Print the field
// The specific format was really just decided by me,
//  a normal loop would work sufficiently as well
void printField(int *outField, int fieldSize){
    for (int i = 0; i < fieldSize-1; i++)
        printf("%d, ", outField[i]);
    printf("%d.\n", outField[fieldSize-1]);
}

// 4. Free the field
void freeField (int ** outField) {
    free (*outField);
}

int main (void) {
    int * field = NULL;

    // int fieldSize = 16;
    // int fieldSize2 = 128;
    int fieldSize3 = 64;

    // createField(&field, fieldSize);
    // fillFieldUniformly(field, fieldSize, 8);
    // printField(field, fieldSize);
    // free(field);

    // createField(&field, fieldSize2);
    // fillFieldRandomly(field, fieldSize2, 500, 499);
    // printField(field, fieldSize2);
    // free(field);

    createField(&field, fieldSize3);
    fillFieldRandomly(field, fieldSize3, 0, 64);
    printField(field, fieldSize3);
    freeField(&field);
}