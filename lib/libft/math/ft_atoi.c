/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:05:36 by pdavi-al          #+#    #+#             */
/*   Updated: 2025/02/26 19:46:39 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_overflow(int number, int digit, int multiplyer);

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

int	ft_safe_atoi(const char *nptr, int *has_err)
{
	size_t	i;
	int		number;
	int		multiplyer;

	i = 0;
	number = 0;
	multiplyer = 1;
	*has_err = FALSE;
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '\0')
	{
		*has_err = TRUE;
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

static int	verify_overflow(int number, int digit, int multiplyer)
{
	if (multiplyer == 1 && number > (INT_MAX - digit) / 10)
		return (TRUE);
	else if (number < (INT_MIN + digit) / 10)
		return (TRUE);
	return (FALSE);
}
