/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:10:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/15 14:59:01 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_data *data, pthread_mutex_t *forks)
{
	int i;
	pthread_t monitoring;

	i = 0;
	(void)forks;
	if (pthread_create(&monitoring, NULL, &monitor, data->philo) != 0)
	{
		printf("Error creating thread\n");
		exit(1);
	}
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) != 0)
		{
			printf("Error creating thread\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	if (pthread_join(monitoring, NULL) == -1)
	{
		printf("Error joining thread\n");
		exit(1);
	}
	while (i < data->philo[0].num_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	
}