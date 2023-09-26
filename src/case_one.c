/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 08:56:28 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/26 11:47:39 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*one_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	*philo->r_fork = 1;
	display_action(philo, "has taken a fork");
	ft_usleep(philo->data->time_die + 1);
	*philo->r_fork = 0;
	return (0);
}

int	case_one(t_data *data)
{
	data->start_time = get_time_ms();
	data->philo[0].philo_id = 1;
	data->philo[0].data = data;
	data->philo[0].r_fork = &(data->forks[0]);
	data->philo[0].l_fork = NULL;
	data->philo[0].r_lock = &data->fork_mutexes[0];
	data->philo[0].l_lock = NULL;
	data->philo[0].no_meals = 0;
	data->philo[0].last_meal_time = get_time_ms();
	if (pthread_create(&data->thrd_id[0], NULL, &one_philo, \
		&data->philo[0]) != 0)
		return (ft_error(CREATE_TH_FAIL, data), 1);
	if (pthread_join(data->thrd_id[0], NULL) != 0)
		return (ft_error(JOIN_TH_FAIL, data), 1);
	return (0);
}
