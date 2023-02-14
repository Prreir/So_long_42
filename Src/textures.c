/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:10:42 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 18:10:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    renderimg(t_data *data)
{
    int     i;
    int     j;

    i = -1;
    while (++i < data->alt)
    {
        j = -1;
        while (++j < data->comp)
        {
            if (data->lines[i][j] == '1')
                mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->textures.wall, WSIZE * j, WSIZE * i);
            else if (data->lines[i][j] == '0')
                mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->textures.empty, WSIZE * j, WSIZE * i);
            else if (data->lines[i][j] == 'C')
                mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->textures.collec, WSIZE * j, WSIZE * i);
            else if (data->lines[i][j] == 'E')
                mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->textures.exit, WSIZE * j, WSIZE * i);
            else if (data->lines[i][j] == 'P')
                mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->textures.player, WSIZE * j, WSIZE * i);
        }
    }
}

void    putimg(t_data *data)
{
    int     imgsize;

    imgsize = WSIZE;
    data->textures.wall = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./Textures/Wall.xpm", &imgsize, &imgsize);
    data->textures.empty = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./Textures/Empty.xpm", &imgsize, &imgsize);
    data->textures.collec = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./Textures/Colect.xpm", &imgsize, &imgsize);
    data->textures.exit = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./Textures/Exit.xpm", &imgsize, &imgsize);
    data->textures.player = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "./Textures/Player.xpm", &imgsize, &imgsize);
    if (!data->textures.wall || !data->textures.empty || !data->textures.collec || !data->textures.exit || !data->textures.player)
        error_msg("Missing images", data);
    renderimg(data);
}

