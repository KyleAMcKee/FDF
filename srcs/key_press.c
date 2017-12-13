/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:07:28 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 12:49:55 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_press_ext(int keycode, t_view *view)
{
	if (keycode == ARROW_R)
		rotate_y(view, 5);
	if (keycode == ARROW_L)
		rotate_y(view, -5);
	if (keycode == PLUS || keycode == PLUS2)
		scale(view->start, 1.5, 1.5, 1.5);
	if (keycode == MINUS || keycode == MINUS2)
		scale(view->start, 0.75, 0.75, 0.75);
	if (keycode == KEY_Q)
		rotate_z(view->start, -5);
	if (keycode == KEY_E)
		rotate_z(view->start, 5);
}

void	key_press_color(int keycode, t_view *view)
{
	if (keycode == ONE)
		set_color("gryffindor", view->color);
	if (keycode == TWO)
		set_color("ravenclaw", view->color);
	if (keycode == THREE)
		set_color("slytherin", view->color);
	if (keycode == FOUR)
		set_color("hufflepuff", view->color);
	if (keycode == FIVE)
		set_color("desert", view->color);
	if (keycode == SIX)
		set_color("aqua", view->color);
}

int		key_press(int keycode, t_view *view)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == KEY_D)
		move(view->start, 30, 0);
	if (keycode == KEY_A)
		move(view->start, -30, 0);
	if (keycode == KEY_S)
		move(view->start, 0, 30);
	if (keycode == KEY_W)
		move(view->start, 0, -30);
	if (keycode == ARROW_U)
		rotate_x(view, 5);
	if (keycode == ARROW_D)
		rotate_x(view, -5);
	key_press_ext(keycode, view);
	key_press_color(keycode, view);
	map_draw(view->mlx, view->win, view->start, view->color);
	return (0);
}
