/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:35:07 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/16 14:42:13 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	chek_long(char *str)
{
	long int	ret;

	if (ft_strlen(str) < 11)
		ret = ft_atoi_long(str);
	else
		return (1);
	if (ret > MAX_INT || ret < MIN_INT)
		return (1);
	return (0);
}

int	chek_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_chek_args(char **argv)
{
	int	i;
	int	ret;

	i = 1;
	while (argv[i] != NULL && ret != 1)
	{
		ret = chek_digit(argv[i]);
		if (ret == 0)
			ret = chek_long(argv[i]);
		i++;
	}
	return (ret);
}
