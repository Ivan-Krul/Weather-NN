// Weather NN.cpp: определяет точку входа для приложения.
//

#include "Weather NN.h"

unsigned __int64 Random::_Sseed = 0;
unsigned __int64 Random::_Sx = Random::_Sseed;

int main() {
	poinve<int> mas;
	mas.init(8);
	
	for (size_t i = 0;i < mas.size();i++)
		mas[i] = rand();

	mas.resize(20);

	printf("Hello, CMake.\n");
	for (int i = 0;i < mas.size();i++)
		printf("%i ", mas[i]);

	return 0;
}
