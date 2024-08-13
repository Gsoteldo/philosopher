/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:10:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/13 21:26:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	(void)forks;
	while (i < data->philo[0].num_of_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) == -1)
		{
			printf("Error creating thread\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->philo[0].num_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	
}