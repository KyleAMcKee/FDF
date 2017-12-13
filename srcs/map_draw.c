/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:07:56 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 12:12:05 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_color(t_point *start)
{
	t_point *temp;

	temp = start;
	while (temp != NULL)
	{
		if (temp->color != 0)
			return (1);
		temp = temp->nextr;
	}
	return (0);
}

void	draw_right(void *mlx, void *win, t_point *curr, t_color *color)
{
	t_point *t;

	t = curr;
	if (t->nextr != NULL && t->depth != 0 &&
		(t->depth == t->nextr->depth))
		bres_r(mlx, win, t, color->color1);
	else if (t->nextr != NULL && t->depth < t->nextr->depth)
		bres_r(mlx, win, t, color->color2);
	else if (t->nextr != NULL && t->depth > t->nextr->depth)
		bres_r(mlx, win, t, color->color2);
	else
		bres_r(mlx, win, t, color->color3);
}

void	draw_down(void *mlx, void *win, t_point *curr, t_color *color)
{
	t_point *t;

	t = curr;
	if (t->nextd != NULL && t->depth != 0 &&
		(t->depth == t->nextd->depth))
		bres_d(mlx, win, t, color->color1);
	else if (t->nextd != NULL && t->depth < t->nextd->depth)
		bres_d(mlx, win, t, color->color2);
	else if (t->nextd != NULL && t->depth > t->nextd->depth)
		bres_d(mlx, win, t, color->color2);
	else
		bres_d(mlx, win, t, color->color3);
}

void	map_draw(void *mlx, void *win, t_point *start, t_color *color)
{
	t_point	*t;
	int		set_color;

	mlx_clear_window(mlx, win);
	t = start;
	set_color = check_color(t);
	while (t != NULL)
	{
		if (set_color == 1)
		{
			if (t->color == 0)
				t->color = 0xFFFFFF;
			bres_d(mlx, win, t, t->color);
			bres_r(mlx, win, t, t->color);
		}
		else
		{
			draw_right(mlx, win, t, color);
			draw_down(mlx, win, t, color);
		}
		t = t->nextr;
	}
}
