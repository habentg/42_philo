/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:42:24 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/26 17:21:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1 -  philo took forks from both sides
int	philo_take_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (1)
	{
		if (!check_simulation(data))
			return (0);
		if (take_forks(philo))
			break ;
		usleep(100);
	}
	return (1);
}

int	philo_eats(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, EAT);
	ft_usleep(philo->data->time_eat);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_lock(&philo->data->meals_lock);
	if (philo->data->max_meals != -1)
		philo->no_meals++;
	pthread_mutex_unlock(&philo->data->meals_lock);
	drop_fork(philo, 'r');
	drop_fork(philo, 'l');
	return (1);
}

int	philo_sleeps(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, SLEEP);
	ft_usleep(philo->data->time_sleep);
	return (1);
}

int	philo_thinks(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, THINK);
	usleep(100);
	return (1);
}
