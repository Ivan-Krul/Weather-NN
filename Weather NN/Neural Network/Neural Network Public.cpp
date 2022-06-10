#include "Neural Network.h"

template <typename var>
NeuralNetwork<var>::NeuralNetwork(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	#ifdef DEBUG
	printd("class NeuralNetwork<typename> is launched",'i');
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
	printd("class NeuralNetwork<typename> is started succesful",'i');
	#endif // DEBUG
}

template<typename var>
void NeuralNetwork<var>::push_back(size_t size) {
	std::vector<neuron<var>> a;
	a.resize(size);
	_hide_neu.push_back(a);

	AdaptWeight();

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<typename>.push_back(size_t) is done",
		'i');
	#endif // DEBUG
}

template<typename var>
void NeuralNetwork<var>::input(std::vector<var> inp_neu) {
	for (size_t i = 0;i < std::min(_inp_neu.size(), inp_neu.size());i++)
		_inp_neu[i] = inp_neu[i];

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<typename>.input(std::vector<typename>) is done",
		'i');
	#endif // DEBUG
}

template<typename var>
std::vector<var> NeuralNetwork<var>::calculate() {
	#ifdef DEBUG
	printd(
		"class NeuralNetwork<typename>.calculate() has starting",
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
		"class NeuralNetwork<typename>.calculate() is done",
		'i');
	#endif // DEBUG
	return out;
}

template<typename var>
void NeuralNetwork<var>::correct(std::vector<var> must_be) {
	#ifdef DEBUG
	printd(
		"class NeuralNetwork<typename>.correct(std::vector<typename>) has starting",
		'i');
	#endif // DEBUG

	for (size_t i = 0;i < std::min(must_be.size(), _out_neu.size());i++)
		_out_neu[i]._error = must_be[i] - _out_neu[i]._val;

	for (size_t l = _hide_neu.size();l > 0;l--) {
		if (l == _hide_neu.size())
			Backward(_hide_neu[l - 1], _out_neu);
		else
			Backward(_hide_neu[l - 1], _hide_neu[l]);
	}

	for (int l = _hide_neu.size();l >= 0;l--) {
		if (l == _hide_neu.size())
			Correcting(_hide_neu[l - 1], _out_neu);
		else if (l == 0)
			Correcting(_inp_neu,_hide_neu[l]);
		else
			Correcting(_hide_neu[l - 1], _hide_neu[l]);
	}

	#ifdef DEBUG
	printd(
		"class NeuralNetwork<typename>.correct(std::vector<typename>) is done",
		'i');
	#endif // DEBUG
}

template <typename var>
void NeuralNetwork<var>::reinit(
	size_t neu_inp, 
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	#ifdef DEBUG
	printd("class NeuralNetwork<typename> is starting restart", 'i');
	#endif // DEBUG
	finit();
	init(neu_inp,
		neu_out,
		coef_learn,
		is_rand);
	#ifdef DEBUG
	printd("class NeuralNetwork<typename> is restarted succesful", 'i');
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
	printd("class NeuralNetwork<typename> is finished succesful", 'i');
	#endif // DEBUG
}

template <typename var>
NeuralNetwork<var>::~NeuralNetwork() {
	finit();
	#ifdef DEBUG
	printd("class NeuralNetwork<typename> is ended up", 'i');
	#endif // DEBUG
}
