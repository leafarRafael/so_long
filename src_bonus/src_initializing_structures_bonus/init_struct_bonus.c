/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:27:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/07 16:59:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_main	*ft_init_main(void)
{
	static t_main	init;

	return (&init);
}

t_valid	*ft_init_valid(void)
{
	static t_valid	valid;

	return (&valid);
}

t_itens	*ft_init_itens(void)
{
	static t_itens	itens;

	return (&itens);
}

t_map	*ft_init_mlx(void)
{
	static t_map	s_mlx;

	return (&s_mlx);
}

t_player	*ft_init_player(void)
{
	static t_player	hero;

	return (&hero);
}
