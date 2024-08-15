/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:29 by gabo              #+#    #+#             */
/*   Updated: 2024/08/15 16:09:53 by gabo             ###   ########.fr       */
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
	int				*dead_flag;
	int				eat_flag;
	int				id;
	int				num_of_meals;
	int				num_of_philo;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
	size_t			last_meal;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
}	t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	t_philo			*philo;
}	t_data;

//check arguments
int		check_valid_args(int argc, char *argv[]);

//initialize philo
void	initialization_philo(t_data *data, pthread_mutex_t *forks, char *argv[]);
//Routine functions
void	*routine(void *arg);
void	*monitor (void *arg);

//Thread management
void create_threads(t_data *data, pthread_mutex_t *forks);

//Utils functions
int		ft_atoi(const char *str);
void	printf_with_id_and_time(t_philo *philo, int id, char *str);
size_t	get_current_time(void);
void 	free_and_destroy(t_data *data, pthread_mutex_t *forks);

#endif