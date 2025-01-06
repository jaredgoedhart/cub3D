/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:28:54 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:28 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char char1 = '0';
// 	char char2 = 'A';
// 	char char3 = 128;
// 	printf ("%d\n", ft_isascii(char1));
// 	printf ("%d\n", ft_isascii(char2));
// 	printf ("%d\n", ft_isascii(char3));
// 	return 0;
// }