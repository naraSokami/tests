# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 15:47:57 by baderwae          #+#    #+#              #
#    Updated: 2025/10/23 09:55:10 by baderwae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


make
make bonus
gcc -Wall -Wextra -Werror tests/main.c -lbsd -lft -L. -o test
./test
python3 tests/test.py
