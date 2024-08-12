/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:29 by gabo              #+#    #+#             */
/*   Updated: 2024/08/12 18:23:13 by gsoteldo         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int 			num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int				*dead_flag;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				dead_flag;
} t_data;


//check arguments
int	check_valid_args(int argc, char *argv[]);

//initialize philo
void	init_philo(t_data *data, char *argv[]);

//Utils functions
int	ft_atoi(const char *str);


#endif