/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:26:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/07 17:00:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_valid_matrix(t_main	*var, t_valid	*v)
{
	v->size_x = ft_strlen(var->v_matrix[v->y]);
	v->size_y = ft_size_y(var->v_matrix);
	if (ft_valid_itens(var, v, var->v_matrix) != 1)
		ft_error("Error 25! check the composition of .ber", var, 2);
	if (ft_valid_composition(var->v_matrix, v, &ft_is_composition) <= 0)
		ft_error("Error 26! Check the composition of the .ber file", var, 2);
	if (ft_valid_regular_line(var->v_matrix, v) <= 0)
		ft_error("Error 27! The map must contain regular lines", var, 2);
	if (ft_surrounded_by_walls(var->v_matrix, v) <= 0)
		ft_error("Error 28! check the composition of .ber.", var, 2);
	if (ft_flood_fill(var->v_matrix, v) <= 0)
		ft_error("Error 29! The map cannot be completed", var, 2);
}
