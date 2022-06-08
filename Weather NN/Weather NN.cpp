// Weather NN.cpp: определяет точку входа для приложения.
//

#include "Weather NN.h"

int main() {
	srand(0);
	#ifdef DEBUG
	printd("debug mode is activated",'D');
	#endif // DEBUG msg activation

	neu_netf nn(2, 5, 0.1f, true);
	nn.push_back(2);
	nn.push_back(2);
	std::vector<float> a = { 0.1,0.5 };

	nn.input(a);
	a = nn.calculate();

	for (int i = 0;i < a.size();i++)
		printf("%f ",a[i]);
	printf("\n");

	#ifdef DEBUG
	printd("application is finished work", 'D');
	#endif // DEBUG msg activation
	(void)getchar();
	return 0;
}
