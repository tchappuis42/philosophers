/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:52:12 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/16 14:43:14 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_data *data)
{
	static int	dead;

	if (dead == 0)
	{
		if (ft_time() - data->last_eat > data->args.time_die)
		{
			dead = 1;
			printf("%d	philo[%d] died\n", ft_time(), data->philo);
			pthread_mutex_unlock(data->right_fork);
			pthread_mutex_unlock(data->left_fork);
		}
	}
	return (dead);
}

int	nb_eat(t_data *data, int nb)
{
	int	i;

	i = -1;
	while (++i != nb)
	{
		if (data[i].eat != data[i].args.nb_eat)
			return (0);
	}
	return (1);
}

void	ft_dead(t_data *data, int nb)
{
	int	i;

	i = -1;
	data->dead = 1;
	while (++i != nb)
	{
		data[i].dead = 1;
		pthread_mutex_unlock(data[i].right_fork);
		pthread_mutex_unlock(data[i].left_fork);
	}
}

void	printmsg(t_data *data, int msg)
{
	if (data->dead == 0)
	{
		if (msg == 1)
			printf("%d	philo[%d] has taken a fork\n", ft_time(), data->philo);
		if (msg == 2)
			printf("%d	philo[%d] is eating\n", ft_time(), data->philo);
		if (msg == 3)
			printf("%d	philo[%d] is sleeping\n", ft_time(), data->philo);
		if (msg == 4)
			printf("%d	philo[%d] is thinking\n", ft_time(), data->philo);
		if (msg == 5)
			printf("%d	philo[%d] eat for the %d time\n",
				ft_time(), data->philo, data->eat);
	}
}

void	init_philo(pthread_t *philo, t_data *data, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		data[i].philos = &philo[i];
		pthread_create(&philo[i], NULL, ft_routine, &data[i]);
	}
	while (nb_eat(data, nb) == 0 && data[0].dead == 0)
	{
		i = 0;
		while (i < nb)
		{
			if (is_dead(&data[i]) == 1)
			{	
				ft_dead(data, nb);
				break ;
			}
			i++;
		}
	}
	i = -1;
	while (++i < nb)
		pthread_join(philo[i], NULL);
}
