#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <type_traits>

#ifdef QUARK_EXPORTS
#define QUARK_API __declspec(dllexport)
#else
#define QUARK_API __declspec(dllimport)
#endif

template<class T>
bool is_vector(const std::vector<T>& x) { return true; }

template<class T>
bool is_vector(const T& x) { return false; }


// NDVector (Tensor) for N>0
template<size_t dimcount, typename T>
class QUARK_API NDVector {
public:
    // Internal DType Definition
    typedef std::vector< typename NDVector<dimcount - 1, T>::ntype > ntype;  // Nested std::vector

    // Constructors and Destructors
    NDVector() {}; // Default constructor
    NDVector(ntype init) : contents{ init } {}; // Initialiser constructor
    ~NDVector(); // Destructor

    // Getters and Setters
    T getElement(std::vector<int> loc); // Return pointer to element (value, position)
    ntype getContents() {
        return this->contents;
    }; // Return pointer to contents
    void setElement(T val, std::vector<int>); // Set element value (value, position)
    void setContents(ntype val); // Change the entire contents of the NDVector to arg

    // Modify by Trivial Methods

    // Modify by Addition or Subtraction
    void insert(); // Insert parameter1 to position parameter2 in the vector

    // Modify by Scalar Multiplication or Division

    // Vector Multiplication

    // Modify by Log, Exp, Power, Root

    // Slicing, Splicing and Dicing

    // Conversions

    // Representations
    void print() { // Print the vector to the console 
        
    } 
    std::string to_string(); // Return string representation of the contents

    // Re-worded Methods (Addition -> Translation, Vector Product -> Rotation)

    // Statistical Methods (Sum, Mean, Standard Deviation)

    // Sampling Methods (Uniform, Normal)

    // Import, Export

    // Logic
private:
    ntype contents{}; // Vector contents
};

// Terminating (0D) Case
template<typename T>
class QUARK_API NDVector<0, T> {
public:
    typedef T ntype; 
};
