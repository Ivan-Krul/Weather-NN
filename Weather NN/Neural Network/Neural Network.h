#pragma once
#include <memory>
#include "../Poinve/poinve.h"
#include "../Random/Random.h"
//#include <functional>

class NeuralNetwork {
	typedef float var;

	float _coef_learn = 0.1f;

	poinve<var> _neuron_inp;

	poinve<poinve<var>> _neuron_hide;
	poinve<poinve<var>> _error_hide;

	poinve<poinve<var>> _weigth;

	// TODO: зробити вказівник-масив для функції активації
	//poinve<std::function<var(var)>> _type_sys;

	poinve<var> _neuron_out;
	poinve<var> _error_out;

	void Forward(var* Li,size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo) {
		for (size_t o = 0;o < size_lo - 1;o++) {
			Lo[o] = 0;
			for (size_t i = 0;i < size_li;i++)
				Lo[o] += Li[i] * W[size_li * o + i];

			// TODO: видалити це
			Lo[o] = var( 1.0 ) / (var( 1.0 ) + var( exp(-Lo[o]) ));
		}
	}

	void Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo) {
		size_li--;

		for (size_t i = 0;i < size_li;i++) {
			Ei[i] = 0;
			for (size_t o = 0;o < size_lo;o++)
				Ei[i] += Eo[o] * W[size_li * o + i];
		}
	}

	void Correcting(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo) {
		for (size_t o = 0;o < size_lo;o++) {
			for (size_t i = 0;i < size_li;i++) {
				W[size_li * o + i] += _coef_learn * Li[i] * Eo[o] //;
					// TODO: видалити це
					* Lo[o] * (var( 1.0 ) - Lo[o]);
			}
		}
	}

	void Forward(poinve<var> Li, poinve<var> W, poinve<var>& Lo) {
		for (size_t o = 0;o < Lo.size() - 1;o++) {
			Lo[o] = 0;
			for (size_t i = 0;i < Li.size();i++)
				Lo[o] += Li[i] * W[Li.size() * o + i];

			// TODO: видалити це
			Lo[o] = var(1.0) / (var(1.0) + var(exp(-Lo[o])));
		}
	}

	void Backward(poinve<var>& Ei, poinve<var> W, poinve<var>& Eo) {

		for (size_t i = 0;i < Ei.size()-1;i++) {
			Ei[i] = 0;
			for (size_t o = 0;o < Eo.size();o++)
				Ei[i] += Eo[o] * W[Ei.size() * o + i];
		}
	}

	void Correcting(poinve<var> Li, poinve<var>& W, poinve<var>& Lo, poinve<var>& Eo) {
		for (size_t o = 0;o < Lo.size();o++) {
			for (size_t i = 0;i < Li.size();i++) {
				W[Li.size() * o + i] += _coef_learn * Li[i] * Eo[o] //;
					// TODO: видалити це
					* Lo[o] * (var(1.0) - Lo[o]);
			}
		}
	}

	void AdaptWeigth() {
		if (_neuron_hide.size() == 0) {
			_weigth.push_back(poinve<var>(_neuron_inp.size() * _neuron_out.size()));
		}
		else {
			_weigth.resize(_neuron_hide.size() + 1);

			for (size_t i = 0;i < _weigth.size();i++) {
				if (i == 0) {
					_weigth[i].resize(_neuron_inp.size() * (_neuron_hide[i].size() - 1));
				}
				else if (i + 1 == _weigth.size()) {
					_weigth[i].resize(_neuron_out.size() * _neuron_hide[i].size());
				}
				else {
					_weigth[i].resize((_neuron_hide[i].size() - 1) * _neuron_hide[i - 1].size());
				}
			}
		}
	}

	public:
	NeuralNetwork() {}
	NeuralNetwork(size_t neu_inp, size_t neu_out) {
		init(neu_inp, neu_out);
	}

	//ініціалізація вхідного і визідного нейронів враховуючи зміщення
	void init(size_t neu_inp,size_t neu_out) {
		_neuron_inp.init(neu_inp + 1);
		_neuron_inp[_neuron_inp.size() - 1] = 1;

		_neuron_hide.init(0);
		_error_hide.init(0);

		_neuron_out.init(neu_out);
		_error_out.init(neu_out);

		AdaptWeigth();
	}

	// створення нового шару прихованого шару нейронів не враховуючи нейрон зміщення
	void push_hide_neurons(size_t lh_size) {
		_neuron_hide.push_back(poinve<var>(lh_size + 1));
		_error_hide.push_back(poinve<var>(lh_size + 1));
		_neuron_hide[_neuron_hide.size() - 1] = 1;

		AdaptWeigth();
	}

	void randomize() {
		Random random;

		for (size_t i = 0;i < _weigth.size();i++) {
			for (size_t j = 0;j < _weigth[i].size();j++) {
				_weigth[i][j] = random.nextf(-3, 3);
			}
		}
	}

	size_t input_size() {
		return _neuron_inp.size();
	}

	poinve<var> calculate_result(poinve<var> input) {
		if (input.size() + 1 == _neuron_inp.size()) {
			for (size_t i = 0;i < _neuron_inp.size() - 1;i++)
				_neuron_inp = input;

			if (_neuron_hide.size() == 0)
				Forward(_neuron_inp, _weigth[0], _neuron_out);
			else {
				for (size_t i = 0;i < _weigth.size();i++) {
					if (i == 0)
						Forward(_neuron_inp, _weigth[i], _neuron_hide[i]);
					else if (i + 1 == _weigth.size())
						Forward(_neuron_hide[i - 1], _weigth[i], _neuron_out);
					else
						Forward(_neuron_hide[i - 1], _weigth[i], _neuron_hide[i]);
				}
			}
		}
		else abort();

		return _neuron_out;
	}

	void mark_error(poinve<var> answer) {
		if (answer.size() == _error_out.size()) {
			for (size_t i = 0;i < _error_out.size();i++)
				_error_out[i] = answer[i] - _neuron_out[i];

			for (size_t i = _weigth.size() - 1;i > 0;i++) {
				if (i + 1 == _weigth.size())
					Backward(_error_out, _weigth[i], _error_hide[i]);
				else
					Backward(_error_hide[i], _weigth[i], _error_hide[i + 1]);
			}
		}
		else abort();
	}

	void correct() {
		for (size_t i = _weigth.size() - 1;i >= 0;i++) {
			if (i + 1 == _weigth.size())
				Correcting(_neuron_hide[i - 1], _weigth[i], _neuron_out, _error_out);
			else if (i == 0)
				Correcting(_neuron_inp, _weigth[i], _neuron_hide[i], _error_hide[i]);
			else
				Correcting(_neuron_hide[i - 1], _weigth[i], _neuron_hide[i], _error_hide[i]);
		}
	}

	~NeuralNetwork() {}
};
