/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:06 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/26 20:22:21 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1 - fork taken successfully 
static int	take_fork(t_philo *philo, char r_or_l)
{
	if (r_or_l == 'r')
	{
		pthread_mutex_lock(philo->r_lock);
		if (*philo->r_fork == 1)
			return (pthread_mutex_unlock(philo->r_lock), 0);
		*philo->r_fork = 1;
		pthread_mutex_unlock(philo->r_lock);
	}
	else
	{
		pthread_mutex_lock(philo->l_lock);
		if (*philo->l_fork == 1)
			return (pthread_mutex_unlock(philo->l_lock), 0);
		*philo->l_fork = 1;
		pthread_mutex_unlock(philo->l_lock);
	}
	return (1);
}

void	drop_fork(t_philo *philo, char r_or_l)
{
	if (r_or_l == 'r')
	{
		pthread_mutex_lock(philo->r_lock);
		*philo->r_fork = 0;
		pthread_mutex_unlock(philo->r_lock);
	}
	else
	{
		pthread_mutex_lock(philo->l_lock);
		*philo->l_fork = 0;
		pthread_mutex_unlock(philo->l_lock);
	}
}

// 1 - successfully taken both forks
int	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (!take_fork(philo, 'r'))
			return (0);
		if (!take_fork(philo, 'l'))
			return (drop_fork(philo, 'r'), 0);
	}
	else
	{
		if (!take_fork(philo, 'l'))
			return (0);
		if (!take_fork(philo, 'r'))
			return (drop_fork(philo, 'l'), 0);
	}
	// if (!take_fork(philo, 'l'))
	// 	return (0);
	// if (!take_fork(philo, 'r'))
	// 	return (drop_fork(philo, 'l'), 0);
	display_action(philo, R_FORK_TAKEN);
	display_action(philo, L_FORK_TAKEN);
	return (1);
}
