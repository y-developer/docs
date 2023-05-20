#include <iostream>

using namespace std;

struct MyStruct
{
    int x;
    bool y;
    double z;
};

int main()
{
    // int
    int a;
    int *pointer_a = &a;
    cout << "memory address of int a : " << pointer_a << endl;
    cout << "size of int a : " << sizeof(a) << " bytes" << endl;
    cout << "size of int pinter a : " << sizeof(pointer_a) << " bytes" << endl;
    cout << "-----------------------" << endl;

    // bool
    bool b;
    bool *pointer_b = &b;
    cout << "memory address of bool b : " << pointer_b << endl;
    cout << "size of bool b : " << sizeof(b) << " bytes" << endl;
    cout << "size of bool pointer b : " << sizeof(pointer_b) << " bytes" << endl;
    cout << "-----------------------" << endl;

    // char
    char c = 65; // or char c = 'a';
    char *pointer_c = &c;
    cout << "memory address of char c : " << &c << endl;
    cout << "size of char c : " << sizeof(c) << " bytes" << endl;
    cout << "size of char pointer c : " << sizeof(pointer_c) << " bytes" << endl;
    cout << "-----------------------" << endl;

    // double
    double d;
    double *pointer_d = &d;
    cout << "memory address of double d : " << pointer_d << endl;
    cout << "size of double d : " << sizeof(d) << " bytes" << endl;
    cout << "size of double pointer d : " << sizeof(pointer_d) << " bytes" << endl;
    cout << "-----------------------" << endl;

    // struct create on stake
    MyStruct e = {1, false, 1.23};
    MyStruct *pointer_e = &e;
    cout << "memory address of MyStruct e : " << pointer_e << endl;
    cout << "size of MyStruct e : " << sizeof(e) << " bytes" << endl;
    cout << "size of MyStruct pointer e : " << sizeof(pointer_e) << " bytes" << endl;
    cout << "-----------------------" << endl;

    // struct create on heap
    MyStruct *pointer_f = new MyStruct();
    cout << "memory address of MyStruct f : " << pointer_f << endl;
    cout << "size of MyStruct pointer f : " << sizeof(pointer_f) << " bytes" << endl;
    delete pointer_f;

    return 0;
}
