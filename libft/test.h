/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:33:06 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/23 09:55:36 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define MAX_ERRORS_PER_TEST 5

# include <stdio.h>
# include <string.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_test
{
	void	*test_value;
	int		is_range;
	int		min;
	int		max;
}	t_test;

#endif
