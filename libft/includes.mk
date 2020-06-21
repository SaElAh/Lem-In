# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    includes.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 15:43:43 by sel-ahma          #+#    #+#              #
#    Updated: 2019/12/11 10:38:44 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT := libft.a

HEADERS_LIB = ./libft/includes/libft.h
HEADERS_LIB += ./libft/includes/ft_printf.h
HEADERS_LIB += ./libft/includes/double.h

LIBFT_SRC := arguments.c      ft_strcat.c\
binary.c         ft_strchr.c\
buffer.c         ft_strclr.c\
char.c           ft_strcmp.c\
double.c         ft_strcpy.c\
ft_atoi.c        ft_strdel.c\
ft_base.c        ft_strdup.c\
ft_bzero.c       ft_strequ.c\
ft_isalnum.c     ft_striter.c\
ft_isalpha.c     ft_striteri.c\
ft_isascii.c     ft_strjoin.c\
ft_isdigit.c     ft_strlcat.c\
ft_isprint.c     ft_strlen.c\
ft_itoa.c        ft_strmap.c\
ft_itoa_base.c   ft_strmapi.c\
ft_lowercase.c   ft_strncat.c\
ft_lstadd.c      ft_strncmp.c\
ft_lstdel.c      ft_strncpy.c\
ft_lstdelone.c   ft_strnequ.c\
ft_lstiter.c     ft_strnew.c\
ft_lstmap.c      ft_strnstr.c\
ft_lstnew.c      ft_strrchr.c\
ft_memalloc.c    ft_strrev.c\
ft_memccpy.c     ft_strsplit.c\
ft_memchr.c      ft_strsplit2.c\
ft_memcmp.c      ft_strstr.c\
ft_memcpy.c      ft_strsub.c\
ft_memdel.c      ft_strtrim.c\
ft_memmove.c     ft_tolower.c\
ft_memset.c      ft_toupper.c\
ft_nb_length.c   hexadecimal.c\
ft_printf.c      integer.c\
ft_putchar.c     octal.c\
ft_putchar_fd.c  pointers.c\
ft_putendl.c     print_double.c\
ft_putendl_fd.c  string.c\
ft_putnbr.c      transform_ldbl.c\
ft_putnbr_fd.c   unicode.c\
ft_putnbrs.c     unsigned.c\
ft_putnstr.c     utils.c\
ft_putstr.c      utils_double.c\
ft_putstr_fd.c   utils_unicode.c\
str_isascii.c	ft_strsplit_map.c\
ft_numlen.c		ft_min.c\
ft_strdel2.c\
