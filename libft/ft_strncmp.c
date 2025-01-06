/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:28:32 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 21:56:08 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	if (n <= 0)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		result = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (result);
}

// int main(void)
// {
//     char str1[] = "Hello";
//     char str2[] = "HelloWorld";
//     size_t n1 = 8;
//     int result1 = ft_strncmp(str1, str2, n1);
//     printf("%d\n", result1);
//     return (0);
// }