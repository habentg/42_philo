/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:29 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/30 16:58:16 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// the OG function from pecine
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
			return (-1);
		i++;
	}
	return (number);
}

// malloc + 0 init instead of garbage value
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	total;

	total = nitems * size;
	if (total >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	p = malloc(total);
	if (!p)
		return (0);
	memset(p, 0, total);
	return (p);
}

// more accurate usleep + accepts milliseconds
/*bc using usleep == usleep(duration) + some small delays (it adds up)*/
void	ft_usleep(unsigned long long duration)
{
	unsigned long long	time;

	time = get_time_ms();
	while (get_time_ms() - time < duration)
		usleep(duration / 10);
}

/*get the num of milliseconds form 1st of Jan 1970 -> CRAZY*/
unsigned long long	get_time_ms(void)
{
	struct timeval	tv;
	long long		curr_time_ms;

	curr_time_ms = 0;
	if (gettimeofday(&tv, 0))
		return (ft_error(GET_TIME_ERROR, 0), 1);
	curr_time_ms = (tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000);
	return (curr_time_ms);
}

// just instructions on the format of the input.
void	print_instruction(void)
{
	printf("%s\n", "😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂");
	printf("%s\n", "ERROR: Invalid Input -> put "\
		"counting numbers & in INT range");
	printf("%s\n", "Philo input format:");
	printf("%s\n", "✅ ./philo {No of philos} {time to die} {time to sleep} "\
		"{no of meals (opt)}");
}
