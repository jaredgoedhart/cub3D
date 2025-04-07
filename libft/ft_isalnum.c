/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:28:54 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:45 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char char1 = '0';
// 	char char2 = '&';
// 	char char3 = 'A';
// 	printf ("%d\n", ft_isalnum(char1));
// 	printf ("%d\n", ft_isalnum(char2));
// 	printf ("%d\n", ft_isalnum(char3));
// 	return 0;
// }