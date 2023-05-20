#include <iostream> // for input and output operations

struct Person
{
    std::string name;
    int age;
};

int main()
{
    // Create a struct instance on the heap
    Person *personPtr = new Person;

    // Assign values to the struct members
    personPtr->name = "RM Yasitha";
    personPtr->age = 30;

    // Print the struct members
    std::cout << "Name : " << personPtr->name << std::endl;
    std::cout << "Age : " << personPtr->age << std::endl;

    // Clean up the memory allocated for the struct
    delete personPtr;

    return 0;
}