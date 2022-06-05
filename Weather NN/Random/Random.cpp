#include "Random.h"

void Random::turn() {
	_Sx = _Sx * _SCa + _SCc;
}

unsigned __int64 Random::nextll() {
	turn();
	return _Sx;
}
unsigned __int64 Random::nextll(unsigned __int64 board){
	return nextll()%board;
}
__int64 Random::nextll(__int64 left, __int64 rigth){
	return nextll(rigth - left) + left;
}

unsigned __int32 Random::nexti(){
	turn();
	return _Sx;
}
unsigned __int32 Random::nexti(unsigned __int32 board){
	return nexti() % board;
}
__int32 Random::nexti(__int32 left, __int32 rigth){
	return nexti(rigth - left) + left;
}

unsigned __int16 Random::nexts(){
	turn();
	return _Sx;
}
unsigned __int16 Random::nexts(unsigned __int16 board){
	return nexts() % board;
}
__int16 Random::nexts(__int16 left, __int16 rigth){
	return nexts(rigth - left)+left;
}

unsigned __int8 Random::nextc(){
	turn();
	return _Sx;
}
unsigned __int8 Random::nextc(unsigned __int8 board){
	return nextc() % board;
}
__int8 Random::nextc(__int8 left, __int8 rigth){
	return nextc(rigth - left)+left;
}

float Random::nextf(){
	turn();
	return _Sx / 0xffff;
}
float Random::nextf(float board){
	return std::fmod(nextf(),board);
}
float Random::nextf(float left,float rigth){
	return nextf(rigth - left)+left;
}

double Random::nextd(){
	turn();
	return _Sx / 0xffffffff;
}
double Random::nextd(double board){
	return std::fmod(nextd(),board);
}
double Random::nextd(double left,double rigth){
	return nextd(rigth - left)+left;
}
