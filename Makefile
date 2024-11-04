SUBDIR	= srcs

OBJDIR	= objs

SRCS	=	${SUBDIR}/ft_atoi.c\
			${SUBDIR}/ft_bzero.c\
			${SUBDIR}/ft_calloc.c\
			${SUBDIR}/ft_gnl.c\
			${SUBDIR}/ft_isalnum.c\
			${SUBDIR}/ft_isalpha.c\
			${SUBDIR}/ft_isascii.c\
			${SUBDIR}/ft_isdigit.c\
			${SUBDIR}/ft_isprint.c\
			${SUBDIR}/ft_itoa.c\
			${SUBDIR}/ft_lstadd_back.c\
			${SUBDIR}/ft_lstadd_front.c\
			${SUBDIR}/ft_lstclear.c\
			${SUBDIR}/ft_lstdelone.c\
			${SUBDIR}/ft_lstiter.c\
			${SUBDIR}/ft_lstlast.c\
			${SUBDIR}/ft_lstmap.c\
			${SUBDIR}/ft_lstnew.c\
			${SUBDIR}/ft_lstsize.c\
			${SUBDIR}/ft_memchr.c\
			${SUBDIR}/ft_memcmp.c\
			${SUBDIR}/ft_memcpy.c\
			${SUBDIR}/ft_memmove.c\
			${SUBDIR}/ft_memset.c\
			${SUBDIR}/ft_printf.c\
			${SUBDIR}/ft_putchar_fd.c\
			${SUBDIR}/ft_putendl_fd.c\
			${SUBDIR}/ft_putnbr_fd.c\
			${SUBDIR}/ft_putstr_fd.c\
			${SUBDIR}/ft_split.c\
			${SUBDIR}/ft_strchr.c\
			${SUBDIR}/ft_strdup.c\
			${SUBDIR}/ft_striteri.c\
			${SUBDIR}/ft_strjoin.c\
			${SUBDIR}/ft_strlcat.c\
			${SUBDIR}/ft_strlcpy.c\
			${SUBDIR}/ft_strlen.c\
			${SUBDIR}/ft_strmapi.c\
			${SUBDIR}/ft_strncmp.c\
			${SUBDIR}/ft_strnstr.c\
			${SUBDIR}/ft_strrchr.c\
			${SUBDIR}/ft_strtrim.c\
			${SUBDIR}/ft_substr.c\
			${SUBDIR}/ft_tolower.c\
			${SUBDIR}/ft_toupper.c\

OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra -O2

CC = cc

CRED = \033[1;31m
CGRN = \033[1;32m
CYEL = \033[1;33m
RSET = \033[0m

${NAME}:	${OBJ}
			@ar rc ${NAME} ${OBJ}
			@printf "│\t${CGRN}${NAME}${RSET} Compiled!\n"


${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				@printf "│\t > Compiling ${CYEL}$<${RSET} for ${CGRN}${NAME}${RSET}...\r"
				@${CC} ${CFLAGS} -c $< -o $@
				@printf "\33[2K"

${OBJDIR}:
		@printf "│\tCreating ${CYEL}${OBJDIR}${RSET} for ${CGRN}${NAME}${RSET}\n"
		@mkdir -p $@

all:	${NAME}

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


.PHONY: all fclean clean re
