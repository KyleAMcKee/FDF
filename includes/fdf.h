/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:42:44 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 17:14:14 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "color.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_W 13
# define KEY_Q 12
# define KEY_E 14
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define ESC 53
# define ARROW_R 124
# define ARROW_L 123
# define ARROW_U 126
# define ARROW_D 125
# define MINUS 78
# define MINUS2 27
# define PLUS 69
# define PLUS2 24
# define MLX mlx_new_window
# define WIN_W 800
# define WIN_H 600
# define FAIL_NEXT(x) if (!x) return ;
# define CHECK_Y(x) if (x) start->nextr = new; else last->nextr = new;

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
	double			height;
	double			width;
	double			depth;
	struct s_point	*nextr;
	struct s_point	*nextd;
}				t_point;

typedef struct	s_line
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	int		swap;
}				t_line;

typedef struct	s_color
{
	int color1;
	int color2;
	int color3;
}				t_color;

typedef struct	s_view
{
	void	*mlx;
	void	*win;
	t_point	*start;
	t_color	*color;
	double	size_x;
	double	size_y;
	double	scale;
	double	height;
	double	width;
	double	center_x;
	double	center_y;
	double	max_x;
	double	max_y;
	double	alpha;
	double	beta;
	double	gamma;
}				t_view;

void			scale(t_point *s, double xscale, double yscale, double zscale);
void			move(t_point *temp, double xmove, double ymove);
void			rotate_x(t_view *view, double angle);
void			rotate_y(t_view *view, double angle);
void			rotate_z(t_point *temp, double angle);
void			map_draw(void *mlx, void *win, t_point *start, t_color *color);
t_point			*map_right(char *line, t_point *start, int y, char *arg);
t_point			*map_down(t_point *start);
t_point			*map(t_point *start, int fd, char *arg);
void			bres_r(void *mlx, void *win, t_point *temp, int color);
void			bres_d(void *mlx, void *win, t_point *temp, int color);
t_view			*determine_size(t_view *view, t_point *last);
double			*to_origin(t_point *start);
double			*scale_move(t_point *start);
int				key_press(int keycode, t_view *view);
void			set_color(char *str, t_color *color);
void			display_usage(void);
int				error_handle(int fd, char *arg1, char *arg2, int argc);
void			error_usage(char *arg, int type);
#endif
