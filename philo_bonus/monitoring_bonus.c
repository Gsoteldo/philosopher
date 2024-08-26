/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:49 by gabo              #+#    #+#             */
/*   Updated: 2024/08/26 13:23:54 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_data *data)
{
	sem_wait(data->eat_semaphore);
	if (get_current_time() - data->last_meal >= data->time_to_die
		&& data->eat_flag == 0)
	{
		sem_post(data->eat_semaphore);
		return (1);
	}
	sem_post(data->eat_semaphore);
	return (0);
}

int check_if_dead(t_data *data)
{
		if (is_dead(data))
		{
			printf_with_id_and_time(data, data->philo->id, "died");
			return (1);
		}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_if_dead(data))
			break ;
	}
	return (NULL);
}