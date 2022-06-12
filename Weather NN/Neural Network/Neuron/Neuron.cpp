#include "Neuron.h"

template<typename var>
neuron<var>::neuron() {
		//////////////////////////////////////////
	#ifdef DEBUG
	printi("struct neuron<var> is launched");
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
void neuron<var>::init_weight(bool is_rand, size_t parent_l) {
	_weight.resize(parent_l);

	for(size_t i = 0; i < parent_l; i++)
		if(is_rand)
			_weight[i] = random::randbf(-3, 3);
		else
			_weight[i] = 0;

	if(is_rand)
		_bias = random::randbf(-3, 3);
	else
		_bias = 0;

	//////////////////////////////////////////
	#ifdef DEBUG
	printi("struct neuron<var>::init_weight(bool is_rand, size_t parent_l) is done");
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename var>
neuron<var>::~neuron() {
		//////////////////////////////////////////
	#ifdef DEBUG
	printi("struct neuron<var> is ended up");
	#endif // DEBUG
	//////////////////////////////////////////
}
