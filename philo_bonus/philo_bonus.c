/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:40:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/24 19:46:53 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_data			data;

	if (check_valid_args(argc, argv) == 0)
		return (1);
	start_philo(&data, argv);
	create_processes(&data);
	return (0);
}

/*
	Orden de las funciones en philo_bonus.c usando procesos:
	1. check_valid_args
	2. start_philo
	3. create_processes
	4. free_and_destroy
*/