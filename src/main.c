/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 04:53:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	if (data)
		ft_clean(data);
}

void	ft_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
		pthread_mutex_destroy(&data->fork_mutexes[i]);
	if (data->philo->r_lock)
		pthread_mutex_destroy(data->philo->r_lock);
	if (data->philo->l_lock)
		pthread_mutex_destroy(data->philo->l_lock);
	pthread_mutex_destroy(&data->is_dead_lock);
	pthread_mutex_destroy(&data->print_lock);
	if (data->fork_mutexes)
		free(data->fork_mutexes);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	if (data->thrd_id)
		free(data->thrd_id);
}

void	check_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		i = -1;
		if (data->is_dead == 1)
		{
			display_action(data->philo, DEAD);
			break ;
		}
		else if (data->max_meals != -1)
		{
			while (++i < data->no_philos)
			{
				if (data->philo[i].no_meals != data->max_meals)
					continue ;
			}
			break ;
		}
		display_philo(data->philo);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	if (data.no_philos == 1)
		case_one(&data);
	else
	{
		if (start_philo(&data) != 0)
			return (1);
		check_simulation(&data);
	}
	ft_clean(&data);
	return (0);
}
