/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:18:09 by ngobert           #+#    #+#             */
/*   Updated: 2023/02/16 13:12:09 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

namespace ft {

//! LEXICOGRAPHICAL COMPARE :
template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (*first1 < *first2)
            return true;
        if (*first2 < *first1)
            return false;
    }
 
    return (first1 == last1) && (first2 != last2);
}

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2, Compare comp)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (comp(*first1, *first2))
            return true;
        if (comp(*first2, *first1))
            return false;
    }
 
    return (first1 == last1) && (first2 != last2);
}


//! PAIR
template<class T1, class T2> struct pair {
        typedef T1    first_type;
        typedef T2    second_type;

        T1    first;
        T2    second;

        pair() : first(), second() {}
        pair(const first_type& x, const second_type& y) : first(x), second(y) {}

        template<class U, class V>
        pair(const pair<U, V>& p) : first(p.first), second(p.second) {}

        virtual ~pair() {}

        pair& operator=(const pair& ref) {
            first = ref.first;
            second = ref.second;
            return (*this);
        }
    };
template<class _T1, class _T2>
  inline pair<typename __decay_and_strip<_T1>::__type,
      typename __decay_and_strip<_T2>::__type>
  make_pair(_T1&& __x, _T2&& __y)
  {
    return pair<typename __decay_and_strip<_T1>::__type,
            typename __decay_and_strip<_T2>::__type>
  (std::forward<_T1>(__x), std::forward<_T2>(__y));
  }


};

#endif