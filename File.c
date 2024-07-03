#include <stdio.h>
#include <stdlib.h>

// Function prototype for dynamic memory allocation
int* allocateArray(int size);

int main() {
    int size = 10; // Example size for the array
    int* arr;

    // Attempt to allocate memory for the array
    arr = allocateArray(size);
    
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program with an error code
    }

    // Assuming we're working with integers, print the first few elements to verify
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}

// Function to allocate memory for an array
int* allocateArray(int size) {
    // Calculate the total size needed for the array
    int totalSize = sizeof(int) * size;

    // Attempt to allocate memory
    int* newArray = (int*) malloc(totalSize);

    // Check if memory allocation was successful
    if (newArray == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Failed to allocate memory for array of size %d\n", size);
        return NULL; // Return NULL to indicate failure
    }

    // Initialize the array to some default values if necessary
    for (int i = 0; i < size; i++) {
        newArray[i] = i; // Example initialization
    }

    return newArray; // Return the newly allocated array
}
