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
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::normal_iterator<value_type> iterator;
		typedef ft::normal_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/**********************************************
		*			       CONSTRUCTORS				  *
		**********************************************/
		explicit vector()
		{
			std::cout << "explicit () constructor" << std::endl;
			_allocator = allocator_type();
			_size = 0;
			_capacity = _size;
			_start = _allocator.allocate(_size);
		}

		explicit vector(const allocator_type& alloc)
		{
			std::cout << "explicit () constructor" << std::endl;
			_allocator = alloc;
			_size = 0;
			_capacity = _size;
			_start = _allocator.allocate(_size);
		}

		explicit vector(size_type count,
						const value_type& val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			std::cout << "explicit (count, val) constructor" << std::endl;
			_size = count;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_start + i, val);
		}

		template <typename InputIt> // , typename std::__is_integer<InputIterator>::__type _Integral >
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type())
		{
			std::cout << "template (first, last) constructor" << std::endl;
			_size = last - first;
			_capacity = _size;
			_allocator = alloc;
			_start = _allocator.allocate(_size);

			for (size_type index = 0; index < _size; index++)
				_allocator.construct(_start + index, *(first + index));
		}

		vector(const vector &other) {*this = other;}

		/**********************************************
		*			       DESTRUCTOR				  *
		**********************************************/
		~vector()
		{
			std::cout << "destructor" << std::endl;
			_allocator.deallocate(_start, _size);
		}

		/**********************************************
		*			 ASSIGN & GET ALLOCATOR			  *
		**********************************************/
		vector& operator=(const vector& other) {
			std::cout << "copy assignment called!" << std::endl;
			if (this == &other)
				return *this;

			_size = other.size();
			_capacity = other.capacity();
			_allocator = other.get_allocator();
			_start = _allocator.allocate(_size);
			_copy_vector(other._start, _start, _size);

			return *this;
		}
		
		//IMPLEMENTAR !!!
		void assign( size_type count, const T& value );

		//IMPLEMENTAR
		template< class InputIt >
		void assign( InputIt first, InputIt last );

		allocator_type get_allocator() const { return allocator_type(); }

		/**********************************************
		*				 ELEMENT ACCESS				  *
		**********************************************/
		reference at(size_type n) { return (*this)[n]; }
		const_reference at(size_type n) const { return (*this)[n]; }


		reference operator[] (size_type pos) { return _start[pos]; }
		const_reference operator[] (size_type pos) const { return _start[pos]; }

		reference front() { return (*begin()); }
		const_reference front() const { return (*begin()); }

		reference back() { return *(--end()); }
		const_reference back() const { return *(--end()); }

		T* data() { return &(front()); }
		const T* data() const { return &(front()); }

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

		//IMPLEMENTAR !!!
		iterator insert(iterator pos, const T& value);

		//IMPLEMENTAR !!!
		void insert(iterator pos, size_type count, const T& value);

		//IMPLEMENTAR !!!
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last );

		//IMPLEMENTAR !!!
		iterator erase( iterator pos ) {
			size_type index = pos - begin();

			if (index >= _size)
				return pos;
			_size--;
			while (index < _size)
			{
				_allocator.destroy(_start + index);
				_allocator.construct(_start + index, *(_start + index + 1));
				index++;
			}
			return (_start + index);		
		}

		//IMPLEMENTAR !!!
		iterator erase( iterator first, iterator last );

		void push_back(const T& value)
		{
			if (_size == _capacity)
				_reallocate_capacity(_capacity * 2);
			(*this)[_size++] = value;
		}

		void pop_back()
		{
			_size--;
			_allocator.destroy(_start + _size);
		}

		//IMPLEMENTAR !!!
		void resize(size_type count);

		//IMPLEMENTAR !!!
		void resize(size_type count, T value = T());

		//IMPLEMENTAR !!!
		void swap( vector& other );

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
			// for (size_type index = 0; index < _size; index++)
			// 	_allocator.construct(temp + index, *(_start + index));
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
