# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 09:50:29 by amassias          #+#    #+#              #
#    Updated: 2023/11/23 02:05:36 by amassias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
#                                                                              #
# Global variables                                                             #
#                                                                              #
# ############################################################################ #

SRC_DIR			:=	sources
INC_DIR			:=	includes

TARGET			:=	libftfull.a

CC				:=	cc

# ############################################################################ #
#                                                                              #
# Libft sources                                                                #
#                                                                              #
# ############################################################################ #

FLAG__INCLUDES	:=							\
	-I$(INC_DIR)/libft
FILES_SROUCES	:=							\
	libft/ft_abs							\
	libft/ft_atof							\
	libft/ft_atoi							\
	libft/ft_bzero							\
	libft/ft_calloc							\
	libft/ft_isalnum						\
	libft/ft_isalpha						\
	libft/ft_isascii						\
	libft/ft_isdigit						\
	libft/ft_isprint						\
	libft/ft_isspace						\
	libft/ft_itoa							\
	libft/ft_lstadd_back					\
	libft/ft_lstadd_front					\
	libft/ft_lstclear						\
	libft/ft_lstdelone						\
	libft/ft_lstiter						\
	libft/ft_lstlast						\
	libft/ft_lstmap							\
	libft/ft_lstnew							\
	libft/ft_lstsize						\
	libft/ft_max							\
	libft/ft_memchr							\
	libft/ft_memcmp							\
	libft/ft_memcpy							\
	libft/ft_memmove						\
	libft/ft_memset							\
	libft/ft_memswap						\
	libft/ft_min							\
	libft/ft_putchar_fd						\
	libft/ft_putendl_fd						\
	libft/ft_putnbr_fd						\
	libft/ft_putstr_fd						\
	libft/ft_qsort							\
	libft/ft_split							\
	libft/ft_strchr							\
	libft/ft_strcpy							\
	libft/ft_strdup							\
	libft/ft_striteri						\
	libft/ft_strjoin						\
	libft/ft_strlcat						\
	libft/ft_strlcpy						\
	libft/ft_strlen							\
	libft/ft_strmapi						\
	libft/ft_strncmp						\
	libft/ft_strnstr						\
	libft/ft_strrchr						\
	libft/ft_strtrim						\
	libft/ft_substr							\
	libft/ft_tolower						\
	libft/ft_toupper

# ############################################################################ #
#                                                                              #
# Printf sources                                                               #
#                                                                              #
# ############################################################################ #

FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\
	-I$(INC_DIR)/ft_printf
FILES_SROUCES	:=	$(FILES_SROUCES)		\
	ft_printf/flags/align_sign				\
	ft_printf/flags/force_sign				\
	ft_printf/flags/left_justify			\
	ft_printf/flags/precision				\
	ft_printf/flags/prefix					\
	ft_printf/flags/zero_padding			\
	ft_printf/ft_printf						\
	ft_printf/ft_vprintf					\
	ft_printf/printers/integer_printer		\
	ft_printf/printers/string_printer		\
	ft_printf/specifiers/char				\
	ft_printf/specifiers/decimal			\
	ft_printf/specifiers/hex_lo				\
	ft_printf/specifiers/hex_up				\
	ft_printf/specifiers/integer			\
	ft_printf/specifiers/pointer			\
	ft_printf/specifiers/string				\
	ft_printf/specifiers/unsigned			\
	ft_printf/utils

# ############################################################################ #
#                                                                              #
# Printf sources                                                               #
#                                                                              #
# ############################################################################ #

FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\
	-I$(INC_DIR)/get_next_line
FILES_SROUCES	:=	$(FILES_SROUCES)		\
	get_next_line/get_next_line				\
	get_next_line/get_next_line_utils

# ############################################################################ #
#                                                                              #
# Object generation                                                            #
#                                                                              #
# ############################################################################ #

OBJS	=	$(addprefix $(SRC_DIR)/,$(addsuffix .o,$(FILES_SROUCES)))

# ############################################################################ #
#                                                                              #
# Phony rules                                                                  #
#                                                                              #
# ############################################################################ #

.PHONY: all clean fclean re norminette

all: $(TARGET)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

norminette:
	@norminette | grep -Ev "^Error: WRONG_SCOPE_COMMENT|OK\!$$|Error\!$$" \
		&& exit 1 \
		|| exit 0

# ############################################################################ #
#                                                                              #
# Binary / Library generation                                                  #
#                                                                              #
# ############################################################################ #

$(TARGET): $(OBJS)
	ar -rcs $@ $^
	cp includes/libft/libft.h .

%.o: %.c
	$(CC) -g -c $< -o $@ $(DEFINES) $(FLAG__INCLUDES)