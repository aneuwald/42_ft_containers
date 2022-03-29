/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:48:43 by acanterg          #+#    #+#             */
/*   Updated: 2022/03/29 16:40:13 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{

    template <typename _Iterator>
    struct iterator_traits
    {
        typedef typename _Iterator::iterator_category iterator_category;
        typedef typename _Iterator::value_type value_type;
        typedef typename _Iterator::difference_type difference_type;
        typedef typename _Iterator::pointer pointer;
        typedef typename _Iterator::reference reference;
    };

    template <typename _Tp>
    struct iterator_traits<_Tp *>
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef _Tp value_type;
        typedef std::ptrdiff_t difference_type;
        typedef _Tp *pointer;
        typedef _Tp &reference;
    };

    template <typename _Tp>
    struct iterator_traits<const _Tp *>
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef _Tp value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const _Tp *pointer;
        typedef const _Tp &reference;
    };
}

#endif