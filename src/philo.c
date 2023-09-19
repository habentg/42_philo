/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/19 08:19:29 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*display_philo(void *philo_ptr)
{
	t_philo	*philo;
	t_data	*p_data;
	int		i;

	philo = (t_philo *)philo_ptr;
	p_data = philo->data;
	i = 0;
	// printf("thread -> %d\n", philo->philo_id);
	while (p_data->is_dead == 0)
	{
		// <----------- check if philo is dead, 0 is success (not dead)
		//<------philo checks to take the forks
		philo_take_forks(philo); // if he is not dead yet lmao and dont forget to release the forks
		// p_data->is_dead = 1;
		// if (is_philo_dead(philo) == 1)
		// {
		// 	display_action(philo, DEAD);
		// 	exit (0);
		// }
		// philo_eats(philo); -- for a given amount of time
		// if (is_philo_dead(philo) == 1)
		// {
		// 	display_action(philo, DEAD);
		// 	exit (0);
		// }
		// <---------------while you do all this shit dont forget to check dude is not dead-------------->
		// philo_sleeps(philo);
		// if (is_philo_dead(philo) == 1)
		// {
		// 	display_action(philo, DEAD);
		// 	exit (0);
		// }
		// <---------------while you do all this shit dont forget to check dude is not dead-------------->
		// philo_thinks(philo);
		// if (is_philo_dead(philo) == 1)
		// {
		// 	display_action(philo, DEAD);
		// 	exit (0);
		// }
		// <---------------while you do all this shit dont forget to check dude is not dead-------------->
		philo->data->no_meals = philo->data->max_meals;
		if (philo->data->max_meals != -1)
			how_many_meals(philo);
	}
	if (is_philo_dead(philo) == 1)
	{
		display_action(philo, DEAD);
		exit (0);
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
