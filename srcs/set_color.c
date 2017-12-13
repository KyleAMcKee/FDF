/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 23:07:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 10:48:57 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	houses(t_color *color, char *str)
{
	if (ft_strequ("slytherin", str))
	{
		color->color1 = 0x0c8346;
		color->color2 = 0x69306d;
		color->color3 = 0xc5d1eb;
	}
	else if (ft_strequ("gryffindor", str))
	{
		color->color1 = 0xeeba30;
		color->color2 = 0x5f021f;
		color->color3 = 0xafaab9;
	}
	else if (ft_strequ(str, "hufflepuff"))
	{
		color->color1 = 0xffba08;
		color->color2 = 0x7180ac;
		color->color3 = 0xa2aebb;
	}
	else if (ft_strequ(str, "ravenclaw"))
	{
		color->color1 = 0x946b2d;
		color->color2 = 0x222f5b;
		color->color3 = 0x5d5d5d;
	}
}

void	set_color(char *str, t_color *color)
{
	if (ft_strequ(str, "aqua"))
	{
		color->color1 = 0x4adbc8;
		color->color2 = 0x547aa5;
		color->color3 = 0x474044;
	}
	else if (ft_strequ(str, "slytherin") || ft_strequ(str, "gryffindor"))
		houses(color, str);
	else if (ft_strequ(str, "hufflepuff") || ft_strequ(str, "ravenclaw"))
		houses(color, str);
	else
	{
		color->color1 = 0xffa500;
		color->color2 = 0x7647a2;
		color->color3 = 0xccbadc;
	}
}
