/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:29 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/17 19:01:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	number;

	i = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		number = (number * 10) + (str[i] - '0');
		if (number > INT_MAX || number < INT_MIN)
			ft_error(INVALID_INPUT, NULL);
		i++;
	}
	return (number);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	total;

	total = nitems * size;
	if (total >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	p = malloc(total);
	if (!p)
		return (NULL);
	memset(p, 0, total);
	return (p);
}
