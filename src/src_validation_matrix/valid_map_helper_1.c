/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_helper_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:11:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/19 18:14:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_is_composition(char c)
{
	return (c == '1' || c == '0' || c == 'P'
		|| c == 'C' || c == 'E');
}

int	ft_size_y(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	ft_valid_regular_line(char	**matrix, t_valid *v)
{
	v->y = 0;
	v->x = 0;
	v->size_x = ft_strlen(matrix[v->y]);
	while (matrix[v->y])
	{
		v->x = ft_strlen(matrix[v->y]);
		if (v->size_x != v->x)
			return (-1);
		v->y++;
	}
	return (v->size_x);
}

int	ft_valid_itens(t_main *var, t_valid *v, char **matrix)
{
	var->it->collect = 0;
	var->it->exit = 0;
	var->it->hero = 0;
	v->y = 0;
	while (matrix[++v->y])
	{
		v->x = 0;
		while (matrix[v->y][++v->x])
		{
			if (matrix[v->y][v->x] == 'C')
				var->it->collect++;
			if (matrix[v->y][v->x] == 'E')
				var->it->exit++;
			if (matrix[v->y][v->x] == 'P')
				var->it->hero++;
		}
	}
	ft_printf("P = %d | C = %d | E = %d\n", var->it->hero, var->it->collect, var->it->exit);
	if ((var->it->hero < 1 || var->it->hero > 1)
		|| (var->it->exit < 1 || var->it->exit > 1) || var->it->collect < 1)
		return (-1);
	return (1);
}
