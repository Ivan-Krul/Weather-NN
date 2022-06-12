#pragma once
#include <vector>
#include "../../Define/Define.h"

template<typename var> struct neuron {
public:
	std::vector<var> _weight;
	var _val = 0;
	var _bias = 0;
	var _error = 0;

	neuron();
	void init_weight(bool is_rand, size_t parent_l);
	~neuron();
};
#include "Neuron.cpp"
