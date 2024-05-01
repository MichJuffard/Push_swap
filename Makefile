NAME		= push_swap
BONUS_NAME	= checker

SRCS		= \
			push_swap.c \
			create_stack.c \
			instruct.c \
			check_arg.c \
			clean_exit.c \
			final_index.c \
			check_order.c \
			ft_sort.c \
			found_biger.c \
			len_list.c \
			instruct_double.c

SRCS_BON	= \
			check_arg.c \
			clean_exit.c \
			create_stack.c \
			checker_bonus.c \
			instruct_bonus.c \
			check_order.c \
			len_list.c \
			final_index.c \
			double_instruct_bonus.c

OBJS		= $(SRCS:%.c=$(PATH_COMP)%.o)
OBJS_BON	= $(SRCS_BON:%.c=$(PATH_COMP)%.o)
DEPS		= $(OBJS:%.o=%.d) \
			$(OBJS_BON:%.o=%.d)
PATH_COMP	= ./.build/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MP -MMD
RM			= rm -rf
LIB			= libft/libft.a
LIB_PATH	= $(dir $(LIB))

all: $(NAME) $(BONUS_NAME)

$(NAME): $(OBJS) $(LIB) 
	$(CC) $(CFLAGS) -I $(LIB_PATH) -o $(NAME) $(OBJS) -l ft -L $(LIB_PATH)

$(LIB): FORCE
	$(MAKE) -C libft

$(PATH_COMP)%.o:%.c
	mkdir -p $(PATH_COMP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(LIB_PATH) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(PATH_COMP)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(MAKE) -C libft fclean


re: fclean all

bonus: $(BONUS_NAME)
 
$(BONUS_NAME): $(OBJS_BON) $(LIB)
	$(CC) $(CFLAGS) -I $(LIB_PATH) -o $(BONUS_NAME) $(OBJS_BON) -l ft -L $(LIB_PATH)

print% :
	@echo $($(patsubst print%,%,$@))

FORCE:

.PHONY: all clean fclean re bonus print FORCE 