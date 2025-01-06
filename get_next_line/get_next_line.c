/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:00 by jgoedhar          #+#    #+#             */
/*   Updated: 2024/01/05 14:38:34 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
	{
		dealloc(list, clean_node, buf);
		return (-1);
	}
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
	return (0);
}

char	*get_line1(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

static int	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return (-1);
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
		{
			free(buf);
			dealloc(list, NULL, NULL);
			return ;
		}
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read || char_read < 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		if (append(list, buf) == -1)
		{
			dealloc(list, NULL, NULL);
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &next_line, 0) < 0)
	{
		dealloc(&list, NULL, NULL);
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line1(list);
	if (polish_list(&list) == -1)
		return (NULL);
	return (next_line);
}

// int main(void)
// {
//  int fd = open("test.txt", O_RDONLY);
//  if (fd < 0) 
//  {
//      perror("Error opening file");
//      return (1);
//  }
//  char *next_line = get_next_line(fd);
//  while (next_line)
//  {
//    printf("%s\n", next_line);
//    free(next_line);
//    next_line = get_next_line(fd);
//  }
//  close(fd);
//  return 0;
// }
