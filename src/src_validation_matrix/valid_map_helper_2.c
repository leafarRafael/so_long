/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_helper_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:57:42 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 09:57:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_check_possible(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (-1);
}

static void	flood_fill_input(char **matrix, t_valid *v, int x, int y)
{
	if (x < 0 || x >= v->size_x -1 || y < 0 || y >= v->size_y -1
		|| matrix[y][x] == '1')
		return ;
	matrix[y][x] = '1';
	flood_fill_input(matrix, v, x +1, y);
	flood_fill_input(matrix, v, x -1, y);
	flood_fill_input(matrix, v, x, y +1);
	flood_fill_input(matrix, v, x, y -1);
}

int	ft_flood_fill(char **matrix, t_valid *v)
{
	v->y = 0;
	v->x = 0;
	ft_ask_for_me(matrix, 'P', &v->y, &v->x);
	flood_fill_input(matrix, v, v->x, v->y);
	if (ft_valid_composition(matrix, v, &ft_check_possible) <= 0)
		return (-1);
	return (1);
}

int	ft_surrounded_by_walls(char	**matrix, t_valid *v)
{
	v->y = 0;
	while (matrix[v->y])
	{
		v->x = 0;
		while (matrix[v->y][v->x])
		{
			if (v->y == 0 && matrix[v->y][v->x] != '1')
				return (-1);
			if (v->x == v->size_x -1 && matrix[v->y][v->x] != '1')
				return (-1);
			if (v->x == 0 && matrix[v->y][v->x] != '1')
				return (-1);
			if (v->y == v->size_y -1 && matrix[v->y][v->x] != '1')
				return (-1);
			v->x++;
		}
		v->y++;
	}
	return (1);
}

int	ft_valid_composition(char **matrix, t_valid *v, int (*f)(char))
{
	v->y = 0;
	while (matrix[v->y])
	{
		v->x = 0;
		while (matrix[v->y][v->x])
		{
			if (f(matrix[v->y][v->x]) != 1)
				return (-1);
			v->x++;
		}
		v->y++;
	}
	return (1);
}
