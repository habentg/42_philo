/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/20 06:44:00 by hatesfam         ###   ########.fr       */
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
	pthread_mutex_destroy(data->philo->r_lock);
	pthread_mutex_destroy(data->philo->l_lock);
	while (++i < data->no_philos)
		pthread_mutex_destroy(&data->fork_mutexes[i]);
	free(data->fork_mutexes);
	free(data->forks);
	free(data->philo);
	free(data->thrd_id);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	if (start_philo(&data) != 0)
		return (1);
	ft_clean(&data);
	return (0);
}
