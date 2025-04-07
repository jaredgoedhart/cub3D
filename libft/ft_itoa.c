/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:13:19 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/10/26 12:13:19 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(long n)
{
	int	count;

	count = 0;
	while (n > 9 && n >= 0)
	{
		n = n / 10;
		count++;
	}
	if (n <= 9)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = (long)n;
	count = counter(num);
	if (n < 0)
	{
		num = -(long)n;
		count = counter(num) + 1;
	}
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (num > 0)
	{
		str[count-- - 1] = '0' + (num % 10);
		num /= 10;
	}
	if (n < 0)
		str[count - 1] = '-';
	return (str);
}

// int main(void)
// {
// 	// int a = -68374;
// 	int a = 0;
// 	// int a = -2147483648;
// 	char *ptr = ft_itoa(a);
// 	if(ptr)
// 		printf("%s\n", ptr);
// 	free(ptr);
// 	return(0);
// }