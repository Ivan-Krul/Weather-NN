#include "Task.h"

template<typename T, size_t size_inp, size_t size_out>
Task<T, size_inp, size_out>::Task()
{

	#ifdef DEBUG
	printd("class Task<typename,size_t,size_t> is launched", 'i');
	#endif // DEBUG
}

template<typename T, size_t size_inp, size_t size_out>
void Task<T, size_inp, size_out>::load(std::string dir_and_name_and_format) {
	std::ifstream ifs;
	ifs.open(dir_and_name_and_format);
	
	assert(!ifs.is_open());
	
	size_t size;
	ifs >> size;

	#ifdef DEBUG
	printa<size_t>(size, "class Task<typename,size_t,size_t>.load(std::string).size");
	#endif // DEBUG

	size_t iter = 0;
	size_t i = 0;
	while(ifs && iter<size) {
		pai p = std::make_pair(std::vector<T>(), std::vector<T>());
		for (i = 0;i < size_inp;i++) {
			T a;
			if(!ifs.eof()) ifs >> a;
			p.first.push_back(a);
		}
		for (i = 0;i < size_out;i++) {
			T a;
			if (!ifs.eof()) ifs >> a;
			p.second.push_back(a);
		}
		_data.push_back(p);
		#ifdef DEBUG
		printa<size_t>(iter, "class Task<typename,size_t,size_t>.load(std::string).i");
		#endif // DEBUG
		iter+= size_inp + size_out;
		i++;
	}
	ifs.close();
	#ifdef DEBUG
	printd("class Task<typename,size_t,size_t>.load(std::string) is done", 'i');
	#endif // DEBUG
}

template<typename T, size_t size_inp, size_t size_out>
const size_t Task<T, size_inp, size_out>::number_test() {
	return return _num_test;
}

template<typename T, size_t size_inp, size_t size_out>
const size_t Task<T, size_inp, size_out>::size() {
	return _data.size();
}

template<typename T, size_t size_inp, size_t size_out>
pai Task<T, size_inp, size_out>::test() {
	_num_test++;
	
	pai a;

	auto iter = _data.begin();
	
	assert(iter != _data.end());

	for (size_t i = 0; i < _num_test && iter != _data.end();i++)
		iter++;

	if (iter != _data.end()) iter--;

	a = *iter;

	#ifdef DEBUG
	printd("class Task<typename,size_t,size_t>.test() is done", 'i');
	#endif // DEBUG
	return a;

}

template<typename T, size_t size_inp, size_t size_out>
void Task<T, size_inp, size_out>::begin() {
	_num_test = 0;
	//_cur_test = _data.begin();
	#ifdef DEBUG
	printd("class Task<typename,size_t,size_t>.begin() is done", 'i');
	#endif // DEBUG
}

template<typename T, size_t size_inp, size_t size_out>
Task<T, size_inp, size_out>::~Task() {

	#ifdef DEBUG
	printd("class Task<typename,size_t,size_t> is ended up", 'i');
	#endif // DEBUG
}
