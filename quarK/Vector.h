#pragma once
#include <vector>
#include <string>

#ifdef QUARK_EXPORTS
#define QUARK_API __declspec(dllexport)
#else
#define QUARK_API __declspec(dllimport)
#endif

template<size_t dimcount, typename T>
struct NSVector
{
    typedef std::vector< typename NSVector<dimcount - 1, T>::type > type; // Recursive vector
};

template<typename T>
struct NSVector<0, T>
{
    typedef T type; // 0 Dimensional vector end case
};

template<class T, int N>
class QUARK_API NVector {
public:
    NSVector<N, T> contents; // Object vector data contents of N dimensions and type T
    NVector(); // Constructor
    ~NVector(); // Destructor
    T get(int num, ...); // Get element at given position
    void set(T val, int num, ...); // Set element at given position
    void insert(); // Insert parameter1 to position parameter2 in the vector
    void printc(); // Print the vector to the console 
    std::string cat(); // Convert the vector to string
protected:
private:
};