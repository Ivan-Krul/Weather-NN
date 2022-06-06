#pragma once
#include <stdio.h>

#define DEBUG

#ifdef DEBUG
void printd(const char msg[]) {
	printf("Debug: %s", msg);
}
#endif // DEBUG

__int64 randll() {
	return static_cast<__int64>(__int64(rand())*113 / 16);
}

__int32 randi() {
	return static_cast<__int32>(__int64(rand()) * 113 / 16);
}

__int16 rands() {
	return static_cast<__int16>(__int64(rand()) * 113 / 16);
}

__int8 randc() {
	return static_cast<__int8>(__int64(rand()) * 113 / 16);
}

float randf() {
	return float(rand()) / 0x7fff;
}

double randd() {
	return double(rand()) / 0x7fffffff;
}

