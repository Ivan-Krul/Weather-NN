#include "Neural Network.h"


template <typename var>
void NeuralNetwork<var>::Forward(std::vector<var>& Li, std::vector<neuron<var>>& Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		Lo[o]._val = 0;
		for (size_t i = 0;i < Li.size();i++)
			Lo[o]._val += Li[i] * Lo[o]._weight[i];

		Lo[o]._val += Lo[o]._bias;
		// TODO: видалити це
		Lo[o]._val = var(1.0) / (var(1.0) + var(exp(-1.0 * Lo[o]._val)));
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class NeuralNetwork<var>::Forward(std::vector<var>& Li, std::vector<neuron<var>>& Lo) is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Forward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		Lo[o]._val = var(0.0);
		for (size_t i = 0;i < Li.size();i++)
			Lo[o]._val += Li[i]._val * Lo[o]._weight[i];

		Lo[o]._val += Lo[o]._bias;
		// TODO: видалити це
		Lo[o]._val = var(1.0) / (var(1.0) + exp(var(-1.0) * Lo[o]._val));
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class NeuralNetwork<var>::Forward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Backward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) {
	for (size_t i = 0;i < Li.size();i++) {
		Li[i]._error = 0;
		for (size_t o = 0;o < Lo.size();o++)
			Li[i]._error += Lo[o]._error * Lo[o]._weight[i];
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class NeuralNetwork<var>::Backward(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Correcting(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		for (size_t i = 0;i < Li.size();i++) {
			Lo[o]._weight[i] += _coef_learn * Li[i]._val * Lo[o]._error
						// TODO: видалити це
				* Lo[o]._val * (var(1.0) - Lo[o]._val);
		}

		Lo[o]._bias += _coef_learn * Lo[o]._error
					// TODO: видалити це
			* Lo[o]._val * (var(1.0) - Lo[o]._val);
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>::Correcting(std::vector<neuron<var>>& Li, std::vector<neuron<var>>& Lo) is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Correcting(std::vector<var>& Li, std::vector<neuron<var>>& Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		for (size_t i = 0;i < Li.size();i++) {
			Lo[o]._weight[i] += _coef_learn * Li[i] * Lo[o]._error
						// TODO: видалити це
				* Lo[o]._val * (var(1.0) - Lo[o]._val);
		}

		Lo[o]._bias += _coef_learn * Lo[o]._error
					// TODO: видалити це
			* Lo[o]._val * (var(1.0) - Lo[o]._val);
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>::Correcting(std::vector<var>& Li, std::vector<neuron<var>>& Lo) is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
void NeuralNetwork<var>::AdaptWeight() {
	for (size_t l = 0;l < _hide_neu.size() + 1;l++) {
		for (size_t n = 0;n < ((l < _hide_neu.size()) ? _hide_neu[l].size() : _out_neu.size());n++) {
			if (l == 0)
				_hide_neu[l][n].init_weight(
				_is_rand,
				_inp_neu.size());
			else if (l == _hide_neu.size())
				_out_neu[n].init_weight(
				_is_rand,
				_hide_neu[l - 1].size());
			else
				_hide_neu[l][n].init_weight(
				_is_rand,
				_hide_neu[l - 1].size());
		}
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class NeuralNetwork<var>::AdaptWeight() is done",
		'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

