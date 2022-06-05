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

	bool is_init();

	T& operator[](size_t index);
	void resize(size_t size);
	T* to_array();

	void push_back(const T& var);
	void push_front(const T& var);

	void pop_back();
	void pop_front();

	size_t size();

	void finit();
	~poinve();
};
#include "poinve.cpp"
