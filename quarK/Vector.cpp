#include "pch.h"
#include "Vector.h"
#include <vector>
#include <string>

template <class T, int N>
NVector<T, N>::NVector() {
	 // Constructor contents
}
template <class T, int N>
NVector<T, N>::~NVector() {
	// Destructor contents
}
template <class T, int N>
T NVector<T, N>::get(int num, ...) {
	va_list valist;
	va_start(valist, num);
	NSVector<num, T> access = this->contents[va_arg(valist, int)];
	for (int i = 0; i < num - 2; i++) {
		NSVector<num - i, T> access = access[va_arg(valist, int)];
	}
	T element = access[va_arg(valist, int)];
	return element;
}
template <class T, int N>
void NVector<T, N>::set(T val, int num, ...) {
}
template <class T, int N>
void NVector<T, N>::insert() {

}
template <class T, int N>
void NVector<T, N>::printc() {

}
template <class T, int N>
std::string NVector<T, N>::cat() {

}