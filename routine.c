/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:38:07 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/16 14:40:30 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_data *data)
{
	int	time;

	time = ft_time();
	printmsg(data, 3);
	while (ft_time() - time < data->args.time_sleep && data->dead == 0)
		usleep(100);
	printmsg(data, 4);
}

void	ft_manger(t_data *data)
{
	int	time;

	time = ft_time();
	if (data->dead == 0)
	{
		if (data->args.nb_eat == -1)
			printmsg(data, 2);
		else
		{
			data->eat++;
			printmsg(data, 5);
		}
		data->last_eat = ft_time();
		while (ft_time() - time < data->args.time_eat && data->dead == 0)
			usleep(100);
	}
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(data->left_fork);
}

void	ft_tackfork(t_data *data)
{
	int			time;
	static int	i;

	time = ft_time();
	if (data->philo % 2 == 0 && i == 0)
	{
		usleep(100);
		i++;
	}
	pthread_mutex_lock(data->right_fork);
	printmsg(data, 1);
	if (data->args.nb_f == 1)
	{
		while (ft_time() - time <= data->args.time_die && data->dead == 0)
			usleep(100);
	}
	else
	{
		pthread_mutex_lock(data->left_fork);
		printmsg(data, 1);
	}
}

void	*ft_routine(void *s_data)
{
	t_data	*data;

	data = (t_data *)s_data;
	while (data->dead == 0 && data->eat != data->args.nb_eat)
	{
		if (data->dead == 0)
			ft_tackfork(data);
		if (data->dead == 0)
			ft_manger(data);
		if (data->dead == 0)
			ft_sleep(data);
	}
	return (NULL);
}
