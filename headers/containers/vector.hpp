#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <stdint.h>

#include "../utils/iterators.hpp"

// REFERENCE: https://en.cppreference.com/w/cpp/container/vector

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::normal_iterator<value_type> iterator;
		typedef ft::normal_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/**********************************************
		 *			       CONSTRUCTORS				  *
		 **********************************************/
		explicit vector(const allocator_type &alloc = Alloc())
		{
			std::cout << "[VECTOR] explicit () constructor" << std::endl;
			_allocator = alloc;
			_size = 0;
			_capacity = _size;
			_start = _allocator.allocate(_size);
		}

		explicit vector(size_type count,
						const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			std::cout << "[VECTOR] explicit (count, val) constructor" << std::endl;
			_size = count;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_start + i, val);
		}

		template <typename InputIt> // , typename std::__is_integer<InputIterator>::__type _Integral >
		vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type())
		{
			std::cout << "[VECTOR] template (first, last) constructor" << std::endl;
			_size = last - first;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);

			for (size_type index = 0; index < _size; index++)
				_allocator.construct(_start + index, *(first + index));
		}

		vector(const vector &other) { 
			std::cout << "[VECTOR] copy constructor" << std::endl;
			*this = other;
		}

		/**********************************************
		 *			       DESTRUCTOR				  *
		 **********************************************/
		~vector()
		{
			std::cout << "[VECTOR] destructor vector" << std::endl;
			_allocator.deallocate(_start, _capacity);
		}

		/**********************************************
		 *			 ASSIGN & GET ALLOCATOR			  *
		 **********************************************/
		vector &operator=(const vector &other)
		{
			std::cout << "[VECTOR] copy assignment called!" << std::endl;
			if (this == &other)
				return *this;
			//this->~vector();
			_size = other.size();
			_capacity = other.capacity();
			_allocator = other.get_allocator();
			_start = _allocator.allocate(_size);
			_copy_vector(other._start, _start, _size);

			return *this;
		}

		void assign(size_type count, const T &value)
		{
			if (count < _capacity)
			{
				for (size_type i = 0; i < count; i++)
				{
					_allocator.destroy(_start + i);
					_allocator.construct(_start + i, value);
				}
				_size = count;
				return;
			}

			_allocator.deallocate(_start, _capacity);
			_size = count;
			_capacity = count;
			_start = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_start + i, value);
		}

		// IMPLEMENTAR
		template <class InputIt>
		void assign(InputIt first, InputIt last);

		allocator_type get_allocator() const { return allocator_type(); }

		/**********************************************
		 *				 ELEMENT ACCESS				  *
		 **********************************************/
		reference at(size_type n) { return (*this)[n]; }
		const_reference at(size_type n) const { return (*this)[n]; }

		reference operator[](size_type pos) { return _start[pos]; }
		const_reference operator[](size_type pos) const { return _start[pos]; }

		reference front() { return (*begin()); }
		const_reference front() const { return (*begin()); }

		reference back() { return *(--end()); }
		const_reference back() const { return *(--end()); }

		T *data() { return &(front()); }
		const T *data() const { return &(front()); }

		/**********************************************
		 *				   ITERATORS				  *
		 **********************************************/
		iterator begin() { return iterator(_start); }
		const_iterator begin() const { return const_iterator(_start); }

		iterator end() { return iterator(_start + _size); }
		const_iterator end() const { return const_iterator(_start + _size); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/**********************************************
		 *				    CAPACITY				  *
		 **********************************************/
		bool empty() const { return (begin() == end()); }

		size_type size() const { return (_size); }

		size_type max_size() { return (PTRDIFF_MAX / sizeof(value_type)); };

		void reserve(size_type n)
		{
			if (n > max_size())
				std::__throw_length_error("vector::reserve");
			if (n <= size())
				return;
			_reallocate_capacity(n);
		}

		size_type capacity() const { return (_capacity); }

		/**********************************************
		 *				   MODIFIERS				  *
		 **********************************************/
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_start + i);
			_size = 0;
		}

		// IMPLEMENTAR !!!
		iterator insert(iterator pos, const T &value);

		// IMPLEMENTAR !!!
		void insert(iterator pos, size_type count, const T &value);

		// IMPLEMENTAR !!!
		template <class InputIt>
		void insert(iterator pos, InputIt first, InputIt last);

		iterator erase(iterator pos)
		{
			size_type index = pos - begin();

			if (index >= _size)
				return pos;
			_size--;

			for (size_type i = index; i < _size; i++)
			{
				_allocator.destroy(_start + i);
				_allocator.construct(_start + i, *(_start + i + 1));
			}
			return (_start + index);
		}

		iterator erase(iterator first, iterator last)
		{
			size_type n = last - first;
			size_type index = first - begin();

			if (index >= size() || first == last)
				return last;
			_size -= n;
			for (size_type i = index; i < _size; i++)
			{
				_allocator.destroy(_start + i);
				_allocator.construct(_start + i, *(_start + i + n));
			}
			return (_start + index);
		}

		void push_back(const T &value)
		{
			if (_size == _capacity)
				_reallocate_capacity(_capacity == 0 ? 1 : _capacity * 2);
			(*this)[_size++] = value;
		}

		void pop_back()
		{
			_size--;
			_allocator.destroy(_start + _size);
		}

		void resize(size_type count, T value = T())
		{
			size_type temp_size = _size;
			_size = count;
			if (count > _capacity)
			{
				_capacity = count;
				pointer temp = _allocator.allocate(_capacity);
				for (size_type index = 0; index < _capacity; index++)
				{
					value_type correct_value = (index < temp_size) ? *(_start + index) : value;
					_allocator.construct(temp + index, correct_value);
				}
				_allocator.deallocate(_start, _size);
				_start = temp;
			}
			else if (temp_size < count)
			{
				while (temp_size++ < count)
					_allocator.construct(_start + temp_size, value);
			}
		}

		// IMPLEMENTAR !!!
		void swap(vector &other) {
			size_type this_capacity = capacity();
			size_type this_size = size();
			pointer this_start = data();
			allocator_type this_allocator = get_allocator();

			_capacity = other.capacity();
			_size = other.size();
			_start = other.data();
			_allocator = other.get_allocator();

			other._capacity = this_capacity;
			other._size = this_size;
			other._start = this_start;
			other._allocator = this_allocator;
		}

	private:
		allocator_type _allocator;
		pointer _start;
		size_type _size;
		size_type _capacity;

		void _reallocate_capacity(size_type newCapacity)
		{
			_capacity = newCapacity;
			pointer temp = _allocator.allocate(_capacity);
			_copy_vector(_start, temp, _size);
			_allocator.deallocate(_start, _size);
			_start = temp;
			if (_size > newCapacity)
				_size = newCapacity;
		}

		void _copy_vector(pointer startFrom, pointer StartTo, size_type n)
		{
			for (size_type index = 0; index < n; index++)
				_allocator.construct(StartTo + index, *(startFrom + index));
		}
	};
}

#endif
