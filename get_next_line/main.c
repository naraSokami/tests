/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:04:42 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/28 12:39:39 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

void	ft_read_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}

void	ft_read_line(char *file_name, int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s -> '%s'\n", file_name, line);
	free(line);
}

int	main(int ac, char **av)
{
	int		a_fd;
	int		b_fd;
	int		c_fd;

	(void)ac;
	(void)av;

	printf("BUFER_SIZE: %d;\n", BUFFER_SIZE);

	a_fd = open("a", O_RDONLY);
	if (a_fd == -1)
		return (-1);
	b_fd = open("b", O_RDONLY);
	if (b_fd == -1)
		return (-1);
	c_fd = open("c", O_RDONLY);
	if (c_fd == -1)
		return (-1);

	ft_read_line("a", 100);

	ft_read_line("a", a_fd);
	write(1, "testing...\n", 11);
	ft_read_line("b", b_fd);
	ft_read_line("c", c_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("a", a_fd);
	ft_read_line("c", c_fd);
	ft_read_line("b", b_fd);
	ft_read_line("c", c_fd);
	ft_read_line("b", b_fd);
	ft_read_line("c", c_fd);
	ft_read_line("c", c_fd);
	ft_read_line("b", b_fd);
	ft_read_line("b", b_fd);
	ft_read_line("b", b_fd);

	char *line;
	line = get_next_line(0);
	free(line);
	line = get_next_line(0);
	free(line);

	// ft_read_lines(fd);
	// ft_read_lines(0);
	close(a_fd);
	close(b_fd);
	close(c_fd);
}
