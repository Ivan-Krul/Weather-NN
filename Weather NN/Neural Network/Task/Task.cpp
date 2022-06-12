#include "Task.h"

template<typename T, size_t size_inp, size_t size_out>
Task<T, size_inp, size_out>::Task() {
	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class Task<T, size_inp, size_out> is launched", 'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

// MARK: save & load work in one folder ith file of executable
template<typename T, size_t size_inp, size_t size_out>
void Task<T, size_inp, size_out>::load(std::string dir_and_name_and_format) {
	std::ifstream ifs;
	try {
		ifs.open(dir_and_name_and_format);

		if(!ifs.is_open()) throw std::system_error(std::make_error_code(std::errc::no_such_file_or_directory));
		if(ifs.fail()) throw std::system_error(std::make_error_code(std::errc::file_exists));

		size_t i = 0;
		double inp;
		std::pair<std::vector<T>, std::vector<T>> p;
		while(ifs >> inp) {

			if(i % (size_inp + size_out) < size_inp)
				p.first.push_back(inp);
			else
				p.second.push_back(inp);
			i++;

			if(i % (size_inp + size_out) == 0 && i != 0)
				_data.push_back(p);
		}
		ifs.close();

		//////////////////////////////////////////
		#ifdef DEBUG
		printd("class Task<T, size_inp, size_out>::load(std::string dir_and_name_and_format) is done", 'i');
		#endif // DEBUG
		//////////////////////////////////////////
	}
	catch(std::system_error& e) {
		//////////////////////////////////////////
		#ifdef DEBUG
		printe(e);
		#endif // DEBUG
		//////////////////////////////////////////
	}

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
std::pair<std::vector<T>, std::vector<T>> Task<T, size_inp, size_out>::test() {
	try {
		if(_data.size() == 0) throw std::system_error(std::make_error_code(std::errc::no_buffer_space));

		_num_test++;
		auto iter = _data.begin();

		for(size_t i = 0; i < _num_test && i < _data.size(); i++)
			iter++;

		iter--;

		//////////////////////////////////////////
		#ifdef DEBUG
		printd("class Task<T, size_inp, size_out>::test() is done", 'i');
		#endif // DEBUG
		//////////////////////////////////////////

		return *iter;
	}
	catch(std::system_error& e) {
		//////////////////////////////////////////
		#ifdef DEBUG
		printe(e);
		#endif // DEBUG
		//////////////////////////////////////////

		return std::pair<std::vector<T>, std::vector<T>>();
	}
}

template<typename T, size_t size_inp, size_t size_out>
void Task<T, size_inp, size_out>::begin() {
	_num_test = 0;

	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class Task<T, size_inp, size_out>::begin() is done", 'i');
	#endif // DEBUG
	//////////////////////////////////////////
}

template<typename T, size_t size_inp, size_t size_out>
Task<T, size_inp, size_out>::~Task() {
	//////////////////////////////////////////
	#ifdef DEBUG
	printd("class Task<T, size_inp, size_out> is ended up", 'i');
	#endif // DEBUG
	//////////////////////////////////////////
}
