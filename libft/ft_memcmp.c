/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:44:35 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:37:20 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	i = 0;
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str1[] = "abc";
// 	char str2[] = "def";
// 	int result = ft_memcmp(str1, str2, 3);
// 	if (result < 0)
// 		printf("str1 is less than str2\n");
// 	else if (result > 0)
// 		printf("str1 is greater than str2\n");
// 	else
// 		printf("str1 is equal to str2\n");
// 	return 0;
// }