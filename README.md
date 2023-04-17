# quarK
This is a personal library of useful functions and data types for scientific computing in C++. It aims to be versataille and easy to use.

## Vectors

### Introduction
The main feature of the quarK library is the NVector ADT. This is a wrapper of the std::vector, allowing for N nested std::vectors (dimensions) opening up linear algebra in c++.

### Construction - NVector<dimensions, datatype> and .setContents()
On construction, one must supply the number of dimensions and the datatype of the contents NVector (respectively). It is possible to declare an uninitialised NVector and then set it using the setter or to declare it upon construction.
```cpp
// Create an object called dat with 2 dimensions and base type int
NVector<2, int> minkowskiMetricOnSetter;
```
The actual data of the NVector is contained within a private attribute aptly called 'contents'. Fundamentally this is a std::vector<...> object with N-2 nested std::vector<...>s, the Nth vector being a std::vector<T> with type T. 
One can get contents with .getContents(), which returns .contents by value.
```cpp
// Minkowski Metric (Rank-2 spacetime tensor)
/* -1, 0, 0, 0
    0, 1, 0, 0
    0, 0, 1, 0
    0, 0, 0, 1 */

// Set contents using .setContents()
minkowskiMetricOnSetter.setContents() = NVector<2, int>::ntype{ // Using NVector internal ntype
		{-1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1} 
	};
```
Note // NVector has an internal data type called 'ntype' which is the raw typedef for the nested std::vectors. It behaves like any other std::vector, with its methods etc. When declaring any vectors to add, set, remove, etc., ntype (or std::vector type) must be used.

```cpp
// Declare contents on construction
NVector<2, int> minkowskiMetricOnConstruction = NVector<2, int>::ntype{ // Using NVector internal ntype
		{-1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1} 
	};
```

### Accessing contents - .getContents()
Getting the entirety of the contents is easy. The .getContents() method returns the contents.

```cpp
// Get contents
NVector<2, int>::ntype minkowskiContents = minkowskiMetricOnSetter.getContents();
```
