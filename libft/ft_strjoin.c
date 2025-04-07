/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:19:54 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/04 14:42:10 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*concatenated_str;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * total_len + 1);
	if (!result)
		return (NULL);
	concatenated_str = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (concatenated_str);
}

// int main() {
// 	const char *str1 = "Skepta";
// 	const char *str2 = "- Can't Play Myself (A Tribute To Amy)";
// 	char *result = ft_strjoin(str1, str2);
// 	if (result) {
// 		printf("Concatenated String: %s\n", result);
// 		free(result); // Remember to free the allocated memory
// 	} else {
// 		printf("Memory allocation failed.\n");
// 	}
// 	return 0;
// }