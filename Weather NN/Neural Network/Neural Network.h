#pragma once
#include <vector>
#include "../Define.h"
//#include <functional>

template <typename var> class NeuralNetwork {
	class neuron {
		public:
		std::vector<var> _weight;
		var _val;
		var _bias;
		var _error;

		void init_weight(bool is_rand, size_t parent_l) {
			_weight.resize(parent_l);

			for (size_t i = 0;i < parent_l;i++)
				if (is_rand)
					_weight[i] = random::randbd(-3, 3);
				else
					_weight[i] = 0;
						
		}
	}

	float								_coef_learn;
	bool								_is_rand;

	std::vector<var>					_inp_neu;
	std::vector<std::vector<neuron>>	_hide_neu;
	std::vector<neuron>					_out_neu;

	// TODO: зробити вказівник-масив для функції активації
	//poinve<std::function<var(var)>> _type_sys;

	void Forward(
		var* Li, size_t size_li,
		var* W, size_t size_w,
		var* Lo, size_t size_lo);
	void Backward(
		var* Ei, size_t size_li,
		var* W, size_t size_w,
		var* Eo, size_t size_lo);
	void Correcting(
		var* Li, size_t size_li,
		var* W, size_t size_w,
		var* Lo, var* Eo, size_t size_lo
	);

	public:
	NeuralNetwork(size_t neu_inp, size_t neu_out,float coef_learn,bool is_rand);
	void init(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void reinit(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void finit();
	~NeuralNetwork();
};
#include "Neural Network.cpp"

using neu_netf = NeuralNetwork<float>;
using neu_netd = NeuralNetwork<double>;
