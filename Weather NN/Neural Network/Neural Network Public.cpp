#include "Neural Network.h"

template <typename var>
NeuralNetwork<var>::NeuralNetwork(
	size_t neu_inp,
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var> is launched");
	#endif // DEBUG
	//////////////////////////////////////////

	init(neu_inp, neu_out, coef_learn, is_rand);
}

template <typename var>
void NeuralNetwork<var>::init(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand) {
	_inp_neu.resize(neu_inp);
	_out_neu.resize(neu_out);
	_coef_learn = coef_learn;
	_is_rand = is_rand;

	for (size_t i = 0;i < _out_neu.size();i++)
		_out_neu[i].init_weight(_is_rand,_inp_neu.size());

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::init(size_t neu_inp, size_t neu_out, float coef_learn, bool is_rand) is started succesful");
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
void NeuralNetwork<var>::push_back(size_t size) {
	std::vector<neuron<var>> a;
	a.resize(size);
	_hide_neu.push_back(a);

	AdaptWeight();

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::push_back(size_t size) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
void NeuralNetwork<var>::input(std::vector<var> inp_neu) {
	for (size_t i = 0;i < std::min(_inp_neu.size(), inp_neu.size());i++)
		_inp_neu[i] = inp_neu[i];

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::input(std::vector<var> inp_neu) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
std::vector<var> NeuralNetwork<var>::calculate() {
	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::calculate() has starting");
	#endif // DEBUG
	//////////////////////////////////////////

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

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::calculate() is done");
	#endif // DEBUG
	//////////////////////////////////////////

	return out;
}

template<typename var>
std::vector<var> NeuralNetwork<var>::output() {
	std::vector<var> out;
	out.resize(_out_neu.size());

	for(size_t i = 0; i < out.size(); i++)
		out[i] = _out_neu[i]._val;

	return out;
}

template<typename var>
void NeuralNetwork<var>::correct(std::vector<var> must_be) {
	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::correct(std::vector<var> must_be) has starting");
	#endif // DEBUG
	//////////////////////////////////////////

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

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::correct(std::vector<var> must_be) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::reinit(
	size_t neu_inp, 
	size_t neu_out,
	float coef_learn,
	bool is_rand
) {
	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var> is starting restart");
	#endif // DEBUG
	//////////////////////////////////////////

	finit();
	init(neu_inp,
		neu_out,
		coef_learn,
		is_rand);

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var> is restarted succesful");
	#endif // DEBUG
	//////////////////////////////////////////
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

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var> is finished succesful");
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
NeuralNetwork<var>::~NeuralNetwork() {
	finit();

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var> is ended up");
	#endif // DEBUG
	//////////////////////////////////////////
}
