<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:12:14 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/27 09:04:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*gonna print out info/error-text if its invalid input*/
int	check_argc(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error(INVALID_PARAMS, 0), 1);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == -1)
			return (print_instruction(), 2);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (ft_error(INVALID_PHILO_INPUT, 0), 1);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (ft_error(INVALID_MS_INPUT, 0), 1);
	return (0);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:12:14 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/18 23:57:38 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_argc(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error(INVALID_PARAMS, NULL), 1);
	if (ft_atoi(argv[1]) <= 0)
		return (ft_error(INVALID_PHILO_INPUT, NULL), 1);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == -1)
			return (ft_error(INVALID_INPUT, NULL), 2);
	}
	return (0);
}
>>>>>>> 977dedb415dbf604b57a6a13760b89c67a54998f
