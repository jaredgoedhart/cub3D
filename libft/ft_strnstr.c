/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: igoedhar <igoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/14/10 13:01:52 by igoedhar          #+#    #+#             */
/*   Updated: 2023/14/10 15:34:13 by igoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int main() {
//     const char *big = "The King of Limbs";
//     const char *little = "Limbs";
//     char *result = ft_strnstr(big, little, 42);
//     if (result) {
//         printf("Substring gevonden: %s\len", result);
//     } else {
//         printf("Substring niet gevonden.\len");
//     }
//     return 0;
// }