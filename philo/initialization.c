/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:21:39 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/12 18:33:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void  init_philo(t_data *data, char *argv[])
{
	// int i;

	// i = 0;
	data->dead_flag = 0;
	data->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!data->philo)
	{
		printf(RED "Error: " DEFAULT "Fail creating philo threads\n");
		//exit(1);
	}



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