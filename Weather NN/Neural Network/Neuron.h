#pragma once
#include <vector>

template<typename var> class neuron {
	public:
	std::vector<var> _weight;
	var _val = 0;
	var _bias = 0;
	var _error = 0;

	void init_weight(bool is_rand, size_t parent_l) {
		_weight.resize(parent_l);

		for (size_t i = 0;i < parent_l;i++)
			if (is_rand)
				_weight[i] = random::randbf(-3, 3);
			else
				_weight[i] = 0;

		if (is_rand)
			_bias = random::randbf(-3, 3);
		else
			_bias = 0;
	}
};