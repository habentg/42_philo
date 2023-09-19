/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:42:24 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/19 08:14:49 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_lock);
		display_action(philo, "has taken right fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_lock);
		display_action(philo, "has taken left fork");
	}
	if (philo->philo_id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->l_lock) != 0)
			return (pthread_mutex_unlock(philo->r_lock), 1);
		if (!is_philo_dead(philo))
			display_action(philo, "has taken left fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->r_lock) != 0)
			return (pthread_mutex_unlock(philo->l_lock), 1);
		if (!is_philo_dead(philo))
			display_action(philo, "has taken right fork");
	}
	return (0);
}

int philo_eats(t_philo *philo)
{
	// dont forget to update the no_of_meals after philo eats
    pthread_mutex_lock(philo->data->data_lock);
    pthread_mutex_unlock(philo->data->data_lock);
    return (0);
}

int philo_sleeps(t_philo *philo)
{
    pthread_mutex_lock(philo->data->data_lock);
    pthread_mutex_unlock(philo->data->data_lock);
    return (0);
}

int philo_thinks(t_philo *philo)
{
    pthread_mutex_lock(philo->data->data_lock);
    pthread_mutex_unlock(philo->data->data_lock);
    return (0);
}