#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>
#include "namespace.h"

// ************************ Notes *************************
/*
1. Never put a using directive or using declaration in a header file,
otherwise you force it on everyone that is including your header.

2. Memory in your C++ application is divided into two parts ¡ª the stack and the heap.
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
void pointer();
void smartPointer();
double divideNumbers(double, double);

void func(char* str) { std::cout << "char* version" << std::endl; }
void func(int i) { std::cout << "int version " << std::endl;}

const std::string message = "Test";

const std::string& foo()
{
    return message;
}

void vectortest();

int main()
{
    std::cout << "Hello, World!" << std::endl;
    mycode::foo();
    variables();
    cast();
    arraytest();
    stdarray();
    rangeLoop();
    pointer();

    func(NULL);
    func(nullptr);

    smartPointer();

    try {
        std::cout << divideNumbers(2.5, 0.5) << std::endl;
        std::cout << divideNumbers(2.3, 0) << std::endl;
        std::cout << divideNumbers(4.5, 2.5) << std::endl;
    } catch (const std::exception& exception) {
        std::cout << "Exception caught: " << exception.what() << std::endl;
    }

    const auto& f1 = foo();
    std::cout << f1 << std::endl;
    decltype(auto) f3 = foo();
    std::cout << f3 << std::endl;

    vectortest();

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

void pointer()
{
    int* myIntegerPointer = nullptr;
    myIntegerPointer = new int;
    *myIntegerPointer = 8;
    std::cout << *myIntegerPointer << std::endl;

    delete myIntegerPointer;
    myIntegerPointer = nullptr;

    int* arr = new int[8];
    for (int i = 0; i < 8; i++) arr[i]=i;
    std::cout<<"Print dynamic array"<<std::endl;
    for (int i = 0; i < 8; i++) std::cout<<arr[i]<<std::endl;
    delete[] arr;
}

void smartPointer()
{
    std::cout << "In smart pointer" << std::endl;
    auto i = std::make_unique<int>();
    *i = 8;
    std::cout << *i << std::endl;

    std::unique_ptr<float> f(new float);
    *f = 3.14;
    std::cout << *f << std::endl;
}

double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0.");
    }
    return numerator / denominator;
}

void vectortest()
{
    std::vector<std::string> myVector = {"A first string", "A second string"};
    myVector.push_back("A third string");
    myVector.push_back("The last string in the vector");
    for (const auto& str: myVector)
        std::cout << str << std::endl;
    for (auto iterator = cbegin(myVector); iterator != cend(myVector); ++iterator) {
        std::cout << *iterator << std::endl;
    }
}
