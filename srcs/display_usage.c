/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:32:30 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/26 18:52:07 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_usage(void)
{
	ft_putstr(MAGENTA "[1]" RESET " gryffindor\n");
	ft_putstr(MAGENTA "[2]" RESET " ravenclaw\n");
	ft_putstr(MAGENTA "[3]" RESET " slytherin\n");
	ft_putstr(MAGENTA "[4]" RESET " hufflepuff\n");
	ft_putstr(MAGENTA "[5]" RESET " desert\n");
	ft_putstr(MAGENTA "[6]" RESET " aqua\n");
}

void	zoom_usage(void)
{
	ft_putstr(YELLOW "[+]" RESET " Zoom in\n");
	ft_putstr(YELLOW "[-]" RESET " Zoom out\n");
}

void	display_usage(void)
{
	ft_putstr("\nGeneral Usage:\n");
	ft_putstr(RED "[Esc]" RESET " Exit program\n");
	ft_putstr(GREEN "[W]" RESET " Move up\n");
	ft_putstr(GREEN "[A]" RESET " Move left\n");
	ft_putstr(GREEN "[S]" RESET " Move down\n");
	ft_putstr(GREEN "[D]" RESET " Move right\n");
	ft_putstr("\n");
	zoom_usage();
	ft_putstr(CYAN "\n[Left arrow]" RESET " Rotate x axis left\n");
	ft_putstr(CYAN "[Right arrow]" RESET " Rotate x axis right\n");
	ft_putstr(CYAN "[Up arrow]" RESET " Rotate y axis up\n");
	ft_putstr(CYAN "[Down arrow]" RESET " Rotate y axis down\n");
	ft_putstr(CYAN "[Q]" RESET " Rotate z axis left\n");
	ft_putstr(CYAN "[E]" RESET " Rotate z axis right\n");
	ft_putstr("\nColor Schemes:\n");
	color_usage();
}
