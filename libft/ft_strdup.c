/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:10:09 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 15:35:56 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (*s)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}

// int	main(int ac, char **av)
// {
// 	char *myfunction;
// 	char *clib_function;
// 	if (ac == 2)
// 	{
// 		myfunction = ft_strdup(av[1]);
// 		clib_function = strdup(av[1]);
// 		printf("myft = :%s: and clibft is :%s:\n", myfunction, clib_function);
// 	}
// 	return (0);
// }