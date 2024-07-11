#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

int getSize(const DynamicArray* arr);
int getCapacity(const DynamicArray* arr);
DynamicArray* createArr(int cap);
void freeArr(DynamicArray* arr);
DynamicArray* copyArr(const DynamicArray* arr);
void append(DynamicArray* arr, int value);
void printArr(const DynamicArray* arr);
int pop(DynamicArray* arr);
void resize(DynamicArray* arr);
int getIndex(DynamicArray* arr, int value);
void removeVal(DynamicArray* arr, int value);
int getVal(DynamicArray* arr, int index);
int removeReturn(DynamicArray* arr, int value);
int min(DynamicArray* arr);
int max(DynamicArray* arr);


int main(void) {
    DynamicArray* arr = createArr(4);

    append(arr, 7);

    append(arr, 10);

    append(arr, 777);

    append(arr, 54);

    int minimum = min(arr);

    int maximum = max(arr);

    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    printArr(arr);

    freeArr(arr);
    return 0;
}

DynamicArray* createArr(const int cap) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));
    if (arr== NULL) {
        fprintf(stderr, "Could not create the array.");
        return NULL;
    }

    arr->capacity = cap;
    arr->data = (int*)malloc(arr->capacity * sizeof(int));
    arr->size = 0;

    return arr;

}
void freeArr(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}
DynamicArray* copyArr(const DynamicArray* arr) {
    DynamicArray* new_arr = malloc(sizeof(DynamicArray));
    if (new_arr == NULL) {
        fprintf(stderr ,"Could not initlize a new array. Aborting");
        return NULL;
    }

    new_arr->capacity = arr->capacity;
    new_arr->size = arr->capacity;

    for (int i = 0; i < arr->size; ++i) {
        new_arr->data[i] = arr->data[i];
    }

    return new_arr;

}

int getSize(const DynamicArray* arr) {
    return arr->size;
}

int getCapacity(const DynamicArray* arr) {
    return arr->capacity;
}

void append(DynamicArray* arr, const int value) {

    if(getSize(arr) >= getCapacity(arr)) {
        resize(arr);
    }

    arr->data[arr->size++] = value;


}

int pop(DynamicArray* arr) {

    int removed_val = arr->data[getSize(arr) - 1];
    arr->size--;

    return removed_val;

}

void printArr(const DynamicArray* arr) {
    for (int i = 0; i < getSize(arr); i++) {
        printf("%d\n", arr->data[i]);
    }
}

void resize(DynamicArray* arr) {
    size_t new_capacity = arr->capacity * 2;
    int* new_data = realloc(arr->data, new_capacity * sizeof(int));

    if (new_data == NULL) {
        fprintf(stderr, "Could not reallocate memory.");
        return;
    }

    arr->capacity = new_capacity;
    arr->data = new_data;

}

int getIndex(DynamicArray* arr, int value) {
    for (int i = 0; i < getSize(arr); i++) {
        if (arr->data[i] == value) {
            return  i;
        }
    }
    return -1;
}

int getVal(DynamicArray* arr, int index) {
    for (int i = 0; i < getSize(arr); i++) {
        if (i  == index && index < getSize(arr)) {
            return arr->data[i];
        }
    }
    return -1;
}

void removeVal(DynamicArray* arr, int value) {

    for(int i = getIndex(arr, value); i < getSize(arr) - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;
}

int removeReturn(DynamicArray* arr, int value) {

    int removed = arr->data[getIndex(arr, value)];

    for(int i = getIndex(arr, value); i < getSize(arr) - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;

    return removed;
}

int min(DynamicArray* arr) {
    int least = arr->data[0];

    for (int i = 0; i < getSize(arr); i++) {
        if (least > arr->data[i]) {
            least = arr->data[i];
        }
    }

    return  least;

}

int max(DynamicArray* arr) {
    int greatest = arr->data[0];

    for (int i = 0; i < getSize(arr); i++) {
        if (greatest < arr->data[i]) {
            greatest = arr->data[i];
        }
    }

    return  greatest;

}
