#include "Tester.h"

template<typename var>
void Tester<var>::write(NeuralNetwork<var> nn, Task t) {
	_cur = t.test();

	nn.input(_cur.first);
}

template<typename var>
void Tester<var>::check(NeuralNetwork<var> nn) {
	nn.correct(_cur.second);
}
