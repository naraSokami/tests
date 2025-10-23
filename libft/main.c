/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:31:24 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/23 10:11:24 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../libft.h"

void	ft_print_content(void *content)
{
	printf("%s", (char *)content);
}

void	ft_print_lst(t_list *lst)
{
	if (!lst)
		return ;
	printf("%s", (char *)lst->content);
	while (lst)
	{
		if (lst->next)
			printf("->%s", (char *)lst->next->content);
		else
			printf("->%s", (char *)lst->next);
		lst = lst->next;
	}
}

void	ft_free_lst(t_list *lst)
{
	t_list	*prev;

	if (!lst)
		return ;
	while (lst)
	{
		prev = lst;
		lst = lst->next;
		free(prev);
	}
}

void	ft_delcontent(void *content)
{
	printf("[del](%s)", (char *)content);
}

void	ft_free_content(void *content)
{
	if (content)
		free(content);
}

void	*ft_a_suprmemacy_content(void *content)
{
	char	*new_content;
	
	if (!content)
		return (NULL);
	new_content = strdup((char *)content);
	if (!new_content)
		return (NULL);
	if (new_content[0])
		new_content[0] = 'a';
	return (new_content);
}

void 	ft_aaa_supremacy(unsigned int n, char *c)
{
	if (n < 3)
		*c = 'a';
}

void 	ft_print_first_char(unsigned int n, char *c)
{
	if (n == 0)
		printf("'%c'", *c);
}

char 	ft_aaa(unsigned int n, char c)
{
	if (n < 3)
		return ('a');
	return (c);
}

char 	ft_increment_char(unsigned int n, char c)
{
	(void)n;
	return (c + 1);
}

t_test	*ft_create_test(void *test_value, int is_range, int min, int max)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (!test)
		return (NULL);
	test->test_value = test_value;
	test->is_range = is_range;
	test->min = min;
	test->max = max;
	return (test);
}

int	ft_test_int_to_bool(int (*ft)(int), int (*f)(int))
{
	int		c;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	c = CHAR_MIN;
	while (c < CHAR_MAX && bad_count < MAX_ERRORS_PER_TEST)
	{
		if ((ft(c) == 0 && f(c) != 0) || (ft(c) != 0 && f(c) == 0))
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for %c (%d) | expected: %d, got  %d\n",
				c, c, f(c), ft(c));
			bad_count++;
		}
		c++;
	}
	if (is_ok)
	{
		printf("\033[32mpassed\n");
		return (1);
	}
	return (0);
}

int	ft_test_int_to_int(int (*ft)(int), int (*f)(int))
{
	int		c;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	c = 0;
	while (c < UCHAR_MAX && bad_count < MAX_ERRORS_PER_TEST)
	{
		if (ft(c) != f(c))
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for %c (%d) | expected: %d, got  %d\n",
				c, c, f(c), ft(c));
			bad_count++;
		}
		c++;
	}
	if (is_ok)
	{
		printf("\033[32mpassed\n");
		return (1);
	}
	return (0);
}

int	ft_test_str_to_size_t(size_t (*ft)(const char *), size_t (*f)(const char *), char **strs)
{
	int		i;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	i = 0;
	while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
	{
		if (ft(strs[i]) != f(strs[i]))
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for '%s' | expected: %ld, got  %ld\n",
				strs[i], f(strs[i]), ft(strs[i]));
			bad_count++;
		}
		i++;
	}
	if (is_ok)
	{
		printf("\033[32mpassed\n");
		return (1);
	}
	return (0);
}

