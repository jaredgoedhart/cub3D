/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/14/10 13:01:52 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/14/10 15:34:13 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

// int main() {
//    char source[] = "Space Heavy by King Krule";
//    char destination[42]; //dest needs enough storage
//    ft_memcpy(destination, source, 10); //copy 10 bytes to src
//    destination[10] = '\0'; //null-terminate the destination string
//    printf("Inhoud van destination: %s\n", destination);
//    return 0;
// }