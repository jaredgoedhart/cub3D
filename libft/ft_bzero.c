/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:52 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/10/08 15:34:13 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char b[] = "Syro";
// 	ft_bzero(b, 2);
// 	printf("%s\n", b);
// 	return (0);
// }