/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:10:58 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 12:44:32 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_screen(t_view *view, char *argv)
{
	display_usage();
	view = determine_size(view, view->start);
	view->win = MLX(view->mlx, view->size_x, view->size_y, argv);
	scale(view->start, view->scale, view->scale, view->scale / 2);
	move(view->start, view->center_x, view->center_y);
	rotate_x(view, 30);
	rotate_y(view, 30);
	map_draw(view->mlx, view->win, view->start, view->color);
	mlx_hook(view->win, 2, 0, key_press, view);
	mlx_loop(view->mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_point *start;
	t_view	*view;
	t_color *color;

	start = (t_point*)malloc(sizeof(t_point));
	view = (t_view*)malloc(sizeof(t_view));
	color = (t_color*)malloc(sizeof(t_color));
	view->mlx = mlx_init();
	view->start = start;
	fd = open(argv[1], O_RDONLY);
	if (!error_handle(fd, argv[1], argv[2], argc))
		return (0);
	if (argc >= 2 && argc < 4)
	{
		set_color(argv[2], color);
		view->color = color;
		map(view->start, fd, argv[1]);
		display_screen(view, argv[1]);
	}
	return (0);
}
