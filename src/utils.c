<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:29 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/27 09:45:56 by hatesfam         ###   ########.fr       */
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
			return (print_instruction(), -1);
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

// just instructions on the format of the input.
void	print_instruction(void)
{
	printf("%s\n", "😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂");
	printf("%s\n", "ERROR: Invalid Input -> only counting numbers");
	printf("%s\n", "Philo input format:");
	printf("%s\n", "✅ ./philo {No of philos} {time to die} {time to sleep} "\
		"{no of meals (opt)}");
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:29 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/24 16:28:40 by hatesfam         ###   ########.fr       */
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
			return (ft_error(INVALID_INPUT, NULL), -1);
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

void	ft_usleep(unsigned long long ms)
{
	unsigned long long	time;

	time = get_time_ms(NULL);
	while (get_time_ms(NULL) - time < ms)
		usleep(ms / 10);
}
>>>>>>> 977dedb415dbf604b57a6a13760b89c67a54998f
