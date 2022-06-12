// Weather NN.cpp: определяет точку входа для приложения.
//

#include <stdio.h>
#include "Neural Network/Task/Task.h"
#include "Define/Define.h"

int main() {
	srand(0);

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("debug mode is activated", 'D');
	#endif // DEBUG msg activation
	//////////////////////////////////////////

	Task<float, 4, 2> t;
	t.load("bbb.txt");
	t.begin();

	auto p = t.test();

	for(size_t i = 0; i < p.first.size(); i++)
		printf("%f\n", p.first[i]);
	for(size_t i = 0; i < p.second.size(); i++)
		printf("%f\n", p.second[i]);

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("application is finished work", 'D');
	#else
	(void)getchar();
	#endif // DEBUG msg activation
	//////////////////////////////////////////

	return 0;
}
