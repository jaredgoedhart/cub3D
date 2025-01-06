/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:14:57 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:39:03 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			last_occurrence = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}

// int main() {
//     const char *str = "minipops 67";
//     int search_char = 's';
//     char *result = ft_strrchr(str, search_char);
//     if (result != NULL) {
//         printf("Last seen '%c' at %ld\n", search_char, result - str);
//     } else {
//         printf("'%c' is not found \n", search_char);
//     }
//     return 0;
// }