#include "Tester.h"

template<typename var, size_t size_inp, size_t size_out>
Tester<var, size_inp, size_out>::Tester() {
	#ifdef DEBUG
	printi("class Tester<var, size_inp, size_out> is launched");
	#endif
}

template<typename var, size_t size_inp, size_t size_out>
void Tester<var,size_inp, size_out>::write(NeuralNetwork<var>& nn, Task<var, size_inp, size_out>& t) {
	_cur = t.test();

	nn.input(_cur.first);
	#ifdef DEBUG
	printi("class Tester<var,size_inp, size_out>::write(NeuralNetwork<var>& nn, Task<var, size_inp, size_out>& t) is done");
	#endif
}

template<typename var, size_t size_inp, size_t size_out>
void Tester<var, size_inp, size_out>::check(NeuralNetwork<var>& nn) {
	std::vector<var> out = nn.output();
	std::vector<var>& must_be = _cur.second;

	std::ofstream ofs;

	ofs.open("statistic.txt");
	
	for(size_t i = 0; i < std::min(out.size(),must_be.size()); i++)
		ofs << out[i] <<' ' << must_be[i]<<'\n';

	ofs.close();

	nn.correct(_cur.second);
	#ifdef DEBUG
	printi("class Tester<var, size_inp, size_out>::check(NeuralNetwork<var>& nn) is done");
	#endif
}

template<typename var, size_t size_inp, size_t size_out>
Tester<var, size_inp, size_out>::~Tester() {
	#ifdef DEBUG
	printi("class Tester<var, size_inp, size_out> is ended up");
	#endif
}
