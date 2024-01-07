/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_to_matrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:20:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/07 16:59:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_size_ber(t_main	*var, int argc, char *argv[])
{
	var->archive_ber = ft_validate_parameter(var, argc, argv);
	var->fd = open(var->archive_ber, O_RDONLY);
	if (var->fd < 0)
		ft_error("Error 1! Invalid fd", var, 1);
	var->read_buffer = 1;
	var->size = 0;
	while (var->read_buffer > 0)
	{
		var->read_buffer = read(var->fd, &var->buffer, 1);
		var->size++;
	}
	close(var->fd);
}

void	ft_cpy_arrey_ber(t_main *var, int argc, char **argv)
{
	ft_size_ber(var, argc, argv);
	var->fd = open(var->archive_ber, O_RDONLY);
	if (var->fd < 0)
		ft_error("Error 2! Invalid fd", var, 1);
	var->temp = ft_calloc(sizeof(char), (var->size +1));
	if (!var->temp)
		ft_error("Error 3! Invalid fd", var, 1);
	read(var->fd, var->temp, (var->size +1));
	close(var->fd);
}

void	ft_ber_cpy_to_matrix(t_main *var, int argc, char **argv)
{
	ft_cpy_arrey_ber(var, argc, argv);
	var->matrix = ft_split(var->temp, '\n');
	var->v_matrix = ft_split(var->temp, '\n');
	if (!var->v_matrix && !var->matrix)
		ft_error("Error 4! Memory allocation", var, 1);
	free(var->temp);
}

void	ft_matrix_free(char	**matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
