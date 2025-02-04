/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:31:47 by educastro         #+#    #+#             */
/*   Updated: 2025/01/29 20:49:04 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*valid_args(int argc, char **argv)
{
	size_t	filename_size;
	size_t	extension_size;

	if (argc != 2)
		err_exit(ERR_INVALID_ARG_NUM);
	filename_size = ft_strlen(argv[1]);
	extension_size = ft_strlen(FILE_EXTENSION);
	if (filename_size < extension_size)
		err_exit(ERR_INVALID_FILE_NAME);
	while (extension_size--)
	{
		if (argv[1][--filename_size] != FILE_EXTENSION[extension_size])
			err_exit(ERR_INVALID_FILE_NAME);
	}
	return (argv[1]);
}