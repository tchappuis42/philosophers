/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:39:27 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/16 14:40:27 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	int	nb_f;
	int	nb_eat;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}		t_args;

typedef struct s_data
{
	int				philo;
	int				last_eat;
	int				dead;
	int				eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		*philos;
	t_args			args;
}		t_data;

long int	ft_atoi_long(const char *str);
void		init_philo(pthread_t *philo, t_data *data, int nb);
int			ft_time(void);
int			is_dead(t_data *data);
int			ft_isdigit(char c);
int			ft_chek_args(char **argv);
size_t		ft_strlen(const char *s);
void		*ft_routine(void *s_data);
void		printmsg(t_data *data, int msg);

#endif