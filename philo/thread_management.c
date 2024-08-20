/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:10:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/20 17:03:50 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_data *data, pthread_mutex_t *forks)
{
	int i;
	pthread_t monitoring;

	i = 0;
	if (pthread_create(&monitoring, NULL, &monitor, data->philo) != 0)
	{
		printf("Error creating thread\n");
		free_and_destroy(data, forks);
		return ;
	}
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) != 0)
		{
			printf("Error creating thread\n");
			free_and_destroy(data, forks);
			// return ;
		}
		i++;
	}
	i = 0;
	if (pthread_join(monitoring, NULL) != 0)
	{
		printf("Error joining thread\n");
		free_and_destroy(data, forks);
		// return ;
	}
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
		{
			printf("Error joining thread\n");
			free_and_destroy(data, forks);
			// return ;
		}
		i++;
	}
	return ;
}