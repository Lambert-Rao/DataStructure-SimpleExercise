#pragma once
#include <array>

template<typename ElemType>
class Vector
{
public:
	//constructor
	Vector(std::initializer_list<ElemType> il)
	{
		_size = il.size();
		_capacity = _size;
		_pointer = new ElemType[_size];
		for (size_t i = 0; i < _size; ++i)
		{
			_pointer[i] = *(il.begin() + i);
		}
	}

	template<ElemType,size_t N>
	Vector(std::array<ElemType, N> array)
	{
		_size = array.size();
		_capacity = _size;
		_pointer = new ElemType[_size];
        for (size_t i = 0; i < _size; i++)
            _pointer[i] = array[i];
	}
	explicit  Vector(int capacity=0)
	{
		_size = 0;
		_capacity = capacity;
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
	//destructor
	~Vector()
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
        if(index>=_size || index<0)
            throw std::out_of_range("index out of range");
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
			_capacity =_capacity* 2+1;
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
    bool empty() const {
        return _size == 0;
    }

protected:
	size_t _size{ 0 }, _capacity{ 0 };
	ElemType* _pointer{ nullptr };
	
};

