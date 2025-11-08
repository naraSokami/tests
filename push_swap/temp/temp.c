/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:40:04 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 10:40:04 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quicksort(t_stack *from, t_stack *to, int size)
{
	t_list	*pivot;
	int		i;

	// opti possible < 4
	if (size < 3)
		ft_little_sort(from, size);
	if ((from->name == 'a' && ft_is_lstsorted(from->list, size))
		|| (from->name == 'b' && ft_is_lstreverse_sorted(from->list, size)))
	{
		return ;
	}

	// push elems lesser than pivot until pivot on top
	pivot = ft_lstfind_pivot(from, size);

	i = 0;
	ft_print_stacks(from, to);
	int	lesser_size = ft_get_lesser_size(ft_value(pivot), from, size); // add size as param
	int rc = 0;
	if ((from->name == 'a' && !ft_is_sorted(from->list, size)) || from->name == 'b' || 1)
	{
		while (i < lesser_size)
		{
			if (from->name == 'a' && ft_value(pivot) > ft_value(from->list))
				ft_push(to, from);
			else if (from->name == 'b' && ft_value(pivot) < ft_value(from->list))
				ft_push(to, from);
			else
			{
				rc++; // opti possible
				ft_reverse_rotate(from);
			}
			i++;
		}
		if (ft_lstsize(from->list) == (size + 1) / 2)
		{
			for (int i = 0; i < size - lesser_size; i++)
				ft_reverse_rotate(from);
		}
		else
		{
			for (int i = 0; i < rc; i++)
				ft_rotate(from);
		}

		if ((size + 1) / 2 > 2)
			ft_quicksort(from, to, (size + 1) / 2);
		else
			ft_little_sort(from, (size + 1) / 2);

		if (size / 2 > 2)
			ft_quicksort(to, from, size / 2);
		else
			ft_little_sort(to, size / 2);
	}
	
	// printf("after split\n");

	// check if sorted
	// a_size = (size + 1) / 2
	// b_size = size / 2

	// divide 18
	// 18  9  9  9  9  9  9  9
	//     9  5  5  5  3s 5s 9s
	//        4  2s 4s 2s 4s
	//           2s    4s

	// call rec for left
	// call rec for right
	// npush
	// binary tree ??

	// int	from_size = (size + 1) / 2;
	// int	to_size = size / 2;

	printf("after split\n");
	ft_print_stacks(from, to);

	ft_npush(from, to, size / 2);

	printf("after push back\n");
	ft_print_stacks(from, to);

	// if (size / 2 > 2)
	// 	ft_quicksort(to, from, size / 2);
	// else
	// 	ft_little_sort(to, size / 2);

	// ft_npush(from, to, size / 2);

	// ft_print_stacks(from, to);

	
	// printf("a %d\n", ft_is_lstsorted(a->list, (size + 1) / 2));
	// printf("b %d\n", ft_is_lstreverse_sorted(b->list, size / 2));
}

void	_ft_little_sort(t_stack *stack, int size)
{
	int	top_index;

	if (size < 2 || !stack || !stack->list || !stack->list->next)
		return ;
	if ((ft_value(stack->list) > ft_value(stack->list->next)
		&& stack->name == 'a' && !ft_is_lstsorted(stack->list, size))
		|| (ft_value(stack->list) < ft_value(stack->list->next)
		&& stack->name == 'b'&& !ft_is_lstreverse_sorted(stack->list, size)))
		ft_swap(stack);
	if (stack->name == 'a')
		top_index = ft_lstfind_min_index(stack->list, size);
	else
		top_index = ft_lstfind_max_index(stack->list, size);

	printf("%c %d\n", stack->name, top_index);
	if (top_index == -1)
		return ;
	ft_lstput_on_top(top_index, stack, size);
}

int	ft_is_lstsorted(t_list	*list, int size)
{
	int	min_jumped;
	int	min;
	int	i;

	if (!list || !list->next)
		return (1);
	min_jumped = 0;
	min = ft_value(list);
	i = 1;
	while (list->next && i < size)
	{
		if (ft_value(list) != ft_value(list->next) - 1)
		{
			if (min > ft_value(list->next) && !min_jumped)
				min_jumped = 1;
			else
				return (0);
		}
		list = list->next;
		i++;
	}
	return (1);
}

int	ft_is_lstreverse_sorted(t_list	*list, int size)
{
	int	max_jumped;
	int	max;
	int	i;

	if (!list || !list->next)
		return (1);
	max_jumped = 0;
	max = ft_value(list);
	i = 1;
	while (list->next && i < size)
	{
		if (ft_value(list) != ft_value(list->next) + 1)
		{
			if (max < ft_value(list->next) && !max_jumped)
				max_jumped = 1;
			else
				return (0);
		}
		list = list->next;
		i++;
	}
	return (1);
}

int	ft_lstfind_min_index(t_list *list, int size)
{
	t_list	*min;
	int		min_index;
	int		i;

	if (!list)
		return (-1);
	min = list;
	min_index = 0;
	i = 0;
	while (i < size && list)
	{
		if (ft_value(list) < ft_value(min))
		{
			min = list;
			min_index = i;
		}
		list = list->next;
		i++;
	}
	return (min_index);
}

int	ft_lstfind_max_index(t_list *list, int size)
{
	t_list	*max;
	int		max_index;
	int		i;

	if (!list)
		return (-1);
	max = list;
	max_index = 0;
	i = 0;
	while (i < size && list)
	{
		printf("max value: %d\n", ft_value(list));
		if (ft_value(list) > ft_value(max))
		{
			max = list;
			max_index = i;
		}
		list = list->next;
		i++;
	}
	printf("max: %d %d\n", max_index, size);
	return (max_index);
}

int	ft_lstfind_index(int value, t_list *list, int size)
{
	int	i;

	i = 0;
	while (i < size && list)
	{
		if (*(int *)(list->content) == value)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

void	ft_print_content(void *n)
{
	printf("%d\n", *((int *)n));
}

int	ft_n(int n, int size)
{
	if (n > size - 1)
		return (n - size);
	if (n < 0)
		return (n + size);
	return (n);
}
