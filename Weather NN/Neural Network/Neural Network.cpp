#include "Neural Network.h"

void NeuralNetwork::Forward(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, size_t size_lo) {
	for (size_t o = 0;o < size_lo - 1;o++) {
		Lo[o] = 0;
		for (size_t i = 0;i < size_li;i++)
			Lo[o] += Li[i] * W[size_li * o + i];

		// TODO: видалити це
		Lo[o] = var(1.0) / (var(1.0) + var(exp(-Lo[o])));
	}
}

void NeuralNetwork::Backward(var* Ei, size_t size_li, var* W, size_t size_w, var* Eo, size_t size_lo) {
	size_li--;

	for (size_t i = 0;i < size_li;i++) {
		Ei[i] = 0;
		for (size_t o = 0;o < size_lo;o++)
			Ei[i] += Eo[o] * W[size_li * o + i];
	}
}

void NeuralNetwork::Correcting(var* Li, size_t size_li, var* W, size_t size_w, var* Lo, var* Eo, size_t size_lo) {
	for (size_t o = 0;o < size_lo;o++) {
		for (size_t i = 0;i < size_li;i++) {
			W[size_li * o + i] += CoeficientLearn * Li[i] * Eo[o] //;
				// TODO: видалити це
				* Lo[o] * (var(1.0) - Lo[o]);
		}
	}
}

NeuralNetwork::NeuralNetwork(size_t neu_inp, size_t neu_out) {
}

void NeuralNetwork::init(size_t neu_inp, size_t neu_out) {
}

void NeuralNetwork::reinit(size_t neu_inp, size_t neu_out) {
}

void NeuralNetwork::finit() {
}

NeuralNetwork::~NeuralNetwork() {
	finit();
}
