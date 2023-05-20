#include <stdio.h>  // for input/output operations
#include <stdlib.h> // for the strcpy() function
#include <string.h> // for string manipulation function

struct Person
{
    char name[50];
    int age;
};

int main()
{
    // Create a struct instance on the heap
    struct Person *personPtr = (struct Person *)malloc(sizeof(struct Person));

    // Assign values to the struct members
    strcpy(personPtr->name, "Yasitha N");
    personPtr->age = 30;

    // Print the struct members
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);

    // Clean up the memory allocated for the struct
    free(personPtr);

    return 0;
}