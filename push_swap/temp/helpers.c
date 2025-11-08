/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:28:06 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/10 14:28:06 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	t_stack *tmp;
	t_list *a_elem;
	t_list *b_elem;

	if (a->name == 'b')
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	a_elem = a->list;
	b_elem = b->list;

	printf("  a  |  b  \n");
	printf("-----------\n");
	while (a_elem || b_elem)
	{
		if (a_elem)
			printf("%3d  |", ft_value(a_elem));
		else
			printf("     |");
		if (b_elem)
			printf("%3d\n",  ft_value(b_elem));
		else
			printf("     \n");

		if (a_elem)
			a_elem = a_elem->next;
		if (b_elem)
			b_elem = b_elem->next;
	}
	printf("\n");
}
