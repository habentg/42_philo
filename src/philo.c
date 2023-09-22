/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/22 14:29:43 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*display_philo(void *philo_ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_ptr;
	data = philo->data;

	while (1)
	{
		if (is_philo_dead(philo) == 1)
			break ;
		philo_take_forks(philo);
		if (is_philo_dead(philo) == 1)
			break ;
		philo_eats(philo);
		if (is_philo_dead(philo) == 1)
			break ;
		philo_sleeps(philo);
		if (is_philo_dead(philo) == 1)
			break ;
		if (philo->data->max_meals == philo->no_meals)
			break ;
	}
	return (0);
}

int	start_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_ms(data->philo);
	while (++i < data->no_philos)
	{
		if (pthread_create(&data->thrd_id[i], NULL, &display_philo, \
			&data->philo[i]) != 0)
			return (ft_error(CREATE_TH_FAIL, data), 1);
	}
	i = -1;
	while (++i < data->no_philos)
	{
		if (pthread_join(data->thrd_id[i], NULL) != 0)
			return (ft_error(JOIN_TH_FAIL, data), 1);
	}
	return (0);
}
