/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:24:44 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/22 13:56:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_usage(char *arg, int type)
{
	ft_putstr(RED "Error: " RESET "File " CYAN);
	ft_putstr(arg);
	if (type == 1)
		ft_putstr(RESET " contained only a single value or was invalid\n");
	else if (type == 2)
		ft_putstr(RESET " contained an empty line\n");
	ft_putstr("Make sure file is a valid FDF file\n");
	ft_putstr(GREEN "Usage: " RESET);
	ft_putstr("./fdf file(.fdf) color scheme(optional)\n");
	exit(0);
}

int		scheme_verify(char *arg)
{
	if (ft_strequ(arg, "desert"))
		return (1);
	if (ft_strequ(arg, "aqua"))
		return (1);
	if (ft_strequ(arg, "slytherin"))
		return (1);
	if (ft_strequ(arg, "gryffindor"))
		return (1);
	if (ft_strequ(arg, "hufflepuff"))
		return (1);
	if (ft_strequ(arg, "ravenclaw"))
		return (1);
	else
	{
		ft_putstr("\nInvalid color scheme\n");
		ft_putstr("Defaults to 'desert', color options listed below\n");
	}
	return (0);
}

void	bad_fd(char *arg1)
{
	ft_putstr(RED "Error: " RESET);
	if (arg1)
	{
		ft_putstr("Problem opening file: "CYAN);
		ft_putstr(arg1);
		ft_putstr(RESET "\nMake sure your file exists and is valid");
		ft_putstr("\n" GREEN);
	}
	else
		ft_putstr("No file specified\n" GREEN);
	ft_putstr("Usage:" RESET " ./fdf file(.fdf) color scheme(optional)\n");
}

int		verify_fdf(char *arg1)
{
	int len;
	int comp;

	len = ft_strlen(arg1);
	comp = ft_strequ(".fdf", &arg1[len-- - 4]);
	if (comp == 0)
	{
		ft_putstr(RED "Error: " RESET);
		ft_putstr("file must end in .fdf\n" GREEN);
		ft_putstr("Usage:" RESET" ./fdf file(.fdf) color scheme(optional)\n");
		return (0);
	}
	return (1);
}

int		error_handle(int fd, char *arg1, char *arg2, int argc)
{
	if (argc > 3)
	{
		ft_putstr(RED "Error: " RESET "Too many arguments\n" GREEN);
		ft_putstr("Usage: " RESET "./fdf file(.fdf) color scheme(optional)\n");
		return (0);
	}
	if (fd < 1)
	{
		bad_fd(arg1);
		return (0);
	}
	if (arg2 != NULL)
	{
		if (!scheme_verify(arg2))
			return (1);
	}
	if (fd > 0)
	{
		if (!verify_fdf(arg1))
			return (0);
	}
	return (1);
}
