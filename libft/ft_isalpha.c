/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:28:54 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:38 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char char1 = 'T';
// 	char char2 = 'm';
// 	char char3 = '9';
// 	printf ("%d\n", ft_isalpha(char1));
// 	printf ("%d\n", ft_isalpha(char2));
// 	printf ("%d\n", ft_isalpha(char3));
// 	return 0;
// }