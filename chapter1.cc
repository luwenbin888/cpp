#include <iostream>
#include <array>
#include "namespace.h"

// ************************ Notes *************************
/*
1. Never put a using directive or using declaration in a header file,
otherwise you force it on everyone that is including your header.

*/

namespace mycode {
    void foo() {
        std::cout << "foo() called in the mycode namespace" << std::endl;
    }
}

void variables();
void cast();
void arraytest();
void stdarray();
void rangeLoop();

int main()
{
    std::cout << "Hello, World!" << std::endl;
    mycode::foo();
    variables();
    cast();
    arraytest();
    stdarray();
    rangeLoop();
    return 0;
}

void cast()
{
    float myFloat = 3.14f;
    int i1 = (int)myFloat;
    int i2 = int(myFloat);
    int i3 = static_cast<int>(myFloat);
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << i3 << std::endl;

    // seems gcc does not issue a warning
    int i5 = myFloat;
    std::cout << i5 <<std::endl;
}

void variables()
{
    /*
    Most compilers will issue a warning or an error when code is using
uninitialized variables. Some compilers will generate code that will report an
error at run time.
*/
    int uninitializedInt;
    int initializedInt = 7;
    std::cout << uninitializedInt << " is a random value" << std::endl;
    std::cout << initializedInt << " was assigned an initial value" << std::endl;
}

void stdarray()
{
    std::array<int, 3> arr = {9, 8, 7};
    std::cout << "Array size = " << arr.size() << std::endl;
    std::cout << "Element 2 = " << arr[1] << std::endl;

    for (std::array<int, 3>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}

void arraytest()
{
    int myArray[3];
    std::cout << "array element at index 0: " << myArray[0] << std::endl;
    std::cout << "array element at index 1: " << myArray[1] << std::endl;
    std::cout << "array element at index 2: " << myArray[2] << std::endl;

    int myArray1[3] = {0};
    std::cout << "array1 element at index 0: " << myArray1[0] << std::endl;
    std::cout << "array1 element at index 1: " << myArray1[1] << std::endl;
    std::cout << "array1 element at index 2: " << myArray1[2] << std::endl;
}

void rangeLoop()
{
    /*
    This type of loop works for C-style arrays, initializer lists (discussed in Chapter 10),
and any type that has a begin() and end() method returning iterators, such as std::array and all
other STL containers discussed in Chapter 16.
*/
    std::array<int, 10> arr = {1,2,3,4,5,6};
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
