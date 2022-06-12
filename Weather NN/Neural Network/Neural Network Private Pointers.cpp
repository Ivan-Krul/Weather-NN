#include "Neural Network.h"

template <typename var>
void NeuralNetwork<var>::Forward(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo) {
	for (size_t o = 0;o < size_lo - 1;o++) {
		Lo[o] = 0;
		for (size_t i = 0;i < size_li;i++)
			Lo[o] += Li[i] * W[size_li * o + i];

		// TODO: �������� ��
		Lo[o] = var(1.0) / (var(1.0) + var(exp(-Lo[o])));
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::Forward(var* Li, size_t size_li,var* W, size_t size_w,var* Lo, size_t size_lo) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo) {
	size_li--;

	for (size_t i = 0;i < size_li;i++) {
		Ei[i] = 0;
		for (size_t o = 0;o < size_lo;o++)
			Ei[i] += Eo[o] * W[size_li * o + i];
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class void NeuralNetwork<var>::Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template <typename var>
void NeuralNetwork<var>::Correcting(var* Li, size_t size_li,var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo) {
	for (size_t o = 0;o < size_lo;o++) {
		for (size_t i = 0;i < size_li;i++) {
			W[size_li * o + i] += _coef_learn * Li[i] * Eo[o] //;
				// TODO: �������� ��
				* Lo[o] * (var(1.0) - Lo[o]);
		}
	}

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("class NeuralNetwork<var>::Correcting(var* Li, size_t size_li, * W, size_t size_w, var* Lo, var* Eo, size_t size_lo) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}
