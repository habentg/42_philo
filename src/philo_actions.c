/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:42:24 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/22 14:33:13 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_take_forks(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->r_lock);
		pthread_mutex_lock(philo->l_lock);
		if ((*philo->r_fork == 0) && (*philo->l_fork == 0))
			break ;
		pthread_mutex_unlock(philo->r_lock);
		pthread_mutex_unlock(philo->l_lock);
	}
	*philo->r_fork = 1;
	pthread_mutex_unlock(philo->r_lock);
	display_action(philo, R_FORK_TAKEN);
	*philo->l_fork = 1;
	pthread_mutex_unlock(philo->l_lock);
	display_action(philo, L_FORK_TAKEN);
	return (0);
}

int	philo_eats(t_philo *philo)
{
	display_action(philo, EAT);
	philo->last_meal_time = get_time_ms(philo);
	if (philo->data->max_meals != -1)
		philo->no_meals++;
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_lock(philo->r_lock);
		*philo->r_fork = 0;
	pthread_mutex_unlock(philo->r_lock);
	pthread_mutex_lock(philo->l_lock);
	*philo->l_fork = 0;
	pthread_mutex_unlock(philo->l_lock);
	return (0);
}

int	philo_sleeps(t_philo *philo)
{
	display_action(philo, SLEEP);
	usleep(philo->data->time_sleep * 1000);
	return (0);
}

int	philo_thinks(t_philo *philo)
{
	display_action(philo, SLEEP);
	usleep(philo->data->time_eat * 1000);
	return (0);
}
