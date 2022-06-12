// Weather NN.cpp: определяет точку входа для приложения.
//

#include <stdio.h>
#include "Neural Network/Task/Task.h"
#include "Define/Define.h"
#include "Neural Network/Tester/Tester.h"

int main() {
	srand(0);

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("debug mode is activated", 'D');
	#endif // DEBUG msg activation
	//////////////////////////////////////////

	Task<float, 4, 2> t;
	NeuralNetwork<float> nn(4,2,0.1,true);
	Tester<float, 4, 2> te;

	nn.push_back(3);
	nn.push_back(2);

	t.load("bbb.txt");
	t.begin();

	te.write(nn, t);
	nn.calculate();
	te.check(nn);

	nn.calculate();

	for(size_t i = 0; i < 2; i++)
		printf("%f\n", nn.output()[i]);

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("application is finished work", 'D');
	#else
	(void)getchar();
	#endif // DEBUG msg activation
	//////////////////////////////////////////

	return 0;
}
