/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:15:12 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/07/31 16:15:12 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			sign;

	if (nptr == NULL)
		return (0);
	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		if (*nptr == '+' || *nptr == '-')
			return (0);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((unsigned int)(res * sign));
}

// int main(void) 
// {
//     char *nptr = "  +-2147483648";
//     int num = ft_atoi(nptr);
//     printf("%d\n", num);
//     return 0;
// }