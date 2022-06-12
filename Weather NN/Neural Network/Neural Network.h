#pragma once
#include <vector>
#include "../Define/Define.h"
#include "Neuron/Neuron.h"
template <typename var> class NeuralNetwork {
	#ifdef DEBUG
	public:
	#else
	private:
	#endif // DEBUG

	float _coef_learn;
	bool _is_rand;

	std::vector<var> _inp_neu;
	std::vector<std::vector<neuron<var>>> _hide_neu;
	std::vector<neuron<var>> _out_neu;

	void Forward(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo);
	void Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo);
	void Correcting(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo);

	void Forward(std::vector<var>& Li, std::vector<neuron<var>>& Lo);
	void Forward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo);
	void Backward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo);
	void Correcting(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo);
	void Correcting(std::vector<var>& Li, std::vector<neuron<var>>& Lo);

	void AdaptWeight();

	public:
	NeuralNetwork(size_t neu_inp, size_t neu_out,float coef_learn,bool is_rand);
	void init(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void push_back(size_t size);

	void input(std::vector<var> inp_neu);
	std::vector<var> calculate();
	std::vector<var> output();
	void correct(std::vector<var> must_be);

	void reinit(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand);

	void finit();
	~NeuralNetwork();
};

#include "Neural Network Private.cpp"
#include "Neural Network Public.cpp"
#include "Neural Network Private Pointers.cpp"

using neu_netf = NeuralNetwork<float>;
using neu_netd = NeuralNetwork<double>;
