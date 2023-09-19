/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:18:33 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/19 07:49:38 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// func to throw an error & clean everything...
void	ft_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	if (data)
		ft_clean(data);
}

// free everything before exiting
void	ft_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
	{
		free(data->thrd_id[i]);
		pthread_mutex_destroy(&data->fork_mutexes[i]);
		free(&data->fork_mutexes[i]);
		free(&data->philo[i]);
		free(&data->forks[i]);
	}
	pthread_mutex_destroy(data->philo->r_lock);
	pthread_mutex_destroy(data->philo->l_lock);
	pthread_mutex_destroy(data->data_lock);
	write (1, "cleaning!", 10);
}
