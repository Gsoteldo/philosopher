/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:16 by gabo              #+#    #+#             */
/*   Updated: 2024/08/13 21:23:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*routine()
// {
// 	int i;

// 	i = 0;
// 	printf("Hello from routine\n");
// 	sleep(3);
// 	printf("Goodbye from routine\n");
// 	while (i < 10000000)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		prueba++;
// 		pthread_mutex_unlock(&mutex);
// 		i++;
// 	}
// 	return (NULL);
// }

int	main(int argc, char *argv[])
{
	t_data data;
	pthread_mutex_t forks;
	// int			i;

	// i = 0;
	if (check_valid_args(argc, argv) == 0)
		return (1);
	initialization_philo(&data, &forks, argv);
	create_threads(&data, &forks);
	// while (i < ft_atoi(argv[1]))
	// {
	// 	printf("Philo id%d\n", data.philo[i].id);
	// 	printf("Philo  num%d\n", data.philo[i].num_of_philo);
	// 	printf("Philo die%d\n", data.philo[i].time_to_die);
	// 	printf("Philo eat %d\n", data.philo[i].time_to_eat);
	// 	printf("Philo  sleep%d\n", data.philo[i].time_to_sleep);
	// 	printf("Philo num of meals%d\n", data.philo[i].num_of_meals);
	// 	printf("Philo dead_flag%d\n", *data.philo[i].dead_flag);
	// 	printf("Philo was crearted: %ld\n", data.philo[i].start_time);
	// 	if (data.philo[i].l_fork != NULL && data.philo[i].r_fork != NULL)
	// 		printf("Philo left and right fork for philo %d exists\n\n", data.philo[i].id);
	// 	else
	// 		printf("Philo left fork doesnt exit for philo %d\n\n", data.philo[i].id);
	// 	i++;

	// 	// pthread_create(&thread[i], NULL, routine, NULL);
	// 	// i++;
	// }
	// i = 0;
	// while (i < ft_atoi(argv[1]))
	// {
	// 	pthread_join(thread[i], NULL);
	// 	i++;
	// }
	// printf("%d\n", prueba);
	// free(thread);
	// pthread_mutex_destroy(&mutex);
	return (0);
}
