/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:35:42 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/16 14:42:56 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_data *data, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_f)
	{
		pthread_mutex_destroy(data[i].left_fork);
	}
}

void	init_args(t_args *args, int argc, char **argv)
{
	args->nb_f = ft_atoi_long(argv[1]);
	args->time_die = ft_atoi_long(argv[2]);
	args->time_eat = ft_atoi_long(argv[3]);
	args->time_sleep = ft_atoi_long(argv[4]);
	if (argc == 6)
		args->nb_eat = ft_atoi_long(argv[5]);
	else
		args->nb_eat = -1;
}

void	init_mutex(pthread_mutex_t *fork, t_data *data, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_f)
		pthread_mutex_init(&fork[i], NULL);
	i = -1;
	while (++i < args->nb_f)
	{
		data[i].eat = 0;
		data[i].dead = 0;
		data[i].last_eat = ft_time();
		data[i].args = *args;
		data[i].philo = i + 1;
		data[i].left_fork = &fork[i];
		if (args->nb_f != i + 1)
			data[i].right_fork = &fork[i + 1];
		else
			data[i].right_fork = &fork[0];
	}
}

void	ft_philosophers(int argc, char **argv)
{
	t_args			args;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	t_data			*data;

	init_args(&args, argc, argv);
	data = malloc(sizeof (t_data) * args.nb_f);
	fork = malloc(sizeof (pthread_mutex_t) * args.nb_f);
	philo = malloc(sizeof (pthread_t) * args.nb_f);
	data->dead = 0;
	init_mutex(fork, data, &args);
	init_philo(philo, data, args.nb_f);
	destroy_mutex(data, &args);
	free (data);
	free (fork);
	free (philo);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_chek_args(argv) == 0)
			ft_philosophers(argc, argv);
		else
			printf("Error: arguments values\n");
	}
	else
		printf("not the right number of arguments\n");
}
