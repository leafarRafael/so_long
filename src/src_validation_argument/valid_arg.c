/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:47:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/15 10:57:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_valid_argv(char *argv)
{
	char	*ber;
	int		i;
	int		size;
	int		size_ber;

	ber = ".ber";
	size_ber = 3;
	size = ft_strlen(argv) -1;
	i = 0;
	while (i < 4)
	{
		if (argv[size] != ber[size_ber])
			return (-1);
		size_ber--;
		size--;
		i++;
	}
	return (1);
}

static int	ft_check_the_spaces(t_main	*var, char *file_ber)
{
	var->i = 0;
	var->n = 0;
	var->fd = open(file_ber, O_RDONLY);
	if (var->fd < 0)
		ft_error("Error 18! Invalid fd\n", var, 1);
	var->read_buffer = 1;
	while (var->read_buffer > 0)
	{
		var->read_buffer = read(var->fd, &var->buffer, 1);
		if (var->i == 0 && var->buffer == '\n')
			ft_error("Error 19! Check the spaces in the .ber file.\n", var, 1);
		if (var->read_buffer == 0 && var->buffer == '\n')
			ft_error("Error 20! Check the spaces in the .ber file.\n", var, 1);
		if (var->buffer == '\n')
			var->n++;
		else
			var->n = 0;
		if (var->n > 1)
			ft_error("Error 21! Check the spaces in the .ber file.\n", var, 1);
		var->i++;
	}
	close(var->fd);
	return (var->i);
}

char	*ft_validate_parameter(t_main *var, int argc, char *argv[])
{
	if (argc <= 1)
		ft_error("Error 22! You ve passed few arguments\n", NULL, 1);
	if (argc > 2)
		ft_error("Error 23! You ve passed manyarguments\n", NULL, 1);
	if (ft_valid_argv(argv[1]) == -1)
		ft_error("Error 24! Waiting for file extension .ber\n", NULL, 1);
	if (ft_check_the_spaces(var, argv[1]) < 15)
		ft_error("Error 21!  Check the file type..\n", var, 1);
	return (argv[1]);
}
