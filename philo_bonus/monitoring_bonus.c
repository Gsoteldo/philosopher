/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:21:49 by gabo              #+#    #+#             */
/*   Updated: 2024/09/30 21:51:24 by gsoteldo         ###   ########.fr       */
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
			return (1);
	return (0);
}
int someone_died(t_data *data)
{
	if (check_if_dead(data))
	{
		printf_with_id_and_time(data, data->philo->id, "died");
		exit(1);
	}
	return (0);
} 

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (someone_died(data))
			break ;
	}
	return (NULL);
}