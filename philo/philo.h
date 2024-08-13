/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:29 by gabo              #+#    #+#             */
/*   Updated: 2024/08/13 21:23:40 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define DEFAULT "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	size_t			start_time;
	size_t			last_meal;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int				*dead_flag;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print_mutex;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				dead_flag;
	pthread_mutex_t	print_mutex;
}	t_data;

//check arguments
int		check_valid_args(int argc, char *argv[]);

//initialize philo
void	initialization_philo(t_data *data, pthread_mutex_t *forks, char *argv[]);

//Routine functions
void   *routine(void *arg);

//Thread management
void create_threads(t_data *data, pthread_mutex_t *forks);

//Utils functions
int		ft_atoi(const char *str);
void	printf_with_id_and_time(t_philo *philo, int id, char *str);
size_t	get_current_time(void);

#endif