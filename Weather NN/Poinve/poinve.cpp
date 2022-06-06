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
			_pointer[i] = T();
		}
	}
}

template<class T>
bool poinve<T>::is_init() {
	return _is_init;
}

template<class T>
void poinve<T>::pop_back() {
	if (_is_init) {
		_size--;
		T* buf = new T[_size];
		for (size_t i = 0;i < _size - 1;i++)
			buf[i] = _pointer[i];

		delete[] _pointer;
		_pointer = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_pointer[i] = buf[i];

		delete[] buf;
	}
}

template<class T>
void poinve<T>::pop_front() {
	if (_is_init) {
		_size--;
		T* buf = new T[_size];
		for (size_t i = 0;i < _size - 1;i++)
			buf[i] = _pointer[i+1];

		delete[] _pointer;
		_pointer = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_pointer[i] = buf[i];

		delete[] buf;
	}
}

template<class T> size_t poinve<T>::size(){
	return _size;
}

template<class T> T& poinve<T>::operator[](size_t index) {
	if (_is_init) return _pointer[index];
	else abort();
}

template<class T>
T* poinve<T>::operator=(T var[]) {
	size_t size = sizeof(var) / sizeof(T);
	for (size_t i = 0;i < min(size,_size) ;i++) {
		_pointer[i] = var[i];
	}
	return _pointer;
}


template<class T>
void poinve<T>::resize(size_t size) {
	if (_is_init) {
		T* buf = new T[size];
		for (size_t i = 0;i < size;i++)
			if (i < _size) buf[i] = _pointer[i];
			else buf[i] = T();

		delete[] _pointer;
		_pointer = new T[size];
		for (size_t i = 0;i < size;i++)
			_pointer[i] = buf[i];

		_size = size;
		delete[] buf;
	}
	else init(size);
}

template<class T> T* poinve<T>::to_array() {
	return _pointer;
}

template<class T>
void poinve<T>::push_back(const T& var) {
	if (_is_init) {
		_size++;
		T* buf = new T[_size];
		for (size_t i = 0;i < _size - 1;i++)
			buf[i] = _pointer[i];
		buf[_size - 1] = var;

		delete[] _pointer;
		_pointer = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_pointer[i] = buf[i];

		delete[] buf;
	}
}

template<class T>
void poinve<T>::push_front(const T& var) {
	if (_is_init) {
		_size++;
		T* buf = new T[_size];
		for (size_t i = 1;i < _size;i++)
			buf[i] = _pointer[i];
		buf[0] = var;

		delete[] _pointer;
		_pointer = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_pointer[i] = buf[i];

		delete[] buf;
	}
}

template<class T> void poinve<T>::finit() {
	if (_is_init) {
		delete[] _pointer;
		_is_init = false;
		_size = 0;
	}
}
template<class T> poinve<T>::~poinve(){
	finit();
}
