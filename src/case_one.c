/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 08:56:28 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/27 09:02:37 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*takes the fork -> waits time to dead+ -> drops fork and DIE*/
void	*one_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (!take_fork(philo, 'l'))
		usleep(100);
	display_action(philo, "taken a fork");
	ft_usleep(philo->data->time_die + 1);
	drop_fork(philo, 'l');
	return (0);
}

// Initialize only one fork, mutex lock and one thread
void	case_one(t_data *data)
{
	data->start_time = get_time_ms();
	data->philo[0].philo_id = 1;
	data->philo[0].data = data;
	data->philo[0].l_fork = &(data->forks[0]);
	data->philo[0].r_fork = 0;
	data->philo[0].l_lock = &data->fork_mutexes[0];
	data->philo[0].r_lock = 0;
	data->philo[0].no_meals = 0;
	pthread_mutex_lock(&data->meals_lock);
	data->philo[0].last_meal_time = get_time_ms();
	pthread_mutex_unlock(&data->meals_lock);
	if (pthread_create(&data->thrd_id[0], 0, &one_philo, \
		&data->philo[0]) != 0)
		ft_error(CREATE_TH_FAIL, data);
}
