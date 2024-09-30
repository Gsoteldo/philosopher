/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:43:47 by gabo              #+#    #+#             */
/*   Updated: 2024/09/30 21:49:01 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_life(t_data *data)
{
	char *str;

	str = ft_strjoin( "/", ft_itoa(data->philo->id));
	if (str == NULL)
	{
		printf("Error: fail creating sem\n");
		kill_them_all();
	}
	sem_unlink(str);
	data->eat_semaphore = sem_open(str, O_CREAT, 0644, 1);
	if (data->eat_semaphore == SEM_FAILED)
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
		data->philo->pid = fork();
		if (data->philo->pid == 0)
			break ;
		else if (data->philo->pid == -1)
			kill_them_all();
		i++;
	}
	if (data->philo->pid == 0)
	{
		data->philo->id = i + 1;
		printf("Existen %d filosofos\n", i);
		philo_life(data);
		routine(data);
	}
		waitpid(-1, NULL, 0);
}
