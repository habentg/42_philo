/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:54:51 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 15:55:11 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	if (data)
		ft_clean(data);
}

void	ft_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
		pthread_mutex_destroy(&data->fork_mutexes[i]);
	if (data->philo->r_lock)
		pthread_mutex_destroy(data->philo->r_lock);
	if (data->philo->l_lock)
		pthread_mutex_destroy(data->philo->l_lock);
	pthread_mutex_destroy(&data->is_dead_lock);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->simulation_status_lock);
	pthread_mutex_destroy(&data->meals_lock);
	if (data->fork_mutexes)
		free(data->fork_mutexes);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	if (data->thrd_id)
		free(data->thrd_id);
}
