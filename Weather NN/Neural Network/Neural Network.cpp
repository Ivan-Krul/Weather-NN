#include "Neural Network.h"

template <typename var>
void NeuralNetwork<var>::Forward(
	var* Li, size_t size_li,
	var* W, size_t size_w,
	var* Lo, size_t size_lo
) {
	for (size_t o = 0;o < size_lo - 1;o++) {
		Lo[o] = 0;
		for (size_t i = 0;i < size_li;i++)
			Lo[o] += Li[i] * W[size_li * o + i];

		// TODO: видалити це
		Lo[o] = var(1.0) / (var(1.0) + var(exp(-Lo[o])));
	}
}

template <typename var>
void NeuralNetwork<var>::Backward(
	var* Ei, size_t size_li,
	var* W, size_t size_w,
	var* Eo, size_t size_lo
) {
	size_li--;

	for (size_t i = 0;i < size_li;i++) {
		Ei[i] = 0;
		for (size_t o = 0;o < size_lo;o++)
			Ei[i] += Eo[o] * W[size_li * o + i];
	}
}

template <typename var>
void NeuralNetwork<var>::Correcting(
	var* Li,size_t size_li,
	var* W, size_t size_w,
	var* Lo, var* Eo, size_t size_lo
) {
	for (size_t o = 0;o < size_lo;o++) {
		for (size_t i = 0;i < size_li;i++) {
			W[size_li * o + i] += _coef_learn * Li[i] * Eo[o] //;
				// TODO: видалити це
				* Lo[o] * (var(1.0) - Lo[o]);
		}
	}
}

template <typename var>
NeuralNetwork<var>::NeuralNetwork(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	init(neu_inp, neu_out, coef_learn, is_rand);
}

template <typename var>
void NeuralNetwork<var>::init(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	_inp_neu(neu_inp);
	_out_neu(neu_out);
	_coef_learn = coef_learn;
	_is_rand = is_rand;

	for (size_t i = 0;i < _out_neu.size();i++)
		_out_neu[i]._weight.resize(_inp_neu);
}

template <typename var>
void NeuralNetwork<var>::reinit(
	size_t neu_inp, 
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	finit();
	init();
}

template <typename var>
void NeuralNetwork<var>::finit() {
}

template <typename var>
NeuralNetwork<var>::~NeuralNetwork() {
	finit();
}
