/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:46:22 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 17:16:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			htoi(char *hex)
{
	int val;
	int i;

	val = 0;
	i = 0;
	while (hex[i])
	{
		if (hex[i] == 'x')
			i++;
		if (hex[i] >= '0' && hex[i] <= '9')
			hex[i] = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			hex[i] = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			hex[i] = hex[i] - 'A' + 10;
		val = (val << 4) | (hex[i]);
		i++;
	}
	return (val);
}

t_point		*map_down(t_point *start)
{
	t_point	*temp;
	t_point	*down;

	temp = start;
	down = start;
	while (temp)
	{
		if (temp->y > 0)
		{
			down->nextd = temp;
			down = down->nextr;
		}
		temp = temp->nextr;
	}
	return (start);
}

int			new_point(t_point *new, int i, int y, char **num_arr)
{
	char	**color;

	color = ft_strsplit(num_arr[i], ',');
	new->x = i;
	new->y = y;
	new->z = ft_atoi(&num_arr[i][0]);
	new->height = y;
	new->width = i;
	if (color[1])
		new->color = htoi(color[1]);
	else
		new->color = 0;
	new->depth = new->z;
	new->nextr = NULL;
	new->nextd = NULL;
	free(color[0]);
	free(color[1]);
	free(color);
	i++;
	return (i);
}

t_point		*map_right(char *line, t_point *start, int y, char *arg)
{
	char	**num_arr;
	int		i;
	t_point	*new;
	t_point	*last;

	num_arr = ft_strsplit(line, ' ');
	i = 0;
	num_arr[1] ? i = 0 : error_usage(arg, 1);
	while (num_arr[i] != NULL)
	{
		if (i == 0 && y == 0)
		{
			i = new_point(start, i, y, num_arr);
			last = start;
			free(num_arr[0]);
		}
		new = (t_point*)malloc(sizeof(t_point));
		CHECK_Y(i == 0 && y > 0);
		i = new_point(new, i, y, num_arr);
		last = new;
		free(num_arr[i - 1]);
	}
	free(num_arr);
	return (last);
}

t_point		*map(t_point *start, int fd, char *arg)
{
	int		y;
	char	*line;
	t_point *temp;
	int		check;

	temp = start;
	y = 0;
	while ((check = get_next_line(fd, &line)))
	{
		if (check < 0)
		{
			ft_putstr("Read failed\n");
			exit(0);
		}
		if (ft_strequ(line, ""))
			error_usage(arg, 2);
		temp = map_right(line, temp, y, arg);
		y++;
		free(line);
	}
	temp = start;
	temp = map_down(temp);
	return (start);
}
