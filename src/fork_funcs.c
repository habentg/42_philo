/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:06 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/30 15:34:31 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1 - fork taken successfully
/*pick up (make un-available) right or left fork based on the character given*/
int	take_fork(t_philo *philo, char r_or_l)
{
	if (r_or_l == 'r')
	{
		pthread_mutex_lock(philo->r_lock);
		if (*philo->r_fork == -1 || *philo->r_fork == philo->philo_id)
			return (pthread_mutex_unlock(philo->r_lock), 0);
		*philo->r_fork = -1;
		pthread_mutex_unlock(philo->r_lock);
	}
	else
	{
		pthread_mutex_lock(philo->l_lock);
		if (*philo->l_fork == -1 || *philo->l_fork == philo->philo_id)
			return (pthread_mutex_unlock(philo->l_lock), 0);
		*philo->l_fork = -1;
		pthread_mutex_unlock(philo->l_lock);
	}
	return (1);
}

/*drop (make available) right or left fork based on the character given*/
void	drop_fork(t_philo *philo, char r_or_l, int code)
{
	if (r_or_l == 'r')
	{
		pthread_mutex_lock(philo->r_lock);
		if (code == 1)
			*philo->r_fork = philo->philo_id;
		else
			*philo->r_fork = 0;
		pthread_mutex_unlock(philo->r_lock);
	}
	else
	{
		pthread_mutex_lock(philo->l_lock);
		if (code == 1)
			*philo->l_fork = philo->philo_id;
		else
			*philo->l_fork = 0;
		pthread_mutex_unlock(philo->l_lock);
	}
}

// 1 - successfully taken both forks
/*pick up one if its available (if not, no reason to check the other side) & 
	check the other side if available(if not, drop the first one and head out)*/
int	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (!take_fork(philo, 'r'))
			return (0);
		if (!take_fork(philo, 'l'))
			return (drop_fork(philo, 'r', 0), 0);
	}
	else
	{
		if (!take_fork(philo, 'l'))
			return (0);
		if (!take_fork(philo, 'r'))
			return (drop_fork(philo, 'l', 0), 0);
	}
	return (1);
}
