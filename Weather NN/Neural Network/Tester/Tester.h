#pragma once
#include "../Task/Task.h"
#include "../Neural Network.h"
#include "../../Define/Define.h"

template<typename var>
class Tester {
	#ifdef DEBUG
public:
	#else
private:
	#endif // DEBUG

	std::pair<std::vector<var>, std::vector<var>> _cur;
public:
	void write(NeuralNetwork<var> nn, Task t);

	void check(NeuralNetwork<var> nn);
};
#include "Tester.cpp"
