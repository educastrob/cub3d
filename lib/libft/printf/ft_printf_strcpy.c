/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:51:47 by vscode            #+#    #+#             */
/*   Updated: 2023/07/23 15:56:13 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

void	ft_printf_strcpy(char *dest, char *source, int len)
{
	while (len--)
		dest[len] = source[len];
}
