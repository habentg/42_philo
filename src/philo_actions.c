/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:42:24 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/28 22:10:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*check if the simulation is still alive*/
/*1 -  philo took forks from both sides, or wiat till then
	// dont comeback empty handed*/
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
		usleep(20);
	}
	display_action(philo, R_FORK_TAKEN);
	display_action(philo, L_FORK_TAKEN);
	return (1);
}

/*check if the simulation is still alive*/
/*Eat for a period of time, update last-eat-time, drop the forks*/
int	philo_eats(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, EAT);
	pthread_mutex_lock(&philo->data->m_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->data->m_lock);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_lock(&philo->data->meals_lock);
	if (philo->data->max_meals != -1)
		philo->no_meals++;
	pthread_mutex_unlock(&philo->data->meals_lock);
	drop_fork(philo, 'r', 1);
	drop_fork(philo, 'l', 1);
	return (1);
}

// rest -> 😴😴😴😴😴😴
int	philo_sleeps(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, SLEEP);
	ft_usleep(philo->data->time_sleep);
	return (1);
}

// let bro think -> he a thinker 🤔🤔🤔
int	philo_thinks(t_philo *philo)
{
	if (!check_simulation(philo->data))
		return (0);
	display_action(philo, THINK);
	usleep(100);
	return (1);
}
