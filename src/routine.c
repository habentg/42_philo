<<<<<<< HEAD:src/routine.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/28 11:52:06 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// breaks out of the loop only if the simulation stops;
// its checked inside each action
void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->philo_id % 2 == 0)
		philo_thinks(philo);
	while (check_simulation(philo->data))
	{
		if (!philo_take_forks(philo))
			break ;
		if (!philo_eats(philo))
			break ;
		if (!philo_sleeps(philo))
			break ;
		if (!philo_thinks(philo))
			break ;
	}
	return (0);
}

// 1 philo is handled separately
// created that many threads
void	start_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_ms();
	if (data->no_philos == 1)
		case_one(data);
	else
		while (++i < data->no_philos)
			if (pthread_create(&data->thrd_id[i], 0, &routine, \
				&data->philo[i]) != 0)
				ft_error(CREATE_TH_FAIL, data);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 05:01:37 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*display_philo(void *philo_ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_ptr;
	data = philo->data;
	while (data->is_dead == 0)
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
>>>>>>> 977dedb415dbf604b57a6a13760b89c67a54998f:src/philo.c
