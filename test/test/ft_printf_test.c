/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:45:56 by pabpalma          #+#    #+#             */
/*   Updated: 2023/09/26 14:26:09 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	typeflag(va_list *content, const char identifier)
{
	if (identifier == 'c')
		return (ft_putchar_fd(va_arg(*content, int), 1));
	else if (identifier == 's')
		return (ft_putstr_fd(va_arg(*content, char *), 1));
	else if (identifier == 'p')
		return (ft_putptr_fd(va_arg(*content, void *), 1));
	else if (identifier == 'd' || identifier == 'i')
		return (ft_putnbr_fd(va_arg(*content, int), 1));
	else if (identifier == 'u')
		return (ft_putunsigned_fd(va_arg(*content, unsigned int), 1));
	else if (identifier == 'x')
		return (ft_puthexlo_fd(va_arg(*content, unsigned long), 1));
	else if (identifier == 'X')
		return (ft_puthexup_fd(va_arg(*content, unsigned long), 1));
	else
		return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		charcount;

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
/*
int	main(void)
{
//	int	nb;
//	void *ptr;

//	nb = 166;
//	ptr = &nb;
//	ft_printf("Imprimir un caracter con %%c: %c\n", 'P');
//	ft_printf(" %c %c %c ", '0', 1, '1');
//	ft_printf("\n");
//	printf(" %c %c %c ", '0', 1, '1');
//	ft_printf("Imprimir una cadena con %%s: %s\n", "Pablo");
//	ft_printf("Imprimir la dirección de memoria de un puntero %%p: %p\n", ptr);
//	printf("Dirección de memoria de nb: %p\n", (void *)&nb);
//	ft_printf("Imprimir un entero base 10 con %%d: %d\n", 11);
//	ft_printf("Imprimir un entero base 10 con %%i: %d\n", 11);
//	ft_printf("Imprimir un entero sin signo en base 10 con %%u: %u\n", 11);
//	ft_printf("Imprimir un entero sin signo en base 10 con %%u: %u\n", -11);
//	printf("%d\n", ft_printf("%u\n", -10));
//	printf("%u\n", -10);
//	printf("%d\n", ft_printf("%u", 0));
//	printf("--------------------\n");
//	printf("%d\n", ft_printf("%u\n", -42));
//	printf("--------------------\n");
//	printf("%u\n", -42);
//	printf("%s\n", "TEST 29");
//	printf("--------------------\n");
//	printf("%d\n", ft_printf("%u", INT_MAX));
//	printf("--------------------\n");
//	ft_printf("maximo int: %u\n", INT_MAX);
//	printf("--------------------\n");
//	printf("maximo int esperado: %u\n", INT_MAX);
//	printf("--------------------\n");
//	ft_printf("minimo int: %u\n", INT_MIN);
//	printf("--------------------\n");
//	printf("minimo int esperado: %u\n", INT_MIN);
//	printf("--------------------\n");
//	printf("--------------------\n");
//	ft_printf("máximo ulong: %u\n", ULONG_MAX);
//	printf("--------------------\n");
//	printf("máximo long esperado: %u\n", LONG_MAX);
//	printf("--------------------\n");
//	printf("--------------------\n");
//	ft_printf("minimo long: %u\n", LONG_MIN);
//	printf("--------------------\n");
//	printf("minimo long esperado: %u\n", LONG_MIN);
//	printf("--------------------\n");

//	printf("%s\n", "TEST5");
//	printf("%s\n", "------------------");
//	ft_printf("Mi resultado: %c %c %c ", '0', 0, '1');
//	printf("\n");
//	printf("El esperado:  %c %c %c ", '0', 0, '1');


	printf("%s\n", "TEST7");
	printf("%s\n", "------------------");
	ft_printf("Mi resultado: %c %c %c ", '1', '2', '3');
	printf("\n");
	printf("El esperado:  %c %c %c ", '1', '2', '3');
//	ft_printf("%x\n", 255);
//	printf("%x\n", 255);
//	ft_printf("%X\n", 255);
//	printf("%X\n", 255);

	return (0);
}*/
