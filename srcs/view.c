/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:53:33 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 15:47:50 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*get_last_node(t_point *start)
{
	t_point *temp;

	temp = start;
	while (temp != NULL)
	{
		if (temp->nextr == NULL)
			break ;
		temp = temp->nextr;
	}
	return (temp);
}

t_view	*determine_size(t_view *v, t_point *start)
{
	t_point *temp;

	temp = get_last_node(start);
	v->size_x = WIN_W;
	v->size_y = WIN_H;
	v->height = temp->y;
	v->width = temp->x;
	if (v->height + v->width / 2 > 200)
	{
		v->size_x *= 2.5;
		v->size_y *= 2.2;
	}
	else if (v->height + v->width / 2 > 100)
	{
		v->size_x *= 2;
		v->size_y *= 2;
	}
	v->scale = (v->size_y / v->height) - ((v->size_y * 4) / v->height) * 0.1;
	v->max_x = v->width * v->scale;
	v->max_y = v->height * v->scale;
	v->center_x = (v->size_x - v->max_x) / 2;
	v->center_y = (v->size_y - v->max_y) / 2;
	return (v);
}
