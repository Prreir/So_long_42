/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:58:50 by marvin            #+#    #+#             */
/*   Updated: 2023/02/10 10:58:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checkargs(int argc, char **argv, t_data *data)
{
	size_t	i;

	if (argc != 2)
		error_msg("Invalid number of arguments", data);
	else
	{
		i = ft_strlen(argv[1]) - 4;
		if (ft_strncmp(".ber", &argv[1][i], 4) != 0)
			error_msg("File is not .ber", data);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	iniciar(&data);
	checkargs(argc, argv, &data);
	getsize(&data, argv[1]);
	savemap(&data, argv[1]);
	checkmap(&data);
	init(&data);
	putimg(&data);
	mlx_hook(data.mlx.win_ptr, 2, (1L << 0), keypress, &data);
	mlx_hook(data.mlx.win_ptr, 17, (1L << 2), closex, &data);
	mlx_loop(data.mlx.mlx_ptr);
	freemap(&data);
	return (0);
}
