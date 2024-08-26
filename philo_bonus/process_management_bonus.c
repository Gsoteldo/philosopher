/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:43:47 by gabo              #+#    #+#             */
/*   Updated: 2024/08/26 13:17:56 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_life(t_data *data)
{
	char *str;

	str = ft_strjoin( "/", ft_itoa(data->philo->id));
	sem_unlink(str);
	data->forks = sem_open(str, O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED)
	{
		write(2, "Semaphore error\n", 16);
		kill_them_all();
	}


}

void	create_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
			break;
		else if (data->philo[i].pid < 0)
			kill_them_all();
		i++;
	}
	if (data->philo[i].pid == 0)
	{
		data->philo[i].id = i + 1;
		philo_life(data);
		routine(data);
	}
		waitpid(-1, NULL, 0);
}