#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "../utils/iterators.hpp"

// REFERENCE: https://en.cppreference.com/w/cpp/container/map

namespace ft
{
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T>>>
	class map
	{
	public:
		;
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;

		typedef ft::normal_iterator<value_type> iterator;
		typedef ft::normal_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/**********************************************
		 *			       CONSTRUCTORS				  *
		 **********************************************/
		map();
		explicit map(const Compare &comp, const Allocator &alloc = Allocator());

		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());

		map( const map& other ) {
			std::cout << "[MAP] copy constructor" << std::endl;
			*this = other;
		}

		/**********************************************
		 *			       DESTRUCTOR				  *
		 **********************************************/
		~stack()
		{
			std::cout << "[STACK] destructor" << std::endl;
			// nothing?
		}

		/**********************************************
		 *			  ASSIGN & GET_ALLOCATOR		  *
		 **********************************************/
		map &operator=(const map &other)
		{
			std::cout << "[STACK] copy assignment called!" << std::endl;
			(void) other;
			return (*this);
		}

		allocator_type get_allocator() const { return allocator_type(); }

		/**********************************************
		 *				 ELEMENT ACCESS				  *
		 **********************************************/
		reference top() { return (c.back()); }
		const_reference top() const { return (c.back()); }

		/**********************************************
		 *				    CAPACITY				  *
		 **********************************************/
		bool empty() const { return (c.empty()); }

		size_type size() const { return (c.size()); }

		/**********************************************
		 *				   MODIFIERS				  *
		 **********************************************/
		void push(const value_type &value) { c.push_back(value); }

		void pop() { c.pop_back(); }

	protected:
		container_type c;
	};
}

#endif
