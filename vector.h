#pragma once
#include <array>


namespace my_data_structure
{
template<typename ElemType>
class vector
{
public:
	//constructor
	vector(std::initializer_list<ElemType> list)
	{
		_size = list.size();
		_capacity = _size;
		_pointer = new ElemType[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_pointer[i] = *(list.begin() + i);
		}
	}
	template<ElemType,size_t N>
	vector(std::array<ElemType, N> array)
	{
		_size = array.size();
		_capacity = _size;
		_pointer = new ElemType[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_pointer[i] = array[i];
		}
	}
	explicit  vector(int size=0)
	{
		_size = size;
		_capacity = _size;
		_pointer = new ElemType[_size];
	}
	size_t size() const
	{
		return _size;
	}
	size_t capacity() const
	{
		return _capacity;
	}
	//distructor
	~vector()
	{
		delete[] _pointer;
	}
	//iterators
	using iterator = ElemType*;
	iterator begin()
	{
		return _pointer;
	}
	iterator end()
	{
		return _pointer + _size;
	}
	const iterator begin() const
	{
		return _pointer;
	}
	const iterator end() const
	{
		return _pointer + _size;
	}
	ElemType &operator[](size_t index)
	{
		return _pointer[index];
	}
	ElemType pop_back()
	{
		ElemType temp = _pointer[_size - 1];
		_size--;
		return temp;
	}
	ElemType push_back(ElemType elem)
	{
		if (_size == _capacity)
		{
			_capacity *= 2;
			ElemType *temp = new ElemType[_capacity];
			for (size_t i = 0; i < _size; i++)
			{
				temp[i] = _pointer[i];
			}
			delete[] _pointer;
			_pointer = temp;
		}
		_pointer[_size] = elem;
		_size++;
		return elem;
	}
private:
	size_t _size{ 0 }, _capacity{ 0 };
	ElemType* _pointer{ nullptr };
	
};

}