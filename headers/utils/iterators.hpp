/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:48:43 by acanterg          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:44 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "iterator_traits.hpp"

namespace ft
{

  template <typename T>
  class normal_iterator
  {
  public:
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef std::random_access_iterator_tag iterator_category;

  public:
    normal_iterator(pointer ptr = NULL) { _m_current = ptr; }
    normal_iterator(const normal_iterator<T> &rawIterator) { *this = rawIterator; };
    ~normal_iterator() {}

    // const iterators
    operator normal_iterator<const value_type>() const { return (_m_current); }

    normal_iterator &operator=(const normal_iterator<T> &rawIterator)
    {
      _m_current = rawIterator._m_current;
      return (*this);
    };

    normal_iterator &operator=(T *ptr)
    {
      _m_current = ptr;
      return (*this);
    }

    operator bool() const { return (_m_current ? true : false); }

    reference operator[](size_type index) { return _m_current[index]; }

    bool operator==(const normal_iterator<T> &rawIterator) const { return (_m_current == rawIterator._m_current); }
    bool operator!=(const normal_iterator<T> &rawIterator) const { return (_m_current != rawIterator._m_current); }

    normal_iterator &operator+=(const difference_type &n)
    {
      _m_current += n;
      return (*this);
    }
    normal_iterator &operator-=(const difference_type &n)
    {
      _m_current -= n;
      return (*this);
    }
    normal_iterator &operator++()
    {
      ++_m_current;
      return (*this);
    }
    normal_iterator &operator--()
    {
      --_m_current;
      return (*this);
    }

    normal_iterator operator++(int) { return normal_iterator(_m_current++); }
    normal_iterator operator--(int) { return normal_iterator(_m_current--); }
    normal_iterator operator+(size_type n) { return normal_iterator(_m_current + n); }
    normal_iterator operator-(size_type n) { return normal_iterator(_m_current - n); }

    difference_type operator-(const normal_iterator &rawIterator) { return std::distance(rawIterator._m_current, _m_current); }

    reference operator*() { return *_m_current; }
    pointer operator->() { return _m_current; }

    const normal_iterator &base() const { return _m_current; }

  protected:
    pointer _m_current;
  };

  template <typename _Iterator>
  class reverse_iterator
  {

  protected:
    _Iterator _current;

    typedef iterator_traits<_Iterator> __traits_type;

  public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::difference_type difference_type;
    typedef typename __traits_type::pointer pointer;
    typedef typename __traits_type::reference reference;
    typedef typename std::size_t size_type;

    reverse_iterator() : _current() {}
    reverse_iterator(iterator_type rawIterator) : _current(rawIterator) {}
    reverse_iterator(const reverse_iterator &rawIterator) : _current(rawIterator.base()) {}

    template <typename _Iter>
    reverse_iterator(const reverse_iterator<_Iter> &rawIterator) : _current(rawIterator.base()) {}

    iterator_type base() const { return _current; }

    reference operator*() const
    {
      iterator_type __tmp = _current;
      return *--__tmp;
    }

    pointer operator->() const
    {
      iterator_type __tmp = _current;
      return *--__tmp;
    }

    reference operator[](difference_type n) const
    {
      return *(*this + n);
    }

    reverse_iterator &operator+=(const difference_type &n)
    {
      _current -= n;
      return (*this);
    }
    reverse_iterator &operator-=(const difference_type &n)
    {
      _current += n;
      return (*this);
    }
    reverse_iterator &operator++()
    {
      --_current;
      return (*this);
    }
    reverse_iterator &operator--()
    {
      ++_current;
      return (*this);
    }

    reverse_iterator operator++(int)
    {
      reverse_iterator __tmp = *this;
      --_current;
      return __tmp;
    }
    reverse_iterator operator--(int)
    {
      reverse_iterator __tmp = *this;
      ++_current;
      return __tmp;
    }
    reverse_iterator operator+(size_type n) { return reverse_iterator(_current - n); }
    reverse_iterator operator-(size_type n) { return reverse_iterator(_current + n); }
  };

  template <typename _Iterator>
  inline bool
  operator==(const reverse_iterator<_Iterator> &__x,
             const reverse_iterator<_Iterator> &__y)
  {
    return __x.base() == __y.base();
  }

  template <typename _Iterator>
  inline bool
  operator<(const reverse_iterator<_Iterator> &__x,
            const reverse_iterator<_Iterator> &__y)
  {
    return __y.base() < __x.base();
  }

  template <typename _Iterator>
  inline bool
  operator!=(const reverse_iterator<_Iterator> &__x,
             const reverse_iterator<_Iterator> &__y)
  {
    return !(__x == __y);
  }

  template <typename _Iterator>
  inline bool
  operator>(const reverse_iterator<_Iterator> &__x,
            const reverse_iterator<_Iterator> &__y)
  {
    return __y < __x;
  }

  template <typename _Iterator>
  inline bool
  operator<=(const reverse_iterator<_Iterator> &__x,
             const reverse_iterator<_Iterator> &__y)
  {
    return !(__y < __x);
  }

  template <typename _Iterator>
  inline bool
  operator>=(const reverse_iterator<_Iterator> &__x,
             const reverse_iterator<_Iterator> &__y)
  {
    return !(__x < __y);
  }

  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // DR 280. Comparison of reverse_iterator to const reverse_iterator.
  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator==(const reverse_iterator<_IteratorL> &__x,
             const reverse_iterator<_IteratorR> &__y)
  {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator<(const reverse_iterator<_IteratorL> &__x,
            const reverse_iterator<_IteratorR> &__y)
  {
    return __y.base() < __x.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator!=(const reverse_iterator<_IteratorL> &__x,
             const reverse_iterator<_IteratorR> &__y)
  {
    return !(__x == __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator>(const reverse_iterator<_IteratorL> &__x,
            const reverse_iterator<_IteratorR> &__y)
  {
    return __y < __x;
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator<=(const reverse_iterator<_IteratorL> &__x,
             const reverse_iterator<_IteratorR> &__y)
  {
    return !(__y < __x);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool
  operator>=(const reverse_iterator<_IteratorL> &__x,
             const reverse_iterator<_IteratorR> &__y)
  {
    return !(__x < __y);
  }
}
#endif