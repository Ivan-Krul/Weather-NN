#pragma once
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include "../../Define/Define.h"

template <typename T, size_t size_inp, size_t size_out> class Task {
	std::list<std::pair<std::vector<T>, std::vector<T>>> _data;

	size_t _num_test = 0;

public:
	Task();

	void load(std::string dir_and_name_and_format);

	const size_t number_test();
	const size_t size();

	void begin();
	std::pair<std::vector<T>, std::vector<T>> test();

	~Task();
};
#include "Task.cpp"

