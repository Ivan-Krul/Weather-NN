#pragma once

namespace point_massive {
	template<typename _T> _T* initializ_and_fill(
		size_t size,
		_T fill
	) {
		_T* mas = new _T[size];

		for (size_t i = 0;i < size;i++)
			mas[i] = fill;

		return mas;
	}

	template<typename _T> _T* initializ_and_fill(
		size_t size,
		_T func()
	) {
		_T* mas = new _T[size];

		for (size_t i = 0;i < size;i++)
			mas[i] = func();

		return mas;
	}

	template<typename _T> void resize(
		_T* mas,
		size_t new_size
	) {
		delete[] mas;
		mas = new _T[new_size];
	}

	template<typename _T> void resize_and_fill(
		_T* mas,
		size_t new_size,
		_T fill
	) {
		delete[] mas;
		mas = new _T[new_size];

		for (size_t i = 0;i < new_size;i++)
			mas[i] = fill;
	}
}