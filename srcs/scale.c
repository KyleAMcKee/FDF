/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:49:26 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 16:35:33 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale(t_point *s, double xscale, double yscale, double zscale)
{
	t_point	*temp;
	double	*mid;

	temp = s;
	mid = scale_move(temp);
	move(temp, -mid[0], -mid[1]);
	while (temp != NULL)
	{
		temp->x = temp->x * xscale;
		temp->y = temp->y * yscale;
		temp->z = temp->z * zscale;
		temp = temp->nextr;
	}
	temp = s;
	move(temp, mid[0], mid[1]);
	free(mid);
}

void	move(t_point *start, double xmove, double ymove)
{
	t_point *temp;

	temp = start;
	while (temp != NULL)
	{
		temp->x = temp->x + xmove;
		temp->y = temp->y + ymove;
		temp = temp->nextr;
	}
}

void	rotate_x(t_view *view, double angle)
{
	t_point	*temp;
	double	y;
	double	z;
	double	*mid;
	double	a[2];

	temp = view->start;
	mid = to_origin(temp);
	move(temp, -mid[0], -mid[1]);
	angle = angle * (M_PI / 180);
	a[0] = cos(angle);
	a[1] = sin(angle);
	while (temp != NULL)
	{
		y = temp->y;
		z = temp->z;
		temp->y = (y * a[0]) + (z * -a[1]);
		temp->z = (y * a[1]) + (z * a[0]);
		temp = temp->nextr;
	}
	temp = view->start;
	move(temp, mid[0], mid[1]);
	free(mid);
}

void	rotate_y(t_view *view, double angle)
{
	t_point	*temp;
	double	x;
	double	z;
	double	*mid;
	double	a[2];

	temp = view->start;
	mid = to_origin(temp);
	move(temp, -mid[0], -mid[1]);
	angle = angle * (M_PI / 180);
	a[0] = cos(angle);
	a[1] = sin(angle);
	while (temp != NULL)
	{
		x = temp->x;
		z = temp->z;
		temp->x = (x * a[0]) + (z * a[1]);
		temp->z = (x * -a[1]) + (z * a[0]);
		temp = temp->nextr;
	}
	temp = view->start;
	move(temp, mid[0], mid[1]);
	free(mid);
}

void	rotate_z(t_point *start, double angle)
{
	t_point	*temp;
	double	x;
	double	y;
	double	*mid;
	double	a[2];

	temp = start;
	mid = to_origin(temp);
	move(temp, -mid[0], -mid[1]);
	angle = angle * (M_PI / 180);
	a[0] = cos(angle);
	a[1] = sin(angle);
	while (temp != NULL)
	{
		x = temp->x;
		y = temp->y;
		temp->x = (x * a[0]) + (y * -a[1]);
		temp->y = (x * a[1]) + (y * a[0]);
		temp = temp->nextr;
	}
	temp = start;
	move(temp, mid[0], mid[1]);
	free(mid);
}