void	ft_test_bzero(void (*ft)(void *, size_t))
{
	int	is_ok;
	int	bad_count;
	int	n;
	int	j;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	ft_dest[20] = "hello";

		ft(ft_dest, n);

		j = 0;
		while (j < n)
		{
			if (ft_dest[j] != 0)
			{
				if (is_ok)
				{
					printf("\033[31mfailed:\n");
					is_ok = 0;
				}
				printf("\033[33m	for 'hello' with n %d | expected: %d, got  %d\n",
					n, 0, ft_dest[j]);
				bad_count++;
			}
			j++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_memset(void *(*ft)(void *, int, size_t))
{
	int	is_ok;
	int	bad_count;
	int	n;
	int	j;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	ft_dest[20] = "hello";
		void	*ret_dest;

		ret_dest = ft(ft_dest, 'A', n);

		j = 0;
		while (j < n)
		{
			if (ft_dest[j] != 'A' || ((char *)ret_dest)[j] != 'A')
			{
				if (is_ok)
				{
					printf("\033[31mfailed:\n");
					is_ok = 0;
				}
				printf("\033[33m	for 'hello' with n %d | expected: %d, got  %d\n",
					n, 'A', ft_dest[j]);
				bad_count++;
			}
			j++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_memcpy(void *(*ft)(void *, const void *, size_t), void *(*f)(void *, const void *, size_t))
{
	int	is_ok;
	int	bad_count;
	int	n;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	src[20] = "abcdefghijklmnopqrs\0";
		char	ft_src[20] = "abcdefghijklmnopqrs\0";
		char	dest[20] = "hello";
		char	ft_dest[20] = "hello";
		void	*ret_dest;
		void	*ft_ret_dest;

		ret_dest = f(dest, src, n);
		ft_ret_dest = ft(ft_dest, ft_src, n);

		if (strcmp(src, ft_src) != 0 ||
			strncmp(dest, ft_dest, n) != 0 ||
			strncmp((char *)ret_dest, (char *)ft_ret_dest, n) != 0)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for 'hello' with n %d | expected: '%s', got  '%s'\n",
				n, (char *)ret_dest, (char *)ft_ret_dest);
			bad_count++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_memmove(void *(*ft)(void *, const void *, size_t), void *(*f)(void *, const void *, size_t))
{
	int	is_ok;
	int	bad_count;
	int	n;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	src[20] = "abcdefghijklmnopqrs\0";
		char	ft_src[20] = "abcdefghijklmnopqrs\0";
		char	dest[20] = "hello";
		char	ft_dest[20] = "hello";
		void	*ret_dest;
		void	*ft_ret_dest;

		ret_dest = f(dest, src, n);
		ft_ret_dest = ft(ft_dest, ft_src, n);

		if (strcmp(src, ft_src) != 0 ||
			strncmp(dest, ft_dest, n) != 0 ||
			strncmp((char *)ret_dest, (char *)ft_ret_dest, n) != 0)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for 'hello' with n %d | expected: '%s', got  '%s'\n",
				n, (char *)ret_dest, (char *)ft_ret_dest);
			bad_count++;
		}
		n++;
	}
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	src[20] = "abcdefghijklmnopqr\0";
		char	ft_src[20] = "abcdefghijklmnopqr\0";
		void	*ret_dest;
		void	*ft_ret_dest;

		ret_dest = f(src + 1, src, n);
		ft_ret_dest = ft(ft_src + 1, ft_src, n);

		if (strcmp(src, ft_src) != 0 ||
			strncmp((char *)ret_dest, (char *)ft_ret_dest, n) != 0)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for 'hello' with n %d | expected: '%s', got  '%s'\n",
				n, (char *)ret_dest, (char *)ft_ret_dest);
			bad_count++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_strchr(char	*(*ft)(const char *, int), char	*(*f)(const char *, int), char *chars, char **strs)
{
	int		i;
	int		j;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	i = 0;
	while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
	{
		j = 0;
		while (chars[j])
		{
			if (ft(strs[i], chars[j]) != f(strs[i], chars[j]))
			{
				if (is_ok)
				{
					printf("\033[31mfailed:\n");
					is_ok = 0;
				}
				printf("\033[33m	for '%s' | expected: '%s', got  '%s'\n",
					strs[i], f(strs[i], chars[j]), ft(strs[i], chars[j]));
				bad_count++;
			}
			j++;
		}
		i++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_str_str_size_t_to_int(int (*ft)(const char *, const char *, size_t),
	int (*f)(const char *, const char *, size_t), char **strs)
{
	size_t	n;
	int		i;
	int		j;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20  && bad_count < MAX_ERRORS_PER_TEST)
	{
		i = 0;
		while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
		{
			j = 0;
			while (strs[j] && bad_count < MAX_ERRORS_PER_TEST)
			{
				if ((ft(strs[i], strs[j], n) > 0 && f(strs[i], strs[j], n) <= 0)
					|| (ft(strs[i], strs[j], n) < 0 && f(strs[i], strs[j], n) >= 0)
					|| (ft(strs[i], strs[j], n) == 0 && f(strs[i], strs[j], n) != 0))
				{
					if (is_ok)
					{
						printf("\033[31mfailed:\n");
						is_ok = 0;
					}
					printf("\033[33m	for '%s' and '%s' with n: %ld | expected: %d, got  %d\n",
						strs[i], strs[j], n, f(strs[i], strs[j], n), ft(strs[i], strs[j], n));
					bad_count++;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_void_void_size_t_to_int(int (*ft)(const void *, const void *, size_t),
	int (*f)(const void *, const void *, size_t), char **strs)
{
	size_t	n;
	int		i;
	int		j;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20  && bad_count < MAX_ERRORS_PER_TEST)
	{
		i = 0;
		while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
		{
			j = 0;
			while (strs[j] && bad_count < MAX_ERRORS_PER_TEST)
			{
				if ((ft(strs[i], strs[j], n) > 0 && f(strs[i], strs[j], n) <= 0)
					|| (ft(strs[i], strs[j], n) < 0 && f(strs[i], strs[j], n) >= 0)
					|| (ft(strs[i], strs[j], n) == 0 && f(strs[i], strs[j], n) != 0))
				{
					if (is_ok)
					{
						printf("\033[31mfailed:\n");
						is_ok = 0;
					}
					printf("\033[33m	for '%s' and '%s' with n: %ld | expected: %d, got  %d\n",
						strs[i], strs[j], n, f(strs[i], strs[j], n), ft(strs[i], strs[j], n));
					bad_count++;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_memchr(void	*(*ft)(const void *, int, size_t), void *(*f)(const void *, int, size_t), char *chars)
{
	size_t	n;
	int		j;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	n = 0;
	while (n < 20 && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	src[20] = "abcdefghijklmnopqrs\0";
		char	ft_src[20] = "abcdefghijklmnopqrs\0";

		j = 0;
		while (chars[j] && bad_count < MAX_ERRORS_PER_TEST)
		{
			char	*ret = f(src, chars[j], n);
			char	*ft_ret = ft(ft_src, chars[j], n);
			
			if ((!ret && ft_ret) || (ret && !ft_ret)
				|| (ret && ft_ret && strcmp(ret, ft_ret) != 0))
			{
				if (is_ok)
				{
					printf("\033[31mfailed:\n");
					is_ok = 0;
				}
				printf("\033[33m	for '%s' | expected: '%s', got  '%s'\n", src, ret, ft_ret);
				bad_count++;
			}
			j++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_strnstr(char **strs)
{
	size_t	n;
	int		i;
	int		j;
	int		is_ok;
	int		bad_count;

	is_ok = 1;
	bad_count = 0;
	n = 1;
	while (n < 20  && bad_count < MAX_ERRORS_PER_TEST)
	{
		i = 0;
		while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
		{
			j = 0;
			while (strs[j] && bad_count < MAX_ERRORS_PER_TEST)
			{
				char	*ft_found = ft_strnstr(strs[i], strs[j], n);
				char	*found = strnstr(strs[i], strs[j], n);
				// check if null ?
				if ((!ft_found && found)
					|| (found && ft_found && strncmp(ft_found, found, n) != 0))
				{
					if (is_ok)
					{
						printf("\033[31mfailed:\n");
						is_ok = 0;
					}
					printf("\033[33m	for '%s' and '%s' with n: %ld | expected: '%s', got  '%s'\n",
						strs[i], strs[j], n, found, ft_found);
					bad_count++;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_atoi()
{
	char	*tests[] = {
		"",
		"    ",
		"	",
		"		    ",
		"    	1",
		"--1",
		"-1",
		"  -1",
		"-+1",
		"+1",
		"  +1",
		"  +10",
		"  -10",
		"  -42sa12",
		"  -42szaez12",
		"  -42sa12",
		"42aaa",
		"4212aa",
		"4a2s12",
		"a42s12",
		"0",
		"1",
		"10",
		"100",
		"1000",
		"9",
		"99",
		"999",
		"-10",
		"-100",
		"-1000",
		"-9",
		"-99",
		"-999",
		"2147483646",
		"2147483647",
		"-2147483647",
		"-2147483648",
		"9223372036854775807",
		"-9223372036854775808",
		"100000000000",
		"1000000000000000",
		"8000000000",
		"2147483640",
		NULL
	};

	int	is_ok;
	int	bad_count;
	int	i;

	is_ok = 1;
	bad_count = 0;
	i = 0;
	while (tests[i] && bad_count < MAX_ERRORS_PER_TEST)
	{
		int	ret = atoi(tests[i]);
		int	ft_ret = ft_atoi(tests[i]);

		if (ft_ret != ret)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for '%s' | expected: %d, got %d\n",
				tests[i], ret, ft_ret);
			bad_count++;
		}
		i++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_calloc()
{
	int	is_ok;
	int	bad_count;

	size_t	nmemb;
	size_t	size;
	size_t	i;

	is_ok = 1;
	bad_count = 0;
	nmemb = 1;
	while (nmemb < 10 && bad_count < MAX_ERRORS_PER_TEST)
	{
		size = 1;
		while (size < 10 && bad_count < MAX_ERRORS_PER_TEST)
		{
			unsigned char	*ptr;

			ptr = ft_calloc(nmemb, size);
			i = 0;
			while (ptr && i < nmemb * size)
			{
				if (ptr[i] != 0)
				{
					if (is_ok)
					{
						printf("\033[31mfailed:\n");
						is_ok = 0;
					}
					printf("\033[33m	for nmemb %ld ans size %ld | expected: 0, got %d\n",
						nmemb, size, ptr[i]);
					bad_count++;
				}
				i++;
			}
			if (ptr)
				free(ptr);
			size++;
		}
		nmemb++;
	}
	if (is_ok)
		printf("\033[32mpassed\n");
}

void	ft_test_strdup(const char **strs)
{
	int	is_ok;
	int	bad_count;
	int	i;

	is_ok = 1;
	bad_count = 0;
	i = 0;
	while (strs[i] && bad_count < MAX_ERRORS_PER_TEST)
	{
		char	*copy;
		char	*ft_copy;

		copy = strdup(strs[i]);
		ft_copy = ft_strdup(strs[i]);
		
		if (!copy || !ft_copy)
		{
			if (copy)
				free(copy);
			if (ft_copy)
				free(ft_copy);
			return ;
		}

		if (strcmp(copy, ft_copy) != 0)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for '%s' | expected: '%s', got '%s'\n",
				strs[i], copy, ft_copy);
			bad_count++;
		}

		if (strs[i][0])
		{
			copy[0] = 'A';
			ft_copy[0] = 'A';
		}
		if (strs[i][0] && strcmp(copy, ft_copy) != 0)
		{
			if (is_ok)
			{
				printf("\033[31mfailed:\n");
				is_ok = 0;
			}
			printf("\033[33m	for '%s' | expected: '%s', got '%s'\n",
				strs[i], copy, ft_copy);
			bad_count++;
		}

		free(copy);
		free(ft_copy);
		i++;
	}
	if (is_ok)
		printf("\033[32mpassed\n\033[37m");
}

void	ft_test_substr(int ac, char **av)
{
	char			*sub;
	const char		*s;
	unsigned int	start;
	size_t			len;

	if (ac < 5)
		return ;
	s = av[2];
	start = atoi(av[3]);
	len = atoi(av[4]);
	sub = ft_substr(s, start, len);
	printf("'%s', '%s'", s, sub);
	free(sub);
}

void	ft_test_strjoin(int ac, char **av)
{
	char			*joined;
	const char		*s1;
	const char		*s2;

	if (ac < 4)
		return ;
	s1 = av[2];
	if (strcmp(s1, "NULL") == 0)
		s1 = NULL;
	s2 = av[3];
	if (strcmp(s2, "NULL") == 0)
		s2 = NULL;
	joined = ft_strjoin(s1, s2);
	printf("'%s'", joined);
	free(joined);
}

void	ft_test_strtrim(int ac, char **av)
{
	char			*trimmed;
	const char		*s1;
	const char		*set;

	if (ac < 4)
		return ;
	s1 = av[2];
	if (strcmp(s1, "NULL") == 0)
		s1 = NULL;
	set = av[3];
	if (strcmp(set, "NULL") == 0)
		set = NULL;
	trimmed = ft_strtrim(s1, set);
	printf("'%s'", trimmed);
	free(trimmed);
}

void	ft_test_split(int ac, char **av)
{
	char			**strs;
	const char		*s;
	char			c;
	int				i;

	if (ac < 4)
		return ;
	s = av[2];
	if (strcmp(s, "NULL") == 0)
		s = NULL;
	c = av[3][0];
	strs = ft_split(s, c);
	if (!strs)
	{
		printf("'(null)'");
		return ;
	}
	i = 0;
	while (strs[i])
	{
		printf("'%s'", strs[i]);
		if (strs[i + 1])
			printf(" ");
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_test_itoa(int ac, char **av)
{
	char	*str;
	int		n;

	if (ac != 3)
		return ;
	n = atoi(av[2]);
	str = ft_itoa(n);
	printf("'%s'", str);
	if (str)
		free(str);
}

void	ft_test_strmapi(int ac, char **av)
{
	char 		*str;
	char const	*s;

	if (ac != 3)
		return ;
	s = av[2];
	if (strcmp(s, "NULL") == 0)
		s = NULL;
	str = ft_strmapi(s, &ft_aaa);
	printf("'%s' ", str);
	if (str)
		free(str);
	str = ft_strmapi(s, &ft_increment_char);
	printf("'%s'", str);
	if (str)
		free(str);
}

void	ft_test_striteri(int ac, char **av)
{
	char const	*s;

	if (ac != 3)
		return ;
	s = av[2];
	if (strcmp(s, "NULL") == 0)
		s = NULL;
	ft_striteri((char *)s, &ft_print_first_char);
	printf(" ");
	ft_striteri((char *)s, &ft_aaa_supremacy);
	printf("'%s'", s);
}

void	ft_test_putchar_fd(int ac, char **av)
{
	char	c;
	int		fd;

	if (ac != 4)
		return ;
	c = av[2][0];
	fd = atoi(av[3]);
	ft_putchar_fd(c, fd);
}

void	ft_test_putstr_fd(int ac, char **av)
{
	char	*s;
	int		fd;

	if (ac != 4)
		return ;
	s = av[2];
	if (strcmp(s, "NULL") == 0)
		s = NULL;
	fd = atoi(av[3]);
	ft_putstr_fd(s, fd);
}

void	ft_test_putendl_fd(int ac, char **av)
{
	char	*s;
	int		fd;

	if (ac != 4)
		return ;
	s = av[2];
	if (strcmp(s, "NULL") == 0)
		s = NULL;
	fd = atoi(av[3]);
	ft_putendl_fd(s, fd);
}

void	ft_test_putnbr_fd(int ac, char **av)
{
	int	n;
	int	fd;

	if (ac != 4)
		return ;
	n = atoi(av[2]);
	fd = atoi(av[3]);
	ft_putnbr_fd(n, fd);
}

void	ft_test_lstnew(int ac, char **av)
{
	t_list	*new;
	char	*content;

	if (ac != 3)
		return ;
	content = av[2];
	if (strcmp(content, "NULL") == 0)
		content = NULL;
	new = ft_lstnew(content);
	printf("%s->%p", (char *)new->content, new->next);
	free(new);
}

void	ft_test_lstadd_front(int ac, char **av)
{
	t_list	*lst;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_front(&lst, new);
		i++;
	}
	ft_print_lst(lst);
	ft_free_lst(lst);
}

void	ft_test_lstsize(int ac, char **av)
{
	t_list	*lst;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_front(&lst, new);
		i++;
	}
	printf("[%d]", ft_lstsize(lst));
	ft_print_lst(lst);
	ft_free_lst(lst);
}

void	ft_test_lstlast(int ac, char **av)
{
	t_list	*lst;
	t_list	*last;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_front(&lst, new);
		i++;
	}
	last = ft_lstlast(lst);
	if (last)
		printf("[%s]", (char *)last->content);
	else
		printf("[(null)]");
	ft_print_lst(lst);
	ft_free_lst(lst);
}

void	ft_test_lstadd_back(int ac, char **av)
{
	t_list	*lst;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	ft_print_lst(lst);
	ft_free_lst(lst);
}

void	ft_test_lstdelone(int ac, char **av)
{
	t_list	*new;
	char	*content;

	if (ac != 3)
		return ;
	content = av[2];
	if (strcmp(content, "NULL") == 0)
		content = NULL;
	new = ft_lstnew(content);
	ft_lstdelone(new, &ft_delcontent);
}

void	ft_test_lstclear(int ac, char **av)
{
	t_list	*lst;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	ft_print_lst(lst);
	ft_lstclear(&lst, &ft_delcontent);
	if (lst)
		printf("lst_no_null");
}

void	ft_test_lstiter(int ac, char **av)
{
	t_list	*lst;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	ft_print_lst(lst);
	printf("_");
	ft_lstiter(lst, &ft_print_content);
	ft_free_lst(lst);
}

void	ft_test_lstmap(int ac, char **av)
{
	t_list	*lst;
	t_list	*mapped;
	int		i;

	if (ac < 2)
		return ;
	lst = NULL;
	i = 2;
	while (i < ac)
	{
		t_list	*new;

		new = ft_lstnew(av[i]);
		if (!new)
		{
			ft_free_lst(lst);
			return ;
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	mapped = ft_lstmap(lst, &ft_a_suprmemacy_content, &ft_free_content);
	ft_print_lst(lst);
	printf("_");
	ft_print_lst(mapped);
	ft_free_lst(lst);
	ft_lstclear(&mapped, &ft_free_content);
}

int	main(int ac, char **av)
{
	char *basic_strs[] = {
		"",
		"A",
		"\n",
		"Apple",
        "Banana",
        "Cherry",
        "        ",
		"		",
		"   A    ",
		"	  AA	  test ",
		"	  AA	  test",
		" test ",
		"t",
		"AA	  test",
		" test",
		" test ",
		"abc",
		"aabc",
		"aabbc",
		NULL
	};

	char basic_chars[] = {
		'a',
		'b',
		'y',
		'z',
		'A',
		'B',
		'Y',
		'Z',
		'0',
		'1',
		'8',
		'9',
		' ',
        '~',
        '!',
		'\n',
		'\t',
		'\v',
		'\0'
	};

	if (ac == 1)
	{
		printf("\033[37mft_isalpha: ");
		ft_test_int_to_bool(&ft_isalpha, &isalpha);
	
		printf("\033[37mft_isdigit: ");
		ft_test_int_to_bool(&ft_isdigit, &isdigit);
	
		printf("\033[37mft_isalnum: ");
		ft_test_int_to_bool(&ft_isalnum, &isalnum);
	
		printf("\033[37mft_isprint: ");
		ft_test_int_to_bool(&ft_isprint, &isprint);
	
		printf("\033[37mft_isascii: ");
		ft_test_int_to_bool(&ft_isascii, &isascii);
	
		printf("\033[37mft_strlen: ");
		ft_test_str_to_size_t(&ft_strlen, &strlen, basic_strs);
	
		printf("\033[37mft_bzero: ");
		ft_test_bzero(&ft_bzero);
	
		printf("\033[37mft_memset: ");
		ft_test_memset(&ft_memset);
	
		printf("\033[37mft_memcpy: ");
		ft_test_memcpy(&ft_memcpy, &memcpy);
	
		printf("\033[37mft_memmove: ");
		ft_test_memmove(&ft_memmove, &memmove);
	
		// ft_strlcpy
		// ft_strlcat
	
		printf("\033[37mft_toupper: ");
		ft_test_int_to_int(&ft_toupper, &toupper);
	
		printf("\033[37mft_tolower: ");
		ft_test_int_to_int(&ft_tolower, &tolower);
	
		printf("\033[37mft_strchr: ");
		ft_test_strchr(&ft_strchr, &strchr, basic_chars, basic_strs);
	
		printf("\033[37mft_strrchr: ");
		ft_test_strchr(&ft_strrchr, &strrchr, basic_chars, basic_strs);
	
		printf("\033[37mft_strncmp: ");
		ft_test_str_str_size_t_to_int(&ft_strncmp, &strncmp, basic_strs);
	
		printf("\033[37mft_memchr: ");
		ft_test_memchr(&ft_memchr, &memchr, basic_chars);
	
		printf("\033[37mft_strncmp: ");
		ft_test_void_void_size_t_to_int(&ft_memcmp, &memcmp, basic_strs);
	
		printf("\033[37mft_strnstr: ");
		ft_test_strnstr(basic_strs);
	
		printf("\033[37mft_atoi: ");
		ft_test_atoi();
	
		printf("\033[37mft_calloc: ");
		ft_test_calloc();
	
		printf("\033[37mft_strdup: ");
		ft_test_strdup((const char **)basic_strs);
	}

	if (ac > 1)
	{
		if (strcmp(av[1], "ft_substr") == 0)
			ft_test_substr(ac, av);

		if (strcmp(av[1], "ft_strjoin") == 0)
			ft_test_strjoin(ac, av);

		if (strcmp(av[1], "ft_strtrim") == 0)
			ft_test_strtrim(ac, av);

		if (strcmp(av[1], "ft_split") == 0)
			ft_test_split(ac, av);

		if (strcmp(av[1], "ft_itoa") == 0)
			ft_test_itoa(ac, av);

		if (strcmp(av[1], "ft_strmapi") == 0)
			ft_test_strmapi(ac, av);

		if (strcmp(av[1], "ft_striteri") == 0)
			ft_test_striteri(ac, av);

		if (strcmp(av[1], "ft_putchar_fd") == 0)
			ft_test_putchar_fd(ac, av);

		if (strcmp(av[1], "ft_putstr_fd") == 0)
			ft_test_putstr_fd(ac, av);

		if (strcmp(av[1], "ft_putendl_fd") == 0)
			ft_test_putendl_fd(ac, av);

		if (strcmp(av[1], "ft_putnbr_fd") == 0)
			ft_test_putnbr_fd(ac, av);

		if (strcmp(av[1], "ft_lstnew") == 0)
			ft_test_lstnew(ac, av);

		if (strcmp(av[1], "ft_lstadd_front") == 0)
			ft_test_lstadd_front(ac, av);

		if (strcmp(av[1], "ft_lstsize") == 0)
			ft_test_lstsize(ac, av);
		
		if (strcmp(av[1], "ft_lstlast") == 0)
			ft_test_lstlast(ac, av);

		if (strcmp(av[1], "ft_lstadd_back") == 0)
			ft_test_lstadd_back(ac, av);

		if (strcmp(av[1], "ft_lstdelone") == 0)
			ft_test_lstdelone(ac, av);

		if (strcmp(av[1], "ft_lstclear") == 0)
			ft_test_lstclear(ac, av);

		if (strcmp(av[1], "ft_lstiter") == 0)
			ft_test_lstiter(ac, av);

		if (strcmp(av[1], "ft_lstmap") == 0)
			ft_test_lstmap(ac, av);
	}
}
