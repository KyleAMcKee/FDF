/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_origin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:35:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 12:57:57 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

double	*to_origin(t_point *start)
{
	double	x1;
	double	y1;
	double	x2y2;
	double	*mid;
	t_point *temp;

	x1 = start->x;
	y1 = start->y;
	mid = (double*)malloc(sizeof(double) * 2);
	temp = start;
	while (temp->nextr != NULL)
	{
		temp = temp->nextr;
	}
	x2y2 = temp->x;
	mid[0] = (x2y2 + x1) / 2;
	x2y2 = temp->y;
	mid[1] = (x2y2 + y1) / 2;
	return (mid);
}

double	*scale_move(t_point *start)
{
	double	x1;
	double	y1;
	double	*mid;
	t_point *temp;

	temp = start;
	x1 = temp->x;
	y1 = temp->y;
	mid = (double*)malloc(sizeof(double) * 2);
	mid[0] = x1;
	mid[1] = y1;
	return (mid);
}
