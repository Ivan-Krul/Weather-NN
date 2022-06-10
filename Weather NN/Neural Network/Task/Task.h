#pragma once
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include "../../Define/Define.h"

template <typename T,size_t size_inp, size_t size_out> class Task {
	#define vec std::vector<T>
	#define pai std::pair<vec, vec>

	#ifdef DEBUG
	public:
	#else
	private:
	#endif // DEBUG

	

	std::list<std::pair<vec, vec>> _data;

	size_t _num_test = 0;
	
	public:
	Task();

	void load(std::string dir_and_name_and_format);

	const size_t number_test();
	const size_t size();

	void begin();
	std::pair<vec, vec> test();

	~Task();
};
#include "Task.cpp"

