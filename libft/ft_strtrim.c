/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:29:37 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 22:24:13 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_check(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_check(s1[start], set))
		start++;
	while (end > start && char_check(s1[end - 1], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}
// int main(void)
// {
//     char *s1 = "Radiohead";
//     char *set = "Radio";
//     char *trimmed;
//     trimmed = ft_strtrim(s1, set);
//     if (trimmed)
//     {
//         printf("Trimmed string: %s\n", trimmed);
//         free(trimmed);
//     }
//     else
//     {
//         printf("Error: Memory allocation failed.\n");
//     }
//     return 0;
// }