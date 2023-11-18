# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 09:50:29 by amassias          #+#    #+#              #
#    Updated: 2023/11/18 16:23:05 by amassias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:=	sources
INC_DIR			:=	includes

FLAG__INCLUDES	:=							\
	-I$(INC_DIR)/libft
FILES_SROUCES	:=							\
	libft/ft_abs							\
	libft/ft_atoi							\
	libft/ft_bzero							\
	libft/ft_calloc							\
	libft/ft_isalnum						\
	libft/ft_isalpha						\
	libft/ft_isascii						\
	libft/ft_isdigit						\
	libft/ft_isprint						\
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
	libft/ft_toupper						\

DEFINES			:=	

ifdef USE_FTPRINTF
FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\
	-I$(INC_DIR)/ft_printf
FILES_SROUCES	:=	$(FILES_SROUCES)		\
	ft_printf/ft_printf						\
	ft_printf/ft_vprintf					\
	ft_printf/utils							\
	ft_printf/flags/align_sign				\
	ft_printf/flags/force_sign				\
	ft_printf/flags/prefix					\
	ft_printf/flags/left_justify			\
	ft_printf/flags/precision				\
	ft_printf/flags/zero_padding			\
	ft_printf/printers/number				\
	ft_printf/printers/hex					\
	ft_printf/printers/string				\
	ft_printf/specifiers/char				\
	ft_printf/specifiers/string				\
	ft_printf/specifiers/pointer			\
	ft_printf/specifiers/decimal			\
	ft_printf/specifiers/integer			\
	ft_printf/specifiers/unsigned			\
	ft_printf/specifiers/hex_lo				\
	ft_printf/specifiers/hex_up
DEFINES			:=	$(DEFINES)				\
	-DUSE_LIB__FT_PRINTF
endif

ifdef USE_GNL
FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\

FILES_SROUCES	:=	$(FILES_SROUCES)		\

DEFINES			:=	$(DEFINES)				\
	-DUSE_LIB__GET_NEXT_LINE
endif

OBJS	=	$(addprefix $(SRC_DIR)/,$(addsuffix .o,$(FILES_SROUCES)))

TARGET	:=	libftfull.a

CC		:=	cc

.PHONY: all clean fclean re

all: $(TARGET)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

$(TARGET): $(OBJS)
	ar -rcs $@ $^
	cp includes/libft/libft.h .

%.o: %.c
	$(CC) -c $< -o $@ $(DEFINES) $(FLAG__INCLUDES)