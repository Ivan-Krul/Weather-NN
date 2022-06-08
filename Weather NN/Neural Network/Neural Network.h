#pragma once
#include <vector>
#include <cassert>
#include "../Define.h"
//#include <functional>

template <typename var> class NeuralNetwork {
	#ifdef DEBUG
	public:
	#else
	private:
	#endif // DEBUG

	class neuron {
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

	float _coef_learn;
	bool _is_rand;

	std::vector<var> _inp_neu;
	std::vector<std::vector<neuron>> _hide_neu;
	std::vector<neuron> _out_neu;

	// TODO: зробити вказівник-масив для функції активації
	//poinve<std::function<var(var)>> _type_sys;

	void Forward(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo);
	void Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo);
	void Correcting(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo);

	void Forward(std::vector<var> Li, std::vector<neuron> Lo);
	void Forward(std::vector<neuron> Li, std::vector<neuron> Lo);
	void Backward(std::vector<neuron> Li, std::vector<neuron> Lo);
	void Correcting(std::vector<neuron> Li, std::vector<neuron> Lo);

	void AdaptWeight();

	public:
	NeuralNetwork(size_t neu_inp, size_t neu_out,float coef_learn,bool is_rand);
	void init(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void push_back(size_t size);

	void input(std::vector<var> inp_neu);
	std::vector<var> calculate();
	void correct();

	void reinit(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void finit();
	~NeuralNetwork();
};
#include "Neural Network.cpp"

using neu_netf = NeuralNetwork<float>;
using neu_netd = NeuralNetwork<double>;
