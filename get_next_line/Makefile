BUFFER_SIZE := 10
FLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
# FLAGS := -Wall -Wextra -Werror

SRCS := get_next_line.c \
		get_next_line_utils.c \
		main.c

SRCS_BONUS :=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				main.c

OBJS := $(SRCS:%.c=%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

test: $(OBJS)
	cc $(FLAGS) $(OBJS) -o test

bonus: $(OBJS_BONUS)
	cc $(FLAGS) $(OBJS_BONUS) -o bonus

#$(OBJS): %.o: %.c
#	gcc $(FLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf test

re: fclean test
