#pragma once
#include <memory>
#include "../Random/Random.h"
//#include <functional>

class NeuralNetwork {
	typedef float var;

	typedef struct {
		var value;
		var error;
	} neuron;

	float CoeficientLearn = 0.1f;
	
	size_t NeuronInputSize;
	var* NeuronInput;
	size_t NeuronHideSize;
	size_t* NeuronHideSizeSize;
	neuron** NeuronHide;
	var** Weigth;
	size_t NeuronOutputSize;
	neuron* NeuronOutput;

	// TODO: зробити вказівник-масив для функції активації
	//poinve<std::function<var(var)>> _type_sys;

	void Forward(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo);
	void Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo);
	void Correcting(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo);

	public:
	NeuralNetwork(size_t neu_inp, size_t neu_out);
	void init(size_t neu_inp, size_t neu_out);

	void reinit(size_t neu_inp, size_t neu_out);

	void finit();
	~NeuralNetwork();
};
#include "Neural Network.cpp"
