#include <iostream.h>

using namespace std;

int main()
{
    int x;
    int y;
    int z = 20;

    int *pointer_x = &x; // store memory address
    int *pointer_y = &y;
    int *pointer_z = &z;

    cout << "x: " << &x << endl;
    cout << "y: " << &y << endl;
    cout << "z: " << &z << endl;

    return 0;
}