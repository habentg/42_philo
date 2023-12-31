/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:12:14 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/30 15:39:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*gonna print out info/error-text if its invalid input*/
int	check_argc(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		ft_error(INVALID_PARAMS, 0);
		return (print_instruction(), 1);
	}
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			return (ft_error(INVALID_PARAMS_EMTY, 0), 1);
		if (ft_atoi(argv[i]) == -1)
			return (print_instruction(), 1);
	}
	if (ft_atoi(argv[1]) <= 0)
		return (ft_error(INVALID_PHILO_INPUT, 0), 1);
	return (0);
}
