// Weather NN.cpp: определяет точку входа для приложения.
//

#include "Weather NN.h"

int main() {
	srand(0);
	#ifdef DEBUG
	printd("debug mode is activated",'D');
	#endif // DEBUG msg activation

	neu_netf nn(2, 2, 0.5f, true);
	nn.push_back(2);
	nn.push_back(2);
	std::vector<float> a = { 0.1f,0.5f };

	nn.input(a);
	a = nn.calculate();

	for (int t = 0;t < 1000;t++) {
		for (int i = 0;i < a.size();i++)
			printf("%f ", a[i]);
		printf("\n");

		a = { 1.0f,0.0f };
		nn.correct(a);

		a = { 0.1f,0.5f };
		nn.input(a);
		a = nn.calculate();
	}

	#ifdef DEBUG
	printd("application is finished work", 'D');
	#else
	(void)getchar();
	#endif // DEBUG msg activation
	return 0;
}
