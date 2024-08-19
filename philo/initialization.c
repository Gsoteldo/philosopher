/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:39 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/19 19:18:06 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_values(t_data *data, char *argv[], pthread_mutex_t **forks)
{
	int i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data->philo[i].id = i + 1;
		data->philo[i].start_time = get_current_time();
		data->philo[i].last_meal = get_current_time();
		data->philo[i].eat_flag = 0;
		data->philo[i].print_mutex = &data->print_mutex;
		data->philo[i].eat_mutex = &data->eat_mutex;
		data->philo[i].dead_mutex = &data->dead_mutex;
		data->philo[i].num_of_philo = ft_atoi(argv[1]);
		data->philo[i].time_to_die = ft_atoi(argv[2]);
		data->philo[i].time_to_eat = ft_atoi(argv[3]);
		data->philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data->philo[i].num_of_meals = ft_atoi(argv[5]);
		else
			data->philo[i].num_of_meals = -1;
		data->philo[i].dead_flag = &data->dead_flag;
		data->philo[i].l_fork = *forks + i;
		if (i == 0)
			data->philo[i].r_fork = *forks + (ft_atoi(argv[1]) - 1);
		else
			data->philo[i].r_fork = *forks + (i - 1);
		i++;
	}
}

static void initialization_forks(pthread_mutex_t **forks, int num_of_philo)
{
	int i;

	i = 0;
	while (i < num_of_philo)
	{
		printf("forks[%d] %p\n", i, (*forks + i));
		pthread_mutex_init((*forks + i), NULL);
		i++;
	}
}

void  initialization_philo(t_data *data, pthread_mutex_t **forks, char *argv[])
{
	// int i;

	// i = 0;
	data->dead_flag = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	data->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!data->philo)
	{
		printf(RED "Error: " DEFAULT "Fail creating philo\n");
		exit(1);
	}
	*forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!forks)
	{
		printf(RED "Error: " DEFAULT "Fail creating forks\n");
		exit(1);
	}
	initialization_forks(forks, ft_atoi(argv[1]));
	init_values(data, argv, forks);	
}

	// while (i < ft_atoi(argv[1]))
	// {
	// 	data->philo[i].id = i + 1;
	// 	data->philo[i].num_of_philo = ft_atoi(argv[1]);
	// 	data->philo[i].time_to_die = ft_atoi(argv[2]);
	// 	data->philo[i].time_to_eat = ft_atoi(argv[3]);
	// 	data->philo[i].time_to_sleep = ft_atoi(argv[4]);
	// 	data->philo[i].num_of_meals = -1;
	// 	data->philo[i].dead_flag = &data->dead_flag;
	// 	i++;
	// }