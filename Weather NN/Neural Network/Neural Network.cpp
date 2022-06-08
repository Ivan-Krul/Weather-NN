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

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.Forward(var*,size_t,var*,size_t,var*,size_t) is done",
		'i');
	#endif // DEBUG
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

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.Backward(var*,size_t,var*,size_t,var*,size_t) is done",
		'i');
	#endif // DEBUG
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

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.Correcting(var*,size_t,var*,size_t,var*,var*,size_t) is done",
		'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::Forward(std::vector<var> Li, std::vector<neuron> Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		Lo[o]._val = 0;
		for (size_t i = 0;i < Li.size();i++)
			Lo[o]._val += Li[i] * Lo[o]._weight[i];

		Lo[o]._val += Lo[o]._bias;
		// TODO: видалити це
		Lo[o]._val = var(1.0) / (var(1.0) + var(exp(-1.0 * Lo[o]._val)));
	}

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.Forward(std::vector<var>,std::vector<neuron>) is done",
		'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::Forward(std::vector<neuron> Li, std::vector<neuron> Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		Lo[o]._val = 0;
		for (size_t i = 0;i < Li.size();i++)
			Lo[o]._val += Li[i]._val * Lo[o]._weight[i];

		Lo[o]._val += Lo[o]._bias;
		// TODO: видалити це
		Lo[o]._val = 1.0 / (1.0 + exp(-1.0 * Lo[o]._val));
	}

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.Forward(std::vector<neuron>,std::vector<neuron>) is done",
		'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::Backward(std::vector<neuron> Li, std::vector<neuron> Lo) {
	for (size_t i = 0;i < Li.size();i++) {
		Li[i]._error = 0;
		for (size_t o = 0;o < Lo.size();o++)
			Li[i]._error += Lo[o]._error * Lo[o]._weight[i];
	}

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.Backward(std::vector<neuron>,std::vector<neuron>) is done",
		'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::Correcting(std::vector<neuron> Li, std::vector<neuron> Lo) {
	for (size_t o = 0;o < Lo.size();o++) {
		for (size_t i = 0;i < Li.size();i++) {
			Lo[o]._weight[i]+= _coef_learn * Li[i]._val * Lo[o]._error
				* Lo[o]._val * (var(1.0) - Lo[o]._val);
		}
	}

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.Correcting(std::vector<neuron>,std::vector<neuron>) is done",
		'i');
	#endif // DEBUG
}

template<typename var>
void NeuralNetwork<var>::AdaptWeight() {
	for (size_t l = 0;l < _hide_neu.size() + 1;l++) {
		for (size_t n = 0;n < ((l< _hide_neu.size())?_hide_neu[l].size():_out_neu.size());n++) {
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
				_hide_neu[l-1].size());
		}
	}

	#ifdef DEBUG
	printd("class NeuralNetwork<var>.AdaptWeight() is done",
		'i');
	#endif // DEBUG
}

template <typename var>
NeuralNetwork<var>::NeuralNetwork(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	#ifdef DEBUG
	printd("class NeuralNetwork<var> is launched",'i');
	#endif // DEBUG
	init(neu_inp, neu_out, coef_learn, is_rand);
}

template <typename var>
void NeuralNetwork<var>::init(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	_inp_neu.resize(neu_inp);
	_out_neu.resize(neu_out);
	_coef_learn = coef_learn;
	_is_rand = is_rand;

	for (size_t i = 0;i < _out_neu.size();i++)
		_out_neu[i].init_weight(_is_rand,_inp_neu.size());

	#ifdef DEBUG
	printd("class NeuralNetwork<var> is started succesful",'i');
	#endif // DEBUG
}

template<typename var>
void NeuralNetwork<var>::push_back(size_t size) {
	std::vector<neuron> a;
	a.resize(size);
	_hide_neu.push_back(a);

	AdaptWeight();

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.push_back(size_t) is done",
		'i');
	#endif // DEBUG
}

template<typename var>
void NeuralNetwork<var>::input(std::vector<var> inp_neu) {
	for (size_t i = 0;i < std::min(_inp_neu.size(), inp_neu.size());i++)
		_inp_neu[i] = inp_neu[i];

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.input(std::vector<var>) is done",
		'i');
	#endif // DEBUG
}

template<typename var>
std::vector<var> NeuralNetwork<var>::calculate() {
	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.calculate() has starting",
		'i');
	#endif // DEBUG

	for (size_t l = 0;l < _hide_neu.size() + 1;l++) {
		if (l == 0)
			Forward(_inp_neu, _hide_neu[l]);
		else if (l == _hide_neu.size())
			Forward(_hide_neu[l - 1], _out_neu);
		else
			Forward(_hide_neu[l - 1], _hide_neu[l]);
	}

	std::vector<var> out;
	for (size_t i = 0;i < _out_neu.size();i++)
		out.push_back(_out_neu[i]._val);

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<var>.calculate() is done",
		'i');
	#endif // DEBUG
	return out;
}

template <typename var>
void NeuralNetwork<var>::reinit(
	size_t neu_inp, 
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	#ifdef DEBUG
	printd("class NeuralNetwork<var> is starting restart", 'i');
	#endif // DEBUG
	finit();
	init(neu_inp,
		neu_out,
		coef_learn,
		is_rand);
	#ifdef DEBUG
	printd("class NeuralNetwork<var> is restarted succesful", 'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::finit() {
	_coef_learn = 0.0f;
	_is_rand = false;

	_inp_neu.clear();

	for(size_t i = 0;i<_hide_neu.size();i++)
		_hide_neu[i].clear();
	_hide_neu.clear();

	_out_neu.clear();

	#ifdef DEBUG
	printd("class NeuralNetwork<var> is finished succesful", 'i');
	#endif // DEBUG
}

template <typename var>
NeuralNetwork<var>::~NeuralNetwork() {
	finit();
	#ifdef DEBUG
	printd("class NeuralNetwork<var> is ended up", 'i');
	#endif // DEBUG
}
