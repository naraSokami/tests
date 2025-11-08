int	ft_calculate_change_force(int index, int value, t_list *list, int size)
{
	int	positive;
	int	negative;
	int	diff;
	int	i;

	positive = 0;
	negative = 0;
	i = 0;
	while (list)
	{
		diff = ft_n(value + i - index, size) - *(int *)(list->content);
		if (diff > size / 2)
			diff -= size;
		else if (diff < -size / 2)
			diff += size;
		if (diff > 0 || (size % 2 == 0 && ft_abs(diff) == size / 2))
			positive++;
		if (diff < 0 || (size % 2 == 0 && ft_abs(diff) == size / 2))
			negative++;
		list = list->next;
		i++;
	}
	if (negative > positive)
		return (-negative);
	return (positive);
}

int	ft_cost(int index, int size)
{
	if (index > size / 2)
		return (ft_abs(index - size));
	return (index);
}

int	ft_get_priority(int index, int value, t_list *list, int size)
{
	int	priority;
	int	force;
	int	cost;

	force = ft_calculate_change_force(index, value, list, size);
	cost = ft_cost(index, size);
	if (force < 0)
	{
		priority = force + cost;
		if (priority > 0)
			return (0);
	}
	else
	{
		priority = force - cost;
		if (priority < 0)
			return (0);
	}
	return (priority);
}

void	ft_get_cheapest(t_cheapest *cheapest, t_list *list, int size)
{
	t_list	*elem;
	int		priority;
	int		i;

	elem = list;
	cheapest->index = INT_MAX;
	cheapest->priority = 0;
	i = 0;
	while (elem)
	{
		priority = ft_get_priority(i, *(int *)(elem->content), list, size);
		if (ft_abs(priority) > ft_abs(cheapest->priority))
		{
			cheapest->priority = priority;
			cheapest->index = i;
		}
		elem = elem->next;
		i++;
	}
}

int	ft_lst_find_index(int n, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (*(int *)(list->content) == n)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

void	ft_move_by_cost(t_list **a_list, t_list **b_list)
{
	t_cheapest cheapest;
	int size = ft_lstsize(*a_list);
	ft_get_cheapest(&cheapest, *a_list, size);
	while (cheapest.index != INT_MAX)
	{
		ft_put_on_top(ft_abs(cheapest.index), a_list, size, 'a');

		int second_priority = ft_get_priority(1, *(int *)((*a_list)->content), *a_list, size);
		if (cheapest.priority > 0 && second_priority < 0)
		{
			ft_swap(a_list, 'a');
		}
		else
		{
			ft_push(b_list, a_list, 'b');
			if (cheapest.priority < 0)
				ft_rotate(a_list, 'a');
			else
				ft_reverse_rotate(a_list, 'a');
			ft_push(a_list, b_list, 'a');
		}
		
		ft_get_cheapest(&cheapest, *a_list, size);

		// printf("priority: %d\n", cheapest.priority);
		// printf("index: %d\n", cheapest.index);
		// ft_print_stacks(a_list,  b_list);
	}

	int zero_index = ft_lst_find_index(0, *a_list);
	ft_put_on_top(zero_index, a_list, size, 'a');
}