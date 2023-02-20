/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:18:09 by ngobert           #+#    #+#             */
/*   Updated: 2023/02/20 12:49:12 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

namespace ft {

//! LEXICOGRAPHICAL COMPARE : #################################################
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


//! PAIR ######################################################################
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

	template <typename T, typename U>
	pair<T, U> make_pair(T first, U second) {
		return (pair<T, U>(first, second));
	}

		template <typename T, typename U>
	bool	operator==(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T, typename U>
	bool	operator!=(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (!(lhs == rhs));
	}

	template <typename T, typename U>
	bool	operator<(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <typename T, typename U>
	bool	operator<=(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (!(rhs < lhs));
	}

	template <typename T, typename U>
	bool	operator>(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (rhs < lhs);
	}

	template <typename T, typename U>
	bool	operator>=(pair<T, U> const &lhs, pair<T, U> const &rhs) {
		return (!(lhs < rhs));
	}

//! ITERATOR_TRAITS ###########################################################


template<class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;
	};

	template<typename T>
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag	iterator_category;

	};

	template<typename T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T const*							pointer;
		typedef T const&							reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};


};

#endif