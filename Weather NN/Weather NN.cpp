// Weather NN.cpp: определяет точку входа для приложения.
//

#include <stdio.h>
#include "Neural Network/Neural Network.h"
#include "Define/Define.h"

int main() {
	srand(0);
	#ifdef DEBUG
	printd("debug mode is activated",'D');
	#endif // DEBUG msg activation

	neu_netf nn(3, 2, 0.2, true);
	nn.push_back(4);
	nn.push_back(3);

	std::vector<float> a;

	for (int i = 0;i < 1000;i++) {
		a = { 0.1f,0.5f,0.9f };
		nn.input(a);
		a = nn.calculate();

		for (const float &iter : a) {
			printf("%f ", iter);
		}
		printf("\n");
		a = { 1.0f,0.0f };
		nn.correct(a);
	}


	#ifdef DEBUG
	printd("application is finished work", 'D');
	#else
	(void)getchar();
	#endif // DEBUG msg activation
	return 0;
}
