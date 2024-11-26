# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 00:27:54 by fclivaz           #+#    #+#              #
#    Updated: 2024/11/26 04:20:11 by fclivaz          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

SRCS	=	${SUBDIR}/char/ft_isalnum.c \
				${SUBDIR}/char/ft_isalpha.c \
				${SUBDIR}/char/ft_isascii.c \
				${SUBDIR}/char/ft_isdigit.c \
				${SUBDIR}/char/ft_isprint.c \
				${SUBDIR}/char/ft_isspace.c \
				${SUBDIR}/char/ft_tolower.c \
				${SUBDIR}/char/ft_toupper.c \
			${SUBDIR}/extras/ft_gnl.c \
				${SUBDIR}/extras/ft_printf.c \
			${SUBDIR}/lst/ft_lstadd_back.c \
				${SUBDIR}/lst/ft_lstadd_front.c \
				${SUBDIR}/lst/ft_lstclear.c \
				${SUBDIR}/lst/ft_lstdelone.c \
				${SUBDIR}/lst/ft_lstiter.c \
				${SUBDIR}/lst/ft_lstlast.c \
				${SUBDIR}/lst/ft_lstmap.c \
				${SUBDIR}/lst/ft_lstnew.c \
				${SUBDIR}/lst/ft_lstsize.c \
			${SUBDIR}/malloc/ft_arrayfree.c \
				${SUBDIR}/malloc/ft_calloc.c \
				${SUBDIR}/malloc/ft_itoa.c \
				${SUBDIR}/malloc/ft_realloc.c \
				${SUBDIR}/malloc/ft_split.c \
				${SUBDIR}/malloc/ft_strdup.c \
				${SUBDIR}/malloc/ft_strjoin.c \
				${SUBDIR}/malloc/ft_strmapi.c \
				${SUBDIR}/malloc/ft_strtrim.c \
				${SUBDIR}/malloc/ft_substr.c \
			${SUBDIR}/mem/ft_memchr.c \
				${SUBDIR}/mem/ft_memcmp.c \
				${SUBDIR}/mem/ft_memcpy.c \
				${SUBDIR}/mem/ft_memmove.c \
				${SUBDIR}/mem/ft_memset.c \
			${SUBDIR}/putfd/ft_putchar_fd.c \
				${SUBDIR}/putfd/ft_putendl_fd.c \
				${SUBDIR}/putfd/ft_putnbr_fd.c \
				${SUBDIR}/putfd/ft_putstr_fd.c \
			${SUBDIR}/str/ft_atoi.c \
				${SUBDIR}/str/ft_atoi_base.c \
				${SUBDIR}/str/ft_bzero.c \
				${SUBDIR}/str/ft_strchr.c \
				${SUBDIR}/str/ft_striteri.c \
				${SUBDIR}/str/ft_strlcat.c \
				${SUBDIR}/str/ft_strlcpy.c \
				${SUBDIR}/str/ft_strlen.c \
				${SUBDIR}/str/ft_strncmp.c \
				${SUBDIR}/str/ft_strnstr.c \
				${SUBDIR}/str/ft_strrchr.c \
				${SUBDIR}/str/ft_strtol.c

SUBDIR	=	srcs

INCL	=	./

DEPS	=	${INCL}libft.h \
			${SRCS}

OBJ		=	$(SRCS:${SUBDIR}/%.c=${OBJDIR}/%.o)

OBJDIR	=	objs

SRCTREE	=	$(shell find ${SUBDIR} -type d)

OBJTREE	=	$(SRCTREE:${SUBDIR}%=${OBJDIR}%)

NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -O2

DFLAGS	=	-g3 -fsanitize=address -fsanitize=leak

CC = cc

CRED = \033[1;31m
CGRN = \033[1;32m
CYEL = \033[1;33m
RSET = \033[0m

bonus:	${NAME}

all:	${NAME}

${NAME}:	${DEPS}
			@${MAKE} ${OBJ}
			@ar rc ${NAME} ${OBJ}
			@printf "│\t${CGRN}${NAME}${RSET} Compiled!\n"


${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				@if [[ $(if $(filter dbg,${MAKECMDGOALS}),1,0) == "1" ]]; then \
					printf "│\t > ${CYEL}DEBUG${RSET} Compiling ${CYEL}$<${RSET} with ${CYEL}${DFLAGS}${RSET}...\r"; \
					${CC} ${DFLAGS} -c $< -o $@ -I${INCL}; \
				else \
					printf "│\t > Compiling ${CYEL}$<${RSET} for ${CGRN}${NAME}${RSET}...\r"; \
					${CC} ${CFLAGS} -c $< -o $@ -I${INCL}; \
				fi
				@printf "\33[2K"

${OBJDIR}:
		@printf "│\tCreating ${CYEL}${OBJDIR}${RSET} for ${CGRN}${NAME}${RSET}\n"
		@mkdir -p ${OBJTREE}

debug:
		@rm -rf objs
		@${MAKE} ${OBJ} dbg
		@ar rc ${NAME} ${OBJ}
		@printf "│\t${CYEL}DEBUG${RSET} ${CGRN}${NAME}${RSET} compiled!\n"

clean:
		@if [ -d "./${OBJDIR}" ]; then \
			printf "│\tRemoving ${CRED}${OBJDIR}${RSET} for ${CYEL}${NAME}${RSET}\n"; \
			rm -rf ${OBJDIR}; \
		fi

fclean:	clean
		@if [ -e "./${NAME}" ]; then \
			printf "│\tRemoving ${CYEL}${NAME}${RSET}\n"; \
			rm -f ${NAME}; \
		else \
			printf "│\t${CYEL}${NAME}${RSET} already removed!\n"; \
		fi

re:
		@printf "\tCleaning and ${CGRN}recompiling${RSET}...\n"
		@${MAKE} fclean
		@${MAKE} all

export MAKEFLAGS += --silent
.PHONY: all fclean clean re
$(eval dbg:;@:)
