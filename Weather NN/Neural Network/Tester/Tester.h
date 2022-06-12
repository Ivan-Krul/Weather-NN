#pragma once
#include "../Task/Task.h"
#include "../Neural Network.h"
#include "../../Define/Define.h"
#include <vector>
#include <fstream>

template<typename var,size_t size_inp,size_t size_out>
class Tester {
	#ifdef DEBUG
public:
	#else
private:
	#endif // DEBUG

	std::pair<std::vector<var>, std::vector<var>> _cur;
	std::ofstream ofs;
public:
	Tester();

	void write(NeuralNetwork<var>& nn, Task<var,size_inp,size_out>& t);

	void check(NeuralNetwork<var>& nn);

	~Tester();
};
#include "Tester.cpp"
