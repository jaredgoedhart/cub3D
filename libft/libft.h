/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:23:59 by jgoedhar          #+#    #+#             */
/*   Updated: 2024/12/22 20:28:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                             CHECK                                          */
/* ************************************************************************** */

/**
 * Checks if the character is alphanumeric.
 *
 * @param[in] c The character to check.
 * @return int 1 if character is alphanumeric, 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * Checks if the character is alphabetic.
 *
 * @param[in] c The character to check.
 * @return int 1 if character is alphabetic, 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * Checks if the character is ASCII.
 *
 * @param[in] c The character to check.
 * @return int 1 if character is ASCII (0-127), 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * Checks if the character is a digit.
 *
 * @param[in] c The character to check.
 * @return int 1 if character is a digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * Checks if the character is printable.
 *
 * @param[in] c The character to check.
 * @return int 1 if character is printable, 0 otherwise.
 */
int		ft_isprint(int c);

/* ************************************************************************** */
/*                             MEMORY                                         */
/* ************************************************************************** */

/**
 * Writes n zeroed bytes to the string s.
 *
 * @param[in] s The memory area to zero out.
 * @param[in] n Number of bytes to zero.
 */
void	ft_bzero(void *s, size_t n);

/**
 * Frees a split array (array of strings) and its contents.
 *
 * @param[in] split The array of strings to free.
 */
void	ft_free_split(char **split);

/**
 * Frees an array and its contents.
 *
 * @param[in] array The array to free.
 */
void	ft_free_array(char **array);

/**
 * Allocates memory for an array of nmemb elements of size bytes and zeroes it.
 *
 * @param[in] nmemb Number of elements.
 * @param[in] size Size of each element.
 * @return void* Pointer to allocated memory, NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * Locates first occurrence of c in string s within n bytes.
 *
 * @param[in] s String to search.
 * @param[in] c Character to find.
 * @param[in] n Number of bytes to search.
 * @return void* Pointer to matching byte or NULL if not found.
 */
void	*ft_memchr(void const *s, int c, size_t n);

/**
 * Copies n bytes from memory area src to memory area dest.
 *
 * @param[out] dest Destination memory area.
 * @param[in] src Source memory area.
 * @param[in] n Number of bytes to copy.
 * @return void* pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copies n bytes from src to dest, handling overlapping memory.
 *
 * @param[out] dest Destination memory area.
 * @param[in] src Source memory area.
 * @param[in] n Number of bytes to copy.
 * @return void* pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Fills memory with a constant byte.
 *
 * @param[out] s Memory area to fill.
 * @param[in] c Constant byte to fill with.
 * @param[in] n Number of bytes to fill.
 * @return void* pointer to memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * Compares memory areas.
 *
 * @param[in] s1 First memory area.
 * @param[in] s2 Second memory area.
 * @param[in] n Number of bytes to compare.
 * @return int <0, 0, or >0 if s1 is less than, equal to, or greater than s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* ************************************************************************** */
/*                             PRINT                                          */
/* ************************************************************************** */

/**
 * Outputs a character to given file descriptor.
 *
 * @param[in] c Character to output.
 * @param[in] fd File descriptor to write to.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Outputs string to given file descriptor, followed by newline.
 *
 * @param[in] s String to output.
 * @param[in] fd File descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * Outputs integer to given file descriptor.
 *
 * @param[in] n Integer to output.
 * @param[in] fd File descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * Outputs string to given file descriptor.
 *
 * @param[in] s String to output.
 * @param[in] fd File descriptor to write to.
 */
void	ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/*                             STRING                                         */
/* ************************************************************************** */

/**
 * Converts ASCII string to integer.
 *
 * @param[in] nptr String containing number to convert.
 * @return int Converted number.
 */
int		ft_atoi(const char *nptr);

/**
 * Converts integer to ASCII string.
 *
 * @param[in] n Integer to convert.
 * @return char* Newly allocated string containing converted number.
 */
char	*ft_itoa(int n);

/**
 * Checks if string contains only digits.
 *
 * @param[in] str String to check.
 * @return int -1 if non-digit found, 0 otherwise.
 */
int		ft_is_string_digits(const char *str);

/**
 * Splits string using character as delimiter.
 *
 * @param[in] s String to split.
 * @param[in] c Delimiter character.
 * @return char** Array of new strings from split.
 */
char	**ft_split(char const *s, char c);

/**
 * Locates first occurrence of character in string.
 *
 * @param[in] str String to search.
 * @param[in] c Character to find.
 * @return char* Pointer to first occurrence or NULL if not found.
 */
char	*ft_strchr(char const *str, int c);

/**
 * Creates new copy of string.
 *
 * @param[in] src String to duplicate.
 * @return char* New string duplicate or NULL if allocation fails.
 */
char	*ft_strdup(const char *src);

/**
 * Applies function to each character of string with its index.
 *
 * @param[in,out] s String to iterate over.
 * @param[in] f Function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * Concatenates two strings into new string.
 *
 * @param[in] s1 First string.
 * @param[in] s2 Second string.
 * @return char* New concatenated string or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Appends src to dst, ensuring NUL-termination.
 *
 * @param[out] dst Destination string.
 * @param[in] src Source string.
 * @param[in] size Size of destination buffer.
 * @return size_t Total length of string tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * Copies up to size-1 characters from src to dst.
 *
 * @param[out] dst Destination string.
 * @param[in] src Source string.
 * @param[in] n Size of destination buffer.
 * @return size_t Length of string tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

/**
 * Calculates length of string.
 *
 * @param[in] str String to measure.
 * @return size_t Length of string.
 */
size_t	ft_strlen(char const *str);

/**
 * Applies function to each character of string, creating new string.
 *
 * @param[in] s String to map.
 * @param[in] f Function to apply to each character.
 * @return char* New string created from mapping or NULL if allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Compares two strings up to n characters.
 *
 * @param[in] s1 First string.
 * @param[in] s2 Second string.
 * @param[in] n Maximum number of characters to compare.
 * @return int <0, 0, or >0 if s1 is less than, equal to, or greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Locates substring in string, limited by len.
 *
 * @param[in] big String to search in.
 * @param[in] little Substring to find.
 * @param[in] len Maximum characters to search.
 * @return char* Pointer to first match or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
* Locates first occurrence of a substring in a string.
* Similar to standard strstr() function.
*
* @param[in] str String to search in
* @param[in] to_find Substring to find
* @return Pointer to first matching substring in str,
*         NULL if not found, str if to_find is empty
*/
char	*ft_strstr(char *str, const char *to_find);

/**
 * Locates last occurrence of character in string.
 *
 * @param[in] s String to search.
 * @param[in] c Character to find.
 * @return char* Pointer to last occurrence or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * Removes specified characters from start and end of string.
 *
 * @param[in] s1 String to trim.
 * @param[in] set Characters to trim.
 * @return char* New trimmed string or NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Creates substring from string.
 *
 * @param[in] s String to create substring from.
 * @param[in] start Start index of substring.
 * @param[in] len Length of substring.
 * @return char* New substring or NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Converts uppercase letter to lowercase.
 *
 * @param[in] c Character to convert.
 * @return int Converted character or unchanged if not uppercase.
 */
int		ft_tolower(int c);

/**
 * Converts lowercase letter to uppercase.
 *
 * @param[in] c Character to convert.
 * @return int Converted character or unchanged if not lowercase.
 */
int		ft_toupper(int c);

#endif
