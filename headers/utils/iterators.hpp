/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:48:43 by acanterg          #+#    #+#             */
/*   Updated: 2022/03/29 13:12:11 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

namespace ft
{

    template <typename T>
    class normal_iterator
    {
    public:
        typedef T                                               value_type;
        typedef T*                                              pointer;
        typedef T&                                              reference;
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef std::random_access_iterator_tag                 iterator_category;
        typedef typename std::iterator<iterator_category, T>    iterator;

    public:
        normal_iterator(pointer ptr = NULL) { _m_current = ptr; }
        normal_iterator(const normal_iterator<T> &rawIterator) { *this = rawIterator; };
        ~normal_iterator() {}

        // const iterators
        operator normal_iterator<const value_type>() const{ return (_m_current); }

        normal_iterator<T> &operator=(const normal_iterator<T> &rawIterator) { _m_current = rawIterator._m_current; return (*this); };

        normal_iterator<T> &operator=(T *ptr) { _m_current = ptr; return (*this); }

        operator bool() const { return (_m_current ? true : false); }

        bool operator==(const normal_iterator<T> &rawIterator) const { return (_m_current == rawIterator._m_current); }
        bool operator!=(const normal_iterator<T> &rawIterator) const { return (_m_current != rawIterator._m_current); }

        normal_iterator<T> &operator+=(const difference_type &n) { _m_current += n; return (*this); }
        normal_iterator<T> &operator-=(const difference_type &n) { _m_current -= n; return (*this); }
        normal_iterator<T> &operator++() { ++_m_current; return (*this); }
        normal_iterator<T> &operator--() { --_m_current; return (*this); }

        normal_iterator<T> operator++(int) { return normal_iterator(_m_current++); }
        normal_iterator<T> operator--(int) { return normal_iterator(_m_current--); }
        normal_iterator<T> operator+(const difference_type &n) { return normal_iterator(_m_current + n); }
        normal_iterator<T> operator-(const difference_type &n) { return normal_iterator(_m_current - n); }

        difference_type operator-(const normal_iterator<T> &rawIterator) { return std::distance(rawIterator._m_current, _m_current); }

        reference operator*() { return *_m_current; }
        pointer operator->() { return _m_current; }

    protected:
        pointer _m_current;
    };


}

#endif