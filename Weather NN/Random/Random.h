#pragma once
#include <cmath>
#include <ctime>

class Random {
	const static unsigned __int64 _SCa = 1103515245;
	const static unsigned __int64 _SCc = 12345;

	void turn();

	public:
	static unsigned __int64 _Sseed;
	static unsigned __int64 _Sx;

	Random() {
	}

	unsigned __int64 nextll();
	unsigned __int64 nextll(unsigned __int64 board);
	__int64 nextll(__int64 left, __int64 rigth);
	
	unsigned __int32 nexti();
	unsigned __int32 nexti(unsigned __int32 board);
	__int32 nexti(__int32 left, __int32 rigth);

	unsigned __int16 nexts();
	unsigned __int16 nexts(unsigned __int16 board);
	__int16 nexts(__int16 left, __int16 rigth);

	unsigned __int8 nextc();
	unsigned __int8 nextc(unsigned __int8 board);
	__int8 nextc(__int8 left, __int8 rigth);
	
	float nextf();
	float nextf(float board);
	float nextf(float left,float rigth);

	double nextd();
	double nextd(double board);
	double nextd(double left,double rigth);

	~Random() {
	}
};
