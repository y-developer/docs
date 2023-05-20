#include <iostream> // for input and output operations

struct Person
{
    std::string name;
    int age;
};

int main()
{
    // Create an instance of the Person struct
    Person person;

    // Assign values to the struct members
    person.name = "John Doe";
    person.age = 30;

    // Print the struct members
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age : " << person.age << std::endl;
}
