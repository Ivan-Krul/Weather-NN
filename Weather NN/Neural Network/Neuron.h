#pragma once
#include "PointMassiveLib.h"
#include "../Define.h"

template<typename _var> class Neuron {
	_var NeuronValue;
	size_t WeightSize;
	_var* Weight;

	public:
	Neuron(size_t count_weight,bool need_rand) {
		if (!(count_weight != 0)) {
			#ifdef DEBUG
			printd("class Neuron<_var>.Neuron(size_t,bool).count_weight is equal 0 (!)\n");
			#endif // DEBUG
		}
		WeightSize = count_weight;

		if (need_rand)
			Weight = point_massive::initializ_and_fill(count_weight, random::randbf(-3, 3));
		else
			Weight = point_massive::initializ_and_fill(count_weight, 0);

		NeuronValue = 0;
		#ifdef DEBUG
		printd("class Neuron<_var> is begined succesful (i)\n");
		#endif // DEBUG
	}

	size_t weight_size() {
		return WeightSize;
	}

	void resize_weight(size_t new_count) {
		point_massive::resize_and_fill(Weight, new_count, random::randbf(-3, 3)));
		WeightSize = new_count;
	}

	_var& operator[](size_t index, _var var) {
		if (!(index < WeightSize)) {
			#ifdef DEBUG
			printd("class Neuron<_var>.operator[](size_t,_var).index is out of range (!)\n");
			#endif // DEBUG
		}
		Weight[index] = var;
		return Weight[index];
	}
	_var operator=(_var var) {
		NeuronValue = val;
		return NeuronValue;
	}

	~Neuron() {
		delete[] Weight;
		#ifdef DEBUG
		printd("class Neuron<_var> is ended succesful (i)\n");
		#endif // DEBUG
	}
};


