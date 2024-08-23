/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:16 by gabo              #+#    #+#             */
/*   Updated: 2024/08/22 14:00:16 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	pthread_mutex_t	*forks;

	forks = NULL;
	if (check_valid_args(argc, argv) == 0)
		return (1);
	initialization_philo(&data, &forks, argv);
	create_threads(&data, forks);
	free_and_destroy(&data, forks);
	return (0);
}
