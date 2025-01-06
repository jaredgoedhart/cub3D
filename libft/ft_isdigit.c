/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:28:54 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:22 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char char1 = '0';
// 	char char2 = '9';
// 	char char3 = 'A';
// 	printf ("%d\n", ft_isalpha(char1));
// 	printf ("%d\n", ft_isalpha(char2));
// 	printf ("%d\n", ft_isalpha(char3));
// 	return 0;
// }