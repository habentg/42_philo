/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:37:47 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/24 12:02:53 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_data *data)
{
	int	i;

	data->fork_mutexes = malloc(data->no_philos * sizeof(pthread_mutex_t));
	data->forks = ft_calloc(data->no_philos, sizeof(int));
	if (!data->fork_mutexes || !data->forks)
		return (ft_error(FORK_ALLOC_FAIL, data), 1);
	i = -1;
	while (++i < data->no_philos)
		pthread_mutex_init(&data->fork_mutexes[i], NULL);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->no_philos);
	if (!data->philo)
		return (ft_error(PHILO_ALLOC_FAIL, data), 1);
	while (++i < data->no_philos)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].data = data;
		data->philo[i].r_fork = &(data->forks[i]);
		data->philo[i].l_fork = &(data->forks[data->philo[i].philo_id \
			% data->no_philos]);
		data->philo[i].r_lock = &data->fork_mutexes \
			[data->philo[i].philo_id - 1];
		data->philo[i].l_lock = &data->fork_mutexes[(data->philo[i].philo_id) \
			% data->no_philos];
		data->philo[i].no_meals = 0;
		data->philo[i].last_meal_time = get_time_ms(data->philo);
	}
	pthread_mutex_init(data->philo->r_lock, NULL);
	pthread_mutex_init(data->philo->l_lock, NULL);
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->no_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->is_dead = 0;
	data->max_meals = -1;
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	data->thrd_id = (pthread_t *)malloc(sizeof(pthread_t) * data->no_philos);
	if (!data->thrd_id)
		return (ft_error(THREAD_ALLOC_FAIL, data), 1);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->is_dead_lock, NULL);
	return (0);
}

int	init(int argc, char **argv, t_data *data)
{
	if (init_data(argc, argv, data) != 0)
		return (1);
	if (init_forks(data) != 0)
		return (1);
	if (init_philos(data) != 0)
		return (1);
	return (0);
}

// for (int i = 0; i < data->no_philos; i++)
// {
// 	printf("%d Right fork: %p\n", data->philo[i].
//		philo_id, data->philo[i].r_fork);
// 	printf("%d Left fork: %p\n", data->philo[i].philo_id,
//		 data->philo[i].l_fork);
// }