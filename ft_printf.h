/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:59:24 by pabpalma          #+#    #+#             */
/*   Updated: 2023/09/23 19:02:15 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(char const *str, ...);

#endif
