/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:29 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/14 14:09:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
    write(1, "\n", 1);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	number;

	i = 0;
	number = 0;
	while (str[i])
	{
        if (str[i] < '0' || str[i] > '9')
            return (-1);
		number = (number * 10) + (str[i] - '0');
		if (number > INT_MAX || number < INT_MIN)
			ft_error(INVALID_INPUT);
		i++;
	}
	return (number);
}
