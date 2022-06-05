#pragma once
#include <memory>
#include "../Poinve/poinve.h"
//#include <functional>

class NeuralNetwork {
	typedef float var;
	typedef unsigned __int32 count;

	float _coef_learn = 0.1f;

	poinve<var> _neuron_inp;
	poinve<poinve<var>> _weigth;

	// TODO: зробити вказівник-масив для функції активації
	//poinve<std::function<var(var)>> _type_sys;

	poinve<var> _neuron_out;

	void forward(var* Li,count size_li, var* W, count size_w, var* Lo, count size_lo) {
		for (count o = 0;o < size_lo;o++) {
			Lo[o] = 0;
			for (count i = 0;i < size_li;i++)
				Lo[o] += Li[i] * W[size_li * o + i];

			// TODO: видалити це
			Lo[o] = var( 1.0 ) / (var( 1.0 ) + var( exp(-Lo[o]) ));
		}
	}

	void backward(var* Ei, count size_li, var* W, count size_w, var* Eo, count size_lo) {
		size_li--;

		for (count i = 0;i < size_li;i++) {
			Ei[i] = 0;
			for (count o = 0;o < size_lo;o++)
				Ei[i] += Eo[o] * W[size_li * o + i];
		}
	}

	void correcting(var* Li, count size_li, var* W, count size_w, var* Lo, var* Eo, count size_lo) {
		for (count o = 0;o < size_lo;o++) {
			for (count i = 0;i < size_li;i++) {
				W[size_li * o + i] += _coef_learn * Li[i] * Eo[o]
					// TODO: видалити це
					* Lo[o] * (var( 1.0 ) - Lo[o]);
			}
		}
	}
	public:
};
