/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:28:22 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:17 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char char1 = '0';
// 	char char2 = '\n';
// 	char char3 = 'A';
// 	printf ("%d\n", ft_isprint(char1));
// 	printf ("%d\n", ft_isprint(char2));
// 	printf ("%d\n", ft_isprint(char3));
// 	return (0);
// }