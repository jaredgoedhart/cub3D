/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:09 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:37:58 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     char str[] = "aisatsana [102]";
//     char c = '1';
//     printf ("Testing ft_strchr with '%s' and '%c'\n", str, c);
//     char *result = ft_strchr(str, c);
//     if (result)
//     {
//         printf("Character found at position: %ld\n", result - str);
//     }
//     else
//     {
//         printf("Character not found\n");
//     }
//     return (0);
// }