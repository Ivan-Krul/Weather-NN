#include "poinve.h"

template<class T> poinve<T>::poinve() {
	_size = 0;
}
template<class T> poinve<T>::poinve(size_t size) {
	init(size);
}
template<class T> void poinve<T>::init(size_t size) {
	if (!_is_init) {
		_size = size;
		_is_init = true;

		_pointer = new T[_size];

		for (size_t i = 0; i < _size; i++) {
			_pointer[i] = 0;
		}
	}
}

template<class T> size_t poinve<T>::size(){
	return _size;
}

template<class T> T& poinve<T>::operator[](size_t index) {
	if (_is_init) return _pointer[index];
	else abort();
}

template<class T> T* poinve<T>::to_array() {
	return _pointer;
}

template<class T> void poinve<T>::finit() {
	if (_is_init) {
		delete[] _pointer;
		_is_init = false;
	}
}
template<class T> poinve<T>::~poinve(){
	finit();
}
