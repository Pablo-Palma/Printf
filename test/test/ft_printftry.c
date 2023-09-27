/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:45:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/09/27 07:26:49 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	length;
	int	written;

	if (!s)
		s = "(null)";
	length = strlen(s);
	written = write(fd, s, length);
	if (written != length)
		return (-1);
	return (written);
}

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

int	typeflag(va_list *content, const char identifier)
{
	if (identifier == 'c')
		return (ft_putchar_fd(va_arg(*content, int), 1));
	if (identifier == 's')
		return (ft_putstr_fd(va_arg(*content, char *), 1));
	else
		return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int	charcount;

	charcount = 0;
	va_start(vargs, str);
	while (*str != 0)
	{
		if (*str == '%')
		{
			if (*(++str) != '%')
				charcount += typeflag(&vargs, *str);
			else
				charcount += ft_putchar_fd(*str, 1);
		}
		else
			charcount += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(vargs);
	return (charcount);
}

int	main(void)
{
    printf("%s\n", "TEST5");
    printf("%s\n", "------------------");
    ft_printf("R: %c %c %c ", '0', 0, '1');
    printf("\n");
    printf("E: %c %c %c ", '0', 0, '1');
    return (0);
}
