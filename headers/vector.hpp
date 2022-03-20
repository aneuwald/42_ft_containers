#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <stdint.h>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		typedef T					value_type;
		typedef std::allocator<T>	allocator_type;
		typedef std::size_t 		size_type;
		typedef value_type			*pointer;
		typedef value_type			&reference;

	private:

		allocator_type	_allocator;
		pointer			_start;
		size_type		_size;
		size_type		_capacity;

		void reallocate_capacity()
		{
			_capacity *= 2;
			pointer temp = _allocator.allocate(_capacity);
			for (size_type index = 0; index < _size; index++)
				_allocator.construct(temp + index, *(_start + index));
			_allocator.deallocate(_start, _size);
			_start = temp;
		}

	public:

		explicit
		vector(const allocator_type &alloc = allocator_type())
		{
			std::cout << "explicit () constructor" << std::endl;
			_allocator = alloc;
			_size = 0;
			_capacity = _size;
			_start = _allocator.allocate(_size);
		}

		explicit
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			std::cout << "explicit (n, val) constructor" << std::endl;
			_size = n;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_start + i, val);
		}

		template <typename InputIterator
			// , typename std::__is_integer<InputIterator>::__type _Integral
		> 
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
			std::cout << "template (first, last) constructor" << std::endl;
			_size = last - first;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);

			for (size_type index = 0; index < _size; index++)
				_allocator.construct(_start + index, *(first + index));
		}

		vector (const vector& vector) {
			(void) vector;
		}

		~vector()
		{
			std::cout << "destructor" << std::endl;
			_allocator.deallocate(_start, _size);
		}

		reference operator[] (size_type index) { return (_start[index]); }

		allocator_type get_allocator() const { return (allocator_type()); }

		reference front() { return (*_start);}
		reference front() const { return (*_start);}

		reference back() { return (*(_start + _size - 1));}
		reference back() const { return (*(_start + _size - 1));}

		reference at(size_type n) { return (*this)[n]; }
		reference at(size_type n) const { return (*this)[n]; }

		pointer data() { return &(front());}
		pointer data() const { return &(front());}

		size_type capacity() const { return (_capacity); }
		size_type size() const { return (_size); }
		bool empty() const { return (!_size);}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_start + i);
			_size = 0;
		}

		void push_back (value_type el)
		{
			if (_size == _capacity)
				reallocate_capacity();
			(*this)[_size++] = el;
		}

		void pop_back ()
		{
			_size--;
			_allocator.destroy(_start + _size);
		}

		size_type max_size() { return (PTRDIFF_MAX / sizeof(value_type)); };

	};
}

#endif
