/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:47:20 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 17:37:19 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		sign(int value)
{
	if (value > 0)
		return (1);
	else if (value < 0)
		return (-1);
	else
		return (0);
}

int		swap_axis(double *dx, double *dy)
{
	double	temp;

	temp = *dx;
	*dx = *dy;
	*dy = temp;
	return (1);
}

t_line	*populate_line(t_point *point, t_line *data, int dir)
{
	data->x1 = point->x;
	data->y1 = point->y;
	if (dir)
	{
		data->x2 = point->nextd->x;
		data->y2 = point->nextd->y;
	}
	else
	{
		data->x2 = point->nextr->x;
       		data->y2 = point->nextr->y;
	}
	data->dx = fabs(data->x2 - data->x1);
	data->dy = fabs(data->y2 - data->y1);
	data->sx = sign(data->x2 - data->x1);
	data->sy = sign(data->y2 - data->y1);
	data->swap = 0;
	return (data);
}

void	bres_r(void *mlx, void *win, t_point *temp, int color)
{
	double	e;
	int		i;
	t_line	*data;

	FAIL_NEXT(temp->nextr);
	if (temp->nextr->width < temp->width)
		return ;
	data = (t_line*)malloc(sizeof(t_line));
	populate_line(temp, data, 0);
	i = -1;
	if (data->dy > data->dx)
		data->swap = swap_axis(&data->dx, &data->dy);
	e = 2 * data->dy - data->dx;
	while (++i < data->dx)
	{
		mlx_pixel_put(mlx, win, data->x1, data->y1, color);
		while (e >= 0)
		{
			e = e - 2 * data->dx;
			data->swap ? (data->x1 += data->sx) : (data->y1 += data->sy);
		}
		e = e + 2 * data->dy;
		data->swap ? (data->y1 += data->sy) : (data->x1 += data->sx);
	}
	free(data);
}

void	bres_d(void *mlx, void *win, t_point *temp, int color)
{
	double	e;
	int		i;
	t_line	*data;

	if (!temp->nextd)
		return ;
	data = (t_line*)malloc(sizeof(t_line));
	populate_line(temp, data, 1);
	i = -1;
	if (data->dy > data->dx)
		data->swap = swap_axis(&data->dx, &data->dy);
	e = 2 * data->dy - data->dx;
	while (++i < data->dx)
	{
		mlx_pixel_put(mlx, win, data->x1, data->y1, color);
		while (e >= 0)
		{
			e = e - 2 * data->dx;
			data->swap ? (data->x1 += data->sx) : (data->y1 += data->sy);
		}
		e = e + 2 * data->dy;
		data->swap ? (data->y1 += data->sy) : (data->x1 += data->sx);
	}
	free(data);
}
