#pragma once
#include <stdint.h>
#include <stdlib.h>

template<class T> class poinve {
	bool _is_init = false;
	T* _pointer;
	size_t _size;

	public:
	poinve();
	poinve(size_t size);
	void init(size_t size);

	T& operator[](size_t index);

	T* to_array();

	size_t size();

	void finit();
	~poinve();
};
#include "poinve.cpp"
