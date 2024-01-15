/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/15 08:58:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_my_hooks(mlx_key_data_t keyd, void *param)
{
	t_main	*var;

	var = (t_main *) param;
	if (keyd.key == MLX_KEY_ESCAPE)
	{
		ft_printf("You chose well to give up ahahah (evil laugh)!");
		ft_delete_all_image(var);
	}
	if (keyd.key == MLX_KEY_W)
		ft_move_hero(var, -1, 0, PNG_HERO_UP);
	if (keyd.key == MLX_KEY_A)
		ft_move_hero(var, 0, -1, PNG_HERO_LEFT);
	if (keyd.key == MLX_KEY_D)
		ft_move_hero(var, 0, +1, PNG_HERO_RIGTH);
	if (keyd.key == MLX_KEY_S)
		ft_move_hero(var, +1, 0, PNG_HERO_DOWN);
}
