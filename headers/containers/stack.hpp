#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

#include "./vector.hpp"

// REFERENCE: https://en.cppreference.com/w/cpp/container/stack

namespace ft
{
	template <typename T, typename Container = ft::vector<T> >
	class stack
	{

	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

		/**********************************************
		 *			       CONSTRUCTORS				  *
		 **********************************************/

		explicit stack(const Container &cont = Container()) : c(cont) {
			std::cout << "[STACK] constructor" << std::endl;
		}

		stack(const stack &other)
		{
			std::cout << "[STACK] copy constructor" << std::endl;
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
		 *			 		ASSIGN					  *
		 **********************************************/
		stack &operator=(const stack &other)
		{
			std::cout << "[STACK] copy assignment called!" << std::endl;
			c = other.c;
			return (*this);
		}

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
		void push( const value_type& value ) { c.push_back(value); }
		
		void pop() { c.pop_back(); }

	
	protected:
		container_type c;
	};
}

#endif
