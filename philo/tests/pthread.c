/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:56:47 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/20 19:20:35 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*t1func(void);
void	*t2func(void);

int	main(void)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, t1func, NULL);
	pthread_create(&thread2, NULL, t2func, NULL);
	return (0);
}

void	*t1func(void)
{
	printf("Hello from thread 1!\n");
	return (NULL);
}

void	*t2func(void)
{
	printf("Hello from thread 2!\n");
	return (NULL);
}