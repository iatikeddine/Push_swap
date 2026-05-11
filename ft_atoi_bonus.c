/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:14:41 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/10 09:21:42 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *s, int *err)
{
	int		i;
	int		sign;
	long	result;

	*err = 0;
	i = 0;
	result = 0;
	sign = 1;
	if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && - result < -2147483648))
			*err = 1;
		i++;
	}
	return ((int)(sign * result));
}
