/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_fix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:13:04 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/06 19:01:59 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	substring_amount(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			s++;
		if (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] != c)
			s++;
	}
	return (i);
}

static char	**ft_free(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
	return (NULL);
}

static char	**ft_spliting_part(const char *s, char c, char **res)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (ft_free(res, j));
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = ft_calloc(substring_amount(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_spliting_part(s, c, res));
}

// int main() {
//     char **test_split;
//     char str[] = "Aphex Twin";
//     char delimiter = ' ';

//     test_split = ft_split(str, delimiter);

//     int i = 0;
//     while (test_split[i]) {
//         printf("%s\n", test_split[i]);
//         i++;
//     }
//     ft_free(test_split, i);

//     return 0;
// }