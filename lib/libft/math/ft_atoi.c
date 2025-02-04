/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:05:36 by pdavi-al          #+#    #+#             */
/*   Updated: 2024/02/26 22:40:22 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	verify_overflow(int number, int digit, int multiplyer);

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		number;
	int		multiplyer;

	i = 0;
	number = 0;
	multiplyer = 1;
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '\0')
		return (number);
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			multiplyer *= -1;
	while (ft_isdigit(nptr[i]))
		number = (number * 10) + (multiplyer * (nptr[i++] - '0'));
	return (number);
}

int	ft_safe_atoi(const char *nptr, bool *has_err)
{
	size_t	i;
	int		number;
	int		multiplyer;

	i = 0;
	number = 0;
	multiplyer = 1;
	*has_err = false;
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '\0')
	{
		*has_err = true;
		return (number);
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			multiplyer *= -1;
	while (ft_isdigit(nptr[i]))
	{
		*has_err = verify_overflow(number, (nptr[i] - '0'), multiplyer);
		number = (number * 10) + (multiplyer * (nptr[i++] - '0'));
	}
	*has_err = (nptr[i] != '\0');
	return (number);
}

static bool	verify_overflow(int number, int digit, int multiplyer)
{
	if (multiplyer == 1 && number > (INT_MAX - digit) / 10)
		return (true);
	else if (number < (INT_MIN + digit) / 10)
		return (true);
	return (false);
}
