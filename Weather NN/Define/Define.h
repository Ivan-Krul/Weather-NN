#pragma once
#include <stdio.h>
#include <cmath>

#define DEBUG

#ifdef DEBUG
void printd(const char msg[],const char type = '\0') {
	if(type != '\0')
		printf("Debug: (%c) %s\n", type, msg);
	else
		printf("Debug: (NULL) %s\n", msg);
}
#endif // DEBUG

namespace random {
	__int64 randll() {
		return static_cast<__int64>(__int64(rand()) * 113 / 16);
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
		return float(rand()) / 0x7f;
	}
	double randd() {
		return double(rand()) / 0x7fffff;
	}

	__int64 randbll(__int64 board) {
		return static_cast<__int64>(std::fmod(randll(), board));
	}
	__int32 randbi(__int32 board) {
		return static_cast<__int32>(std::fmod(randll(), board));
	}
	__int16 randbs(__int16 board) {
		return static_cast<__int16>(std::fmod(randll(), board));
	}
	__int8 randbc(__int8 board) {
		return static_cast<__int8>(std::fmod(randll(), board));
	}
	float randbf(float board) {
		return std::fmodf(randll(), board);
	}
	double randbd(double board) {
		return std::fmod(randll(), board);
	}

	__int64 randbll(__int64 left, __int64 rigth) {
		return randbll(rigth - left) + left;
	}
	__int32 randbi(__int32 left, __int32 rigth) {
		return randbi(rigth - left) + left;
	}
	__int16 randbs(__int16 left, __int16 rigth) {
		return randbs(rigth - left) + left;
	}
	__int8 randbc(__int8 left, __int8 rigth) {
		return randbc(rigth - left) + left;
	}
	float randbf(float left, float rigth) {
		return randbf(rigth - left) + left;
	}
	double randbd(double left, double rigth) {
		return randbd(rigth - left) + left;
	}
}
