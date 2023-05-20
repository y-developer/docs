#include <stdio.h>  // for input/output operations
#include <stdlib.h> // for the strcpy() function
#include <string.h> // for string manipulation function

struct Person
{
    char name[50]; // fixed length of 50 to store the name
    int age;
};

int main()
{
    // Create an instance of the Person struct
    struct Person person;

    // Assign values to the struct members
    strcpy(person.name, "Yasitha Nadeeshan"); // The strcpy function from string.h is used to copy the name string into the name member of the struct.
    person.age = 30;

    // Print the struct members
    printf("Name : %s\n", person.name); // format specifiers %s for the name
    printf("Age : %d\n", person.age);   // format specifiers %d for the age

    return 0;
}