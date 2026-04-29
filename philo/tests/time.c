/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:10:15 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/29 19:19:22 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	long	start_time;

	if (argc != 2)
	{
		printf("Usage: %s <time to sleep in ms>\n", argv[0]);
		return (1);
	}
	start_time = current_time_ms();
	printf("Current time in ms:\t%ld\n", start_time);
	usleep(ft_uatoi(argv[1]) * 1000);
	printf("Time after sleeping:\t%ld\n", current_time_ms());
}